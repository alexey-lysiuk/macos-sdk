//
//  hv_vm_config.h
//  Hypervisor
//
//  Copyright © 2022-2024 Apple Inc. All rights reserved.
//

#pragma once

#ifdef __arm64__

#include <Hypervisor/hv_vm_types.h>

OS_ASSUME_NONNULL_BEGIN

__BEGIN_DECLS

/*!
 @abstract Creates a virtual machine configuration object.
 @result A new virtual machine configuration object. This should be released with os_release
    when no longer used.
 */
API_AVAILABLE(macos(13.0)) API_UNAVAILABLE(ios, tvos)
OS_EXPORT OS_OBJECT_RETURNS_RETAINED OS_WARN_RESULT
hv_vm_config_t hv_vm_config_create(void);

/*!
 @abstract Return the maximum intermediate physical address bit length.
 @param ipa_bit_length Pointer to bit length (written on success)
 @result HV_SUCCESS on success, an error code otherwise.
 @discussion The bit length is the number of valid bits from an intermediate physical address (IPA).
    For example, max IPA bit length of 36 means only the least significant 36 bits
    of an IPA are valid, and covers a 64GB range.
 */
OS_EXPORT API_AVAILABLE(macos(13.0)) API_UNAVAILABLE(ios, tvos)
hv_return_t hv_vm_config_get_max_ipa_size(uint32_t *ipa_bit_length);

/*!
 @abstract Return the default intermediate physical address bit length.
 @param ipa_bit_length Pointer to bit length (written on success)
 @result HV_SUCCESS on success, an error code otherwise.
 @discussion This default IPA size is used if the IPA size is not set explicitly.
 */
OS_EXPORT API_AVAILABLE(macos(13.0)) API_UNAVAILABLE(ios, tvos)
hv_return_t hv_vm_config_get_default_ipa_size(uint32_t *ipa_bit_length);

/*!
 @abstract Set intermediate physical address bit length in virtual machine configuration.
 @param config Configuration.
 @param ipa_bit_length intermediate physical address bit length.
 @result HV_SUCCESS on success, an error code otherwise.
 @discussion VM IPA size should be no greater than the max IPA size from hv_vm_config_get_max_ipa_size().
 @see hv_vm_config_get_max_ipa_size
 */
OS_EXPORT API_AVAILABLE(macos(13.0)) API_UNAVAILABLE(ios, tvos)
hv_return_t hv_vm_config_set_ipa_size(hv_vm_config_t config, uint32_t ipa_bit_length);

/*!
 @abstract Return intermediate physical address bit length in configuration.
 @param config Configuration.
 @param ipa_bit_length Pointer to bit length (written on success)
 @result HV_SUCCESS on success, an error code otherwise.
 */
OS_EXPORT API_AVAILABLE(macos(13.0)) API_UNAVAILABLE(ios, tvos)
hv_return_t hv_vm_config_get_ipa_size(hv_vm_config_t config, uint32_t *ipa_bit_length);

/*!
 @abstract Return whether or not EL2 is supported on the current platform.
 @param el2_supported Pointer to whether or not EL2 is supported (written on success).
 @result HV_SUCCESS on success, an error code otherwise.
 */
OS_EXPORT API_AVAILABLE(macos(15.0)) API_UNAVAILABLE(ios, tvos)
hv_return_t hv_vm_config_get_el2_supported(bool *el2_supported);

/*!
 @abstract Return whether or not EL2 is enabled for a VM configuration.
 @param config Configuration.
 @param el2_enabled Pointer to whether or not EL2 is enabled (written on success).
 @result HV_SUCCESS on success, an error code otherwise.
 */
OS_EXPORT API_AVAILABLE(macos(15.0)) API_UNAVAILABLE(ios, tvos)
hv_return_t hv_vm_config_get_el2_enabled(hv_vm_config_t config, bool *el2_enabled);

/*!
 @abstract Set whether or not EL2 is enabled for a VM configuration.
 @param config Configuration.
 @param el2_enabled Whether or not to enable EL2.
 @result HV_SUCCESS on success, an error code otherwise.
 */
OS_EXPORT API_AVAILABLE(macos(15.0)) API_UNAVAILABLE(ios, tvos)
hv_return_t hv_vm_config_set_el2_enabled(hv_vm_config_t config, bool el2_enabled);

__END_DECLS

OS_ASSUME_NONNULL_END

#endif
