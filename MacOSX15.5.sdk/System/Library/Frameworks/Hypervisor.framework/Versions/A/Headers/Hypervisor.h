//
//  Hypervisor.h
//  Hypervisor
//
//  Copyright © 2019-2024 Apple Inc. All rights reserved.
//

#pragma once

#if defined(__arm64__)
#include <Hypervisor/hv_gic.h>
#include <Hypervisor/hv_gic_config.h>
#include <Hypervisor/hv_gic_parameters.h>
#include <Hypervisor/hv_gic_state.h>
#include <Hypervisor/hv_gic_types.h>
#include <Hypervisor/hv_sme_config.h>
#include <Hypervisor/hv_vcpu.h>
#include <Hypervisor/hv_vcpu_config.h>
#include <Hypervisor/hv_vcpu_types.h>
#include <Hypervisor/hv_vm.h>
#include <Hypervisor/hv_vm_config.h>
#include <Hypervisor/hv_vm_types.h>
#elif defined(__x86_64__)
#include <Hypervisor/hv.h>
#include <Hypervisor/hv_error.h>
#include <Hypervisor/hv_intr.h>
#include <Hypervisor/hv_types.h>
#include <Hypervisor/hv_vmx.h>
#endif

#include <Hypervisor/hv_vm_allocate.h>
