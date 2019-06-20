#ifndef __ENDPOINT_SECURITY_MESSAGE_H
#define __ENDPOINT_SECURITY_MESSAGE_H

#include <mach/message.h>
#include <stdbool.h>
#include <sys/mount.h>
#include <sys/xattr.h>
#include <os/availability.h>
#include <os/base.h>

#define ES_MAX_KEXT_BUNDLE_ID_LEN 128
#define ES_MAX_SIGNING_ID_LEN 128
#define ES_MAX_TEAM_ID_LEN 16
#define ES_MAX_USER_CLIENT_NAME_LEN 64

/**
 * The following struct defintions are shared between kernel and user code
 * The kernel will populate these data structures and deliver them to ESClients
 */

/** es_file_t provides the inode/devno and path to a file that relates to a security event
 * the path may be truncated, which is indeciated by the path_truncated flag.
 */
typedef struct {
	char path[MAXPATHLEN];
	bool path_truncated;
	dev_t devno;
	ino64_t inode;
} es_file_t;

/**
 * es_process_t describes a process that took the action being described in an es_message_t
 */
typedef struct {
	audit_token_t audit_token;
	pid_t ppid; //parent pid
	pid_t original_ppid; //may differ for foster children
	bool is_platform_binary;
	bool is_es_client; //indicates this process is connected to the ES subsystem.
	bool signing_id_truncated;
	bool team_id_truncated;
	char signing_id[ES_MAX_SIGNING_ID_LEN];
	char team_id[ES_MAX_TEAM_ID_LEN];
	uint8_t cdhash[CS_CDHASH_LEN];
	es_file_t file;
} es_process_t;

/**
 * Arguments and environment variables are packed
 * Use the exec_arg/exec_env functions to extract
 */
typedef struct {
	es_process_t proc;
	es_packed_token_blob_t args;
} es_event_exec_t;

typedef struct {
	int32_t requested;
	es_file_t file;
} es_event_open_t;

typedef struct {
	char identifier[ES_MAX_KEXT_BUNDLE_ID_LEN];
} es_event_kextload_t;

typedef struct {
	char identifier[ES_MAX_KEXT_BUNDLE_ID_LEN];
} es_event_kextunload_t;

typedef struct {
	es_file_t file;
	es_file_t parent;
} es_event_unlink_t;

typedef struct {
	int32_t protection;
	int32_t max_protection;
	int32_t flags;
	uint64_t file_pos;
	es_file_t file;
} es_event_mmap_t;

typedef struct {
	es_file_t source;
	es_file_t target;
} es_event_link_t;

typedef struct {
	char fs_type_name[MFSTYPENAMELEN];
	char mount_point[MAXPATHLEN];
} es_event_mount_t;

typedef struct {
	char fs_type_name[MFSTYPENAMELEN];
	char mount_point[MAXPATHLEN];
} es_event_unmount_t;

typedef struct {
	es_process_t child;
} es_event_fork_t;

typedef struct {
	int32_t protection;
} es_event_mprotect_t;

typedef struct {
	int signal_number;
	es_process_t target_process;
} es_event_signal_t;

typedef enum {
	ES_DESTINATION_TYPE_EXISTING_FILE,
	ES_DESTINATION_TYPE_NEW_PATH,
} es_destination_type_t;

typedef struct {
	es_file_t source;
	es_destination_type_t destination_type;
	union {
		char new_path[MAXPATHLEN];
		es_file_t existing_file;
	} destination;
} es_event_rename_t;

typedef struct {
	char extattr[XATTR_MAXNAMELEN+1];
	es_file_t target;
} es_event_setextattr_t;

typedef struct {
	es_file_t target;
	mode_t mode;
} es_event_setmode_t;

typedef struct {
	es_file_t target;
	u_long flags;
} es_event_setflags_t;

typedef struct {
	es_file_t target;
	uid_t uid;
	gid_t gid;
} es_event_setowner_t;

typedef struct {
	es_file_t target;
	bool close_modified;
} es_event_close_t;

typedef struct {
	es_file_t target;
} es_event_create_t;

typedef struct {
} es_event_exit_t;

typedef struct {
	es_file_t file1;
	es_file_t file2;
} es_event_exchangedata_t;

typedef struct {
	es_file_t file;
} es_event_write_t;

typedef struct {
	char user_client[ES_MAX_USER_CLIENT_NAME_LEN];
	uint32_t user_client_type;
} es_event_iokit_open_t;

typedef struct {
	es_process_t target_process;
} es_event_get_task_t;

typedef struct {
	es_file_t target;
	struct attrlist attr_list;
} es_event_setattrlist_t;

/**
 * Union of all possble events that can appear in an es_message_t
 */
typedef union {
	es_event_close_t close;
	es_event_create_t create;
	es_event_exchangedata_t exchangedata;
	es_event_exec_t exec;
	es_event_exit_t exit;
	es_event_fork_t fork;
	es_event_get_task_t get_task;
	es_event_iokit_open_t iokit_open;
	es_event_kextload_t kextload;
	es_event_kextunload_t kextunload;
	es_event_link_t link;
	es_event_mmap_t mmap;
	es_event_mount_t mount;
	es_event_mprotect_t mprotect;
	es_event_open_t open;
	es_event_rename_t rename;
	es_event_setattrlist_t setattrlist;
	es_event_setextattr_t setextattr;
	es_event_setflags_t setflags;
	es_event_setmode_t setmode;
	es_event_setowner_t setowner;
	es_event_signal_t signal;
	es_event_unlink_t unlink;
	es_event_unmount_t unmount;
	es_event_write_t write;
} es_events_t;

/**
 * es_result_t indicates the result of the ES subsystem authorization process
 * The result_type field indicates if the result is an es_auth_result_t or a uint32_t (flags)
 */
typedef struct {
	es_result_type_t result_type;
	union {
		es_auth_result_t auth;
		uint32_t flags;
	} result;
} es_result_t;

/**
 * es_message_t is the top level datatype that encodes information sent from the ES subsystem to it's clients
 * Each security event being processed by the ES subsystem will be encoded in an es_message_t
 * A message can be an authorization request or a notification of an event that has already taken place
 * The action_type indicates if the action field is an auth or notify action
 * The event_type indicates which event struct is defined in the event union.
 * For events that can be authorized there are unique NOTIFY and AUTH event types for the same event data
 * eg: event.exec is the correct union label for both ES_EVENT_TYPE_AUTH_EXEC and ES_EVENT_TYPE_NOTIFY_EXEC event types
 */
typedef struct {
	struct timespec time;
	uint64_t mach_time;
	es_process_t proc;
	es_action_type_t action_type;
	union {
		es_event_id_t auth;
		es_result_t notify;
	} action;
	es_event_type_t event_type;
	es_events_t event;
} es_message_t;

__BEGIN_DECLS

/**
 * Calculate the size of an es_message_t.
 * @param msg The message for which the size will be calculated
 * @return size_t of the message
 */
OS_EXPORT
API_AVAILABLE(macos(10.15)) API_UNAVAILABLE(ios, tvos, watchos)
size_t
es_message_size(const es_message_t * _Nonnull msg);

/**
 * Copy an es_message_t, allocating new memory.
 * @param msg The message to be copied
 * @return pointer to newly allocated es_message_t. The caller now owns this memory and must free it.
 */
OS_EXPORT
API_AVAILABLE(macos(10.15)) API_UNAVAILABLE(ios, tvos, watchos)
es_message_t * _Nullable
es_copy_message(const es_message_t * _Nonnull msg);

/**
 * Get the number of arguments in an es_event_exec_t
 * @param exec_event The exec_event_t being inspected
 * @return The number of arguments
 */
OS_EXPORT
API_AVAILABLE(macos(10.15)) API_UNAVAILABLE(ios, tvos, watchos)
uint64_t
es_exec_arg_count(const es_event_exec_t * _Nonnull exec_event);

/**
 * Get the number of environment variables in an es_event_exec_t
 * @param exec_event The exec_event_t being inspected
 * @return The number of environment variables
 */
OS_EXPORT
API_AVAILABLE(macos(10.15)) API_UNAVAILABLE(ios, tvos, watchos)
uint64_t
es_exec_env_count(const es_event_exec_t * _Nonnull exec_event);

/**
 * Get the argument at the specified position in the provided es_event_exec_t
 * @param exec_event The exec_event_t being inspected
 * @param index Index of the arguement to retrieve (starts from 0)
 * @return  es_token_t containing a pointer to the argument and its length.
 *          This is a zero-allocation operation. The returned pointer must not outlive exec_event.
 */
OS_EXPORT
API_AVAILABLE(macos(10.15)) API_UNAVAILABLE(ios, tvos, watchos)
es_token_t
es_exec_arg(const es_event_exec_t * _Nonnull exec_event, uint32_t index);

/**
 * Get the environemnt variable at the specified position in the provided exec_event
 * @param exec_event The exec_event_t being inspected
 * @param index Index of the environemnt variable to retrieve (starts from 0)
 * @return  es_token_t containing a pointer to the environemnt variable and its length.
 *          This is zero-allocation operation. The returned pointer must not outlive exec_event.
 */
OS_EXPORT
API_AVAILABLE(macos(10.15)) API_UNAVAILABLE(ios, tvos, watchos)
es_token_t
es_exec_env(const es_event_exec_t * _Nonnull exec_event, uint32_t index);

__END_DECLS

#endif /* __ENDPOINT_SECURITY_MESSAGE_H */
