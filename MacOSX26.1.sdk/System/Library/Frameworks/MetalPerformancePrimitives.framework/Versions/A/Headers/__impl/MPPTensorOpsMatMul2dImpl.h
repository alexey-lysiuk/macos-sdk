
// -*- Metal -*-
//===-- MetalTensorOpsMatMul2dImpl
//------------------------------------------------------===//
// Copyright (c) 2025 Apple Inc. All rights reserved
//===----------------------------------------------------------------------===//

#ifndef __MetalTensorOpsMatMul2dImpl__
#define __MetalTensorOpsMatMul2dImpl__

#if defined(__METAL_VERSION__) && defined(__HAVE_TENSOR__)

namespace __mutmul2d_detail
{

#ifndef EXTERNALLY_DEFINED_ATTR
#define EXTERNALLY_DEFINED_ATTR \
  __attribute__((section("air.externally_defined")))
#endif

#define TENSOROPS_EXPORT [[gnu::visibility("default")]]
#define INLINE __attribute__((__always_inline__))

using __matmul2d_descriptor = matmul2d_descriptor;

using __matmul2d_cooperative_operand_index = matmul2d_cooperative_operand_index;

using __reduction_operation = reduction_operation;

constexpr bool matmul2d_descriptor_is_equal(matmul2d_descriptor a, matmul2d_descriptor b) {
  return a.m == b.m &&
         a.n == b.n &&
         a.k == b.k &&
         a.transpose_left == b.transpose_left &&
         a.transpose_right == b.transpose_right &&
         a.relaxed_precision == b.relaxed_precision &&
         a.matmul_mode == b.matmul_mode;
}

extern "C" EXTERNALLY_DEFINED_ATTR size_t
__tensorops_impl_matmul2d_op_cooperative_destination_data_size(
    __matmul2d_descriptor descriptor,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype,
    int);
extern "C" EXTERNALLY_DEFINED_ATTR uint16_t
__tensorops_impl_matmul2d_op_cooperative_destination_tensor_num_elements(
    __matmul2d_descriptor descriptor,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype,
    int);
extern "C" EXTERNALLY_DEFINED_ATTR thread void *
__tensorops_impl_matmul2d_op_cooperative_destination_tensor_get_element_pointer(
    __matmul2d_descriptor descriptor,
    __tensor_ops_detail::__thread_void_t,
    uint16_t,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype);
extern "C" EXTERNALLY_DEFINED_ATTR thread uint16_t
__tensorops_impl_matmul2d_op_cooperative_destination_tensor_get_element_index(
    __matmul2d_descriptor descriptor,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_tensor_get_coordinate(
    __matmul2d_descriptor descriptor,
    __tensor_ops_detail::__const_thread_void_t,
    uint16_t,
    __tensor_ops_detail::__thread_void_t,
    __tensor_ops_detail::__tensor_ops_datatype,
    int,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_tensor_init(
    __matmul2d_descriptor,
    __tensor_ops_detail::__thread_void_t,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype,
    int);
extern "C" EXTERNALLY_DEFINED_ATTR bool
__tensorops_impl_matmul2d_op_cooperative_destination_tensor_is_valid_element(
    __matmul2d_descriptor,
    __tensor_ops_detail::__const_thread_void_t,
    uint16_t,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype,
    int);

extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_tensor_load_dv_f16(
    __matmul2d_descriptor,
    __tensor_ops_detail::__thread_void_t,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type,
    int,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype,
    int);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_tensor_load_tg_f16(
    __matmul2d_descriptor,
    __tensor_ops_detail::__thread_void_t,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type,
    int,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype,
    int);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_tensor_load_dv_i32(
    __matmul2d_descriptor,
    __tensor_ops_detail::__thread_void_t,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type,
    int,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype,
    int);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_tensor_load_tg_i32(
    __matmul2d_descriptor,
    __tensor_ops_detail::__thread_void_t,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type,
    int,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype,
    int);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_tensor_load_dv_f32(
    __matmul2d_descriptor,
    __tensor_ops_detail::__thread_void_t,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type,
    int,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype,
    int);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_tensor_load_tg_f32(
    __matmul2d_descriptor,
    __tensor_ops_detail::__thread_void_t,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type,
    int,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype,
    int);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_tensor_load_dv_b16(
    __matmul2d_descriptor,
    __tensor_ops_detail::__thread_void_t,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type,
    int,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype,
    int);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_tensor_load_tg_b16(
    __matmul2d_descriptor,
    __tensor_ops_detail::__thread_void_t,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type,
    int,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype,
    int);

extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_tensor_store_dv_f16(
    __matmul2d_descriptor,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_tensor_store_tg_f16(
    __matmul2d_descriptor,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_tensor_store_dv_i32(
    __matmul2d_descriptor,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_tensor_store_tg_i32(
    __matmul2d_descriptor,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_tensor_store_dv_f32(
    __matmul2d_descriptor,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_tensor_store_tg_f32(
    __matmul2d_descriptor,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_tensor_store_dv_b16(
    __matmul2d_descriptor,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_tensor_store_tg_b16(
    __matmul2d_descriptor,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype,
    int threads);

extern "C" EXTERNALLY_DEFINED_ATTR size_t
__tensorops_impl_matmul2d_op_cooperative_reduction_destination_data_size(
    __matmul2d_descriptor,
    int,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype,
    int);
extern "C" EXTERNALLY_DEFINED_ATTR uint16_t
__tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_num_elements(
    __matmul2d_descriptor,
    __tensor_ops_detail::__const_thread_void_t,
    int,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype,
    int);
extern "C" EXTERNALLY_DEFINED_ATTR thread void *
__tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_get_element_pointer(
    __matmul2d_descriptor,
    __tensor_ops_detail::__thread_void_t,
    uint16_t,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype);
extern "C" EXTERNALLY_DEFINED_ATTR thread uint16_t
__tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_get_element_index(
    __matmul2d_descriptor,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_get_coordinate(
    __matmul2d_descriptor,
    int,
    __tensor_ops_detail::__const_thread_void_t,
    uint16_t,
    __tensor_ops_detail::__thread_void_t,
    __tensor_ops_detail::__tensor_ops_datatype,
    int,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_init(
    __tensor_ops_detail::__thread_void_t,
    __matmul2d_descriptor,
    int,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype,
    int);
extern "C" EXTERNALLY_DEFINED_ATTR bool
__tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_is_valid_element(
    __matmul2d_descriptor descriptor,
    __tensor_ops_detail::__const_thread_void_t,
    int,
    uint16_t,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype,
    int);
extern "C" EXTERNALLY_DEFINED_ATTR uint16_t
__tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_map_index(
    __tensor_ops_detail::__const_thread_void_t,
    __matmul2d_descriptor,
    __tensor_ops_detail::__const_thread_void_t,
    __matmul2d_descriptor,
    int,
    int,
    uint16_t,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype);
extern "C" EXTERNALLY_DEFINED_ATTR bool
__tensorops_impl_matmul2d_op_cooperative_destination_is_iterator_compatible(
    __matmul2d_descriptor,
    __matmul2d_descriptor,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype);

extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_load_dv_f16(
    __matmul2d_descriptor,
    __tensor_ops_detail::__thread_void_t,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type,
    int,
    int,
    __tensor_ops_detail::__tensor_ops_datatype leftDataType,
    __tensor_ops_detail::__tensor_ops_datatype rightDataType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_load_tg_f16(
    __matmul2d_descriptor,
    __tensor_ops_detail::__thread_void_t,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type,
    int,
    int,
    __tensor_ops_detail::__tensor_ops_datatype leftDataType,
    __tensor_ops_detail::__tensor_ops_datatype rightDataType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_load_dv_i32(
    __matmul2d_descriptor,
    __tensor_ops_detail::__thread_void_t,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type,
    int,
    int,
    __tensor_ops_detail::__tensor_ops_datatype leftDataType,
    __tensor_ops_detail::__tensor_ops_datatype rightDataType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_load_tg_i32(
    __matmul2d_descriptor,
    __tensor_ops_detail::__thread_void_t,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type,
    int,
    int,
    __tensor_ops_detail::__tensor_ops_datatype leftDataType,
    __tensor_ops_detail::__tensor_ops_datatype rightDataType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_load_dv_f32(
    __matmul2d_descriptor,
    __tensor_ops_detail::__thread_void_t,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type,
    int,
    int,
    __tensor_ops_detail::__tensor_ops_datatype leftDataType,
    __tensor_ops_detail::__tensor_ops_datatype rightDataType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_load_tg_f32(
    __matmul2d_descriptor,
    __tensor_ops_detail::__thread_void_t,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type,
    int,
    int,
    __tensor_ops_detail::__tensor_ops_datatype leftDataType,
    __tensor_ops_detail::__tensor_ops_datatype rightDataType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_load_dv_b16(
    __matmul2d_descriptor,
    __tensor_ops_detail::__thread_void_t,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type,
    int,
    int,
    __tensor_ops_detail::__tensor_ops_datatype leftDataType,
    __tensor_ops_detail::__tensor_ops_datatype rightDataType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_load_tg_b16(
    __matmul2d_descriptor,
    __tensor_ops_detail::__thread_void_t,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type,
    int,
    int,
    __tensor_ops_detail::__tensor_ops_datatype leftDataType,
    __tensor_ops_detail::__tensor_ops_datatype rightDataType);

extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_store_dv_f16(
    __matmul2d_descriptor,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type,
    int,
    int,
    __tensor_ops_detail::__tensor_ops_datatype leftDataType,
    __tensor_ops_detail::__tensor_ops_datatype rightDataType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_store_tg_f16(
    __matmul2d_descriptor,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type,
    int,
    int,
    __tensor_ops_detail::__tensor_ops_datatype leftDataType,
    __tensor_ops_detail::__tensor_ops_datatype rightDataType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_store_dv_i32(
    __matmul2d_descriptor,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type,
    int,
    int,
    __tensor_ops_detail::__tensor_ops_datatype leftDataType,
    __tensor_ops_detail::__tensor_ops_datatype rightDataType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_store_tg_i32(
    __matmul2d_descriptor,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type,
    int,
    int,
    __tensor_ops_detail::__tensor_ops_datatype leftDataType,
    __tensor_ops_detail::__tensor_ops_datatype rightDataType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_store_dv_f32(
    __matmul2d_descriptor,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type,
    int,
    int,
    __tensor_ops_detail::__tensor_ops_datatype leftDataType,
    __tensor_ops_detail::__tensor_ops_datatype rightDataType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_store_tg_f32(
    __matmul2d_descriptor,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type,
    int,
    int,
    __tensor_ops_detail::__tensor_ops_datatype leftDataType,
    __tensor_ops_detail::__tensor_ops_datatype rightDataType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_store_dv_b16(
    __matmul2d_descriptor,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type,
    int,
    int,
    __tensor_ops_detail::__tensor_ops_datatype leftDataType,
    __tensor_ops_detail::__tensor_ops_datatype rightDataType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_store_tg_b16(
    __matmul2d_descriptor,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type,
    int,
    int,
    __tensor_ops_detail::__tensor_ops_datatype leftDataType,
    __tensor_ops_detail::__tensor_ops_datatype rightDataType);

extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_reduce_rows_f16(
    __matmul2d_descriptor,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__thread_void_t,
    half,
    __reduction_operation,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_reduce_rows_f32(
    __matmul2d_descriptor,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__thread_void_t,
    float,
    __reduction_operation,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_reduce_rows_i32(
    __matmul2d_descriptor,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__thread_void_t,
    int,
    __reduction_operation,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_reduce_rows_b16(
    __matmul2d_descriptor,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__thread_void_t,
    bfloat,
    __reduction_operation,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype);

extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_reduce_columns_f16(
    __matmul2d_descriptor,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__thread_void_t,
    half,
    __reduction_operation,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_reduce_columns_f32(
    __matmul2d_descriptor,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__thread_void_t,
    float,
    __reduction_operation,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_reduce_columns_i32(
    __matmul2d_descriptor,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__thread_void_t,
    int,
    __reduction_operation,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_reduce_columns_b16(
    __matmul2d_descriptor,
    __tensor_ops_detail::__const_thread_void_t,
    __tensor_ops_detail::__thread_void_t,
    bfloat,
    __reduction_operation,
    __tensor_ops_detail::__tensor_ops_datatype,
    __tensor_ops_detail::__tensor_ops_datatype);

extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f16_dv_f16_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f16_dv_f16_tg_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f16_tg_f16_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f16_tg_f16_tg_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f16_dv_f16_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f16_dv_f16_tg_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f16_tg_f16_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f16_tg_f16_tg_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f16_dv_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f16_dv_f16_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f16_tg_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f16_tg_f16_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f16_dv_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f16_dv_f16_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f16_tg_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f16_tg_f16_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f16_dv_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f16_dv_f32_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f16_tg_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f16_tg_f32_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f16_dv_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f16_dv_f32_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f16_tg_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f16_tg_f32_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f16_dv_i8_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f16_dv_i8_tg_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f16_tg_i8_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f16_tg_i8_tg_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f16_dv_i8_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f16_dv_i8_tg_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f16_tg_i8_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f16_tg_i8_tg_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f16_dv_i8_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f16_dv_i8_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f16_tg_i8_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f16_tg_i8_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f16_dv_i8_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f16_dv_i8_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f16_tg_i8_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f16_tg_i8_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f32_dv_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f32_dv_f16_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f32_tg_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f32_tg_f16_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f32_dv_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f32_dv_f16_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f32_tg_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f32_tg_f16_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f32_dv_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f32_dv_f32_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f32_tg_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f32_tg_f32_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f32_dv_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f32_dv_f32_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f32_tg_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f32_tg_f32_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f32_dv_i8_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f32_dv_i8_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f32_tg_i8_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f32_tg_i8_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f32_dv_i8_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f32_dv_i8_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f32_tg_i8_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f32_tg_i8_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_i8_dv_f16_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_i8_dv_f16_tg_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_i8_tg_f16_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_i8_tg_f16_tg_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_i8_dv_f16_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_i8_dv_f16_tg_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_i8_tg_f16_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_i8_tg_f16_tg_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_i8_dv_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_i8_dv_f16_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_i8_tg_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_i8_tg_f16_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_i8_dv_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_i8_dv_f16_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_i8_tg_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_i8_tg_f16_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_i8_dv_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_i8_dv_f32_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_i8_tg_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_i8_tg_f32_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_i8_dv_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_i8_dv_f32_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_i8_tg_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_i8_tg_f32_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_i8_dv_i8_dv_i32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_i8_dv_i8_tg_i32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_i8_tg_i8_dv_i32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_i8_tg_i8_tg_i32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_i8_dv_i8_dv_i32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_i8_dv_i8_tg_i32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_i8_tg_i8_dv_i32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_i8_tg_i8_tg_i32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);

extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_f16_dv_f16_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_f16_tg_f16_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_f16_dv_f16_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_f16_tg_f16_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_f16_dv_f16_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_f16_tg_f16_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_f16_dv_f16_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_f16_tg_f16_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_f16_dv_f32_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_f16_tg_f32_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_f16_dv_f32_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_f16_tg_f32_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_f16_dv_i8_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_f16_tg_i8_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_f16_dv_i8_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_f16_tg_i8_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_f16_dv_i8_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_f16_tg_i8_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_f16_dv_i8_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_f16_tg_i8_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_f32_dv_f16_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_f32_tg_f16_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_f32_dv_f16_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_f32_tg_f16_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_f32_dv_f32_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_f32_tg_f32_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_f32_dv_f32_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_f32_tg_f32_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_f32_dv_i8_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_f32_tg_i8_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_f32_dv_i8_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_f32_tg_i8_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_i8_dv_f16_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_i8_tg_f16_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_i8_dv_f16_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_i8_tg_f16_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_i8_dv_f16_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_i8_tg_f16_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_i8_dv_f16_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_i8_tg_f16_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_i8_dv_f32_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_i8_tg_f32_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_i8_dv_f32_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_i8_tg_f32_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_i8_dv_i8_i32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_i8_tg_i8_i32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_i8_dv_i8_i32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_i8_tg_i8_i32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);

extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_f16_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_f16_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_f16_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_f16_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_f16_th_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_f16_th_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_f16_th_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_f16_th_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_i8_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_i8_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_i8_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_i8_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_i8_th_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_i8_th_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_i8_th_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_i8_th_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_i8_dv_f16_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_i8_dv_f16_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_i8_th_f16_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_i8_th_f16_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_i8_dv_f16_th_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_i8_dv_f16_th_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_i8_th_f16_th_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_i8_th_f16_th_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_f16_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_f16_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_f16_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_f16_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_f32_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_f32_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_f32_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_f32_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_i8_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_i8_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_i8_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_i8_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_i8_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_i8_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_i8_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_i8_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f32_dv_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f32_dv_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f32_th_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f32_th_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f32_dv_f16_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f32_dv_f16_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f32_th_f16_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f32_th_f16_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f32_dv_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f32_dv_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f32_th_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f32_th_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f32_dv_f32_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f32_dv_f32_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f32_th_f32_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f32_th_f32_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f32_dv_i8_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f32_dv_i8_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f32_th_i8_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f32_th_i8_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f32_dv_i8_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f32_dv_i8_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f32_th_i8_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f32_th_i8_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_i8_dv_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_i8_dv_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_i8_th_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_i8_th_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_i8_dv_f16_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_i8_dv_f16_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_i8_th_f16_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_i8_th_f16_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_i8_dv_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_i8_dv_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_i8_th_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_i8_th_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_i8_dv_f32_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_i8_dv_f32_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_i8_th_f32_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_i8_th_f32_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_i8_dv_i8_dv_i32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_i8_dv_i8_dv_i32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_i8_th_i8_dv_i32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_i8_th_i8_dv_i32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_i8_dv_i8_th_i32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_i8_dv_i8_th_i32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_i8_th_i8_th_i32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_i8_th_i8_th_i32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);

extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_b16_dv_b16_dv_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_b16_dv_b16_tg_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_b16_tg_b16_dv_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_b16_tg_b16_tg_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_b16_dv_b16_dv_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_b16_dv_b16_tg_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_b16_tg_b16_dv_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_b16_tg_b16_tg_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_b16_dv_b16_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_b16_dv_b16_tg_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_b16_tg_b16_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_b16_tg_b16_tg_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_b16_dv_b16_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_b16_dv_b16_tg_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_b16_tg_b16_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_b16_tg_b16_tg_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_b16_dv_f32_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_b16_dv_f32_tg_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_b16_tg_f32_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_b16_tg_f32_tg_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_b16_dv_f32_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_b16_dv_f32_tg_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_b16_tg_f32_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_b16_tg_f32_tg_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_b16_dv_i8_dv_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_b16_dv_i8_tg_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_b16_tg_i8_dv_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_b16_tg_i8_tg_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_b16_dv_i8_dv_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_b16_dv_i8_tg_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_b16_tg_i8_dv_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_b16_tg_i8_tg_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_b16_dv_i8_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_b16_dv_i8_tg_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_b16_tg_i8_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_b16_tg_i8_tg_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_b16_dv_i8_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_b16_dv_i8_tg_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_b16_tg_i8_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_b16_tg_i8_tg_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_f32_dv_b16_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_f32_dv_b16_tg_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_f32_tg_b16_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_f32_tg_b16_tg_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_f32_dv_b16_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_f32_dv_b16_tg_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_f32_tg_b16_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_f32_tg_b16_tg_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_i8_dv_b16_dv_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_i8_dv_b16_tg_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_i8_tg_b16_dv_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_i8_tg_b16_tg_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_i8_dv_b16_dv_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_i8_dv_b16_tg_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_i8_tg_b16_dv_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_i8_tg_b16_tg_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_i8_dv_b16_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_i8_dv_b16_tg_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_i8_tg_b16_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_i8_tg_b16_tg_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_i8_dv_b16_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_i8_dv_b16_tg_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_i8_tg_b16_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_i8_tg_b16_tg_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_b16_dv_f16_dv_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_b16_dv_f16_tg_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_b16_tg_f16_dv_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_b16_tg_f16_tg_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_b16_dv_f16_dv_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_b16_dv_f16_tg_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_b16_tg_f16_dv_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_b16_tg_f16_tg_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_b16_dv_f16_dv_f16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_b16_dv_f16_tg_f16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_b16_tg_f16_dv_f16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_b16_tg_f16_tg_f16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_b16_dv_f16_dv_f16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_b16_dv_f16_tg_f16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_b16_tg_f16_dv_f16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_b16_tg_f16_tg_f16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_b16_dv_f16_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_b16_dv_f16_tg_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_b16_tg_f16_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_b16_tg_f16_tg_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_b16_dv_f16_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_b16_dv_f16_tg_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_b16_tg_f16_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_b16_tg_f16_tg_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_f16_dv_b16_dv_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_f16_dv_b16_tg_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_f16_tg_b16_dv_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_f16_tg_b16_tg_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_f16_dv_b16_dv_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_f16_dv_b16_tg_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_f16_tg_b16_dv_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_f16_tg_b16_tg_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_f16_dv_b16_dv_f16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_f16_dv_b16_tg_f16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_f16_tg_b16_dv_f16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_f16_tg_b16_tg_f16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_f16_dv_b16_dv_f16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_f16_dv_b16_tg_f16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_f16_tg_b16_dv_f16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_f16_tg_b16_tg_f16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_f16_dv_b16_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_f16_dv_b16_tg_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_f16_tg_b16_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_dv_f16_tg_b16_tg_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_f16_dv_b16_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_f16_dv_b16_tg_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_f16_tg_b16_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_tg_f16_tg_b16_tg_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_dv_b16_dv_b16_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_dv_b16_tg_b16_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_tg_b16_dv_b16_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_tg_b16_tg_b16_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_dv_b16_dv_b16_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_dv_b16_tg_b16_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_tg_b16_dv_b16_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_tg_b16_tg_b16_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_dv_b16_dv_f32_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_dv_b16_tg_f32_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_tg_b16_dv_f32_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_tg_b16_tg_f32_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_dv_b16_dv_i8_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_dv_b16_tg_i8_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_tg_b16_dv_i8_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_tg_b16_tg_i8_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_dv_b16_dv_i8_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_dv_b16_tg_i8_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_tg_b16_dv_i8_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_tg_b16_tg_i8_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_dv_f32_dv_b16_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_dv_f32_tg_b16_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_tg_f32_dv_b16_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_tg_f32_tg_b16_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_dv_i8_dv_b16_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_dv_i8_tg_b16_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_tg_i8_dv_b16_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_tg_i8_tg_b16_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_dv_i8_dv_b16_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_dv_i8_tg_b16_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_tg_i8_dv_b16_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_tg_i8_tg_b16_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_dv_b16_dv_f16_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_dv_b16_tg_f16_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_tg_b16_dv_f16_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_tg_b16_tg_f16_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_dv_b16_dv_f16_f16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_dv_b16_tg_f16_f16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_tg_b16_dv_f16_f16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_tg_b16_tg_f16_f16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_dv_b16_dv_f16_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_dv_b16_tg_f16_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_tg_b16_dv_f16_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_tg_b16_tg_f16_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_dv_f16_dv_b16_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_dv_f16_tg_b16_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_tg_f16_dv_b16_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_tg_f16_tg_b16_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_dv_f16_dv_b16_f16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_dv_f16_tg_b16_f16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_tg_f16_dv_b16_f16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_tg_f16_tg_b16_f16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_dv_f16_dv_b16_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_dv_f16_tg_b16_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_tg_f16_dv_b16_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_cooperative_tg_f16_tg_b16_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_dv_b16_dv_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_b16_dv_b16_dv_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_th_b16_dv_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_b16_th_b16_dv_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_dv_b16_th_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_b16_dv_b16_th_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_th_b16_th_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_b16_th_b16_th_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_dv_b16_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_b16_dv_b16_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_th_b16_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_b16_th_b16_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_dv_b16_th_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_b16_dv_b16_th_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_th_b16_th_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_b16_th_b16_th_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_dv_f32_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_b16_dv_f32_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_th_f32_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_b16_th_f32_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_dv_f32_th_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_b16_dv_f32_th_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_th_f32_th_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_b16_th_f32_th_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_dv_i8_dv_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_b16_dv_i8_dv_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_th_i8_dv_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_b16_th_i8_dv_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_dv_i8_th_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_b16_dv_i8_th_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_th_i8_th_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_b16_th_i8_th_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_dv_i8_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_b16_dv_i8_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_th_i8_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_b16_th_i8_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_dv_i8_th_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_b16_dv_i8_th_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_th_i8_th_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_b16_th_i8_th_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_f32_dv_b16_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_f32_dv_b16_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_f32_th_b16_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_f32_th_b16_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_f32_dv_b16_th_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_f32_dv_b16_th_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_f32_th_b16_th_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_f32_th_b16_th_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_dv_b16_dv_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_i8_dv_b16_dv_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_th_b16_dv_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_i8_th_b16_dv_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_dv_b16_th_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_i8_dv_b16_th_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_th_b16_th_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_i8_th_b16_th_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_dv_b16_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_i8_dv_b16_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_th_b16_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_i8_th_b16_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_dv_b16_th_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_i8_dv_b16_th_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_th_b16_th_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_i8_th_b16_th_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_dv_f16_dv_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_b16_dv_f16_dv_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_th_f16_dv_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_b16_th_f16_dv_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_dv_f16_th_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_b16_dv_f16_th_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_th_f16_th_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_b16_th_f16_th_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_dv_f16_dv_f16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_b16_dv_f16_dv_f16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_th_f16_dv_f16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_b16_th_f16_dv_f16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_dv_f16_th_f16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_b16_dv_f16_th_f16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_th_f16_th_f16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_b16_th_f16_th_f16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_dv_f16_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_b16_dv_f16_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_th_f16_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_b16_th_f16_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_dv_f16_th_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_b16_dv_f16_th_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_th_f16_th_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_b16_th_f16_th_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_b16_dv_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_b16_dv_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_b16_dv_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_b16_dv_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_b16_th_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_b16_th_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_b16_th_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_b16_th_b16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_b16_dv_f16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_b16_dv_f16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_b16_dv_f16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_b16_dv_f16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_b16_th_f16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_b16_th_f16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_b16_th_f16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_b16_th_f16(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_b16_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_b16_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_b16_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_b16_dv_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_b16_th_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_b16_th_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_b16_th_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void __tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_b16_th_f32(thread __matmul2d_descriptor &desc, thread void *left, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType, thread void *right, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType, thread void *destination, __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destinationDescType);

template <__matmul2d_descriptor descriptor,
          __matmul2d_cooperative_operand_index operand_index, typename scope,
          typename left_operand, typename right_operand, typename element_type,
          typename coord_type, typename... args>
struct __operand_layout
{

  static_assert(operand_index ==
                    matmul2d_cooperative_operand_index::destination,
                "only destination can be cooperative tensor");
  static_assert(__tensor_ops_detail::__is_same_v<element_type, float> ||
                    __tensor_ops_detail::__is_same_v<element_type, half> ||
                    __tensor_ops_detail::__is_same_v<element_type, bfloat> ||
                    __tensor_ops_detail::__is_same_v<element_type, int32_t>,
                "cooperative tensor data type can only be one of "
                "float/half/bfloat/int32_t");

  static constant constexpr __tensor_ops_detail::__rank_t rank = 2;
  using element_t = element_type;
  using coord_t = coord_type;
  using extent_t = metal::dextents<coord_t, rank>;
  using thread_storage_t = thread void *;
  using const_thread_storage_t = const thread void *;
  using index_t = uint16_t;
  using operand_layout_t =
      __operand_layout<descriptor, operand_index, scope, left_operand, right_operand, element_t, coord_t>;
  using cooperative_tensor_t =
      metal::cooperative_tensor<element_t, extent_t, operand_layout_t>;
  using scope_t = scope;

  using left_t  = __tensor_ops_detail::__remove_addrspace_t<__tensor_ops_detail::__remove_reference_t<left_operand>>;
  using right_t = __tensor_ops_detail::__remove_addrspace_t<__tensor_ops_detail::__remove_reference_t<right_operand>>;

  using left_elem_t  = typename left_t::element_type;
  using right_elem_t = typename right_t::element_type;

  using left_value_t  = typename left_t::value_type;
  using right_value_t = typename right_t::value_type;

  static_assert(__tensor_ops_detail::__is_tensorops_execution_scope_v<scope>,
                "scope should be of type __tensorops_scope");

  static constexpr constant bool is_matmul2d_cooperative_destination_layout =
      true;

  static constexpr constant __matmul2d_descriptor matmul2d_desc = descriptor;

  // Returns the alignment of the storage allocated in each thread
  // for this cooperative_tensor.
  static constexpr size_t thread_storage_align()
  {
    return alignof(element_t);
  };

  // Copy-constructs from the cooperative_tensor `other`.
  static void copy_construct(thread void *this_, thread void *other)
  {
    thread element_t *this_e = (thread element_t *)(this_);
    thread element_t *other_e = (thread element_t *)(other);
    for (size_t i = 0, e = get_capacity(this_); i != e; ++i)
    {
      other_e[i] = this_e[i];
    }
  };

  // Move-constructs from the cooperative_tensor `other`.
  static void move_construct(thread void *this_, thread void *other)
  {
    thread element_t *this_e = (thread element_t *)(this_);
    thread element_t *other_e = this_e;
  };

  // Copy-assigns from the cooperative_tensor `other`.
  static void copy_assign(thread void *this_, thread void *other)
  {
    thread element_t *this_e = (thread element_t *)(this_);
    thread element_t *other_e = (thread element_t *)(other);
    for (size_t i = 0, e = get_capacity(this_); i != e; ++i)
    {
      other_e[i] = this_e[i];
    }
  };

  // Move-assigns from the cooperative_tensor `other`.
  static void move_assign(thread void *this_, thread void *other)
  {
    thread element_t *this_e = (thread element_t *)(this_);
    thread element_t *other_e = this_e;
  };

  // Destroys the per-thread object.
  static void destroy(thread void *) {};

  static size_t thread_storage_size()
  {
    metal::execution_threads t = scope();
    int threads = t.size();

    __tensor_ops_detail::__tensor_ops_datatype leftDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<left_value_t>::value;
    __tensor_ops_detail::__tensor_ops_datatype rightDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<right_value_t>::value;
    __tensor_ops_detail::__tensor_ops_datatype elemDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<element_t>::value;

    return __tensorops_impl_matmul2d_op_cooperative_destination_data_size(
        descriptor, leftDataType, rightDataType, elemDataType, threads);
  }

  template <class ElemType, class Extents, class Descriptor, class... Tags>
  static void load(thread_storage_t storage,
                   const thread metal::tensor<ElemType, Extents, Descriptor,
                                              Tags...> &sourceT)
  {
    using elem_t = __tensor_ops_detail::__remove_addrspace_t<ElemType>;

    static_assert(__tensor_ops_detail::__is_same_v<elem_t, element_t>,
                  "Source tensor datatype does not match cooperative tensor");
    static_assert(Extents::rank() == 1 || Extents::rank() == 2,
                  "Source tensor must be rank 1 or 2");

    int sourceRank = Extents::rank();

    metal::execution_threads t = scope();
    int threads = t.size();

    __matmul2d_descriptor desc = descriptor;

    using tensorType = metal::tensor<ElemType, Extents, Descriptor, Tags...>;

    using sourcePtrType = typename tensorType::data_handle_type;

    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type sourceDescType =
        __tensor_ops_detail::__tensor_type_to_tensor_descriptor_type<
            tensorType>();

    const thread void *source = (const thread void *)(&sourceT);

    __tensor_ops_detail::__tensor_ops_datatype leftDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<left_value_t>::value;
    __tensor_ops_detail::__tensor_ops_datatype rightDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<right_value_t>::value;

    if constexpr (__tensor_ops_detail::__is_same_v<elem_t, half>)
    {
      if constexpr (__tensor_ops_detail::__is_device_addrspace_v<sourcePtrType>)
        __tensorops_impl_matmul2d_op_cooperative_destination_tensor_load_dv_f16(
            desc, storage, source, sourceDescType, sourceRank, leftDataType,
            rightDataType, threads);
      else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                             sourcePtrType>)
        __tensorops_impl_matmul2d_op_cooperative_destination_tensor_load_tg_f16(
            desc, storage, source, sourceDescType, sourceRank, leftDataType,
            rightDataType, threads);
      else
        static_assert(__tensor_ops_detail::__assert_false_v<sourcePtrType>,
                      "Unsupported address space");
    }
    else if constexpr (__tensor_ops_detail::__is_same_v<elem_t, int32_t>)
    {
      if constexpr (__tensor_ops_detail::__is_device_addrspace_v<sourcePtrType>)
        __tensorops_impl_matmul2d_op_cooperative_destination_tensor_load_dv_i32(
            desc, storage, source, sourceDescType, sourceRank, leftDataType,
            rightDataType, threads);
      else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                             sourcePtrType>)
        __tensorops_impl_matmul2d_op_cooperative_destination_tensor_load_tg_i32(
            desc, storage, source, sourceDescType, sourceRank, leftDataType,
            rightDataType, threads);
      else
        static_assert(__tensor_ops_detail::__assert_false_v<sourcePtrType>,
                      "Unsupported address space");
    }
    else if constexpr (__tensor_ops_detail::__is_same_v<elem_t, float>)
    {
      if constexpr (__tensor_ops_detail::__is_device_addrspace_v<sourcePtrType>)
        __tensorops_impl_matmul2d_op_cooperative_destination_tensor_load_dv_f32(
            desc, storage, source, sourceDescType, sourceRank, leftDataType,
            rightDataType, threads);
      else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                             sourcePtrType>)
        __tensorops_impl_matmul2d_op_cooperative_destination_tensor_load_tg_f32(
            desc, storage, source, sourceDescType, sourceRank, leftDataType,
            rightDataType, threads);
      else
        static_assert(__tensor_ops_detail::__assert_false_v<sourcePtrType>,
                      "Unsupported address space");
    }
    else if constexpr (__tensor_ops_detail::__is_same_v<elem_t, bfloat>)
    {
      if constexpr (__tensor_ops_detail::__is_device_addrspace_v<sourcePtrType>)
        __tensorops_impl_matmul2d_op_cooperative_destination_tensor_load_dv_b16(
            desc, storage, source, sourceDescType, sourceRank, leftDataType,
            rightDataType, threads);
      else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                             sourcePtrType>)
        __tensorops_impl_matmul2d_op_cooperative_destination_tensor_load_tg_b16(
            desc, storage, source, sourceDescType, sourceRank, leftDataType,
            rightDataType, threads);
      else
        static_assert(__tensor_ops_detail::__assert_false_v<sourcePtrType>,
                      "Unsupported address space");
    }
    else
      static_assert(__tensor_ops_detail::__assert_false_v<elem_t>,
                    "Unsupported type");
  };

  template <class ElemType, class Extents, class Descriptor, class... Tags>
  static void store(const_thread_storage_t storage,
                    const thread metal::tensor<ElemType, Extents, Descriptor,
                                               Tags...> &destinationT)
  {
    using elem_t = __tensor_ops_detail::__remove_addrspace_t<ElemType>;

    static_assert(__tensor_ops_detail::__is_same_v<elem_t, element_t>,
                  "Tensor datatype does not match cooperative tensor");
    static_assert(Extents::rank() == 1 || Extents::rank() == rank,
                  "Tensor must be rank 1 or 2");

    __matmul2d_descriptor desc = descriptor;

    metal::execution_threads t = scope();
    int threads = t.size();

    using tensorType = metal::tensor<ElemType, Extents, Descriptor, Tags...>;

    using destinationPtrType = typename tensorType::data_handle_type;

    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType =
            __tensor_ops_detail::__tensor_type_to_tensor_descriptor_type<
                tensorType>();

    const thread void *destination = (const thread void *)(&destinationT);

    __tensor_ops_detail::__tensor_ops_datatype leftDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<left_value_t>::value;
    __tensor_ops_detail::__tensor_ops_datatype rightDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<right_value_t>::value;

    if constexpr (__tensor_ops_detail::__is_same_v<elem_t, half>)
    {
      if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                        destinationPtrType>)
        __tensorops_impl_matmul2d_op_cooperative_destination_tensor_store_dv_f16(
            desc, storage, destination, destinationDescType, leftDataType,
            rightDataType, threads);
      else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                             destinationPtrType>)
        __tensorops_impl_matmul2d_op_cooperative_destination_tensor_store_tg_f16(
            desc, storage, destination, destinationDescType, leftDataType,
            rightDataType, threads);
      else
        static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>,
                      "Unsupported address space");
    }
    else if constexpr (__tensor_ops_detail::__is_same_v<elem_t, int32_t>)
    {
      if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                        destinationPtrType>)
        __tensorops_impl_matmul2d_op_cooperative_destination_tensor_store_dv_i32(
            desc, storage, destination, destinationDescType, leftDataType,
            rightDataType, threads);
      else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                             destinationPtrType>)
        __tensorops_impl_matmul2d_op_cooperative_destination_tensor_store_tg_i32(
            desc, storage, destination, destinationDescType, leftDataType,
            rightDataType, threads);
      else
        static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>,
                      "Unsupported address space");
    }
    else if constexpr (__tensor_ops_detail::__is_same_v<elem_t, float>)
    {
      if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                        destinationPtrType>)
        __tensorops_impl_matmul2d_op_cooperative_destination_tensor_store_dv_f32(
            desc, storage, destination, destinationDescType, leftDataType,
            rightDataType, threads);
      else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                             destinationPtrType>)
        __tensorops_impl_matmul2d_op_cooperative_destination_tensor_store_tg_f32(
            desc, storage, destination, destinationDescType, leftDataType,
            rightDataType, threads);
      else
        static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>,
                      "Unsupported address space");
    }
    else if constexpr (__tensor_ops_detail::__is_same_v<elem_t, bfloat>)
    {
      if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                        destinationPtrType>)
        __tensorops_impl_matmul2d_op_cooperative_destination_tensor_store_dv_b16(
            desc, storage, destination, destinationDescType, leftDataType,
            rightDataType, threads);
      else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                             destinationPtrType>)
        __tensorops_impl_matmul2d_op_cooperative_destination_tensor_store_tg_b16(
            desc, storage, destination, destinationDescType, leftDataType,
            rightDataType, threads);
      else
        static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>,
                      "Unsupported address space");
    }
    else
      static_assert(__tensor_ops_detail::__assert_false_v<elem_t>,
                    "Unsupported type");
  };

  static uint16_t get_capacity(const_thread_storage_t storage)
  {
    metal::execution_threads t = scope();
    int threads = t.size();

    __tensor_ops_detail::__tensor_ops_datatype leftDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<left_value_t>::value;
    __tensor_ops_detail::__tensor_ops_datatype rightDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<right_value_t>::value;

    return __tensorops_impl_matmul2d_op_cooperative_destination_tensor_num_elements(
        descriptor, storage, leftDataType, rightDataType, threads);
  }

  static thread element_t *get_element_pointer(const_thread_storage_t storage,
                                               index_t idx)
  {
    __tensor_ops_detail::__tensor_ops_datatype leftDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<left_value_t>::value;
    __tensor_ops_detail::__tensor_ops_datatype rightDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<right_value_t>::value;
    __tensor_ops_detail::__tensor_ops_datatype dataType =
        __tensor_ops_detail::__element_type_to_tensor_ops_datatype<element_type>();

    return (thread element_t *)
        __tensorops_impl_matmul2d_op_cooperative_destination_tensor_get_element_pointer(
            descriptor, (thread_storage_t)storage, idx, leftDataType,
            rightDataType, dataType);
  }

  static index_t get_element_index(const_thread_storage_t storage,
                                   const thread element_type *element)
  {
    __tensor_ops_detail::__tensor_ops_datatype leftDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<left_value_t>::value;
    __tensor_ops_detail::__tensor_ops_datatype rightDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<right_value_t>::value;
    __tensor_ops_detail::__tensor_ops_datatype dataType =
        __tensor_ops_detail::__element_type_to_tensor_ops_datatype<element_type>();

    return (index_t)
        __tensorops_impl_matmul2d_op_cooperative_destination_tensor_get_element_index(
            descriptor, (thread_storage_t)storage, element, leftDataType,
            rightDataType, dataType);
  }

  static bool is_valid_element(const_thread_storage_t storage, index_t idx)
  {
    metal::execution_threads t = scope();
    int threads = t.size();

    __tensor_ops_detail::__tensor_ops_datatype leftDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<left_value_t>::value;
    __tensor_ops_detail::__tensor_ops_datatype rightDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<right_value_t>::value;
    __tensor_ops_detail::__tensor_ops_datatype dataType =
        __tensor_ops_detail::__element_type_to_tensor_ops_datatype<element_type>();

    return __tensorops_impl_matmul2d_op_cooperative_destination_tensor_is_valid_element(
        descriptor, (__tensor_ops_detail::__thread_void_t)storage, idx,
        leftDataType, rightDataType, dataType, threads);
  }

  template <typename index_t, __tensor_ops_detail::__rank_t rank = 2>
  static metal::array<index_t, rank>
  get_multidimensional_index(const_thread_storage_t storage, index_t idx)
  {
    metal::execution_threads t = scope();
    int threads = t.size();

    __tensor_ops_detail::__tensor_ops_datatype leftDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<left_value_t>::value;
    __tensor_ops_detail::__tensor_ops_datatype rightDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<right_value_t>::value;
    __tensor_ops_detail::__tensor_ops_datatype dataType =
        __tensor_ops_detail::__element_type_to_tensor_ops_datatype<element_type>();

    if constexpr (__tensor_ops_detail::__is_same_v<coord_t, ushort>)
    {
      ushort coords[2];
      __tensorops_impl_matmul2d_op_cooperative_destination_tensor_get_coordinate(
          descriptor, (__tensor_ops_detail::__const_thread_void_t)storage, idx,
          coords, __tensor_ops_detail::__tensor_ops_datatype_uint16,
          threads, leftDataType, rightDataType, dataType);
      return {coords[0], coords[1]};
    }
    else if constexpr (__tensor_ops_detail::__is_same_v<coord_t, short>)
    {
      short coords[2];
      __tensorops_impl_matmul2d_op_cooperative_destination_tensor_get_coordinate(
          descriptor, (__tensor_ops_detail::__const_thread_void_t)storage, idx,
          coords, __tensor_ops_detail::__tensor_ops_datatype_int16,
          threads, leftDataType, rightDataType, dataType);
      return {coords[0], coords[1]};
    }
    else if constexpr (__tensor_ops_detail::__is_same_v<coord_t, uint>)
    {
      uint coords[2];
      __tensorops_impl_matmul2d_op_cooperative_destination_tensor_get_coordinate(
          descriptor, (__tensor_ops_detail::__const_thread_void_t)storage, idx,
          coords, __tensor_ops_detail::__tensor_ops_datatype_uint32,
          threads, leftDataType, rightDataType, dataType);
      ;
      return {coords[0], coords[1]};
    }
    else if constexpr (__tensor_ops_detail::__is_same_v<coord_t, int>)
    {
      int coords[2];
      __tensorops_impl_matmul2d_op_cooperative_destination_tensor_get_coordinate(
          descriptor, (__tensor_ops_detail::__const_thread_void_t)storage, idx,
          coords, __tensor_ops_detail::__tensor_ops_datatype_int32,
          threads, leftDataType, rightDataType, dataType);
      return {coords[0], coords[1]};
    }
    else {
        static_assert(__tensor_ops_detail::__assert_false_v<coord_t>,
                    "unsupported coordinate data type");
    }
  }

  static void construct(thread_storage_t storage)
  {
    metal::execution_threads t = scope();
    int threads = t.size();

    __tensor_ops_detail::__tensor_ops_datatype leftDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<left_value_t>::value;
    __tensor_ops_detail::__tensor_ops_datatype rightDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<right_value_t>::value;
    __tensor_ops_detail::__tensor_ops_datatype elemDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<element_t>::value;

    __tensorops_impl_matmul2d_op_cooperative_destination_tensor_init(
        descriptor, (__tensor_ops_detail::__thread_void_t)storage, leftDataType,
        rightDataType, elemDataType, threads);
  }
};

template <__matmul2d_descriptor descriptor,
          __matmul2d_cooperative_operand_index operand_index, typename scope,
          typename left_operand, typename right_operand, typename element_type, typename coord_type, typename... args>
using __cooperative_tensor_t =
    typename __operand_layout<descriptor, operand_index, scope, left_operand, right_operand, element_type,
                              coord_type, args...>::cooperative_tensor_t;

template <__matmul2d_descriptor descriptor, typename scope, typename left_operand, typename right_operand,
          typename element_type, typename coord_type, typename... args>
using __cooperative_tensor_destination_t =
    __cooperative_tensor_t<descriptor,
                           matmul2d_cooperative_operand_index::destination,
                           scope, left_operand, right_operand, element_type, coord_type, args...>;

template <__matmul2d_descriptor descriptor, typename scope,
          typename left_operand, typename right_operand, typename element_type, typename coord_type,  typename... args>
__cooperative_tensor_destination_t<descriptor, scope, left_operand, right_operand, element_type, coord_type,
                                   args...>
__get_destination_cooperative_tensor()
{
  static_assert(__tensor_ops_detail::__is_tensorops_execution_scope_v<scope>,
                "scope should be of type __tensorops_scope");
  return __cooperative_tensor_destination_t<descriptor, scope, left_operand, right_operand, element_type,
                                            coord_type, args...>();
}

template <__matmul2d_descriptor descriptor, int reduction_dim, typename scope,
          typename left_operand, typename right_operand,
          typename element_type, typename coord_type, typename... args>
struct __reduction_operand_layout
{
  static_assert(__tensor_ops_detail::__is_same_v<element_type, float> ||
                    __tensor_ops_detail::__is_same_v<element_type, half> ||
                    __tensor_ops_detail::__is_same_v<element_type, bfloat> ||
                    __tensor_ops_detail::__is_same_v<element_type, int32_t>,
                "cooperative tensor data type can only be one of "
                "float/half/bfloat/int32_t");

  static constant constexpr __tensor_ops_detail::__rank_t rank = 1;
  using element_t = element_type;
  using coord_t = coord_type;
  using extent_t = metal::dextents<coord_t, rank>;
  using thread_storage_t = thread void *;
  using const_thread_storage_t = const thread void *;
  using index_t = uint16_t;
  using operand_layout_t =
      __reduction_operand_layout<descriptor, reduction_dim, scope, left_operand,
                                 right_operand, element_t, coord_t>;
  using cooperative_tensor_t =
      metal::cooperative_tensor<element_t, extent_t, operand_layout_t>;
  using scope_t = scope;

  using left_t  = __tensor_ops_detail::__remove_addrspace_t<__tensor_ops_detail::__remove_reference_t<left_operand>>;
  using right_t = __tensor_ops_detail::__remove_addrspace_t<__tensor_ops_detail::__remove_reference_t<right_operand>>;

  using left_elem_t  = typename left_t::element_type;
  using right_elem_t = typename right_t::element_type;

  using left_value_t  = typename left_t::value_type;
  using right_value_t = typename right_t::value_type;

  static_assert(__tensor_ops_detail::__is_tensorops_execution_scope_v<scope>,
                "scope should be of type __tensorops_scope");
  static_assert(reduction_dim == 0 || reduction_dim == 1, "Reduction dimension must be 0 or 1");

  static constexpr constant bool is_matmul2d_reduction_cooperative_destination_layout =
      true;
  static constexpr constant int __reduction_dim = reduction_dim;

  static constexpr constant __matmul2d_descriptor matmul2d_desc = descriptor;

  // Returns the alignment of the storage allocated in each thread
  // for this cooperative_tensor.
  static constexpr size_t thread_storage_align()
  {
    return alignof(element_t);
  };

  // Copy-constructs from the cooperative_tensor `other`.
  static void copy_construct(thread void *this_, thread void *other)
  {
    thread element_t *this_e = (thread element_t *)(this_);
    thread element_t *other_e = (thread element_t *)(other);
    for (size_t i = 0, e = get_capacity(this_); i != e; ++i)
    {
      other_e[i] = this_e[i];
    }
  };

  // Move-constructs from the cooperative_tensor `other`.
  static void move_construct(thread void *this_, thread void *other)
  {
    thread element_t *this_e = (thread element_t *)(this_);
    thread element_t *other_e = this_e;
  };

  // Copy-assigns from the cooperative_tensor `other`.
  static void copy_assign(thread void *this_, thread void *other)
  {
    thread element_t *this_e = (thread element_t *)(this_);
    thread element_t *other_e = (thread element_t *)(other);
    for (size_t i = 0, e = get_capacity(this_); i != e; ++i)
    {
      other_e[i] = this_e[i];
    }
  };

  // Move-assigns from the cooperative_tensor `other`.
  static void move_assign(thread void *this_, thread void *other)
  {
    thread element_t *this_e = (thread element_t *)(this_);
    thread element_t *other_e = this_e;
  };

  // Destroys the per-thread object.
  static void destroy(thread void *) {};

  static size_t thread_storage_size()
  {
    metal::execution_threads t = scope();
    int threads = t.size();
    
    __tensor_ops_detail::__tensor_ops_datatype leftDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<left_value_t>::value;
    __tensor_ops_detail::__tensor_ops_datatype rightDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<right_value_t>::value;
    __tensor_ops_detail::__tensor_ops_datatype elementDataType =
        __tensor_ops_detail::__element_type_to_tensor_ops_datatype<element_type>();

    return __tensorops_impl_matmul2d_op_cooperative_reduction_destination_data_size(
        descriptor, reduction_dim, leftDataType, rightDataType, elementDataType, threads);
  }

  template <class ElemType, class Extents, class Descriptor, class... Tags>
  static void load(thread_storage_t storage,
                   const thread metal::tensor<ElemType, Extents, Descriptor,
                                              Tags...> &sourceT)
  {
    using elem_t = __tensor_ops_detail::__remove_addrspace_t<ElemType>;

    static_assert(__tensor_ops_detail::__is_same_v<elem_t, element_t>,
                  "Source tensor datatype does not match cooperative tensor");
    static_assert(Extents::rank() == 1,
                  "Source tensor must be rank 1");

    metal::execution_threads t = scope();
    int threads = t.size();

    __matmul2d_descriptor desc = descriptor;

    using tensorType = metal::tensor<ElemType, Extents, Descriptor, Tags...>;

    using sourcePtrType = typename tensorType::data_handle_type;

    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type sourceDescType =
        __tensor_ops_detail::__tensor_type_to_tensor_descriptor_type<
            tensorType>();

    __tensor_ops_detail::__tensor_ops_datatype leftDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<left_value_t>::value;
    __tensor_ops_detail::__tensor_ops_datatype rightDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<right_value_t>::value;

    const thread void *source = (const thread void *)(&sourceT);

    if constexpr (__tensor_ops_detail::__is_same_v<elem_t, half>)
    {
      if constexpr (__tensor_ops_detail::__is_device_addrspace_v<sourcePtrType>)
        __tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_load_dv_f16(
            desc, storage, source, sourceDescType, reduction_dim, threads, leftDataType, rightDataType);
      else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                             sourcePtrType>)
        __tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_load_tg_f16(
            desc, storage, source, sourceDescType, reduction_dim, threads, leftDataType, rightDataType);
      else
        static_assert(__tensor_ops_detail::__assert_false_v<sourcePtrType>,
                      "Unsupported address space");
    }
    else if constexpr (__tensor_ops_detail::__is_same_v<elem_t, int32_t>)
    {
      if constexpr (__tensor_ops_detail::__is_device_addrspace_v<sourcePtrType>)
        __tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_load_dv_i32(
            desc, storage, source, sourceDescType, reduction_dim, threads, leftDataType, rightDataType);
      else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                             sourcePtrType>)
        __tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_load_tg_i32(
            desc, storage, source, sourceDescType, reduction_dim, threads, leftDataType, rightDataType);
      else
        static_assert(__tensor_ops_detail::__assert_false_v<sourcePtrType>,
                      "Unsupported address space");
    }
    else if constexpr (__tensor_ops_detail::__is_same_v<elem_t, float>)
    {
      if constexpr (__tensor_ops_detail::__is_device_addrspace_v<sourcePtrType>)
        __tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_load_dv_f32(
            desc, storage, source, sourceDescType, reduction_dim, threads, leftDataType, rightDataType);
      else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                             sourcePtrType>)
        __tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_load_tg_f32(
            desc, storage, source, sourceDescType, reduction_dim, threads, leftDataType, rightDataType);
      else
        static_assert(__tensor_ops_detail::__assert_false_v<sourcePtrType>,
                      "Unsupported address space");
    }
    else if constexpr (__tensor_ops_detail::__is_same_v<elem_t, bfloat>)
    {
      if constexpr (__tensor_ops_detail::__is_device_addrspace_v<sourcePtrType>)
        __tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_load_dv_b16(
            desc, storage, source, sourceDescType, reduction_dim, threads, leftDataType, rightDataType);
      else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                             sourcePtrType>)
        __tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_load_tg_b16(
            desc, storage, source, sourceDescType, reduction_dim, threads, leftDataType, rightDataType);
      else
        static_assert(__tensor_ops_detail::__assert_false_v<sourcePtrType>,
                      "Unsupported address space");
    }
    else
      static_assert(__tensor_ops_detail::__assert_false_v<elem_t>,
                    "Unsupported type");
  };

  template <class ElemType, class Extents, class Descriptor, class... Tags>
  static void store(const_thread_storage_t storage,
                    const thread metal::tensor<ElemType, Extents, Descriptor,
                                               Tags...> &destinationT)
  {
    using elem_t = __tensor_ops_detail::__remove_addrspace_t<ElemType>;

    static_assert(__tensor_ops_detail::__is_same_v<elem_t, element_t>,
                  "Tensor datatype does not match cooperative tensor");
    static_assert(Extents::rank() == 1,
                  "Tensor must be rank 1");

    __matmul2d_descriptor desc = descriptor;

    metal::execution_threads t = scope();
    int threads = t.size();

    using tensorType = metal::tensor<ElemType, Extents, Descriptor, Tags...>;

    using destinationPtrType = typename tensorType::data_handle_type;

    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType =
            __tensor_ops_detail::__tensor_type_to_tensor_descriptor_type<
                tensorType>();

    __tensor_ops_detail::__tensor_ops_datatype leftDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<left_value_t>::value;
    __tensor_ops_detail::__tensor_ops_datatype rightDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<right_value_t>::value;

    const thread void *destination = (const thread void *)(&destinationT);

    if constexpr (__tensor_ops_detail::__is_same_v<elem_t, half>)
    {
      if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                        destinationPtrType>)
        __tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_store_dv_f16(
            desc, storage, destination, destinationDescType, reduction_dim, threads, leftDataType, rightDataType);
      else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                             destinationPtrType>)
        __tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_store_tg_f16(
            desc, storage, destination, destinationDescType, reduction_dim, threads, leftDataType, rightDataType);
      else
        static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>,
                      "Unsupported address space");
    }
    else if constexpr (__tensor_ops_detail::__is_same_v<elem_t, int32_t>)
    {
      if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                        destinationPtrType>)
        __tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_store_dv_i32(
            desc, storage, destination, destinationDescType, reduction_dim, threads, leftDataType, rightDataType);
      else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                             destinationPtrType>)
        __tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_store_tg_i32(
            desc, storage, destination, destinationDescType, reduction_dim, threads, leftDataType, rightDataType);
      else
        static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>,
                      "Unsupported address space");
    }
    else if constexpr (__tensor_ops_detail::__is_same_v<elem_t, float>)
    {
      if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                        destinationPtrType>)
        __tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_store_dv_f32(
            desc, storage, destination, destinationDescType, reduction_dim, threads, leftDataType, rightDataType);
      else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                             destinationPtrType>)
        __tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_store_tg_f32(
            desc, storage, destination, destinationDescType, reduction_dim, threads, leftDataType, rightDataType);
      else
        static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>,
                      "Unsupported address space");
    }
    else if constexpr (__tensor_ops_detail::__is_same_v<elem_t, bfloat>)
    {
      if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                        destinationPtrType>)
        __tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_store_dv_b16(
            desc, storage, destination, destinationDescType, reduction_dim, threads, leftDataType, rightDataType);
      else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                             destinationPtrType>)
        __tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_store_tg_b16(
            desc, storage, destination, destinationDescType, reduction_dim, threads, leftDataType, rightDataType);
      else
        static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>,
                      "Unsupported address space");
    }
    else
      static_assert(__tensor_ops_detail::__assert_false_v<elem_t>,
                    "Unsupported type");
  };

  static uint16_t get_capacity(const_thread_storage_t storage)
  {
    metal::execution_threads t = scope();
    int threads = t.size();

    __tensor_ops_detail::__tensor_ops_datatype leftDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<left_value_t>::value;
    __tensor_ops_detail::__tensor_ops_datatype rightDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<right_value_t>::value;

    return __tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_num_elements(
        descriptor, storage, reduction_dim, leftDataType, rightDataType, threads);
  }

  static thread element_t *get_element_pointer(const_thread_storage_t storage,
                                               index_t idx)
  {
    __tensor_ops_detail::__tensor_ops_datatype leftDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<left_value_t>::value;
    __tensor_ops_detail::__tensor_ops_datatype rightDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<right_value_t>::value;
    __tensor_ops_detail::__tensor_ops_datatype dataType =
        __tensor_ops_detail::__element_type_to_tensor_ops_datatype<element_type>();

    return (thread element_t *)
        __tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_get_element_pointer(
            descriptor, (thread_storage_t)storage, idx, leftDataType, rightDataType, dataType);
  }

  static index_t get_element_index(const_thread_storage_t storage,
                                   const thread element_type *element)
  {
    __tensor_ops_detail::__tensor_ops_datatype leftDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<left_value_t>::value;
    __tensor_ops_detail::__tensor_ops_datatype rightDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<right_value_t>::value;
    __tensor_ops_detail::__tensor_ops_datatype dataType =
        __tensor_ops_detail::__element_type_to_tensor_ops_datatype<element_type>();

    return (index_t)
        __tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_get_element_index(
            descriptor, (thread_storage_t)storage, element, leftDataType, rightDataType, dataType);
  }

  static bool is_valid_element(const_thread_storage_t storage, index_t idx)
  {
    metal::execution_threads t = scope();
    int threads = t.size();

    __tensor_ops_detail::__tensor_ops_datatype leftDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<left_value_t>::value;
    __tensor_ops_detail::__tensor_ops_datatype rightDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<right_value_t>::value;
    __tensor_ops_detail::__tensor_ops_datatype dataType =
        __tensor_ops_detail::__element_type_to_tensor_ops_datatype<element_type>();

    return __tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_is_valid_element(
        descriptor, (__tensor_ops_detail::__thread_void_t)storage, reduction_dim, idx,
        leftDataType, rightDataType, dataType, threads);
  }

  template <typename index_t, __tensor_ops_detail::__rank_t rank = 1>
  static metal::array<index_t, rank>
  get_multidimensional_index(const_thread_storage_t storage, index_t idx)
  {
    metal::execution_threads t = scope();
    int threads = t.size();

    __tensor_ops_detail::__tensor_ops_datatype leftDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<left_value_t>::value;
    __tensor_ops_detail::__tensor_ops_datatype rightDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<right_value_t>::value;
    __tensor_ops_detail::__tensor_ops_datatype elementDataType =
        __tensor_ops_detail::__element_type_to_tensor_ops_datatype<element_type>();

    if constexpr (__tensor_ops_detail::__is_same_v<coord_t, ushort>)
    {
      ushort coords[1];
      __tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_get_coordinate(
          descriptor, reduction_dim, (__tensor_ops_detail::__thread_void_t)storage, idx,
          coords, __tensor_ops_detail::__tensor_ops_datatype_uint16,
          threads, leftDataType, rightDataType, elementDataType);
      return { coords[0] };
    }
    else if constexpr (__tensor_ops_detail::__is_same_v<coord_t, short>)
    {
      short coords[1];
      __tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_get_coordinate(
          descriptor, reduction_dim, (__tensor_ops_detail::__thread_void_t)storage, idx,
          coords, __tensor_ops_detail::__tensor_ops_datatype_int16,
          threads, leftDataType, rightDataType, elementDataType);
      return { coords[0] };
    }
    else if constexpr (__tensor_ops_detail::__is_same_v<coord_t, uint>)
    {
      uint coords[1];
      __tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_get_coordinate(
          descriptor, reduction_dim, (__tensor_ops_detail::__thread_void_t)storage, idx,
          coords, __tensor_ops_detail::__tensor_ops_datatype_uint32,
          threads, leftDataType, rightDataType, elementDataType);
      ;
      return { coords[0] };
    }
    else if constexpr (__tensor_ops_detail::__is_same_v<coord_t, int>)
    {
      int coords[1];
      __tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_get_coordinate(
          descriptor, reduction_dim, (__tensor_ops_detail::__thread_void_t)storage, idx,
          coords, __tensor_ops_detail::__tensor_ops_datatype_int32,
          threads, leftDataType, rightDataType, elementDataType);
      return { coords[0] };
    }
    else {
        static_assert(__tensor_ops_detail::__assert_false_v<coord_t>,
                    "unsupported coordinate data type");
    }
  }

  static void construct(thread_storage_t storage)
  {
    metal::execution_threads t = scope();
    int threads = t.size();

    __tensor_ops_detail::__tensor_ops_datatype elementDataType =
        __tensor_ops_detail::__element_type_to_tensor_ops_datatype<element_t>();
    __tensor_ops_detail::__tensor_ops_datatype leftDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<left_value_t>::value;
    __tensor_ops_detail::__tensor_ops_datatype rightDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<right_value_t>::value;

    __tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_init(
        (__tensor_ops_detail::__thread_void_t)storage, descriptor, 
        reduction_dim, leftDataType, rightDataType, elementDataType, threads);
  }

  template <class FromIterator, class ToIterator>
  static uint16_t map_index(const thread void *from_storage, uint16_t from_idx,
                            const thread void *to_storage)
  {
    using sourceLayout = typename FromIterator::layout;
    using destLayout = typename ToIterator::layout;

    static_assert(sourceLayout::is_matmul2d_cooperative_destination_layout,
                  "Source must be a matmul2d destination cooperative tensor");
    static_assert(destLayout::is_matmul2d_reduction_cooperative_destination_layout,
                  "Destination must be a matmul2d reduction destination cooperative tensor");
    static_assert(__tensor_ops_detail::__is_same_v<typename sourceLayout::scope_t, metal::execution_simdgroup>,
                  "map_index requires a single SIMD group");
    static_assert(__tensor_ops_detail::__is_same_v<typename destLayout::scope_t, metal::execution_simdgroup>,
                  "map_index requires a single SIMD group");

    metal::execution_threads t = scope();
    int threads = t.size();

    constexpr __matmul2d_descriptor sourceDesc = sourceLayout::matmul2d_desc;
    constexpr __matmul2d_descriptor destDesc = destLayout::matmul2d_desc;

    static_assert(reduction_dim == 0 || sourceDesc.n == destDesc.n, "Source and destination must have matching N dimension if reduction_dim = 1");
    static_assert(reduction_dim == 1 || sourceDesc.m == destDesc.m, "Source and destination must have matching M dimension if reduction_dim = 0");
    
    static_assert(__tensor_ops_detail::__is_same_v<typename sourceLayout::element_t, typename destLayout::element_t>, "Source and destination element types must match");

    __tensor_ops_detail::__tensor_ops_datatype srcLeftDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<typename sourceLayout::left_value_t>::value;
    __tensor_ops_detail::__tensor_ops_datatype srcRightDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<typename sourceLayout::right_value_t>::value;

    return __tensorops_impl_matmul2d_op_cooperative_reduction_destination_tensor_map_index(
        from_storage, sourceDesc,
        to_storage, destDesc,
        reduction_dim, threads, from_idx,
        srcLeftDataType, srcRightDataType);
  }
};

template <__matmul2d_descriptor descriptor, typename scope,
          typename left_operand, typename right_operand,
          typename element_type, typename coord_type, typename... args>
using __cooperative_tensor_row_reduction_destination_t =
    typename __reduction_operand_layout<descriptor, 0, scope, left_operand, right_operand,
                              element_type, coord_type, args...>::cooperative_tensor_t;

template <__matmul2d_descriptor descriptor, typename scope,
          typename left_operand, typename right_operand,
          typename element_type, typename coord_type, typename... args>
using __cooperative_tensor_column_reduction_destination_t =
    typename __reduction_operand_layout<descriptor, 1, scope, left_operand, right_operand,
                              element_type, coord_type, args...>::cooperative_tensor_t;

template <__matmul2d_descriptor descriptor, typename scope,
          typename left_operand, typename right_operand,
          typename element_type, typename coord_type, typename... args>
__cooperative_tensor_row_reduction_destination_t<descriptor, scope, left_operand, right_operand,
                                                 element_type, coord_type, args...>
__get_row_reduction_destination_cooperative_tensor()
{
  static_assert(__tensor_ops_detail::__is_tensorops_execution_scope_v<scope>,
                "scope should be of type __tensorops_scope");
  return __cooperative_tensor_row_reduction_destination_t<descriptor, scope, left_operand, right_operand,
                                                          element_type, coord_type, args...>();
}

template <__matmul2d_descriptor descriptor, typename scope,
          typename left_operand, typename right_operand,
          typename element_type, typename coord_type, typename... args>
__cooperative_tensor_column_reduction_destination_t<descriptor, scope, left_operand, right_operand,
                                                    element_type, coord_type, args...>
__get_column_reduction_destination_cooperative_tensor()
{
  static_assert(__tensor_ops_detail::__is_tensorops_execution_scope_v<scope>,
                "scope should be of type __tensorops_scope");
  return __cooperative_tensor_column_reduction_destination_t<descriptor, scope, left_operand, right_operand,
                                                             element_type, coord_type, args...>();
}

template <__matmul2d_descriptor descriptor, typename scope,
          typename left_operand, typename right_operand,
          typename destination_operand, typename... args>
void __run(thread left_operand &leftIn, thread right_operand &rightIn,
           thread destination_operand &destinationT)
{
  using leftTensorType = __tensor_ops_detail::__remove_addrspace_t<
      __tensor_ops_detail::__remove_reference_t<decltype(leftIn)>>;
  using rightTensorType = __tensor_ops_detail::__remove_addrspace_t<
      __tensor_ops_detail::__remove_reference_t<decltype(rightIn)>>;
  using destinationTensorType = __tensor_ops_detail::__remove_addrspace_t<
      __tensor_ops_detail::__remove_reference_t<decltype(destinationT)>>;

  metal::execution_threads t = scope();
  int threads = t.size();

  static_assert(__tensor_ops_detail::__is_tensor_type_v<leftTensorType>,
                "Left operand must be a tensor");
  static_assert(__tensor_ops_detail::__is_tensor_type_v<rightTensorType>,
                "Right operand must be a tensor");
  static_assert(
      __tensor_ops_detail::__is_tensor_type_v<destinationTensorType> ||
          __tensor_ops_detail::__is_cooperative_tensor_type_v<
              destinationTensorType>,
      "Destination operand must be a tensor or cooperative tensor");

  static_assert(__tensor_ops_detail::__is_tensorops_execution_scope_v<scope>,
                "scope should be of type __tensorops_scope");

  static_assert(__tensor_ops_detail::__get_rank<leftTensorType>() == 2,
                "Operand must have rank 2");
  static_assert(__tensor_ops_detail::__get_rank<rightTensorType>() == 2,
                "Operand must have rank 2");
  static_assert(__tensor_ops_detail::__get_rank<destinationTensorType>() == 2,
                "Operand must have rank 2");

  static_assert(
      __tensor_ops_detail::__is_same_v<typename leftTensorType::index_type,
                                       int>,
      "Index type must be int");
  static_assert(
      __tensor_ops_detail::__is_same_v<typename rightTensorType::index_type,
                                       int>,
      "Index type must be int");
  static_assert(__tensor_ops_detail::__is_same_v<
                    typename destinationTensorType::index_type, int>,
                "Index type must be int");

  using leftPtrType = typename leftTensorType::data_handle_type;
  using rightPtrType = typename rightTensorType::data_handle_type;
  using destinationPtrType = typename destinationTensorType::data_handle_type;

  using leftValueType = __tensor_ops_detail::__remove_addrspace_t<
      __tensor_ops_detail::__remove_reference_t<
          typename leftTensorType::element_type>>;
  using rightValueType = __tensor_ops_detail::__remove_addrspace_t<
      __tensor_ops_detail::__remove_reference_t<
          typename rightTensorType::element_type>>;
  using destinationValueType = __tensor_ops_detail::__remove_addrspace_t<
      __tensor_ops_detail::__remove_reference_t<
          typename destinationTensorType::element_type>>;

  const __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType =
      __tensor_ops_detail::__tensor_type_to_tensor_descriptor_type<
          leftTensorType>();
  const __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType =
      __tensor_ops_detail::__tensor_type_to_tensor_descriptor_type<
          rightTensorType>();

  thread void *left = (thread void *)(&leftIn);
  thread void *right = (thread void *)(&rightIn);

  __matmul2d_descriptor desc = descriptor;

  // single thread
  if constexpr (__tensor_ops_detail::__is_same_v<scope, metal::execution_thread>)
  {
    if constexpr (!__tensor_ops_detail::__is_cooperative_tensor_type_v<
                      destinationTensorType>)
    {
      __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
          destinationDescType =
              __tensor_ops_detail::__tensor_type_to_tensor_descriptor_type<
                  destinationTensorType>();

      thread void *destination = (thread void *)(&destinationT);

      if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, half> &&
                    __tensor_ops_detail::__is_same_v<rightValueType, half> &&
                    __tensor_ops_detail::__is_same_v<destinationValueType,
                                                     half>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_f16_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_f16_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_f16_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_f16_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_f16_th_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_f16_th_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_f16_th_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_f16_th_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, half>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_i8_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_i8_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_i8_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_i8_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_i8_th_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_i8_th_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_i8_th_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_i8_th_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, half>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_dv_f16_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_i8_dv_f16_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_th_f16_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_i8_th_f16_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_dv_f16_th_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_i8_dv_f16_th_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_th_f16_th_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_i8_th_f16_th_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_f16_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_f16_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_f16_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_f16_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          float> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_f32_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_f32_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_f32_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_f32_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_i8_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_i8_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_i8_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_i8_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_i8_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_i8_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_i8_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_i8_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          float> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f32_dv_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f32_dv_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f32_th_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f32_th_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f32_dv_f16_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f32_dv_f16_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f32_th_f16_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f32_th_f16_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          float> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          float> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f32_dv_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f32_dv_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f32_th_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f32_th_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f32_dv_f32_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f32_dv_f32_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f32_th_f32_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f32_th_f32_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          float> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f32_dv_i8_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f32_dv_i8_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f32_th_i8_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f32_th_i8_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f32_dv_i8_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f32_dv_i8_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f32_th_i8_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f32_th_i8_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_dv_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_i8_dv_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_th_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_i8_th_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_dv_f16_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_i8_dv_f16_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_th_f16_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_i8_th_f16_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          float> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_dv_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_i8_dv_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_th_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_i8_th_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_dv_f32_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_i8_dv_f32_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_th_f32_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_i8_th_f32_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, int32_t>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_dv_i8_dv_i32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_i8_dv_i8_dv_i32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_th_i8_dv_i32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_i8_th_i8_dv_i32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_dv_i8_th_i32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_i8_dv_i8_th_i32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_th_i8_th_i32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_i8_th_i8_th_i32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<rightValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<destinationValueType, bfloat>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_dv_b16_dv_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_b16_dv_b16_dv_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_th_b16_dv_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_b16_th_b16_dv_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_dv_b16_th_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_b16_dv_b16_th_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_th_b16_th_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_b16_th_b16_th_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else
          static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>, "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<rightValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<destinationValueType, float>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_dv_b16_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_b16_dv_b16_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_th_b16_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_b16_th_b16_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_dv_b16_th_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_b16_dv_b16_th_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_th_b16_th_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_b16_th_b16_th_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else
          static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>, "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<rightValueType, float> &&
                         __tensor_ops_detail::__is_same_v<destinationValueType, float>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_dv_f32_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_b16_dv_f32_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_th_f32_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_b16_th_f32_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_dv_f32_th_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_b16_dv_f32_th_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_th_f32_th_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_b16_th_f32_th_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else
          static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>, "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<rightValueType, int8_t> &&
                         __tensor_ops_detail::__is_same_v<destinationValueType, bfloat>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_dv_i8_dv_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_b16_dv_i8_dv_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_th_i8_dv_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_b16_th_i8_dv_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_dv_i8_th_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_b16_dv_i8_th_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_th_i8_th_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_b16_th_i8_th_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else
          static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>, "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<rightValueType, int8_t> &&
                         __tensor_ops_detail::__is_same_v<destinationValueType, float>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_dv_i8_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_b16_dv_i8_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_th_i8_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_b16_th_i8_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_dv_i8_th_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_b16_dv_i8_th_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_th_i8_th_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_b16_th_i8_th_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else
          static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>, "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, float> &&
                         __tensor_ops_detail::__is_same_v<rightValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<destinationValueType, float>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f32_dv_b16_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f32_dv_b16_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f32_th_b16_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f32_th_b16_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f32_dv_b16_th_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f32_dv_b16_th_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f32_th_b16_th_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f32_th_b16_th_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else
          static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>, "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, int8_t> &&
                         __tensor_ops_detail::__is_same_v<rightValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<destinationValueType, bfloat>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_dv_b16_dv_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_i8_dv_b16_dv_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_th_b16_dv_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_i8_th_b16_dv_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_dv_b16_th_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_i8_dv_b16_th_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_th_b16_th_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_i8_th_b16_th_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else
          static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>, "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, int8_t> &&
                         __tensor_ops_detail::__is_same_v<rightValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<destinationValueType, float>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_dv_b16_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_i8_dv_b16_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_th_b16_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_i8_th_b16_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_dv_b16_th_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_i8_dv_b16_th_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_th_b16_th_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_i8_th_b16_th_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else
          static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>, "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<rightValueType, half> &&
                         __tensor_ops_detail::__is_same_v<destinationValueType, bfloat>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_dv_f16_dv_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_b16_dv_f16_dv_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_th_f16_dv_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_b16_th_f16_dv_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_dv_f16_th_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_b16_dv_f16_th_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_th_f16_th_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_b16_th_f16_th_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else
          static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>, "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<rightValueType, half> &&
                         __tensor_ops_detail::__is_same_v<destinationValueType, half>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_dv_f16_dv_f16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_b16_dv_f16_dv_f16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_th_f16_dv_f16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_b16_th_f16_dv_f16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_dv_f16_th_f16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_b16_dv_f16_th_f16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_th_f16_th_f16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_b16_th_f16_th_f16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else
          static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>, "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<rightValueType, half> &&
                         __tensor_ops_detail::__is_same_v<destinationValueType, float>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_dv_f16_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_b16_dv_f16_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_th_f16_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_b16_th_f16_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_dv_f16_th_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_b16_dv_f16_th_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_b16_th_f16_th_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_b16_th_f16_th_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else
          static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>, "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, half> &&
                         __tensor_ops_detail::__is_same_v<rightValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<destinationValueType, bfloat>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_b16_dv_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_b16_dv_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_b16_dv_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_b16_dv_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_b16_th_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_b16_th_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_b16_th_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_b16_th_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else
          static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>, "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, half> &&
                         __tensor_ops_detail::__is_same_v<rightValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<destinationValueType, half>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_b16_dv_f16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_b16_dv_f16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_b16_dv_f16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_b16_dv_f16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_b16_th_f16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_b16_th_f16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_b16_th_f16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_b16_th_f16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else
          static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>, "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, half> &&
                         __tensor_ops_detail::__is_same_v<rightValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<destinationValueType, float>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_b16_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_b16_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_b16_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_b16_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_b16_th_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_b16_th_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_b16_th_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else if constexpr (__tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_b16_th_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType);
        else
          static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>, "Unsupported address space");
      }
      else
        static_assert(
            __tensor_ops_detail::__assert_false_v<destinationValueType>,
            "Unsupported type");
    }
    else
      static_assert(
          __tensor_ops_detail::__assert_false_v<destinationTensorType>,
          "destination cannot be cooperative tensor with cooperative group of "
          "size 1");
  }
  else
  {
    // multiple threads
    if constexpr (!__tensor_ops_detail::__is_cooperative_tensor_type_v<
                      destinationTensorType>)
    {
      __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
          destinationDescType =
              __tensor_ops_detail::__tensor_type_to_tensor_descriptor_type<
                  destinationTensorType>();

      thread void *destination = (thread void *)(&destinationT);

      if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, half> &&
                    __tensor_ops_detail::__is_same_v<rightValueType, half> &&
                    __tensor_ops_detail::__is_same_v<destinationValueType,
                                                     half>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_dv_f16_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_dv_f16_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_tg_f16_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_tg_f16_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_dv_f16_tg_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_dv_f16_tg_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_tg_f16_tg_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_tg_f16_tg_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, half>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_dv_i8_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_dv_i8_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_tg_i8_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_tg_i8_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_dv_i8_tg_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_dv_i8_tg_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_tg_i8_tg_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_tg_i8_tg_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, half>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_i8_dv_f16_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_i8_dv_f16_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_i8_tg_f16_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_i8_tg_f16_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_i8_dv_f16_tg_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_i8_dv_f16_tg_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_i8_tg_f16_tg_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_i8_tg_f16_tg_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_dv_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_dv_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_tg_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_tg_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_dv_f16_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_dv_f16_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_tg_f16_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_tg_f16_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          float> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_dv_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_dv_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_tg_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_tg_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_dv_f32_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_dv_f32_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_tg_f32_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_tg_f32_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_dv_i8_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_dv_i8_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_tg_i8_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_tg_i8_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_dv_i8_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_dv_i8_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_tg_i8_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_tg_i8_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          float> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f32_dv_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f32_dv_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f32_tg_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f32_tg_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f32_dv_f16_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f32_dv_f16_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f32_tg_f16_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f32_tg_f16_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          float> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          float> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f32_dv_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f32_dv_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f32_tg_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f32_tg_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f32_dv_f32_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f32_dv_f32_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f32_tg_f32_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f32_tg_f32_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          float> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f32_dv_i8_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f32_dv_i8_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f32_tg_i8_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f32_tg_i8_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f32_dv_i8_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f32_dv_i8_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f32_tg_i8_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f32_tg_i8_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_i8_dv_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_i8_dv_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_i8_tg_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_i8_tg_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_i8_dv_f16_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_i8_dv_f16_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_i8_tg_f16_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_i8_tg_f16_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          float> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_i8_dv_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_i8_dv_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_i8_tg_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_i8_tg_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_i8_dv_f32_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_i8_dv_f32_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_i8_tg_f32_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_i8_tg_f32_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, int32_t>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_i8_dv_i8_dv_i32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_i8_dv_i8_dv_i32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_i8_tg_i8_dv_i32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_i8_tg_i8_dv_i32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_i8_dv_i8_tg_i32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_i8_dv_i8_tg_i32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_i8_tg_i8_tg_i32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_i8_tg_i8_tg_i32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<rightValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<destinationValueType, bfloat>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_b16_dv_b16_dv_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_b16_dv_b16_dv_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_b16_tg_b16_dv_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_b16_tg_b16_dv_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_b16_dv_b16_tg_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_b16_dv_b16_tg_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_b16_tg_b16_tg_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_b16_tg_b16_tg_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else
          static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>, "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<rightValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<destinationValueType, float>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_b16_dv_b16_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_b16_dv_b16_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_b16_tg_b16_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_b16_tg_b16_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_b16_dv_b16_tg_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_b16_dv_b16_tg_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_b16_tg_b16_tg_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_b16_tg_b16_tg_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else
          static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>, "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<rightValueType, float> &&
                         __tensor_ops_detail::__is_same_v<destinationValueType, float>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_b16_dv_f32_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_b16_dv_f32_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_b16_tg_f32_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_b16_tg_f32_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_b16_dv_f32_tg_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_b16_dv_f32_tg_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_b16_tg_f32_tg_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_b16_tg_f32_tg_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else
          static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>, "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<rightValueType, int8_t> &&
                         __tensor_ops_detail::__is_same_v<destinationValueType, bfloat>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_b16_dv_i8_dv_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_b16_dv_i8_dv_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_b16_tg_i8_dv_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_b16_tg_i8_dv_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_b16_dv_i8_tg_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_b16_dv_i8_tg_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_b16_tg_i8_tg_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_b16_tg_i8_tg_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else
          static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>, "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<rightValueType, int8_t> &&
                         __tensor_ops_detail::__is_same_v<destinationValueType, float>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_b16_dv_i8_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_b16_dv_i8_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_b16_tg_i8_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_b16_tg_i8_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_b16_dv_i8_tg_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_b16_dv_i8_tg_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_b16_tg_i8_tg_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_b16_tg_i8_tg_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else
          static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>, "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, float> &&
                         __tensor_ops_detail::__is_same_v<rightValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<destinationValueType, float>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f32_dv_b16_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f32_dv_b16_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f32_tg_b16_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f32_tg_b16_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f32_dv_b16_tg_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f32_dv_b16_tg_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f32_tg_b16_tg_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f32_tg_b16_tg_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else
          static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>, "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, int8_t> &&
                         __tensor_ops_detail::__is_same_v<rightValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<destinationValueType, bfloat>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_i8_dv_b16_dv_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_i8_dv_b16_dv_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_i8_tg_b16_dv_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_i8_tg_b16_dv_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_i8_dv_b16_tg_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_i8_dv_b16_tg_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_i8_tg_b16_tg_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_i8_tg_b16_tg_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else
          static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>, "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, int8_t> &&
                         __tensor_ops_detail::__is_same_v<rightValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<destinationValueType, float>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_i8_dv_b16_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_i8_dv_b16_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_i8_tg_b16_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_i8_tg_b16_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_i8_dv_b16_tg_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_i8_dv_b16_tg_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_i8_tg_b16_tg_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_i8_tg_b16_tg_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else
          static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>, "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<rightValueType, half> &&
                         __tensor_ops_detail::__is_same_v<destinationValueType, bfloat>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_b16_dv_f16_dv_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_b16_dv_f16_dv_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_b16_tg_f16_dv_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_b16_tg_f16_dv_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_b16_dv_f16_tg_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_b16_dv_f16_tg_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_b16_tg_f16_tg_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_b16_tg_f16_tg_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else
          static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>, "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<rightValueType, half> &&
                         __tensor_ops_detail::__is_same_v<destinationValueType, half>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_b16_dv_f16_dv_f16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_b16_dv_f16_dv_f16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_b16_tg_f16_dv_f16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_b16_tg_f16_dv_f16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_b16_dv_f16_tg_f16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_b16_dv_f16_tg_f16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_b16_tg_f16_tg_f16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_b16_tg_f16_tg_f16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else
          static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>, "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<rightValueType, half> &&
                         __tensor_ops_detail::__is_same_v<destinationValueType, float>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_b16_dv_f16_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_b16_dv_f16_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_b16_tg_f16_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_b16_tg_f16_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_b16_dv_f16_tg_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_b16_dv_f16_tg_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_b16_tg_f16_tg_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_b16_tg_f16_tg_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else
          static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>, "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, half> &&
                         __tensor_ops_detail::__is_same_v<rightValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<destinationValueType, bfloat>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_dv_b16_dv_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_dv_b16_dv_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_tg_b16_dv_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_tg_b16_dv_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_dv_b16_tg_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_dv_b16_tg_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_tg_b16_tg_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_tg_b16_tg_b16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else
          static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>, "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, half> &&
                         __tensor_ops_detail::__is_same_v<rightValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<destinationValueType, half>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_dv_b16_dv_f16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_dv_b16_dv_f16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_tg_b16_dv_f16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_tg_b16_dv_f16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_dv_b16_tg_f16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_dv_b16_tg_f16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_tg_b16_tg_f16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_tg_b16_tg_f16(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else
          static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>, "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, half> &&
                         __tensor_ops_detail::__is_same_v<rightValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<destinationValueType, float>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_dv_b16_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_dv_b16_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_tg_b16_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_tg_b16_dv_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_dv_b16_tg_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_dv_b16_tg_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_tg_b16_tg_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_tg_b16_tg_f32(desc, left, leftDescType, right, rightDescType, destination, destinationDescType, threads);
        else
          static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>, "Unsupported address space");
      }
      else
        static_assert(
            __tensor_ops_detail::__assert_false_v<destinationValueType>,
            "Unsupported type");
    }
    else
    {
      thread void *destination = (thread void *)&destinationT[__tensor_ops_detail::__tensor_ops_reserved_index];

      if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, half> &&
                    __tensor_ops_detail::__is_same_v<rightValueType, half> &&
                    __tensor_ops_detail::__is_same_v<destinationValueType,
                                                     half>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                          leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<
                          rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_f16_dv_f16_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_f16_dv_f16_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_f16_tg_f16_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_f16_tg_f16_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, half>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                          leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<
                          rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_f16_dv_i8_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_f16_dv_i8_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_f16_tg_i8_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_f16_tg_i8_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, half>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                          leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<
                          rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_i8_dv_f16_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_i8_dv_f16_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_i8_tg_f16_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_i8_tg_f16_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                          leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<
                          rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_f16_dv_f16_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_f16_dv_f16_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_f16_tg_f16_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_f16_tg_f16_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          float> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                          leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<
                          rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_f16_dv_f32_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_f16_dv_f32_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_f16_tg_f32_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_f16_tg_f32_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                          leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<
                          rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_f16_dv_i8_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_f16_dv_i8_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_f16_tg_i8_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_f16_tg_i8_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          float> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                          leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<
                          rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_f32_dv_f16_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_f32_dv_f16_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_f32_tg_f16_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_f32_tg_f16_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          float> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          float> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                          leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<
                          rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_f32_dv_f32_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_f32_dv_f32_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_f32_tg_f32_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_f32_tg_f32_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          float> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                          leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<
                          rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_f32_dv_i8_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_f32_dv_i8_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_f32_tg_i8_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_f32_tg_i8_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                          leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<
                          rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_i8_dv_f16_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_i8_dv_f16_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_i8_tg_f16_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_i8_tg_f16_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          float> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                          leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<
                          rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_i8_dv_f32_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_i8_dv_f32_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_i8_tg_f32_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_i8_tg_f32_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, int32_t>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                          leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<
                          rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_i8_dv_i8_i32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_i8_dv_i8_i32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_i8_tg_i8_i32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_i8_tg_i8_i32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<rightValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<destinationValueType, bfloat>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_b16_dv_b16_b16(desc, left, leftDescType, right, rightDescType, destination, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_b16_dv_b16_b16(desc, left, leftDescType, right, rightDescType, destination, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_b16_tg_b16_b16(desc, left, leftDescType, right, rightDescType, destination, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_b16_tg_b16_b16(desc, left, leftDescType, right, rightDescType, destination, threads);
        else
          static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>, "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<rightValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<destinationValueType, float>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_b16_dv_b16_f32(desc, left, leftDescType, right, rightDescType, destination, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_b16_dv_b16_f32(desc, left, leftDescType, right, rightDescType, destination, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_b16_tg_b16_f32(desc, left, leftDescType, right, rightDescType, destination, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_b16_tg_b16_f32(desc, left, leftDescType, right, rightDescType, destination, threads);
        else
          static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>, "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<rightValueType, float> &&
                         __tensor_ops_detail::__is_same_v<destinationValueType, float>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_b16_dv_f32_f32(desc, left, leftDescType, right, rightDescType, destination, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_b16_dv_f32_f32(desc, left, leftDescType, right, rightDescType, destination, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_b16_tg_f32_f32(desc, left, leftDescType, right, rightDescType, destination, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_b16_tg_f32_f32(desc, left, leftDescType, right, rightDescType, destination, threads);
        else
          static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>, "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<rightValueType, int8_t> &&
                         __tensor_ops_detail::__is_same_v<destinationValueType, bfloat>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_b16_dv_i8_b16(desc, left, leftDescType, right, rightDescType, destination, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_b16_dv_i8_b16(desc, left, leftDescType, right, rightDescType, destination, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_b16_tg_i8_b16(desc, left, leftDescType, right, rightDescType, destination, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_b16_tg_i8_b16(desc, left, leftDescType, right, rightDescType, destination, threads);
        else
          static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>, "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<rightValueType, int8_t> &&
                         __tensor_ops_detail::__is_same_v<destinationValueType, float>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_b16_dv_i8_f32(desc, left, leftDescType, right, rightDescType, destination, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_b16_dv_i8_f32(desc, left, leftDescType, right, rightDescType, destination, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_b16_tg_i8_f32(desc, left, leftDescType, right, rightDescType, destination, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_b16_tg_i8_f32(desc, left, leftDescType, right, rightDescType, destination, threads);
        else
          static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>, "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, float> &&
                         __tensor_ops_detail::__is_same_v<rightValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<destinationValueType, float>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_f32_dv_b16_f32(desc, left, leftDescType, right, rightDescType, destination, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_f32_dv_b16_f32(desc, left, leftDescType, right, rightDescType, destination, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_f32_tg_b16_f32(desc, left, leftDescType, right, rightDescType, destination, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_f32_tg_b16_f32(desc, left, leftDescType, right, rightDescType, destination, threads);
        else
          static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>, "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, int8_t> &&
                         __tensor_ops_detail::__is_same_v<rightValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<destinationValueType, bfloat>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_i8_dv_b16_b16(desc, left, leftDescType, right, rightDescType, destination, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_i8_dv_b16_b16(desc, left, leftDescType, right, rightDescType, destination, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_i8_tg_b16_b16(desc, left, leftDescType, right, rightDescType, destination, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_i8_tg_b16_b16(desc, left, leftDescType, right, rightDescType, destination, threads);
        else
          static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>, "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, int8_t> &&
                         __tensor_ops_detail::__is_same_v<rightValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<destinationValueType, float>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_i8_dv_b16_f32(desc, left, leftDescType, right, rightDescType, destination, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_i8_dv_b16_f32(desc, left, leftDescType, right, rightDescType, destination, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_i8_tg_b16_f32(desc, left, leftDescType, right, rightDescType, destination, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_i8_tg_b16_f32(desc, left, leftDescType, right, rightDescType, destination, threads);
        else
          static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>, "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<rightValueType, half> &&
                         __tensor_ops_detail::__is_same_v<destinationValueType, bfloat>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_b16_dv_f16_b16(desc, left, leftDescType, right, rightDescType, destination, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_b16_dv_f16_b16(desc, left, leftDescType, right, rightDescType, destination, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_b16_tg_f16_b16(desc, left, leftDescType, right, rightDescType, destination, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_b16_tg_f16_b16(desc, left, leftDescType, right, rightDescType, destination, threads);
        else
          static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>, "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<rightValueType, half> &&
                         __tensor_ops_detail::__is_same_v<destinationValueType, half>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_b16_dv_f16_f16(desc, left, leftDescType, right, rightDescType, destination, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_b16_dv_f16_f16(desc, left, leftDescType, right, rightDescType, destination, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_b16_tg_f16_f16(desc, left, leftDescType, right, rightDescType, destination, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_b16_tg_f16_f16(desc, left, leftDescType, right, rightDescType, destination, threads);
        else
          static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>, "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<rightValueType, half> &&
                         __tensor_ops_detail::__is_same_v<destinationValueType, float>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_b16_dv_f16_f32(desc, left, leftDescType, right, rightDescType, destination, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_b16_dv_f16_f32(desc, left, leftDescType, right, rightDescType, destination, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_b16_tg_f16_f32(desc, left, leftDescType, right, rightDescType, destination, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_b16_tg_f16_f32(desc, left, leftDescType, right, rightDescType, destination, threads);
        else
          static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>, "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, half> &&
                         __tensor_ops_detail::__is_same_v<rightValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<destinationValueType, bfloat>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_f16_dv_b16_b16(desc, left, leftDescType, right, rightDescType, destination, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_f16_dv_b16_b16(desc, left, leftDescType, right, rightDescType, destination, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_f16_tg_b16_b16(desc, left, leftDescType, right, rightDescType, destination, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_f16_tg_b16_b16(desc, left, leftDescType, right, rightDescType, destination, threads);
        else
          static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>, "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, half> &&
                         __tensor_ops_detail::__is_same_v<rightValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<destinationValueType, half>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_f16_dv_b16_f16(desc, left, leftDescType, right, rightDescType, destination, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_f16_dv_b16_f16(desc, left, leftDescType, right, rightDescType, destination, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_f16_tg_b16_f16(desc, left, leftDescType, right, rightDescType, destination, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_f16_tg_b16_f16(desc, left, leftDescType, right, rightDescType, destination, threads);
        else
          static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>, "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, half> &&
                         __tensor_ops_detail::__is_same_v<rightValueType, bfloat> &&
                         __tensor_ops_detail::__is_same_v<destinationValueType, float>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_f16_dv_b16_f32(desc, left, leftDescType, right, rightDescType, destination, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_f16_dv_b16_f32(desc, left, leftDescType, right, rightDescType, destination, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_f16_tg_b16_f32(desc, left, leftDescType, right, rightDescType, destination, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_f16_tg_b16_f32(desc, left, leftDescType, right, rightDescType, destination, threads);
        else
          static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>, "Unsupported address space");
      }
      else
        static_assert(
            __tensor_ops_detail::__assert_false_v<destinationValueType>,
            "Unsupported type");
    }
  }
}

template <class ElementType, class SrcExtents, class DstExtents, class SrcLayout, class DstLayout>
inline void __reduce_rows(
    thread metal::cooperative_tensor<ElementType, SrcExtents, SrcLayout> &sourceT,
    thread metal::cooperative_tensor<ElementType, DstExtents, DstLayout> &destT,
    ElementType identity = (ElementType)0,
    __reduction_operation op = reduction_operation::sum)
{
  static_assert(SrcLayout::is_matmul2d_cooperative_destination_layout,
                "Source must be matmul2d cooperative destination tensor");
  static_assert(DstLayout::is_matmul2d_reduction_cooperative_destination_layout,
                "Destination must be matmul2d row reduction cooperative destination tensor");
  static_assert(DstLayout::__reduction_dim == 0,
                "Destination must be matmul2d row reduction cooperative destination tensor");
  static_assert(__tensor_ops_detail::__is_same_v<typename SrcLayout::scope_t,
                                                 metal::execution_simdgroup>,
                "reduce_rows requires a single SIMD group");
  static_assert(__tensor_ops_detail::__is_same_v<typename DstLayout::scope_t,
                                                 metal::execution_simdgroup>,
                "reduce_rows requires a single SIMD group");
  static_assert(SrcExtents::rank() == 2, "Source rank must be 2");
  static_assert(DstExtents::rank() == 1, "Destination rank must be 1");

  constexpr __matmul2d_descriptor sourceDesc = SrcLayout::matmul2d_desc;
  constexpr __matmul2d_descriptor destDesc = DstLayout::matmul2d_desc;

  static_assert(matmul2d_descriptor_is_equal(sourceDesc, destDesc), "Source and destination matmul2d descriptor must match");
  static_assert(__tensor_ops_detail::__is_same_v<typename SrcLayout::left_t, typename DstLayout::left_t>, "Source and destination operand types must match");
  static_assert(__tensor_ops_detail::__is_same_v<typename SrcLayout::right_t, typename DstLayout::right_t>, "Source and destination operand types must match");
  static_assert(__tensor_ops_detail::__is_same_v<typename SrcLayout::element_t, typename DstLayout::element_t>, "Source and destination element types must match");

  __tensor_ops_detail::__tensor_ops_datatype leftDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<typename SrcLayout::left_value_t>::value;
  __tensor_ops_detail::__tensor_ops_datatype rightDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<typename SrcLayout::right_value_t>::value;

  thread void *src = (thread void *)&sourceT[__tensor_ops_detail::__tensor_ops_reserved_index];
  thread void *dst = (thread void *)&destT[__tensor_ops_detail::__tensor_ops_reserved_index];

  __matmul2d_descriptor desc = SrcLayout::matmul2d_desc;

  if constexpr (__tensor_ops_detail::__is_same_v<ElementType, half>)
    __tensorops_impl_matmul2d_op_cooperative_destination_reduce_rows_f16(
        desc, src, dst, identity, op, leftDataType, rightDataType);
  else if constexpr (__tensor_ops_detail::__is_same_v<ElementType, int32_t>)
    __tensorops_impl_matmul2d_op_cooperative_destination_reduce_rows_i32(
        desc, src, dst, identity, op, leftDataType, rightDataType);
  else if constexpr (__tensor_ops_detail::__is_same_v<ElementType, float>)
    __tensorops_impl_matmul2d_op_cooperative_destination_reduce_rows_f32(
        desc, src, dst, identity, op, leftDataType, rightDataType);
  else if constexpr (__tensor_ops_detail::__is_same_v<ElementType, bfloat>)
    __tensorops_impl_matmul2d_op_cooperative_destination_reduce_rows_b16(
        desc, src, dst, identity, op, leftDataType, rightDataType);
  else
    static_assert(__tensor_ops_detail::__assert_false_v<ElementType>,
                  "Unsupported type");
}

template <class ElementType, class SrcExtents, class DstExtents, class SrcLayout, class DstLayout>
inline void __reduce_columns(
    thread metal::cooperative_tensor<ElementType, SrcExtents, SrcLayout> &sourceT,
    thread metal::cooperative_tensor<ElementType, DstExtents, DstLayout> &destT,
    ElementType identity = (ElementType)0,
    __reduction_operation op = reduction_operation::sum)
{
  static_assert(SrcLayout::is_matmul2d_cooperative_destination_layout,
                "Source must be matmul2d cooperative destination tensor");
  static_assert(DstLayout::is_matmul2d_reduction_cooperative_destination_layout,
                "Destination must be matmul2d column reduction cooperative destination tensor");
  static_assert(DstLayout::__reduction_dim == 1,
                "Destination must be matmul2d column reduction cooperative destination tensor");
  static_assert(__tensor_ops_detail::__is_same_v<typename SrcLayout::scope_t,
                                                 metal::execution_simdgroup>,
                "reduce_columns requires a single SIMD group");
  static_assert(__tensor_ops_detail::__is_same_v<typename DstLayout::scope_t,
                                                 metal::execution_simdgroup>,
                "reduce_columns requires a single SIMD group");
  static_assert(SrcExtents::rank() == 2, "Source rank must be 2");
  static_assert(DstExtents::rank() == 1, "Destination rank must be 1");

  constexpr __matmul2d_descriptor sourceDesc = SrcLayout::matmul2d_desc;
  constexpr __matmul2d_descriptor destDesc = DstLayout::matmul2d_desc;

  static_assert(matmul2d_descriptor_is_equal(sourceDesc, destDesc), "Source and destination matmul2d descriptor must match");
  static_assert(__tensor_ops_detail::__is_same_v<typename SrcLayout::left_t, typename DstLayout::left_t>, "Source and destination operand types must match");
  static_assert(__tensor_ops_detail::__is_same_v<typename SrcLayout::right_t, typename DstLayout::right_t>, "Source and destination operand types must match");
  static_assert(__tensor_ops_detail::__is_same_v<typename SrcLayout::element_t, typename DstLayout::element_t>, "Source and destination element types must match");

  __tensor_ops_detail::__tensor_ops_datatype leftDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<typename SrcLayout::left_value_t>::value;
  __tensor_ops_detail::__tensor_ops_datatype rightDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<typename SrcLayout::right_value_t>::value;

  thread void *src = (thread void *)&sourceT[__tensor_ops_detail::__tensor_ops_reserved_index];
  thread void *dst = (thread void *)&destT[__tensor_ops_detail::__tensor_ops_reserved_index];

  __matmul2d_descriptor desc = SrcLayout::matmul2d_desc;

  if constexpr (__tensor_ops_detail::__is_same_v<ElementType, half>)
    __tensorops_impl_matmul2d_op_cooperative_destination_reduce_columns_f16(
        desc, src, dst, identity, op, leftDataType, rightDataType);
  else if constexpr (__tensor_ops_detail::__is_same_v<ElementType, int32_t>)
    __tensorops_impl_matmul2d_op_cooperative_destination_reduce_columns_i32(
        desc, src, dst, identity, op, leftDataType, rightDataType);
  else if constexpr (__tensor_ops_detail::__is_same_v<ElementType, float>)
    __tensorops_impl_matmul2d_op_cooperative_destination_reduce_columns_f32(
        desc, src, dst, identity, op, leftDataType, rightDataType);
  else if constexpr (__tensor_ops_detail::__is_same_v<ElementType, bfloat>)
    __tensorops_impl_matmul2d_op_cooperative_destination_reduce_columns_b16(
        desc, src, dst, identity, op, leftDataType, rightDataType);
  else
    static_assert(__tensor_ops_detail::__assert_false_v<ElementType>,
                  "Unsupported type");
}

template <class SrcElementType, class DstElementType, class SrcExtents, class DstExtents, class SrcLayout, class DstLayout>
inline bool __is_iterator_compatible(
    const thread metal::cooperative_tensor<SrcElementType, SrcExtents, SrcLayout> &sourceT,
    const thread metal::cooperative_tensor<DstElementType, DstExtents, DstLayout> &destT)
{
  if (!SrcLayout::is_matmul2d_cooperative_destination_layout ||
      !DstLayout::is_matmul2d_reduction_cooperative_destination_layout ||
      !__tensor_ops_detail::__is_same_v<typename SrcLayout::scope_t, metal::execution_simdgroup> ||
      !__tensor_ops_detail::__is_same_v<typename DstLayout::scope_t, metal::execution_simdgroup> ||
      !__tensor_ops_detail::__is_same_v<SrcElementType, DstElementType> ||
      SrcExtents::rank() != 2 || DstExtents::rank() != 1)
  {
    return false;
  }

  constexpr __matmul2d_descriptor sourceDesc = SrcLayout::matmul2d_desc;
  constexpr __matmul2d_descriptor destDesc = DstLayout::matmul2d_desc;

  constexpr int reduction_dim = DstLayout::__reduction_dim;

  if ((reduction_dim == 0 && sourceDesc.m != destDesc.m) ||
      (reduction_dim == 1 && sourceDesc.n == destDesc.n))
  {
    return false;
  }

  thread void *src = (thread void *)&sourceT[__tensor_ops_detail::__tensor_ops_reserved_index];
  thread void *dst = (thread void *)&destT[__tensor_ops_detail::__tensor_ops_reserved_index];

  __tensor_ops_detail::__tensor_ops_datatype srcLeftDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<typename SrcLayout::left_value_t>::value;
  __tensor_ops_detail::__tensor_ops_datatype srcRightDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<typename SrcLayout::right_value_t>::value;
  __tensor_ops_detail::__tensor_ops_datatype srcElemDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<SrcElementType>::value;
  __tensor_ops_detail::__tensor_ops_datatype dstLeftDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<typename DstLayout::left_value_t>::value;
  __tensor_ops_detail::__tensor_ops_datatype dstRightDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<typename DstLayout::right_value_t>::value;
  __tensor_ops_detail::__tensor_ops_datatype dstElemDataType =
        __tensor_ops_detail::__type_to_tensor_ops_datatype<DstElementType>::value;

  return __tensorops_impl_matmul2d_op_cooperative_destination_is_iterator_compatible(
         sourceDesc, destDesc, src, dst, srcLeftDataType, srcRightDataType,
        srcElemDataType, dstLeftDataType, dstRightDataType, dstElemDataType);
}

#undef EXTERNALLY_DEFINED_ATTR

} // namespace __mutmul2d_detail

#endif

#endif // __TensorOpsMatMul2DImpl__
