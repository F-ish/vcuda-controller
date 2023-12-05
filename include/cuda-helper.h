/*
 * Tencent is pleased to support the open source community by making TKEStack
 * available.
 *
 * Copyright (C) 2012-2019 Tencent. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 * https://opensource.org/licenses/Apache-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OF ANY KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations under the License.
 */

#ifndef HIJACK_CUDA_HELPER_H
#define HIJACK_CUDA_HELPER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <dlfcn.h>

#include "cuda-subset.h"
#include "hijack.h"

/**
 *  CUDA library prefix
 */
#define CUDA_LIBRARY_PREFIX "libcuda.so"

#define CUDA_ENTRY_ENUM(x) ENTRY_##x

#define CUDA_FIND_ENTRY(table, sym) ({ (table)[CUDA_ENTRY_ENUM(sym)].fn_ptr; })

#define CUDA_ENTRY_CALL(table, sym, ...)                                       \
  ({                                                                           \
    cuda_sym_t _entry = CUDA_FIND_ENTRY(table, sym);                           \
    _entry(__VA_ARGS__);                                                       \
  })

#define CUDA_ENTRY_DEBUG_VOID_CALL(table, sym, ...)                            \
  ({                                                                           \
    cuda_debug_void_sym_t _entry = CUDA_FIND_ENTRY(table, sym);                \
    _entry(__VA_ARGS__);                                                       \
  })

#define CUDA_ENTRY_DEBUG_RESULT_CALL(table, sym, ...)                          \
  ({                                                                           \
    cuda_debug_result_sym_t _entry = CUDA_FIND_ENTRY(table, sym);              \
    _entry(__VA_ARGS__);                                                       \
  })

/**
 * CUDA library enumerator entry
 */
 
typedef enum {
  /** cuGetErrorString */
  CUDA_ENTRY_ENUM(cuGetErrorString),
  /** cuGetErrorName */
  CUDA_ENTRY_ENUM(cuGetErrorName),
  /** cuInit */
  CUDA_ENTRY_ENUM(cuInit),
  /** cuDriverGetVersion */
  CUDA_ENTRY_ENUM(cuDriverGetVersion),
  /** cuDeviceGet */
  CUDA_ENTRY_ENUM(cuDeviceGet),
  /** cuDeviceGetCount */
  CUDA_ENTRY_ENUM(cuDeviceGetCount),
  /** cuDeviceGetName */
  CUDA_ENTRY_ENUM(cuDeviceGetName),
  /** cuDeviceGetUuid */
  CUDA_ENTRY_ENUM(cuDeviceGetUuid),
  /** cuDeviceGetUuid_v2 */
  CUDA_ENTRY_ENUM(cuDeviceGetUuid_v2),
  /** cuDeviceGetLuid */
  CUDA_ENTRY_ENUM(cuDeviceGetLuid),
  /** cuDeviceTotalMem */
  CUDA_ENTRY_ENUM(cuDeviceTotalMem_v2),
  /** cuDeviceGetTexture1DLinearMaxWidth */
  CUDA_ENTRY_ENUM(cuDeviceGetTexture1DLinearMaxWidth),
  /** cuDeviceGetAttribute */
  CUDA_ENTRY_ENUM(cuDeviceGetAttribute),
  /** cuDeviceGetNvSciSyncAttributes */
  CUDA_ENTRY_ENUM(cuDeviceGetNvSciSyncAttributes),
  /** cuDeviceSetMemPool */
  CUDA_ENTRY_ENUM(cuDeviceSetMemPool),
  /** cuDeviceGetMemPool */
  CUDA_ENTRY_ENUM(cuDeviceGetMemPool),
  /** cuDeviceGetDefaultMemPool */
  CUDA_ENTRY_ENUM(cuDeviceGetDefaultMemPool),
  /** cuFlushGPUDirectRDMAWrites */
  CUDA_ENTRY_ENUM(cuFlushGPUDirectRDMAWrites),
  /** cuDeviceGetProperties */
  CUDA_ENTRY_ENUM(cuDeviceGetProperties),
  /** cuDeviceComputeCapability */
  CUDA_ENTRY_ENUM(cuDeviceComputeCapability),
  /** cuDevicePrimaryCtxRetain */
  CUDA_ENTRY_ENUM(cuDevicePrimaryCtxRetain),
  /** cuDevicePrimaryCtxRelease */
  CUDA_ENTRY_ENUM(cuDevicePrimaryCtxRelease_v2),
  /** cuDevicePrimaryCtxSetFlags */
  CUDA_ENTRY_ENUM(cuDevicePrimaryCtxSetFlags_v2),
  /** cuDevicePrimaryCtxGetState */
  CUDA_ENTRY_ENUM(cuDevicePrimaryCtxGetState),
  /** cuDevicePrimaryCtxReset */
  CUDA_ENTRY_ENUM(cuDevicePrimaryCtxReset_v2),
  /** cuDeviceGetExecAffinitySupport */
  CUDA_ENTRY_ENUM(cuDeviceGetExecAffinitySupport),
  /** cuCtxCreate */
  CUDA_ENTRY_ENUM(cuCtxCreate_v2),
  /** cuCtxCreate_v3 */
  CUDA_ENTRY_ENUM(cuCtxCreate_v3),
  /** cuCtxDestroy */
  CUDA_ENTRY_ENUM(cuCtxDestroy_v2),
  /** cuCtxPushCurrent */
  CUDA_ENTRY_ENUM(cuCtxPushCurrent_v2),
  /** cuCtxPopCurrent */
  CUDA_ENTRY_ENUM(cuCtxPopCurrent_v2),
  /** cuCtxSetCurrent */
  CUDA_ENTRY_ENUM(cuCtxSetCurrent),
  /** cuCtxGetCurrent */
  CUDA_ENTRY_ENUM(cuCtxGetCurrent),
  /** cuCtxGetDevice */
  CUDA_ENTRY_ENUM(cuCtxGetDevice),
  /** cuCtxGetFlags */
  CUDA_ENTRY_ENUM(cuCtxGetFlags),
  /** cuCtxSynchronize */
  CUDA_ENTRY_ENUM(cuCtxSynchronize),
  /** cuCtxSetLimit */
  CUDA_ENTRY_ENUM(cuCtxSetLimit),
  /** cuCtxGetLimit */
  CUDA_ENTRY_ENUM(cuCtxGetLimit),
  /** cuCtxGetCacheConfig */
  CUDA_ENTRY_ENUM(cuCtxGetCacheConfig),
  /** cuCtxSetCacheConfig */
  CUDA_ENTRY_ENUM(cuCtxSetCacheConfig),
  /** cuCtxGetSharedMemConfig */
  CUDA_ENTRY_ENUM(cuCtxGetSharedMemConfig),
  /** cuCtxSetSharedMemConfig */
  CUDA_ENTRY_ENUM(cuCtxSetSharedMemConfig),
  /** cuCtxGetApiVersion */
  CUDA_ENTRY_ENUM(cuCtxGetApiVersion),
  /** cuCtxGetStreamPriorityRange */
  CUDA_ENTRY_ENUM(cuCtxGetStreamPriorityRange),
  /** cuCtxResetPersistingL2Cache */
  CUDA_ENTRY_ENUM(cuCtxResetPersistingL2Cache),
  /** cuCtxGetExecAffinity */
  CUDA_ENTRY_ENUM(cuCtxGetExecAffinity),
  /** cuCtxAttach */
  CUDA_ENTRY_ENUM(cuCtxAttach),
  /** cuCtxDetach */
  CUDA_ENTRY_ENUM(cuCtxDetach),
  /** cuModuleLoad */
  CUDA_ENTRY_ENUM(cuModuleLoad),
  /** cuModuleLoadData */
  CUDA_ENTRY_ENUM(cuModuleLoadData),
  /** cuModuleLoadDataEx */
  CUDA_ENTRY_ENUM(cuModuleLoadDataEx),
  /** cuModuleLoadFatBinary */
  CUDA_ENTRY_ENUM(cuModuleLoadFatBinary),
  /** cuModuleUnload */
  CUDA_ENTRY_ENUM(cuModuleUnload),
  /** cuModuleGetFunction */
  CUDA_ENTRY_ENUM(cuModuleGetFunction),
  /** cuModuleGetGlobal */
  CUDA_ENTRY_ENUM(cuModuleGetGlobal_v2),
  /** cuModuleGetTexRef */
  CUDA_ENTRY_ENUM(cuModuleGetTexRef),
  /** cuModuleGetSurfRef */
  CUDA_ENTRY_ENUM(cuModuleGetSurfRef),
  /** cuLinkCreate */
  CUDA_ENTRY_ENUM(cuLinkCreate_v2),
  /** cuLinkAddData */
  CUDA_ENTRY_ENUM(cuLinkAddData_v2),
  /** cuLinkAddFile */
  CUDA_ENTRY_ENUM(cuLinkAddFile_v2),
  /** cuLinkComplete */
  CUDA_ENTRY_ENUM(cuLinkComplete),
  /** cuLinkDestroy */
  CUDA_ENTRY_ENUM(cuLinkDestroy),
  /** cuMemGetInfo */
  CUDA_ENTRY_ENUM(cuMemGetInfo_v2),
  /** cuMemAlloc */
  CUDA_ENTRY_ENUM(cuMemAlloc_v2),
  /** cuMemAllocPitch */
  CUDA_ENTRY_ENUM(cuMemAllocPitch_v2),
  /** cuMemFree */
  CUDA_ENTRY_ENUM(cuMemFree_v2),
  /** cuMemGetAddressRange */
  CUDA_ENTRY_ENUM(cuMemGetAddressRange_v2),
  /** cuMemAllocHost */
  CUDA_ENTRY_ENUM(cuMemAllocHost_v2),
  /** cuMemFreeHost */
  CUDA_ENTRY_ENUM(cuMemFreeHost),
  /** cuMemHostAlloc */
  CUDA_ENTRY_ENUM(cuMemHostAlloc),
  /** cuMemHostGetDevicePointer */
  CUDA_ENTRY_ENUM(cuMemHostGetDevicePointer_v2),
  /** cuMemHostGetFlags */
  CUDA_ENTRY_ENUM(cuMemHostGetFlags),
  /** cuMemAllocManaged */
  CUDA_ENTRY_ENUM(cuMemAllocManaged),
  /** cuDeviceGetByPCIBusId */
  CUDA_ENTRY_ENUM(cuDeviceGetByPCIBusId),
  /** cuDeviceGetPCIBusId */
  CUDA_ENTRY_ENUM(cuDeviceGetPCIBusId),
  /** cuIpcGetEventHandle */
  CUDA_ENTRY_ENUM(cuIpcGetEventHandle),
  /** cuIpcOpenEventHandle */
  CUDA_ENTRY_ENUM(cuIpcOpenEventHandle),
  /** cuIpcGetMemHandle */
  CUDA_ENTRY_ENUM(cuIpcGetMemHandle),
  /** cuIpcOpenMemHandle */
  CUDA_ENTRY_ENUM(cuIpcOpenMemHandle_v2),
  /** cuIpcCloseMemHandle */
  CUDA_ENTRY_ENUM(cuIpcCloseMemHandle),
  /** cuMemHostRegister */
  CUDA_ENTRY_ENUM(cuMemHostRegister_v2),
  /** cuMemHostUnregister */
  CUDA_ENTRY_ENUM(cuMemHostUnregister),
  /** cuMemcpy */
  CUDA_ENTRY_ENUM(cuMemcpy),
  /** cuMemcpyPeer */
  CUDA_ENTRY_ENUM(cuMemcpyPeer),
  /** cuMemcpyHtoD */
  CUDA_ENTRY_ENUM(cuMemcpyHtoD_v2),
  /** cuMemcpyDtoH */
  CUDA_ENTRY_ENUM(cuMemcpyDtoH_v2),
  /** cuMemcpyDtoD */
  CUDA_ENTRY_ENUM(cuMemcpyDtoD_v2),
  /** cuMemcpyDtoA */
  CUDA_ENTRY_ENUM(cuMemcpyDtoA_v2),
  /** cuMemcpyAtoD */
  CUDA_ENTRY_ENUM(cuMemcpyAtoD_v2),
  /** cuMemcpyHtoA */
  CUDA_ENTRY_ENUM(cuMemcpyHtoA_v2),
  /** cuMemcpyAtoH */
  CUDA_ENTRY_ENUM(cuMemcpyAtoH_v2),
  /** cuMemcpyAtoA */
  CUDA_ENTRY_ENUM(cuMemcpyAtoA_v2),
  /** cuMemcpy2D */
  CUDA_ENTRY_ENUM(cuMemcpy2D_v2),
  /** cuMemcpy2DUnaligned */
  CUDA_ENTRY_ENUM(cuMemcpy2DUnaligned_v2),
  /** cuMemcpy3D */
  CUDA_ENTRY_ENUM(cuMemcpy3D_v2),
  /** cuMemcpy3DPeer */
  CUDA_ENTRY_ENUM(cuMemcpy3DPeer),
  /** cuMemcpyAsync */
  CUDA_ENTRY_ENUM(cuMemcpyAsync),
  /** cuMemcpyPeerAsync */
  CUDA_ENTRY_ENUM(cuMemcpyPeerAsync),
  /** cuMemcpyHtoDAsync */
  CUDA_ENTRY_ENUM(cuMemcpyHtoDAsync_v2),
  /** cuMemcpyDtoHAsync */
  CUDA_ENTRY_ENUM(cuMemcpyDtoHAsync_v2),
  /** cuMemcpyDtoDAsync */
  CUDA_ENTRY_ENUM(cuMemcpyDtoDAsync_v2),
  /** cuMemcpyHtoAAsync */
  CUDA_ENTRY_ENUM(cuMemcpyHtoAAsync_v2),
  /** cuMemcpyAtoHAsync */
  CUDA_ENTRY_ENUM(cuMemcpyAtoHAsync_v2),
  /** cuMemcpy2DAsync */
  CUDA_ENTRY_ENUM(cuMemcpy2DAsync_v2),
  /** cuMemcpy3DAsync */
  CUDA_ENTRY_ENUM(cuMemcpy3DAsync_v2),
  /** cuMemcpy3DPeerAsync */
  CUDA_ENTRY_ENUM(cuMemcpy3DPeerAsync),
  /** cuMemsetD8 */
  CUDA_ENTRY_ENUM(cuMemsetD8_v2),
  /** cuMemsetD16 */
  CUDA_ENTRY_ENUM(cuMemsetD16_v2),
  /** cuMemsetD32 */
  CUDA_ENTRY_ENUM(cuMemsetD32_v2),
  /** cuMemsetD2D8 */
  CUDA_ENTRY_ENUM(cuMemsetD2D8_v2),
  /** cuMemsetD2D16 */
  CUDA_ENTRY_ENUM(cuMemsetD2D16_v2),
  /** cuMemsetD2D32 */
  CUDA_ENTRY_ENUM(cuMemsetD2D32_v2),
  /** cuMemsetD8Async */
  CUDA_ENTRY_ENUM(cuMemsetD8Async),
  /** cuMemsetD16Async */
  CUDA_ENTRY_ENUM(cuMemsetD16Async),
  /** cuMemsetD32Async */
  CUDA_ENTRY_ENUM(cuMemsetD32Async),
  /** cuMemsetD2D8Async */
  CUDA_ENTRY_ENUM(cuMemsetD2D8Async),
  /** cuMemsetD2D16Async */
  CUDA_ENTRY_ENUM(cuMemsetD2D16Async),
  /** cuMemsetD2D32Async */
  CUDA_ENTRY_ENUM(cuMemsetD2D32Async),
  /** cuArrayCreate */
  CUDA_ENTRY_ENUM(cuArrayCreate_v2),
  /** cuArrayGetDescriptor */
  CUDA_ENTRY_ENUM(cuArrayGetDescriptor_v2),
  /** cuArrayGetSparseProperties */
  CUDA_ENTRY_ENUM(cuArrayGetSparseProperties),
  /** cuMipmappedArrayGetSparseProperties */
  CUDA_ENTRY_ENUM(cuMipmappedArrayGetSparseProperties),
  /** cuArrayGetMemoryRequirements */
  CUDA_ENTRY_ENUM(cuArrayGetMemoryRequirements),
  /** cuMipmappedArrayGetMemoryRequirements */
  CUDA_ENTRY_ENUM(cuMipmappedArrayGetMemoryRequirements),
  /** cuArrayGetPlane */
  CUDA_ENTRY_ENUM(cuArrayGetPlane),
  /** cuArrayDestroy */
  CUDA_ENTRY_ENUM(cuArrayDestroy),
  /** cuArray3DCreate */
  CUDA_ENTRY_ENUM(cuArray3DCreate_v2),
  /** cuArray3DGetDescriptor */
  CUDA_ENTRY_ENUM(cuArray3DGetDescriptor_v2),
  /** cuMipmappedArrayCreate */
  CUDA_ENTRY_ENUM(cuMipmappedArrayCreate),
  /** cuMipmappedArrayGetLevel */
  CUDA_ENTRY_ENUM(cuMipmappedArrayGetLevel),
  /** cuMipmappedArrayDestroy */
  CUDA_ENTRY_ENUM(cuMipmappedArrayDestroy),
  /** cuMemAddressReserve */
  CUDA_ENTRY_ENUM(cuMemAddressReserve),
  /** cuMemAddressFree */
  CUDA_ENTRY_ENUM(cuMemAddressFree),
  /** cuMemCreate */
  CUDA_ENTRY_ENUM(cuMemCreate),
  /** cuMemRelease */
  CUDA_ENTRY_ENUM(cuMemRelease),
  /** cuMemMap */
  CUDA_ENTRY_ENUM(cuMemMap),
  /** cuMemMapArrayAsync */
  CUDA_ENTRY_ENUM(cuMemMapArrayAsync),
  /** cuMemUnmap */
  CUDA_ENTRY_ENUM(cuMemUnmap),
  /** cuMemSetAccess */
  CUDA_ENTRY_ENUM(cuMemSetAccess),
  /** cuMemGetAccess */
  CUDA_ENTRY_ENUM(cuMemGetAccess),
  /** cuMemExportToShareableHandle */
  CUDA_ENTRY_ENUM(cuMemExportToShareableHandle),
  /** cuMemImportFromShareableHandle */
  CUDA_ENTRY_ENUM(cuMemImportFromShareableHandle),
  /** cuMemGetAllocationGranularity */
  CUDA_ENTRY_ENUM(cuMemGetAllocationGranularity),
  /** cuMemGetAllocationPropertiesFromHandle */
  CUDA_ENTRY_ENUM(cuMemGetAllocationPropertiesFromHandle),
  /** cuMemRetainAllocationHandle */
  CUDA_ENTRY_ENUM(cuMemRetainAllocationHandle),
  /** cuMemFreeAsync */
  CUDA_ENTRY_ENUM(cuMemFreeAsync),
  /** cuMemAllocAsync */
  CUDA_ENTRY_ENUM(cuMemAllocAsync),
  /** cuMemPoolTrimTo */
  CUDA_ENTRY_ENUM(cuMemPoolTrimTo),
  /** cuMemPoolSetAttribute */
  CUDA_ENTRY_ENUM(cuMemPoolSetAttribute),
  /** cuMemPoolGetAttribute */
  CUDA_ENTRY_ENUM(cuMemPoolGetAttribute),
  /** cuMemPoolSetAccess */
  CUDA_ENTRY_ENUM(cuMemPoolSetAccess),
  /** cuMemPoolGetAccess */
  CUDA_ENTRY_ENUM(cuMemPoolGetAccess),
  /** cuMemPoolCreate */
  CUDA_ENTRY_ENUM(cuMemPoolCreate),
  /** cuMemPoolDestroy */
  CUDA_ENTRY_ENUM(cuMemPoolDestroy),
  /** cuMemAllocFromPoolAsync */
  CUDA_ENTRY_ENUM(cuMemAllocFromPoolAsync),
  /** cuMemPoolExportToShareableHandle */
  CUDA_ENTRY_ENUM(cuMemPoolExportToShareableHandle),
  /** cuMemPoolImportFromShareableHandle */
  CUDA_ENTRY_ENUM(cuMemPoolImportFromShareableHandle),
  /** cuMemPoolExportPointer */
  CUDA_ENTRY_ENUM(cuMemPoolExportPointer),
  /** cuMemPoolImportPointer */
  CUDA_ENTRY_ENUM(cuMemPoolImportPointer),
  /** cuPointerGetAttribute */
  CUDA_ENTRY_ENUM(cuPointerGetAttribute),
  /** cuMemPrefetchAsync */
  CUDA_ENTRY_ENUM(cuMemPrefetchAsync),
  /** cuMemAdvise */
  CUDA_ENTRY_ENUM(cuMemAdvise),
  /** cuMemRangeGetAttribute */
  CUDA_ENTRY_ENUM(cuMemRangeGetAttribute),
  /** cuMemRangeGetAttributes */
  CUDA_ENTRY_ENUM(cuMemRangeGetAttributes),
  /** cuPointerSetAttribute */
  CUDA_ENTRY_ENUM(cuPointerSetAttribute),
  /** cuPointerGetAttributes */
  CUDA_ENTRY_ENUM(cuPointerGetAttributes),
  /** cuStreamCreate */
  CUDA_ENTRY_ENUM(cuStreamCreate),
  /** cuStreamCreateWithPriority */
  CUDA_ENTRY_ENUM(cuStreamCreateWithPriority),
  /** cuStreamGetPriority */
  CUDA_ENTRY_ENUM(cuStreamGetPriority),
  /** cuStreamGetFlags */
  CUDA_ENTRY_ENUM(cuStreamGetFlags),
  /** cuStreamGetCtx */
  CUDA_ENTRY_ENUM(cuStreamGetCtx),
  /** cuStreamWaitEvent */
  CUDA_ENTRY_ENUM(cuStreamWaitEvent),
  /** cuStreamAddCallback */
  CUDA_ENTRY_ENUM(cuStreamAddCallback),
  /** cuStreamBeginCapture */
  CUDA_ENTRY_ENUM(cuStreamBeginCapture_v2),
  /** cuThreadExchangeStreamCaptureMode */
  CUDA_ENTRY_ENUM(cuThreadExchangeStreamCaptureMode),
  /** cuStreamEndCapture */
  CUDA_ENTRY_ENUM(cuStreamEndCapture),
  /** cuStreamIsCapturing */
  CUDA_ENTRY_ENUM(cuStreamIsCapturing),
  /** cuStreamGetCaptureInfo */
  CUDA_ENTRY_ENUM(cuStreamGetCaptureInfo),
  CUDA_ENTRY_ENUM(cuStreamGetCaptureInfo_v2),
  CUDA_ENTRY_ENUM(cuStreamUpdateCaptureDependencies),
  CUDA_ENTRY_ENUM(cuStreamAttachMemAsync),
  CUDA_ENTRY_ENUM(cuStreamQuery),
  CUDA_ENTRY_ENUM(cuStreamSynchronize),
  CUDA_ENTRY_ENUM(cuStreamDestroy_v2),
  CUDA_ENTRY_ENUM(cuStreamCopyAttributes),
  CUDA_ENTRY_ENUM(cuStreamGetAttribute),
  CUDA_ENTRY_ENUM(cuStreamSetAttribute),
  CUDA_ENTRY_ENUM(cuEventCreate),
  CUDA_ENTRY_ENUM(cuEventRecord),
  CUDA_ENTRY_ENUM(cuEventRecordWithFlags),
  CUDA_ENTRY_ENUM(cuEventQuery),
  CUDA_ENTRY_ENUM(cuEventSynchronize),
  CUDA_ENTRY_ENUM(cuEventDestroy_v2),
  CUDA_ENTRY_ENUM(cuEventElapsedTime),
  CUDA_ENTRY_ENUM(cuImportExternalMemory),
  CUDA_ENTRY_ENUM(cuExternalMemoryGetMappedBuffer),
  CUDA_ENTRY_ENUM(cuExternalMemoryGetMappedMipmappedArray),
  CUDA_ENTRY_ENUM(cuDestroyExternalMemory),
  CUDA_ENTRY_ENUM(cuImportExternalSemaphore),
  CUDA_ENTRY_ENUM(cuSignalExternalSemaphoresAsync),
  CUDA_ENTRY_ENUM(cuWaitExternalSemaphoresAsync),
  CUDA_ENTRY_ENUM(cuDestroyExternalSemaphore),
  CUDA_ENTRY_ENUM(cuStreamWaitValue32),
  CUDA_ENTRY_ENUM(cuStreamWaitValue64),
  CUDA_ENTRY_ENUM(cuStreamWriteValue32),
  CUDA_ENTRY_ENUM(cuStreamWriteValue64),
  CUDA_ENTRY_ENUM(cuStreamBatchMemOp),
  CUDA_ENTRY_ENUM(cuStreamWaitValue32_v2),
  CUDA_ENTRY_ENUM(cuStreamWaitValue64_v2),
  CUDA_ENTRY_ENUM(cuStreamWriteValue32_v2),
  CUDA_ENTRY_ENUM(cuStreamWriteValue64_v2),
  CUDA_ENTRY_ENUM(cuStreamBatchMemOp_v2),
  CUDA_ENTRY_ENUM(cuFuncGetAttribute),
  CUDA_ENTRY_ENUM(cuFuncSetAttribute),
  CUDA_ENTRY_ENUM(cuFuncSetCacheConfig),
  CUDA_ENTRY_ENUM(cuFuncSetSharedMemConfig),
  CUDA_ENTRY_ENUM(cuFuncGetModule),
  CUDA_ENTRY_ENUM(cuLaunchKernel),
  CUDA_ENTRY_ENUM(cuLaunchCooperativeKernel),
  CUDA_ENTRY_ENUM(cuLaunchCooperativeKernelMultiDevice),
  CUDA_ENTRY_ENUM(cuLaunchHostFunc),
  CUDA_ENTRY_ENUM(cuFuncSetBlockShape),
  CUDA_ENTRY_ENUM(cuFuncSetSharedSize),
  CUDA_ENTRY_ENUM(cuParamSetSize),
  CUDA_ENTRY_ENUM(cuParamSeti),
  CUDA_ENTRY_ENUM(cuParamSetf),
  CUDA_ENTRY_ENUM(cuParamSetv),
  CUDA_ENTRY_ENUM(cuLaunch),
  CUDA_ENTRY_ENUM(cuLaunchGrid),
  CUDA_ENTRY_ENUM(cuLaunchGridAsync),
  CUDA_ENTRY_ENUM(cuParamSetTexRef),
  CUDA_ENTRY_ENUM(cuGraphCreate),
  CUDA_ENTRY_ENUM(cuGraphAddKernelNode),
  CUDA_ENTRY_ENUM(cuGraphKernelNodeGetParams),
  CUDA_ENTRY_ENUM(cuGraphKernelNodeSetParams),
  CUDA_ENTRY_ENUM(cuGraphAddMemcpyNode),
  CUDA_ENTRY_ENUM(cuGraphMemcpyNodeGetParams),
  CUDA_ENTRY_ENUM(cuGraphMemcpyNodeSetParams),
  CUDA_ENTRY_ENUM(cuGraphAddMemsetNode),
  CUDA_ENTRY_ENUM(cuGraphMemsetNodeGetParams),
  CUDA_ENTRY_ENUM(cuGraphMemsetNodeSetParams),
  CUDA_ENTRY_ENUM(cuGraphAddHostNode),
  CUDA_ENTRY_ENUM(cuGraphHostNodeGetParams),
  CUDA_ENTRY_ENUM(cuGraphHostNodeSetParams),
  CUDA_ENTRY_ENUM(cuGraphAddChildGraphNode),
  CUDA_ENTRY_ENUM(cuGraphChildGraphNodeGetGraph),
  CUDA_ENTRY_ENUM(cuGraphAddEmptyNode),
  CUDA_ENTRY_ENUM(cuGraphAddEventRecordNode),
  CUDA_ENTRY_ENUM(cuGraphEventRecordNodeGetEvent),
  CUDA_ENTRY_ENUM(cuGraphEventRecordNodeSetEvent),
  CUDA_ENTRY_ENUM(cuGraphAddEventWaitNode),
  CUDA_ENTRY_ENUM(cuGraphEventWaitNodeGetEvent),
  CUDA_ENTRY_ENUM(cuGraphEventWaitNodeSetEvent),
  CUDA_ENTRY_ENUM(cuGraphAddExternalSemaphoresSignalNode),
  CUDA_ENTRY_ENUM(cuGraphExternalSemaphoresSignalNodeGetParams),
  CUDA_ENTRY_ENUM(cuGraphExternalSemaphoresSignalNodeSetParams),
  CUDA_ENTRY_ENUM(cuGraphAddExternalSemaphoresWaitNode),
  CUDA_ENTRY_ENUM(cuGraphExternalSemaphoresWaitNodeGetParams),
  CUDA_ENTRY_ENUM(cuGraphExternalSemaphoresWaitNodeSetParams),
  CUDA_ENTRY_ENUM(cuGraphAddBatchMemOpNode),
  CUDA_ENTRY_ENUM(cuGraphBatchMemOpNodeGetParams),
  CUDA_ENTRY_ENUM(cuGraphBatchMemOpNodeSetParams),
  CUDA_ENTRY_ENUM(cuGraphExecBatchMemOpNodeSetParams),
  CUDA_ENTRY_ENUM(cuGraphAddMemAllocNode),
  CUDA_ENTRY_ENUM(cuGraphMemAllocNodeGetParams),
  CUDA_ENTRY_ENUM(cuGraphAddMemFreeNode),
  CUDA_ENTRY_ENUM(cuGraphMemFreeNodeGetParams),
  CUDA_ENTRY_ENUM(cuDeviceGraphMemTrim),
  CUDA_ENTRY_ENUM(cuDeviceGetGraphMemAttribute),
  CUDA_ENTRY_ENUM(cuDeviceSetGraphMemAttribute),
  CUDA_ENTRY_ENUM(cuGraphClone),
  CUDA_ENTRY_ENUM(cuGraphNodeFindInClone),
  CUDA_ENTRY_ENUM(cuGraphNodeGetType),
  CUDA_ENTRY_ENUM(cuGraphGetNodes),
  CUDA_ENTRY_ENUM(cuGraphGetRootNodes),
  CUDA_ENTRY_ENUM(cuGraphGetEdges),
  CUDA_ENTRY_ENUM(cuGraphNodeGetDependencies),
  CUDA_ENTRY_ENUM(cuGraphNodeGetDependentNodes),
  CUDA_ENTRY_ENUM(cuGraphAddDependencies),
  CUDA_ENTRY_ENUM(cuGraphRemoveDependencies),
  CUDA_ENTRY_ENUM(cuGraphDestroyNode),
  CUDA_ENTRY_ENUM(cuGraphInstantiate_v2),
  CUDA_ENTRY_ENUM(cuGraphInstantiateWithFlags),
  CUDA_ENTRY_ENUM(cuGraphExecKernelNodeSetParams),
  CUDA_ENTRY_ENUM(cuGraphExecMemcpyNodeSetParams),
  CUDA_ENTRY_ENUM(cuGraphExecMemsetNodeSetParams),
  CUDA_ENTRY_ENUM(cuGraphExecHostNodeSetParams),
  CUDA_ENTRY_ENUM(cuGraphExecChildGraphNodeSetParams),
  CUDA_ENTRY_ENUM(cuGraphExecEventRecordNodeSetEvent),
  CUDA_ENTRY_ENUM(cuGraphExecEventWaitNodeSetEvent),
  CUDA_ENTRY_ENUM(cuGraphExecExternalSemaphoresSignalNodeSetParams),
  CUDA_ENTRY_ENUM(cuGraphExecExternalSemaphoresWaitNodeSetParams),
  CUDA_ENTRY_ENUM(cuGraphNodeSetEnabled),
  CUDA_ENTRY_ENUM(cuGraphNodeGetEnabled),
  CUDA_ENTRY_ENUM(cuGraphUpload),
  CUDA_ENTRY_ENUM(cuGraphLaunch),
  CUDA_ENTRY_ENUM(cuGraphExecDestroy),
  CUDA_ENTRY_ENUM(cuGraphDestroy),
  CUDA_ENTRY_ENUM(cuGraphExecUpdate),
  CUDA_ENTRY_ENUM(cuGraphKernelNodeCopyAttributes),
  CUDA_ENTRY_ENUM(cuGraphKernelNodeGetAttribute),
  CUDA_ENTRY_ENUM(cuGraphKernelNodeSetAttribute),
  CUDA_ENTRY_ENUM(cuGraphDebugDotPrint),
  CUDA_ENTRY_ENUM(cuUserObjectCreate),
  CUDA_ENTRY_ENUM(cuUserObjectRetain),
  CUDA_ENTRY_ENUM(cuUserObjectRelease),
  CUDA_ENTRY_ENUM(cuGraphRetainUserObject),
  CUDA_ENTRY_ENUM(cuGraphReleaseUserObject),
  CUDA_ENTRY_ENUM(cuOccupancyMaxActiveBlocksPerMultiprocessor),
  CUDA_ENTRY_ENUM(cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags),
  CUDA_ENTRY_ENUM(cuOccupancyMaxPotentialBlockSize),
  CUDA_ENTRY_ENUM(cuOccupancyMaxPotentialBlockSizeWithFlags),
  CUDA_ENTRY_ENUM(cuOccupancyAvailableDynamicSMemPerBlock),
  CUDA_ENTRY_ENUM(cuTexRefSetArray),
  CUDA_ENTRY_ENUM(cuTexRefSetMipmappedArray),
  CUDA_ENTRY_ENUM(cuTexRefSetAddress_v2),
  CUDA_ENTRY_ENUM(cuTexRefSetAddress2D_v3),
  CUDA_ENTRY_ENUM(cuTexRefSetFormat),
  CUDA_ENTRY_ENUM(cuTexRefSetAddressMode),
  CUDA_ENTRY_ENUM(cuTexRefSetFilterMode),
  CUDA_ENTRY_ENUM(cuTexRefSetMipmapFilterMode),
  CUDA_ENTRY_ENUM(cuTexRefSetMipmapLevelBias),
  CUDA_ENTRY_ENUM(cuTexRefSetMipmapLevelClamp),
  CUDA_ENTRY_ENUM(cuTexRefSetMaxAnisotropy),
  CUDA_ENTRY_ENUM(cuTexRefSetBorderColor),
  CUDA_ENTRY_ENUM(cuTexRefSetFlags),
  CUDA_ENTRY_ENUM(cuTexRefGetAddress_v2),
  CUDA_ENTRY_ENUM(cuTexRefGetArray),
  CUDA_ENTRY_ENUM(cuTexRefGetMipmappedArray),
  CUDA_ENTRY_ENUM(cuTexRefGetAddressMode),
  CUDA_ENTRY_ENUM(cuTexRefGetFilterMode),
  CUDA_ENTRY_ENUM(cuTexRefGetFormat),
  CUDA_ENTRY_ENUM(cuTexRefGetMipmapFilterMode),
  CUDA_ENTRY_ENUM(cuTexRefGetMipmapLevelBias),
  CUDA_ENTRY_ENUM(cuTexRefGetMipmapLevelClamp),
  CUDA_ENTRY_ENUM(cuTexRefGetMaxAnisotropy),
  CUDA_ENTRY_ENUM(cuTexRefGetBorderColor),
  CUDA_ENTRY_ENUM(cuTexRefGetFlags),
  CUDA_ENTRY_ENUM(cuTexRefCreate),
  CUDA_ENTRY_ENUM(cuTexRefDestroy),
  CUDA_ENTRY_ENUM(cuSurfRefSetArray),
  CUDA_ENTRY_ENUM(cuSurfRefGetArray),
  CUDA_ENTRY_ENUM(cuTexObjectCreate),
  CUDA_ENTRY_ENUM(cuTexObjectDestroy),
  CUDA_ENTRY_ENUM(cuTexObjectGetResourceDesc),
  CUDA_ENTRY_ENUM(cuTexObjectGetTextureDesc),
  CUDA_ENTRY_ENUM(cuTexObjectGetResourceViewDesc),
  CUDA_ENTRY_ENUM(cuSurfObjectCreate),
  CUDA_ENTRY_ENUM(cuSurfObjectDestroy),
  CUDA_ENTRY_ENUM(cuSurfObjectGetResourceDesc),
  CUDA_ENTRY_ENUM(cuDeviceCanAccessPeer),
  CUDA_ENTRY_ENUM(cuCtxEnablePeerAccess),
  CUDA_ENTRY_ENUM(cuCtxDisablePeerAccess),
  CUDA_ENTRY_ENUM(cuDeviceGetP2PAttribute),
  CUDA_ENTRY_ENUM(cuGraphicsUnregisterResource),
  CUDA_ENTRY_ENUM(cuGraphicsSubResourceGetMappedArray),
  CUDA_ENTRY_ENUM(cuGraphicsResourceGetMappedMipmappedArray),
  CUDA_ENTRY_ENUM(cuGraphicsResourceGetMappedPointer_v2),
  CUDA_ENTRY_ENUM(cuGraphicsResourceSetMapFlags_v2),
  CUDA_ENTRY_ENUM(cuGraphicsMapResources),
  CUDA_ENTRY_ENUM(cuGraphicsUnmapResources),
  CUDA_ENTRY_ENUM(cuGetProcAddress),
  CUDA_ENTRY_ENUM(cuModuleGetLoadingMode),
  CUDA_ENTRY_ENUM(cuMemGetHandleForAddressRange),
  CUDA_ENTRY_ENUM(cuGetExportTable),
  CUDA_ENTRY_END
} cuda_entry_enum_t;

/**
 * CUDA library function pointer
 */
typedef CUresult (*cuda_sym_t)();

/**
 * CUDA library debug function pointer
 */
typedef void (*cuda_debug_void_sym_t)();

/**
 * CUDA library debug result function pointer
 */
typedef CUDBGResult (*cuda_debug_result_sym_t)();

#ifdef __cplusplus
}
#endif

#endif // HIJACK_CUDA_HELPER_H
