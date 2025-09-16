//
//  MTL4Archive.h
//  Metal
//
//  Copyright © 2024 Apple, Inc. All rights reserved.
//

#ifndef MTL4Archive_h
#define MTL4Archive_h

#import <Metal/MTLDefines.h>
#import <Metal/MTLDevice.h>
#import <Metal/MTL4ComputePipeline.h>
#import <Metal/MTL4RenderPipeline.h>


@class MTL4BinaryFunctionDescriptor;

NS_ASSUME_NONNULL_BEGIN

/// A read-only container that stores pipeline states from a shader compiler.
///
/// The pipeline states can have intermediate representation (IR) binaries,
/// GPU- and system-specifc binaries, or a combination.
///
/// ## Topics
///
/// ### Identifiying the archive
/// - ``label``
///
/// ### Creating compute pipeline states
///
/// - ``newComputePipelineStateWithDescriptor:dynamicLinkingDescriptor:error:``
/// - ``newComputePipelineStateWithDescriptor:error:``
/// - ``newComputePipelineStateWithName:dynamicLinkingDescriptor:error:``
/// - ``newComputePipelineStateWithName:error:``
///
/// ### Creating reder pipeline states
///
/// - ``newRenderPipelineStateWithDescriptor:dynamicLinkingDescriptor:error:``
/// - ``newRenderPipelineStateWithDescriptor:error:``
/// - ``newRenderPipelineStateWithName:dynamicLinkingDescriptor:error:``
/// - ``newRenderPipelineStateWithName:error:``
///
/// ### Creating binary functions
///
/// - ``newBinaryFunctionWithDescriptor:functionType:error:``
API_AVAILABLE(macos(26.0), ios(26.0)) NS_SWIFT_SENDABLE
@protocol MTL4Archive <NSObject>

/// A label that you can associate with this archive.
@property (nullable, copy, atomic) NSString* label;


/// Creates a compute pipeline state from the archive with a descriptor.
///
/// - Parameters:
///   - descriptor: A compute pipeline descriptor.
///   - error: On return, if the method fails, a pointer to an error information instance; otherwise `nil`.
///
/// - Returns: A compute pipeline state if the method succeeds, otherwise `nil`.
- (nullable id<MTLComputePipelineState>)newComputePipelineStateWithDescriptor:(MTL4ComputePipelineDescriptor*)descriptor
                                                                        error:(NSError**)error;

/// Creates a compute pipeline state from the archive with a compute descriptor and a dynamic linking descriptor.
///
/// - Parameters:
///   - descriptor: A compute pipeline descriptor.
///   - dynamicLinkingDescriptor: A descriptor that provides additional properties
///   to link other functions with the pipeline.
///   - error: On return, if the method fails, a pointer to an error information instance; otherwise `nil`.
///
/// - Returns: A compute pipeline state if the method succeeds, otherwise `nil`.
- (nullable id<MTLComputePipelineState>)newComputePipelineStateWithDescriptor:(MTL4ComputePipelineDescriptor *)descriptor
                                                     dynamicLinkingDescriptor:(MTL4PipelineStageDynamicLinkingDescriptor*)dynamicLinkingDescriptor
                                                                        error:(NSError**)error;

/// Creates a render pipeline state from the archive with a descriptor.
///
/// You create any kind of render pipeline states with this method, including:
/// - Traditional render pipelines
/// - Mesh render pipelines
/// - Tile render pipelines
///
/// - Parameters:
///   - descriptor: A render pipeline descriptor.
///   - error: On return, if the method fails, a pointer to an error information instance; otherwise `nil`.
///
/// - Returns: A render pipeline state if the method succeeds, otherwise `nil`.
- (nullable id<MTLRenderPipelineState>)newRenderPipelineStateWithDescriptor:(MTL4PipelineDescriptor*)descriptor
                                                                      error:(NSError**)error;

/// Creates a render pipeline state from the archive with a render descriptor and a dynamic linking descriptor.
///
/// You create any kind of render pipeline states with this method, including:
/// - Traditional render pipelines
/// - Mesh render pipelines
/// - Tile render pipelines
///
/// - Parameters:
///   - descriptor: A render pipeline descriptor.
///   - dynamicLinkingDescriptor: A descriptor that provides additional properties
///   to link other functions with the pipeline.
///   - error: On return, if the method fails, a pointer to an error information instance; otherwise `nil`.
///
/// - Returns: A render pipeline state if the method succeeds, otherwise `nil`.
- (nullable id<MTLRenderPipelineState>)newRenderPipelineStateWithDescriptor:(MTL4PipelineDescriptor *)descriptor
                                                   dynamicLinkingDescriptor:(MTL4RenderPipelineDynamicLinkingDescriptor*)dynamicLinkingDescriptor
                                                                      error:(NSError**)error;


/// Method used to create a binary function, with a given descriptor, from the contents of the archive.
/// - Parameters:
///   - descriptor: the function descriptor for a visible or intersection function.
///   - error: an optional parameter that is populated in the case of an error.
/// - Returns: a binary function object, otherwise `nil`.
- (nullable id<MTL4BinaryFunction>)newBinaryFunctionWithDescriptor:(MTL4BinaryFunctionDescriptor *)descriptor
                                                             error:(NSError**)error;


@end

NS_ASSUME_NONNULL_END
#endif // MTL4Archive_h
