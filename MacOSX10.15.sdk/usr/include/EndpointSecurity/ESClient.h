#ifndef __ENDPOINT_SECURITY_CLIENT_H
#define __ENDPOINT_SECURITY_CLIENT_H

#include <os/availability.h>
#include <os/base.h>

struct es_client_s;
/**
 * es_client_t is an opaque type that stores the endpoint security client state
 */
typedef struct es_client_s es_client_t;

__BEGIN_DECLS

/**
 * Subscribe to some set of events
 * This is a variadic function
 * @param client The client that will be subscribing
 * @param event_count The number of event types being subscribed to
 * pass event types (es_event_type_t) as variadic arguments
 * @return true indicates success, false indicates the subsystem could not be reached or that the request was invalid
 */
OS_EXPORT
API_AVAILABLE(macos(10.15)) API_UNAVAILABLE(ios, tvos, watchos)
bool es_subscribe(es_client_t * _Nonnull client, uint32_t event_count, ...);

/**
 * Unsubscribe from some set of events
 * This is a variadic function
 * @param client The client that will be unsubscribing
 * @param event_count The number of event types being unsubscribed from
 * pass event types (es_event_type_t) as variadic arguments
 * @return true indicates success, false indicates the subsystem could not be reached or that the request was invalid
 */
OS_EXPORT
API_AVAILABLE(macos(10.15)) API_UNAVAILABLE(ios, tvos, watchos)
bool es_unsubscribe(es_client_t * _Nonnull client, uint32_t event_count, ...);

/**
 * Unsubscribe from all events
 * @param client The client that will be unsubscribing
 * @return true indicates success, false indicates the subsystem could not be reached or that the request was invalid
 */
OS_EXPORT
API_AVAILABLE(macos(10.15)) API_UNAVAILABLE(ios, tvos, watchos)
bool es_unsubscribe_all(es_client_t * _Nonnull client);

/**
 * Respond to an auth event that requires an es_auth_result_t response
 * @param client The client that produced the event
 * @param message The message being responded to
 * @param result A result indicating the action the ES subsystem should take
 * @param cache Indicates if this result should be cached (the specific caching semantics depend on es_event_type_t)
 * @return An es_respond_result_t value indicating success or an error
 */
OS_EXPORT
API_AVAILABLE(macos(10.15)) API_UNAVAILABLE(ios, tvos, watchos)
es_respond_result_t
es_respond_auth_result(es_client_t * _Nonnull client, const es_message_t * _Nonnull message, es_auth_result_t result, bool cache);

/**
 * Respond to an auth event that requires an uint32_t flags response
 * @param client The client that produced the event
 * @param message The message being responded to
 * @param authorized_flags A flags value that will mask the flags in event being responded to
 * @param cache Indicates if this result should be cached. The specific caching semantics depend on es_event_type_t
 * @return An es_respond_result_t value indicating success or an error
 */
OS_EXPORT
API_AVAILABLE(macos(10.15)) API_UNAVAILABLE(ios, tvos, watchos)
es_respond_result_t
es_respond_flags_result(es_client_t * _Nonnull client, const es_message_t * _Nonnull message, uint32_t authorized_flags, bool cache);

/**
 * Supress events relating to the process with audit_token
 * @param client The client for which events will be supressed
 * @param audit_token The audit token of the process for which events will be supressed
 * @return true indicates success, false indicates the ES subsystem could not be reached or that the request was invalid
 */
OS_EXPORT
API_AVAILABLE(macos(10.15)) API_UNAVAILABLE(ios, tvos, watchos)
bool es_mute_process(es_client_t * _Nonnull client, audit_token_t audit_token);

/**
 * Clear all cached results for all clients
 * @param client that will perform the request
 * @return An es_clear_cache_result_t value indicating success or an error
 */
OS_EXPORT
API_AVAILABLE(macos(10.15)) API_UNAVAILABLE(ios, tvos, watchos)
es_clear_cache_result_t es_clear_cache(es_client_t * _Nonnull client);

/**
 * es_handler_block_t The type of block that will be invoked to handled messages from the ES subsystem
 * The es_client_t is a handle to the client being sent the event. It must be passed to any "respond" functions
 * The es_message_t is the message that must be handled
 */
typedef void (^es_handler_block_t)(es_client_t * _Nonnull, const es_message_t * _Nonnull);

/**
 * Initialise a new es_client_t and connect to the ES subsystem
 * @param handler The handler that will be run on all messages sent to this client
 * @return The newly created es_client_t. Null on failure.
 * @discussion Messages are handled strictly serially and in the order they are delivered.
 *			   Returning control from the handler causes the next available message to be dequeued.
 *        	   Messages can be responded to out of order by returning control before calling es_respond_*.
 *			   The es_message_t is only guaranteed to live as long as the scope it is passed into.
 *		  	   For out of order responding the handler must copy the message with es_copy_message.
 *		  	   Callers are required to be entitled with com.apple.developer.endpoint-security.client.
 *		  	   The application calling this interface must also be approved by users via Transparency, Consent & Control
 *		  	   (TCC) mechanisms using the Privacy Preferences pane and adding the application to Full Disk Access.
 * @see es_copy_message
 */
OS_EXPORT
API_AVAILABLE(macos(10.15)) API_UNAVAILABLE(ios, tvos, watchos)
es_new_client_result_t
es_new_client(es_client_t * _Nullable * _Nonnull client, es_handler_block_t _Nonnull handler);

/**
 * Destroy an es_client_t, freeing resources and disconnecting from the ES subsystem
 * @param client The client to be destroyed
 * @return  True indicates all resources were freed.
		   	False indicates an error occured during shutdown and resources were leaked.
 */
OS_EXPORT
API_AVAILABLE(macos(10.15)) API_UNAVAILABLE(ios, tvos, watchos)
bool es_delete_client(es_client_t * _Nonnull client);

__END_DECLS;

#endif /* __ENDPOINT_SECURITY_CLIENT_H */
