// This header is required to define message types that are used across
// both SPI and API messages.
//
// ESTypes.h is not processed automatically into ESKTypes.h, so it cannot be
// used for core types that we don't want to manually convert into esk types.
#ifndef __ENDPOINT_SECURITY_CORE_MESSAGE_H
#define __ENDPOINT_SECURITY_CORE_MESSAGE_H

#include <sys/stat.h>
#include <sys/time.h>

/**
 * @brief es_file_t provides the stat information and path to a file that relates to a security
 * event. The path may be truncated, which is indicated by the path_truncated flag.
 *
 * @field path Absolute path of the file
 * @field path_truncated Indicates if the path field was truncated
 * @field stat stat of file. See `man 2 stat` for details
 *
 * @note For the FAT family of filesystems the `stat.st_ino` field is set to 999999999 for empty files
 *
 * @discussion For files with a link count greater than 1, the absolute path given may not be the only absolute path that exists,
 * and which hard link the emitted path points to is undefined.
 *
 * Overlong paths are truncated at a maximum length that currently is 16K, though that number is not considered API and may change
 * at any time.
 *
 */
typedef struct {
	es_string_token_t path;
	bool path_truncated;
	struct stat stat;
} es_file_t;

/**
 * @brief Information related to a process. This is used both for describing processes that
 * performed an action (e.g. in the case of the `es_message_t` `process` field, or are targets
 * of an action (e.g. for exec events this describes the new process being executed, for signal
 * events this describes the process that will receive the signal).
 *
 * @field audit_token Audit token of the process.
 * @field ppid Parent pid of the process. It is recommended to instead use the parent_audit_token field.
 *        @see parent_audit_token
 * @field original_ppid Original ppid of the process.  This field stays constant even in the event
 *        this process is reparented.
 * @field group_id Process group id the process belongs to.
 * @field session_id Session id the process belongs to.
 * @field codesigning_flags Code signing flags of the process.  The values for these flags can be
 *        found in the include file `cs_blobs.h` (`#include <kern/cs_blobs.h>`).
 * @field is_es_client Indicates this process has the Endpoint Security entitlement.
 * @field cdhash The code directory hash of the code signature associated with this process.
 * @field signing_id The signing id of the code signature associated with this process.
 * @field team_id The team id of the code signature associated with this process.
 * @field executable The executable file that is executing in this process.
 * @field tty The TTY this process is associated with, or NULL if the process does not have an
 *        associated TTY.  The TTY is a property of the POSIX session the process belongs to.
 *        A process' session may be associated with a TTY independently from whether its stdin
 *        or any other file descriptors point to a TTY device (as per isatty(3), tty(1)).
 * @field start_time Process start time, i.e. time of fork creating this process.
 * @field responsible_audit_token audit token of the process responsible for this process, which
 *        may be the process itself in case there is no responsible process or the responsible
 *        process has already exited.
 * @field parent_audit_token The audit token of the parent process
 * @field cs_validation_category Indicates the codesigning validation policy that authorized this binary
 *
 * @discussion
 * - Values such as pid, pidversion, uid, gid, etc. can be extracted from audit tokens using API
 *   provided in libbsm.
 * - The tuple (pid, pidversion) identifies a specific process execution, and should be used to link
 *   events to the process that emitted them.  Executing an executable image in a process using the
 *   exec or posix_spawn family of syscalls increments the pidversion.  However, (pid, pidversion)
 *   is not meant to be unique across reboots or across multiple systems.
 * - Clients should take caution when processing events where `is_es_client` is true. If multiple ES
 *   clients exist, actions taken by one client could trigger additional actions by the other client,
 *   causing a potentially infinite cycle.
 * - Fields related to code signing in the target `es_process_t` reflect the state of the process
 *   at the time the message is generated.  In the specific case of exec, this is after the exec
 *   completed in the kernel, but before any code in the process has started executing.  At that
 *   point, XNU has validated the signature itself and has verified that the CDHash is correct in
 *   that the hash of all the individual page hashes in the Code Directory matches the signed CDHash,
 *   essentially verifying the signature was not tampered with.  However, individual page hashes are
 *   not verified by XNU until the corresponding pages are paged in once they are accessed while the
 *   binary executes.  It is not until the individual pages are paged in that XNU determines if a
 *   binary has been tampered with and will update the code signing flags accordingly.
 *   EndpointSecurity provides clients the current state of the CS flags in the `codesigning_flags`
 *   member of the `es_process_t` struct.  The CS_VALID bit in the `codesigning_flags` means that
 *   everything the kernel has validated up to that point in time was valid, but not that there has
 *   been a full validation of all the pages in the executable file.  If page content has been
 *   tampered with in the executable, we won't know until that page is paged in.  At that time, the
 *   process will have its CS_VALID bit cleared and, if CS_KILL is set, the process will be killed,
 *   preventing any tampered code from being executed.  CS_KILL is generally set for platform
 *   binaries and for binaries having opted into the hardened runtime.  An ES client wishing to
 *   detect tampered code before it is paged in, for example at exec time, can use the Security
 *   framework to do so, but should be cautious of the potentially significant performance cost.  The
 *   EndpointSecurity subsystem itself has no role in verifying the validity of code signatures.
 */
typedef struct {
	audit_token_t audit_token;
	pid_t ppid;
	pid_t original_ppid;
	pid_t group_id;
	pid_t session_id;
	uint32_t codesigning_flags;
	bool is_platform_binary;
	bool is_es_client;
	es_cdhash_t cdhash;
	es_string_token_t signing_id;
	es_string_token_t team_id;
	es_file_t *_Nonnull executable;
	es_file_t *_Nullable tty;                           /* field available only if message version >= 2 */
	struct timeval start_time;                          /* field available only if message version >= 3 */
	audit_token_t responsible_audit_token;              /* field available only if message version >= 4 */
	audit_token_t parent_audit_token;                   /* field available only if message version >= 4 */
	es_cs_validation_category_t cs_validation_category; /* field available only if message version >= 10 */
} es_process_t;



#endif /* __ENDPOINT_SECURITY_CORE_MESSAGE_H */
