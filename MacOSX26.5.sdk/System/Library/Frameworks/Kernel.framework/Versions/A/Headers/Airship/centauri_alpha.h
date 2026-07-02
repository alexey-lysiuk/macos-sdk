//
//  centauri_alpha.h
//  Airship
//
//  Created by Jake Cronin on 9/13/23.
//

#if !defined(airship_api_indirect) && !defined(__clang_tapi__)
#error Please #include <Airship/Airship.h> instead of this file directly.
#endif

#ifndef airship__core__api__centauri_alpha_h
#define airship__core__api__centauri_alpha_h

/**
 * @file centauri_alpha.h
 * @brief Provides used exclusively by Centauri Alpha.
 */

#include <Airship/base.h>
#include <Airship/client.h>

AIRSHIP_ASSUME_NONNULL_BEGIN

/// Centauri Alpha transfer ring pool handle type.
typedef struct airship_centauri_alpha_ring_pool *airship_centauri_alpha_tr_pool_t;
/// Centauri Alpha completion ring pool handle type.
typedef struct airship_centauri_alpha_ring_pool *airship_centauri_alpha_cr_pool_t;

/**
 * @brief Creates a transfer ring pool handle to manage available rings for a given configuration.
 *
 * The returned handle must be released with `::airship_centauri_alpha_tr_pool_destroy`.
 *
 * @param client A client handle connected to the driver.
 * @param name The name configuration for the desired transfer rings.
 * @returns Transfer ring pool to manage autonomous transfer ring creation.
 */
AIRSHIP_EXPORT
airship_centauri_alpha_tr_pool_t airship_centauri_alpha_tr_pool_create(airship_client_t client, airship_string_t name);

/**
 * @brief Destroys a transfer ring pool handle.
 *
 * Destroying a transfer ring pool handle requires that all handles managed by the pool
 * be released prior to destruction using `::airship_centauri_alpha_tr_pool_release`.
 *
 * @pre All subordinate transfer ring handles created with the ring pool handle are
 * destroyed.
 *
 * @param pool The transfer ring pool handle to be destroyed.
 */
AIRSHIP_EXPORT
void airship_centauri_alpha_tr_pool_destroy(airship_centauri_alpha_tr_pool_t pool);

/**
 * @brief Reserve transfer ring with the selector given.
 *
 * This method is compatible with `::airship_centauri_alpha_tr_pool_reserve_next`,
 * but not compatible with `::airship_acipc_tr_create`.
 *
 * A null handle will be returned if the transfer ring is not available or the selector
 * is invalid.
 *
 * @param pool The transfer ring pool handle tracking the transfer ring config.
 * @param selector The desired transfer ring selector.
 * @returns A reserved transfer ring handle for the selector given, or null.
 */
AIRSHIP_EXPORT
airship_acipc_tr_t AIRSHIP_NULLABLE airship_centauri_alpha_tr_pool_reserve(airship_centauri_alpha_tr_pool_t pool, uint32_t selector);

/**
 * @brief Reserve the next available transfer ring in the configured group.
 *
 * This method is compatible with `::airship_centauri_alpha_tr_pool_reserve`, but not
 * compatible with `::airship_acipc_tr_create`.
 *
 * A null handle will be returned if no transfer ring is available.
 *
 * @param pool The transfer ring pool handle tracking the transfer ring group.
 * @param out_selector pointer to the selector for the returned transfer ring.
 * @returns A reserved transfer ring handle for the selector given.
 */
AIRSHIP_EXPORT
airship_acipc_tr_t AIRSHIP_NULLABLE airship_centauri_alpha_tr_pool_reserve_next(airship_centauri_alpha_tr_pool_t pool,
                                                                                AIRSHIP_NOESCAPE uint32_t *AIRSHIP_NULLABLE out_selector);

/**
 * @brief Release a transfer ring handle that was previously reserved, and destroys the handle.
 * @param pool The transfer ring pool handle tracking the transfer ring group.
 * @param tr Transfer ring handle to be released.
 */
AIRSHIP_EXPORT
void airship_centauri_alpha_tr_pool_release(airship_centauri_alpha_tr_pool_t pool, airship_acipc_tr_t tr);

/**
 * @brief Get the base ID value for the set of transfer rings in the ring pool.
 * @param pool The transfer ring pool handle tracking the transfer ring group.
 * @returns The base ID value for this tr pool.
 */
AIRSHIP_EXPORT
uint16_t airship_centauri_alpha_tr_pool_get_base_id(airship_centauri_alpha_tr_pool_t pool);

/**
 * @brief Get the total number of rings in the transfer ring pool.
 * @param pool The transfer ring pool handle tracking the transfer ring group.
 * @returns The total number of rings in the tr pool.
 */
AIRSHIP_EXPORT
uint32_t airship_centauri_alpha_tr_pool_get_count(airship_centauri_alpha_tr_pool_t pool);

/**
 * @brief Indicates if the transfer ring pool has available handles.
 * @param pool The transfer ring pool handle tracking the transfer ring group.
 * @returns true if the ring pool is empty (no handles available) false otherwise.
*/
AIRSHIP_EXPORT
bool airship_centauri_alpha_tr_pool_is_empty(airship_centauri_alpha_tr_pool_t pool);

/**
 * @brief Creates a completion ring pool handle to manage available rings for a given configuration.
 *
 * The returned handle must be released with `::airship_centauri_alpha_cr_pool_destroy`.
 *
 * @param client A client handle connected to the driver.
 * @param name The name configuration for the desired completion rings.
 * @returns Completion ring pool to manage autonomous completion ring creation.
 */
AIRSHIP_EXPORT
airship_centauri_alpha_cr_pool_t airship_centauri_alpha_cr_pool_create(airship_client_t client, airship_string_t name);

/**
 * @brief Destroys a completion ring pool handle.
 *
 * Destroying a completion ring pool handle requires that all handles managed by the pool
 * be released prior to destruction using `::airship_centauri_alpha_cr_pool_release`.
 *
 * @pre All subordinate completion ring handles created with the ring pool handle are
 * destroyed.
 *
 * @param pool The completion ring pool handle to be destroyed.
 */
AIRSHIP_EXPORT
void airship_centauri_alpha_cr_pool_destroy(airship_centauri_alpha_cr_pool_t pool);

/**
 * @brief Reserve completion ring with the selector given.
 *
 * This method is compatible with `::airship_centauri_alpha_cr_pool_reserve_next`,
 * but not compatible with `::airship_acipc_tr_create`.
 *
 * A null handle will be returned if the completion ring is not available or the selector
 * is invalid.
 *
 * @param pool The completion ring pool handle tracking the completion ring config.
 * @param selector The desired completion ring selector.
 * @returns A reserved completion ring handle for the selector given, or null.
 */
AIRSHIP_EXPORT
airship_acipc_cr_t AIRSHIP_NULLABLE airship_centauri_alpha_cr_pool_reserve(airship_centauri_alpha_cr_pool_t pool, uint32_t selector);

/**
 * @brief Reserve the next available completion ring in the configured group.
 *
 * This method is compatible with `::airship_centauri_alpha_cr_pool_reserve`, but not
 * compatible with `::airship_acipc_tr_create`.
 *
 * A null handle will be returned if no completion ring is available.
 *
 * @param pool The completion ring pool handle tracking the completion ring group.
 * @param out_selector pointer to the selector for the returned completion ring.
 * @returns A reserved completion ring handle for the selector given.
 */
AIRSHIP_EXPORT
airship_acipc_cr_t AIRSHIP_NULLABLE airship_centauri_alpha_cr_pool_reserve_next(airship_centauri_alpha_cr_pool_t pool,
                                                                                AIRSHIP_NOESCAPE uint32_t *AIRSHIP_NULLABLE out_selector);

/**
 * @brief Release a completion ring handle that was previously reserved, and destroys the handle.
 * @param pool The completion ring pool handle tracking the completion ring group.
 * @param cr completion ring handle to be released.
 */
AIRSHIP_EXPORT
void airship_centauri_alpha_cr_pool_release(airship_centauri_alpha_cr_pool_t pool, airship_acipc_cr_t cr);

/**
 * @brief Get the base ID value for the set of completion rings in the ring pool.
 * @param pool The completion ring pool handle tracking the completion ring group.
 * @returns The base ID value for this cr pool.
 */
AIRSHIP_EXPORT
uint16_t airship_centauri_alpha_cr_pool_get_base_id(airship_centauri_alpha_cr_pool_t pool);

/**
 * @brief Get the total number of rings in the completion ring pool.
 * @param pool The completion ring pool handle tracking the completion ring group.
 * @returns The total number of rings in the cr pool.
 */
AIRSHIP_EXPORT
uint32_t airship_centauri_alpha_cr_pool_get_count(airship_centauri_alpha_cr_pool_t pool);

/**
 * @brief Indicates if the completion ring pool has available handles.
 * @param pool The completion ring pool handle tracking the completion ring group.
 * @returns true if the ring pool is empty (no handles available) false otherwise.
*/
AIRSHIP_EXPORT
bool airship_centauri_alpha_cr_pool_is_empty(airship_centauri_alpha_cr_pool_t pool);

AIRSHIP_ASSUME_NONNULL_END

#endif /* airship__core__api__centauri_alpha_h */
