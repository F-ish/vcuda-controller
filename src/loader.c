
//
// Created by fish on 28/11/23.
//
#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <regex.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "include/cuda-helper.h"
#include "include/hijack.h"
#include "include/nvml-helper.h"

entry_t cuda_library_entry[] = {
    {.name = "cuGetErrorString"},
    {.name = "cuGetErrorName"},
    {.name = "cuInit"},
    {.name = "cuDriverGetVersion"},
    {.name = "cuDeviceGet"},
    {.name = "cuDeviceGetCount"},
    {.name = "cuDeviceGetName"},
    {.name = "cuDeviceGetUuid"},
    {.name = "cuDeviceGetUuid_v2"},
    {.name = "cuDeviceGetLuid"},
    {.name = "cuDeviceTotalMem"},
    {.name = "cuDeviceGetTexture1DLinearMaxWidth"},
    {.name = "cuDeviceGetAttribute"},
    {.name = "cuDeviceGetNvSciSyncAttributes"},
    {.name = "cuDeviceSetMemPool"},
    {.name = "cuDeviceGetMemPool"},
    {.name = "cuDeviceGetDefaultMemPool"},
    {.name = "cuFlushGPUDirectRDMAWrites"},
    {.name = "cuDeviceGetProperties"},
    {.name = "cuDeviceComputeCapability"},
    {.name = "cuDevicePrimaryCtxRetain"},
    {.name = "cuDevicePrimaryCtxRelease"},
    {.name = "cuDevicePrimaryCtxSetFlags"},
    {.name = "cuDevicePrimaryCtxGetState"},
    {.name = "cuDevicePrimaryCtxReset"},
    {.name = "cuDeviceGetExecAffinitySupport"},
    {.name = "cuCtxCreate"},
    {.name = "cuCtxCreate_v3"},
    {.name = "cuCtxDestroy"},
    {.name = "cuCtxPushCurrent"},
    {.name = "cuCtxPopCurrent"},
    {.name = "cuCtxSetCurrent"},
    {.name = "cuCtxGetCurrent"},
    {.name = "cuCtxGetDevice"},
    {.name = "cuCtxGetFlags"},
    {.name = "cuCtxSynchronize"},
    {.name = "cuCtxSetLimit"},
    {.name = "cuCtxGetLimit"},
    {.name = "cuCtxGetCacheConfig"},
    {.name = "cuCtxSetCacheConfig"},
    {.name = "cuCtxGetSharedMemConfig"},
    {.name = "cuCtxSetSharedMemConfig"},
    {.name = "cuCtxGetApiVersion"},
    {.name = "cuCtxGetStreamPriorityRange"},
    {.name = "cuCtxResetPersistingL2Cache"},
    {.name = "cuCtxGetExecAffinity"},
    {.name = "cuCtxAttach"},
    {.name = "cuCtxDetach"},
    {.name = "cuModuleLoad"},
    {.name = "cuModuleLoadData"},
    {.name = "cuModuleLoadDataEx"},
    {.name = "cuModuleLoadFatBinary"},
    {.name = "cuModuleUnload"},
    {.name = "cuModuleGetFunction"},
    {.name = "cuModuleGetGlobal"},
    {.name = "cuModuleGetTexRef"},
    {.name = "cuModuleGetSurfRef"},
    {.name = "cuLinkCreate"},
    {.name = "cuLinkAddData"},
    {.name = "cuLinkAddFile"},
    {.name = "cuLinkComplete"},
    {.name = "cuLinkDestroy"},
    {.name = "cuMemGetInfo"},
    {.name = "cuMemAlloc"},
    {.name = "cuMemAllocPitch"},
    {.name = "cuMemFree"},
    {.name = "cuMemGetAddressRange"},
    {.name = "cuMemAllocHost"},
    {.name = "cuMemFreeHost"},
    {.name = "cuMemHostAlloc"},
    {.name = "cuMemHostGetDevicePointer"},
    {.name = "cuMemHostGetFlags"},
    {.name = "cuMemAllocManaged"},
    {.name = "cuDeviceGetByPCIBusId"},
    {.name = "cuDeviceGetPCIBusId"},
    {.name = "cuIpcGetEventHandle"},
    {.name = "cuIpcOpenEventHandle"},
    {.name = "cuIpcGetMemHandle"},
    {.name = "cuIpcOpenMemHandle"},
    {.name = "cuIpcCloseMemHandle"},
    {.name = "cuMemHostRegister"},
    {.name = "cuMemHostUnregister"},
    {.name = "cuMemcpy"},
    {.name = "cuMemcpyPeer"},
    {.name = "cuMemcpyHtoD"},
    {.name = "cuMemcpyDtoH"},
    {.name = "cuMemcpyDtoD"},
    {.name = "cuMemcpyDtoA"},
    {.name = "cuMemcpyAtoD"},
    {.name = "cuMemcpyHtoA"},
    {.name = "cuMemcpyAtoH"},
    {.name = "cuMemcpyAtoA"},
    {.name = "cuMemcpy2D"},
    {.name = "cuMemcpy2DUnaligned"},
    {.name = "cuMemcpy3D"},
    {.name = "cuMemcpy3DPeer"},
    {.name = "cuMemcpyAsync"},
    {.name = "cuMemcpyPeerAsync"},
    {.name = "cuMemcpyHtoDAsync"},
    {.name = "cuMemcpyDtoHAsync"},
    {.name = "cuMemcpyDtoDAsync"},
    {.name = "cuMemcpyHtoAAsync"},
    {.name = "cuMemcpyAtoHAsync"},
    {.name = "cuMemcpy2DAsync"},
    {.name = "cuMemcpy3DAsync"},
    {.name = "cuMemcpy3DPeerAsync"},
    {.name = "cuMemsetD8"},
    {.name = "cuMemsetD16"},
    {.name = "cuMemsetD32"},
    {.name = "cuMemsetD2D8"},
    {.name = "cuMemsetD2D16"},
    {.name = "cuMemsetD2D32"},
    {.name = "cuMemsetD8Async"},
    {.name = "cuMemsetD16Async"},
    {.name = "cuMemsetD32Async"},
    {.name = "cuMemsetD2D8Async"},
    {.name = "cuMemsetD2D16Async"},
    {.name = "cuMemsetD2D32Async"},
    {.name = "cuArrayCreate"},
    {.name = "cuArrayGetDescriptor"},
    {.name = "cuArrayGetSparseProperties"},
    {.name = "cuMipmappedArrayGetSparseProperties"},
    {.name = "cuArrayGetMemoryRequirements"},
    {.name = "cuMipmappedArrayGetMemoryRequirements"},
    {.name = "cuArrayGetPlane"},
    {.name = "cuArrayDestroy"},
    {.name = "cuArray3DCreate"},
    {.name = "cuArray3DGetDescriptor"},
    {.name = "cuMipmappedArrayCreate"},
    {.name = "cuMipmappedArrayGetLevel"},
    {.name = "cuMipmappedArrayDestroy"},
    {.name = "cuMemAddressReserve"},
    {.name = "cuMemAddressFree"},
    {.name = "cuMemCreate"},
    {.name = "cuMemRelease"},
    {.name = "cuMemMap"},
    {.name = "cuMemMapArrayAsync"},
    {.name = "cuMemUnmap"},
    {.name = "cuMemSetAccess"},
    {.name = "cuMemGetAccess"},
    {.name = "cuMemExportToShareableHandle"},
    {.name = "cuMemImportFromShareableHandle"},
    {.name = "cuMemGetAllocationGranularity"},
    {.name = "cuMemGetAllocationPropertiesFromHandle"},
    {.name = "cuMemRetainAllocationHandle"},
    {.name = "cuMemFreeAsync"},
    {.name = "cuMemAllocAsync"},
    {.name = "cuMemPoolTrimTo"},
    {.name = "cuMemPoolSetAttribute"},
    {.name = "cuMemPoolGetAttribute"},
    {.name = "cuMemPoolSetAccess"},
    {.name = "cuMemPoolGetAccess"},
    {.name = "cuMemPoolCreate"},
    {.name = "cuMemPoolDestroy"},
    {.name = "cuMemAllocFromPoolAsync"},
    {.name = "cuMemPoolExportToShareableHandle"},
    {.name = "cuMemPoolImportFromShareableHandle"},
    {.name = "cuMemPoolExportPointer"},
    {.name = "cuMemPoolImportPointer"},
    {.name = "cuPointerGetAttribute"},
    {.name = "cuMemPrefetchAsync"},
    {.name = "cuMemAdvise"},
    {.name = "cuMemRangeGetAttribute"},
    {.name = "cuMemRangeGetAttributes"},
    {.name = "cuPointerSetAttribute"},
    {.name = "cuPointerGetAttributes"},
    {.name = "cuStreamCreate"},
    {.name = "cuStreamCreateWithPriority"},
    {.name = "cuStreamGetPriority"},
    {.name = "cuStreamGetFlags"},
    {.name = "cuStreamGetCtx"},
    {.name = "cuStreamWaitEvent"},
    {.name = "cuStreamAddCallback"},
    {.name = "cuStreamBeginCapture"},
    {.name = "cuThreadExchangeStreamCaptureMode"},
    {.name = "cuStreamEndCapture"},
    {.name = "cuStreamIsCapturing"},
    {.name = "cuStreamGetCaptureInfo"},
    {.name = "cuStreamGetCaptureInfo_v2"},
    {.name = "cuStreamUpdateCaptureDependencies"},
    {.name = "cuStreamAttachMemAsync"},
    {.name = "cuStreamQuery"},
    {.name = "cuStreamSynchronize"},
    {.name = "cuStreamDestroy"},
    {.name = "cuStreamCopyAttributes"},
    {.name = "cuStreamGetAttribute"},
    {.name = "cuStreamSetAttribute"},
    {.name = "cuEventCreate"},
    {.name = "cuEventRecord"},
    {.name = "cuEventRecordWithFlags"},
    {.name = "cuEventQuery"},
    {.name = "cuEventSynchronize"},
    {.name = "cuEventDestroy"},
    {.name = "cuEventElapsedTime"},
    {.name = "cuImportExternalMemory"},
    {.name = "cuExternalMemoryGetMappedBuffer"},
    {.name = "cuExternalMemoryGetMappedMipmappedArray"},
    {.name = "cuDestroyExternalMemory"},
    {.name = "cuImportExternalSemaphore"},
    {.name = "cuSignalExternalSemaphoresAsync"},
    {.name = "cuWaitExternalSemaphoresAsync"},
    {.name = "cuDestroyExternalSemaphore"},
    {.name = "cuStreamWaitValue32"},
    {.name = "cuStreamWaitValue64"},
    {.name = "cuStreamWriteValue32"},
    {.name = "cuStreamWriteValue64"},
    {.name = "cuStreamBatchMemOp"},
    {.name = "cuStreamWaitValue32_v2"},
    {.name = "cuStreamWaitValue64_v2"},
    {.name = "cuStreamWriteValue32_v2"},
    {.name = "cuStreamWriteValue64_v2"},
    {.name = "cuStreamBatchMemOp_v2"},
    {.name = "cuFuncGetAttribute"},
    {.name = "cuFuncSetAttribute"},
    {.name = "cuFuncSetCacheConfig"},
    {.name = "cuFuncSetSharedMemConfig"},
    {.name = "cuFuncGetModule"},
    {.name = "cuLaunchKernel"},
    {.name = "cuLaunchCooperativeKernel"},
    {.name = "cuLaunchCooperativeKernelMultiDevice"},
    {.name = "cuLaunchHostFunc"},
    {.name = "cuFuncSetBlockShape"},
    {.name = "cuFuncSetSharedSize"},
    {.name = "cuParamSetSize"},
    {.name = "cuParamSeti"},
    {.name = "cuParamSetf"},
    {.name = "cuParamSetv"},
    {.name = "cuLaunch"},
    {.name = "cuLaunchGrid"},
    {.name = "cuLaunchGridAsync"},
    {.name = "cuParamSetTexRef"},
    {.name = "cuGraphCreate"},
    {.name = "cuGraphAddKernelNode"},
    {.name = "cuGraphKernelNodeGetParams"},
    {.name = "cuGraphKernelNodeSetParams"},
    {.name = "cuGraphAddMemcpyNode"},
    {.name = "cuGraphMemcpyNodeGetParams"},
    {.name = "cuGraphMemcpyNodeSetParams"},
    {.name = "cuGraphAddMemsetNode"},
    {.name = "cuGraphMemsetNodeGetParams"},
    {.name = "cuGraphMemsetNodeSetParams"},
    {.name = "cuGraphAddHostNode"},
    {.name = "cuGraphHostNodeGetParams"},
    {.name = "cuGraphHostNodeSetParams"},
    {.name = "cuGraphAddChildGraphNode"},
    {.name = "cuGraphChildGraphNodeGetGraph"},
    {.name = "cuGraphAddEmptyNode"},
    {.name = "cuGraphAddEventRecordNode"},
    {.name = "cuGraphEventRecordNodeGetEvent"},
    {.name = "cuGraphEventRecordNodeSetEvent"},
    {.name = "cuGraphAddEventWaitNode"},
    {.name = "cuGraphEventWaitNodeGetEvent"},
    {.name = "cuGraphEventWaitNodeSetEvent"},
    {.name = "cuGraphAddExternalSemaphoresSignalNode"},
    {.name = "cuGraphExternalSemaphoresSignalNodeGetParams"},
    {.name = "cuGraphExternalSemaphoresSignalNodeSetParams"},
    {.name = "cuGraphAddExternalSemaphoresWaitNode"},
    {.name = "cuGraphExternalSemaphoresWaitNodeGetParams"},
    {.name = "cuGraphExternalSemaphoresWaitNodeSetParams"},
    {.name = "cuGraphAddBatchMemOpNode"},
    {.name = "cuGraphBatchMemOpNodeGetParams"},
    {.name = "cuGraphBatchMemOpNodeSetParams"},
    {.name = "cuGraphExecBatchMemOpNodeSetParams"},
    {.name = "cuGraphAddMemAllocNode"},
    {.name = "cuGraphMemAllocNodeGetParams"},
    {.name = "cuGraphAddMemFreeNode"},
    {.name = "cuGraphMemFreeNodeGetParams"},
    {.name = "cuDeviceGraphMemTrim"},
    {.name = "cuDeviceGetGraphMemAttribute"},
    {.name = "cuDeviceSetGraphMemAttribute"},
    {.name = "cuGraphClone"},
    {.name = "cuGraphNodeFindInClone"},
    {.name = "cuGraphNodeGetType"},
    {.name = "cuGraphGetNodes"},
    {.name = "cuGraphGetRootNodes"},
    {.name = "cuGraphGetEdges"},
    {.name = "cuGraphNodeGetDependencies"},
    {.name = "cuGraphNodeGetDependentNodes"},
    {.name = "cuGraphAddDependencies"},
    {.name = "cuGraphRemoveDependencies"},
    {.name = "cuGraphDestroyNode"},
    {.name = "cuGraphInstantiate"},
    {.name = "cuGraphInstantiateWithFlags"},
    {.name = "cuGraphExecKernelNodeSetParams"},
    {.name = "cuGraphExecMemcpyNodeSetParams"},
    {.name = "cuGraphExecMemsetNodeSetParams"},
    {.name = "cuGraphExecHostNodeSetParams"},
    {.name = "cuGraphExecChildGraphNodeSetParams"},
    {.name = "cuGraphExecEventRecordNodeSetEvent"},
    {.name = "cuGraphExecEventWaitNodeSetEvent"},
    {.name = "cuGraphExecExternalSemaphoresSignalNodeSetParams"},
    {.name = "cuGraphExecExternalSemaphoresWaitNodeSetParams"},
    {.name = "cuGraphNodeSetEnabled"},
    {.name = "cuGraphNodeGetEnabled"},
    {.name = "cuGraphUpload"},
    {.name = "cuGraphLaunch"},
    {.name = "cuGraphExecDestroy"},
    {.name = "cuGraphDestroy"},
    {.name = "cuGraphExecUpdate"},
    {.name = "cuGraphKernelNodeCopyAttributes"},
    {.name = "cuGraphKernelNodeGetAttribute"},
    {.name = "cuGraphKernelNodeSetAttribute"},
    {.name = "cuGraphDebugDotPrint"},
    {.name = "cuUserObjectCreate"},
    {.name = "cuUserObjectRetain"},
    {.name = "cuUserObjectRelease"},
    {.name = "cuGraphRetainUserObject"},
    {.name = "cuGraphReleaseUserObject"},
    {.name = "cuOccupancyMaxActiveBlocksPerMultiprocessor"},
    {.name = "cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags"},
    {.name = "cuOccupancyMaxPotentialBlockSize"},
    {.name = "cuOccupancyMaxPotentialBlockSizeWithFlags"},
    {.name = "cuOccupancyAvailableDynamicSMemPerBlock"},
    {.name = "cuTexRefSetArray"},
    {.name = "cuTexRefSetMipmappedArray"},
    {.name = "cuTexRefSetAddress"},
    {.name = "cuTexRefSetAddress2D"},
    {.name = "cuTexRefSetFormat"},
    {.name = "cuTexRefSetAddressMode"},
    {.name = "cuTexRefSetFilterMode"},
    {.name = "cuTexRefSetMipmapFilterMode"},
    {.name = "cuTexRefSetMipmapLevelBias"},
    {.name = "cuTexRefSetMipmapLevelClamp"},
    {.name = "cuTexRefSetMaxAnisotropy"},
    {.name = "cuTexRefSetBorderColor"},
    {.name = "cuTexRefSetFlags"},
    {.name = "cuTexRefGetAddress"},
    {.name = "cuTexRefGetArray"},
    {.name = "cuTexRefGetMipmappedArray"},
    {.name = "cuTexRefGetAddressMode"},
    {.name = "cuTexRefGetFilterMode"},
    {.name = "cuTexRefGetFormat"},
    {.name = "cuTexRefGetMipmapFilterMode"},
    {.name = "cuTexRefGetMipmapLevelBias"},
    {.name = "cuTexRefGetMipmapLevelClamp"},
    {.name = "cuTexRefGetMaxAnisotropy"},
    {.name = "cuTexRefGetBorderColor"},
    {.name = "cuTexRefGetFlags"},
    {.name = "cuTexRefCreate"},
    {.name = "cuTexRefDestroy"},
    {.name = "cuSurfRefSetArray"},
    {.name = "cuSurfRefGetArray"},
    {.name = "cuTexObjectCreate"},
    {.name = "cuTexObjectDestroy"},
    {.name = "cuTexObjectGetResourceDesc"},
    {.name = "cuTexObjectGetTextureDesc"},
    {.name = "cuTexObjectGetResourceViewDesc"},
    {.name = "cuSurfObjectCreate"},
    {.name = "cuSurfObjectDestroy"},
    {.name = "cuSurfObjectGetResourceDesc"},
    {.name = "cuDeviceCanAccessPeer"},
    {.name = "cuCtxEnablePeerAccess"},
    {.name = "cuCtxDisablePeerAccess"},
    {.name = "cuDeviceGetP2PAttribute"},
    {.name = "cuGraphicsUnregisterResource"},
    {.name = "cuGraphicsSubResourceGetMappedArray"},
    {.name = "cuGraphicsResourceGetMappedMipmappedArray"},
    {.name = "cuGraphicsResourceGetMappedPointer"},
    {.name = "cuGraphicsResourceSetMapFlags"},
    {.name = "cuGraphicsMapResources"},
    {.name = "cuGraphicsUnmapResources"},
    {.name = "cuGetProcAddress"},
    {.name = "cuModuleGetLoadingMode"},
    {.name = "cuMemGetHandleForAddressRange"},
    {.name = "cuGetExportTable"},
};


entry_t nvml_library_entry[] = {
    {.name = "nvmlInit"},
    {.name = "nvmlShutdown"},
    {.name = "nvmlErrorString"},
    {.name = "nvmlDeviceGetHandleByIndex"},
    {.name = "nvmlDeviceGetComputeRunningProcesses"},
    {.name = "nvmlDeviceGetPciInfo"},
    {.name = "nvmlDeviceGetProcessUtilization"},
    {.name = "nvmlDeviceGetCount"},
    {.name = "nvmlDeviceClearAccountingPids"},
    {.name = "nvmlDeviceClearCpuAffinity"},
    {.name = "nvmlDeviceClearEccErrorCounts"},
    {.name = "nvmlDeviceDiscoverGpus"},
    {.name = "nvmlDeviceFreezeNvLinkUtilizationCounter"},
    {.name = "nvmlDeviceGetAccountingBufferSize"},
    {.name = "nvmlDeviceGetAccountingMode"},
    {.name = "nvmlDeviceGetAccountingPids"},
    {.name = "nvmlDeviceGetAccountingStats"},
    {.name = "nvmlDeviceGetActiveVgpus"},
    {.name = "nvmlDeviceGetAPIRestriction"},
    {.name = "nvmlDeviceGetApplicationsClock"},
    {.name = "nvmlDeviceGetAutoBoostedClocksEnabled"},
    {.name = "nvmlDeviceGetBAR1MemoryInfo"},
    {.name = "nvmlDeviceGetBoardId"},
    {.name = "nvmlDeviceGetBoardPartNumber"},
    {.name = "nvmlDeviceGetBrand"},
    {.name = "nvmlDeviceGetBridgeChipInfo"},
    {.name = "nvmlDeviceGetClock"},
    {.name = "nvmlDeviceGetClockInfo"},
    {.name = "nvmlDeviceGetComputeMode"},
    {.name = "nvmlDeviceGetCount_v2"},
    {.name = "nvmlDeviceGetCpuAffinity"},
    {.name = "nvmlDeviceGetCreatableVgpus"},
    {.name = "nvmlDeviceGetCudaComputeCapability"},
    {.name = "nvmlDeviceGetCurrentClocksThrottleReasons"},
    {.name = "nvmlDeviceGetCurrPcieLinkGeneration"},
    {.name = "nvmlDeviceGetCurrPcieLinkWidth"},
    {.name = "nvmlDeviceGetDecoderUtilization"},
    {.name = "nvmlDeviceGetDefaultApplicationsClock"},
    {.name = "nvmlDeviceGetDetailedEccErrors"},
    {.name = "nvmlDeviceGetDisplayActive"},
    {.name = "nvmlDeviceGetDisplayMode"},
    {.name = "nvmlDeviceGetDriverModel"},
    {.name = "nvmlDeviceGetEccMode"},
    {.name = "nvmlDeviceGetEncoderCapacity"},
    {.name = "nvmlDeviceGetEncoderSessions"},
    {.name = "nvmlDeviceGetEncoderStats"},
    {.name = "nvmlDeviceGetEncoderUtilization"},
    {.name = "nvmlDeviceGetEnforcedPowerLimit"},
    {.name = "nvmlDeviceGetFanSpeed"},
    {.name = "nvmlDeviceGetFanSpeed_v2"},
    {.name = "nvmlDeviceGetFieldValues"},
    {.name = "nvmlDeviceGetGpuOperationMode"},
    {.name = "nvmlDeviceGetGraphicsRunningProcesses"},
    {.name = "nvmlDeviceGetGridLicensableFeatures"},
    {.name = "nvmlDeviceGetHandleByIndex_v2"},
    {.name = "nvmlDeviceGetHandleByPciBusId"},
    {.name = "nvmlDeviceGetHandleByPciBusId_v2"},
    {.name = "nvmlDeviceGetHandleBySerial"},
    {.name = "nvmlDeviceGetHandleByUUID"},
    {.name = "nvmlDeviceGetIndex"},
    {.name = "nvmlDeviceGetInforomConfigurationChecksum"},
    {.name = "nvmlDeviceGetInforomImageVersion"},
    {.name = "nvmlDeviceGetInforomVersion"},
    {.name = "nvmlDeviceGetMaxClockInfo"},
    {.name = "nvmlDeviceGetMaxCustomerBoostClock"},
    {.name = "nvmlDeviceGetMaxPcieLinkGeneration"},
    {.name = "nvmlDeviceGetMaxPcieLinkWidth"},
    {.name = "nvmlDeviceGetMemoryErrorCounter"},
    {.name = "nvmlDeviceGetMemoryInfo"},
    {.name = "nvmlDeviceGetMemoryInfo_v2"},
    {.name = "nvmlDeviceGetMinorNumber"},
    {.name = "nvmlDeviceGetMPSComputeRunningProcesses"},
    {.name = "nvmlDeviceGetMultiGpuBoard"},
    {.name = "nvmlDeviceGetName"},
    {.name = "nvmlDeviceGetNvLinkCapability"},
    {.name = "nvmlDeviceGetNvLinkErrorCounter"},
    {.name = "nvmlDeviceGetNvLinkRemotePciInfo"},
    {.name = "nvmlDeviceGetNvLinkRemotePciInfo_v2"},
    {.name = "nvmlDeviceGetNvLinkState"},
    {.name = "nvmlDeviceGetNvLinkUtilizationControl"},
    {.name = "nvmlDeviceGetNvLinkUtilizationCounter"},
    {.name = "nvmlDeviceGetNvLinkVersion"},
    {.name = "nvmlDeviceGetP2PStatus"},
    {.name = "nvmlDeviceGetPcieReplayCounter"},
    {.name = "nvmlDeviceGetPcieThroughput"},
    {.name = "nvmlDeviceGetPciInfo_v2"},
    {.name = "nvmlDeviceGetPciInfo_v3"},
    {.name = "nvmlDeviceGetPerformanceState"},
    {.name = "nvmlDeviceGetPersistenceMode"},
    {.name = "nvmlDeviceGetPowerManagementDefaultLimit"},
    {.name = "nvmlDeviceGetPowerManagementLimit"},
    {.name = "nvmlDeviceGetPowerManagementLimitConstraints"},
    {.name = "nvmlDeviceGetPowerManagementMode"},
    {.name = "nvmlDeviceGetPowerState"},
    {.name = "nvmlDeviceGetPowerUsage"},
    {.name = "nvmlDeviceGetRetiredPages"},
    {.name = "nvmlDeviceGetRetiredPagesPendingStatus"},
    {.name = "nvmlDeviceGetSamples"},
    {.name = "nvmlDeviceGetSerial"},
    {.name = "nvmlDeviceGetSupportedClocksThrottleReasons"},
    {.name = "nvmlDeviceGetSupportedEventTypes"},
    {.name = "nvmlDeviceGetSupportedGraphicsClocks"},
    {.name = "nvmlDeviceGetSupportedMemoryClocks"},
    {.name = "nvmlDeviceGetSupportedVgpus"},
    {.name = "nvmlDeviceGetTemperature"},
    {.name = "nvmlDeviceGetTemperatureThreshold"},
    {.name = "nvmlDeviceGetTopologyCommonAncestor"},
    {.name = "nvmlDeviceGetTopologyNearestGpus"},
    {.name = "nvmlDeviceGetTotalEccErrors"},
    {.name = "nvmlDeviceGetTotalEnergyConsumption"},
    {.name = "nvmlDeviceGetUtilizationRates"},
    {.name = "nvmlDeviceGetUUID"},
    {.name = "nvmlDeviceGetVbiosVersion"},
    {.name = "nvmlDeviceGetVgpuMetadata"},
    {.name = "nvmlDeviceGetVgpuProcessUtilization"},
    {.name = "nvmlDeviceGetVgpuUtilization"},
    {.name = "nvmlDeviceGetViolationStatus"},
    {.name = "nvmlDeviceGetVirtualizationMode"},
    {.name = "nvmlDeviceModifyDrainState"},
    {.name = "nvmlDeviceOnSameBoard"},
    {.name = "nvmlDeviceQueryDrainState"},
    {.name = "nvmlDeviceRegisterEvents"},
    {.name = "nvmlDeviceRemoveGpu"},
    {.name = "nvmlDeviceRemoveGpu_v2"},
    {.name = "nvmlDeviceResetApplicationsClocks"},
    {.name = "nvmlDeviceResetNvLinkErrorCounters"},
    {.name = "nvmlDeviceResetNvLinkUtilizationCounter"},
    {.name = "nvmlDeviceSetAccountingMode"},
    {.name = "nvmlDeviceSetAPIRestriction"},
    {.name = "nvmlDeviceSetApplicationsClocks"},
    {.name = "nvmlDeviceSetAutoBoostedClocksEnabled"},
    /** We hijack this call*/
    {.name = "nvmlDeviceSetComputeMode"},
    {.name = "nvmlDeviceSetCpuAffinity"},
    {.name = "nvmlDeviceSetDefaultAutoBoostedClocksEnabled"},
    {.name = "nvmlDeviceSetDriverModel"},
    {.name = "nvmlDeviceSetEccMode"},
    {.name = "nvmlDeviceSetGpuOperationMode"},
    {.name = "nvmlDeviceSetNvLinkUtilizationControl"},
    {.name = "nvmlDeviceSetPersistenceMode"},
    {.name = "nvmlDeviceSetPowerManagementLimit"},
    {.name = "nvmlDeviceSetVirtualizationMode"},
    {.name = "nvmlDeviceValidateInforom"},
    {.name = "nvmlEventSetCreate"},
    {.name = "nvmlEventSetFree"},
    {.name = "nvmlEventSetWait"},
    {.name = "nvmlGetVgpuCompatibility"},
    {.name = "nvmlInit_v2"},
    {.name = "nvmlInitWithFlags"},
    {.name = "nvmlInternalGetExportTable"},
    {.name = "nvmlSystemGetCudaDriverVersion"},
    {.name = "nvmlSystemGetCudaDriverVersion_v2"},
    {.name = "nvmlSystemGetDriverVersion"},
    {.name = "nvmlSystemGetHicVersion"},
    {.name = "nvmlSystemGetNVMLVersion"},
    {.name = "nvmlSystemGetProcessName"},
    {.name = "nvmlSystemGetTopologyGpuSet"},
    {.name = "nvmlUnitGetCount"},
    {.name = "nvmlUnitGetDevices"},
    {.name = "nvmlUnitGetFanSpeedInfo"},
    {.name = "nvmlUnitGetHandleByIndex"},
    {.name = "nvmlUnitGetLedState"},
    {.name = "nvmlUnitGetPsuInfo"},
    {.name = "nvmlUnitGetTemperature"},
    {.name = "nvmlUnitGetUnitInfo"},
    {.name = "nvmlUnitSetLedState"},
    {.name = "nvmlVgpuInstanceGetEncoderCapacity"},
    {.name = "nvmlVgpuInstanceGetEncoderSessions"},
    {.name = "nvmlVgpuInstanceGetEncoderStats"},
    {.name = "nvmlVgpuInstanceGetFbUsage"},
    {.name = "nvmlVgpuInstanceGetFrameRateLimit"},
    {.name = "nvmlVgpuInstanceGetLicenseStatus"},
    {.name = "nvmlVgpuInstanceGetMetadata"},
    {.name = "nvmlVgpuInstanceGetType"},
    {.name = "nvmlVgpuInstanceGetUUID"},
    {.name = "nvmlVgpuInstanceGetVmDriverVersion"},
    {.name = "nvmlVgpuInstanceGetVmID"},
    {.name = "nvmlVgpuInstanceSetEncoderCapacity"},
    {.name = "nvmlVgpuTypeGetClass"},
    {.name = "nvmlVgpuTypeGetDeviceID"},
    {.name = "nvmlVgpuTypeGetFramebufferSize"},
    {.name = "nvmlVgpuTypeGetFrameRateLimit"},
    {.name = "nvmlVgpuTypeGetLicense"},
    {.name = "nvmlVgpuTypeGetMaxInstances"},
    {.name = "nvmlVgpuTypeGetName"},
    {.name = "nvmlVgpuTypeGetNumDisplayHeads"},
    {.name = "nvmlVgpuTypeGetResolution"},
    {.name = "nvmlDeviceGetFBCSessions"},
    {.name = "nvmlDeviceGetFBCStats"},
    {.name = "nvmlDeviceGetGridLicensableFeatures_v2"},
    {.name = "nvmlDeviceGetRetiredPages_v2"},
    {.name = "nvmlDeviceResetGpuLockedClocks"},
    {.name = "nvmlDeviceSetGpuLockedClocks"},
    {.name = "nvmlGetBlacklistDeviceCount"},
    {.name = "nvmlGetBlacklistDeviceInfoByIndex"},
    {.name = "nvmlVgpuInstanceGetAccountingMode"},
    {.name = "nvmlVgpuInstanceGetAccountingPids"},
    {.name = "nvmlVgpuInstanceGetAccountingStats"},
    {.name = "nvmlVgpuInstanceGetFBCSessions"},
    {.name = "nvmlVgpuInstanceGetFBCStats"},
    {.name = "nvmlVgpuTypeGetMaxInstancesPerVm"},
    {.name = "nvmlGetVgpuVersion"},
    {.name = "nvmlSetVgpuVersion"},
    {.name = "nvmlDeviceGetGridLicensableFeatures_v3"},
    {.name = "nvmlDeviceGetHostVgpuMode"},
    {.name = "nvmlDeviceGetPgpuMetadataString"},
    {.name = "nvmlVgpuInstanceGetEccMode"},
    {.name = "nvmlComputeInstanceDestroy"},
    {.name = "nvmlComputeInstanceGetInfo"},
    {.name = "nvmlDeviceCreateGpuInstance"},
    {.name = "nvmlDeviceGetArchitecture"},
    {.name = "nvmlDeviceGetAttributes"},
    {.name = "nvmlDeviceGetAttributes_v2"},
    {.name = "nvmlDeviceGetComputeInstanceId"},
    {.name = "nvmlDeviceGetCpuAffinityWithinScope"},
    {.name = "nvmlDeviceGetDeviceHandleFromMigDeviceHandle"},
    {.name = "nvmlDeviceGetGpuInstanceById"},
    {.name = "nvmlDeviceGetGpuInstanceId"},
    {.name = "nvmlDeviceGetGpuInstancePossiblePlacements"},
    {.name = "nvmlDeviceGetGpuInstanceProfileInfo"},
    {.name = "nvmlDeviceGetGpuInstanceRemainingCapacity"},
    {.name = "nvmlDeviceGetGpuInstances"},
    {.name = "nvmlDeviceGetMaxMigDeviceCount"},
    {.name = "nvmlDeviceGetMemoryAffinity"},
    {.name = "nvmlDeviceGetMigDeviceHandleByIndex"},
    {.name = "nvmlDeviceGetMigMode"},
    {.name = "nvmlDeviceGetRemappedRows"},
    {.name = "nvmlDeviceGetRowRemapperHistogram"},
    {.name = "nvmlDeviceIsMigDeviceHandle"},
    {.name = "nvmlDeviceSetMigMode"},
    {.name = "nvmlEventSetWait_v2"},
    {.name = "nvmlGpuInstanceCreateComputeInstance"},
    {.name = "nvmlGpuInstanceDestroy"},
    {.name = "nvmlGpuInstanceGetComputeInstanceById"},
    {.name = "nvmlGpuInstanceGetComputeInstanceProfileInfo"},
    {.name = "nvmlGpuInstanceGetComputeInstanceRemainingCapacity"},
    {.name = "nvmlGpuInstanceGetComputeInstances"},
    {.name = "nvmlGpuInstanceGetInfo"},
    {.name = "nvmlVgpuInstanceClearAccountingPids"},
    {.name = "nvmlVgpuInstanceGetMdevUUID"},
    {.name = "nvmlComputeInstanceGetInfo_v2"},
    {.name = "nvmlDeviceGetComputeRunningProcesses_v2"},
    {.name = "nvmlDeviceGetGraphicsRunningProcesses_v2"},
    {.name = "nvmlDeviceSetTemperatureThreshold"},
    {.name = "nvmlRetry_NvRmControl"},
    {.name = "nvmlVgpuInstanceGetGpuInstanceId"},
    {.name = "nvmlVgpuTypeGetGpuInstanceProfileId"},
    {.name = "nvmlDeviceCreateGpuInstanceWithPlacement"},
    {.name = "nvmlDeviceGetBusType"},
    {.name = "nvmlDeviceGetClkMonStatus"},
    {.name = "nvmlDeviceGetGpuInstancePossiblePlacements_v2"},
    {.name = "nvmlDeviceGetGridLicensableFeatures_v4"},
    {.name = "nvmlDeviceGetIrqNum"},
    {.name = "nvmlDeviceGetMPSComputeRunningProcesses_v2"},
    {.name = "nvmlDeviceGetNvLinkRemoteDeviceType"},
    {.name = "nvmlDeviceResetMemoryLockedClocks"},
    {.name = "nvmlDeviceSetMemoryLockedClocks"},
    {.name = "nvmlGetExcludedDeviceCount"},
    {.name = "nvmlGetExcludedDeviceInfoByIndex"},
    {.name = "nvmlVgpuInstanceGetLicenseInfo"},
};

static void UNUSED bug_on() {
  BUILD_BUG_ON((sizeof(nvml_library_entry) / sizeof(nvml_library_entry[0])) !=
               NVML_ENTRY_END);

  BUILD_BUG_ON((sizeof(cuda_library_entry) / sizeof(cuda_library_entry[0])) !=
               CUDA_ENTRY_END);
}

/** register once set */
static pthread_once_t g_cuda_set = PTHREAD_ONCE_INIT;
static pthread_once_t g_driver_set = PTHREAD_ONCE_INIT;

resource_data_t g_vcuda_config = {
    .pod_uid = "",
    .limit = 0,
    .container_name = "",
    .utilization = 0,
    .gpu_memory = 0,
    .enable = 1,
};

static char base_dir[FILENAME_MAX] = EMPTY_PREFIX;
char config_path[FILENAME_MAX] = CONTROLLER_CONFIG_PATH;
char pid_path[FILENAME_MAX] = PIDS_CONFIG_PATH;
char driver_version[FILENAME_MAX] = "";
int cgroupVersion = 0;

static void load_driver_libraries() {
  void *table = NULL;
  char driver_filename[FILENAME_MAX];
  int i;

  snprintf(driver_filename, FILENAME_MAX - 1, "%s.%s", DRIVER_ML_LIBRARY_PREFIX,
           driver_version);
  driver_filename[FILENAME_MAX - 1] = '\0';

  table = dlopen(driver_filename, RTLD_NOW | RTLD_NODELETE);
  if (unlikely(!table)) {
    LOGGER(FATAL, "can't find library %s", driver_filename);
  }

  for (i = 0; i < NVML_ENTRY_END; i++) {
    nvml_library_entry[i].fn_ptr = dlsym(table, nvml_library_entry[i].name);
    if (unlikely(!nvml_library_entry[i].fn_ptr)) {
      LOGGER(4, "can't find function %s in %s", nvml_library_entry[i].name,
             driver_filename);
    }
  }

  dlclose(table);

  // Initialize the ml driver
  if (NVML_FIND_ENTRY(nvml_library_entry, nvmlInitWithFlags)) {
    NVML_ENTRY_CALL(nvml_library_entry, nvmlInitWithFlags, 0);
  } else if (NVML_FIND_ENTRY(nvml_library_entry, nvmlInit_v2)) {
    NVML_ENTRY_CALL(nvml_library_entry, nvmlInit_v2);
  } else {
    NVML_ENTRY_CALL(nvml_library_entry, nvmlInit);
  }
}

static void load_cuda_single_library(int idx) {
  void *table = NULL;
  char cuda_filename[FILENAME_MAX];

  snprintf(cuda_filename, FILENAME_MAX - 1, "%s.%s", CUDA_LIBRARY_PREFIX,
           driver_version);
  cuda_filename[FILENAME_MAX - 1] = '\0';

  table = dlopen(cuda_filename, RTLD_NOW | RTLD_NODELETE);
  if (unlikely(!table)) {
    LOGGER(FATAL, "can't find library %s", cuda_filename);
  }

  cuda_library_entry[idx].fn_ptr = dlsym(table, cuda_library_entry[idx].name);
  if (unlikely(!cuda_library_entry[idx].fn_ptr)) {
    LOGGER(4, "can't find function %s in %s", cuda_library_entry[idx].name,
           cuda_filename);
  }

  dlclose(table);
}

void load_cuda_libraries() {
  void *table = NULL;
  int i = 0;
  char cuda_filename[FILENAME_MAX];

  LOGGER(4, "Start hijacking");

  snprintf(cuda_filename, FILENAME_MAX - 1, "%s.%s", CUDA_LIBRARY_PREFIX,
           driver_version);
  cuda_filename[FILENAME_MAX - 1] = '\0';
  cuda_filename[FILENAME_MAX - 1] = '\0';

  table = dlopen(cuda_filename, RTLD_NOW | RTLD_NODELETE);
  if (unlikely(!table)) {
    LOGGER(FATAL, "can't find library %s", cuda_filename);
  }

  for (i = 0; i < CUDA_ENTRY_END; i++) {
    cuda_library_entry[i].fn_ptr = dlsym(table, cuda_library_entry[i].name);
    if (unlikely(!cuda_library_entry[i].fn_ptr)) {
      LOGGER(4, "can't find function %s in %s", cuda_library_entry[i].name,
             cuda_filename);
    }
  }

  dlclose(table);
}

int getStr(const char *buffer, const char *prefixstr, const char *endstr, char *poduid, char *podName){
        size_t length = 0;
        char *start;
        char *end;
        char *nameEnd;

        start = strstr(buffer, prefixstr);
        end = strstr(buffer, endstr);
        if (start == NULL || end == NULL)
            return 0;
        length = end - (start + strlen(prefixstr));
        strncpy(poduid, start + strlen(prefixstr), length);
        poduid[length] = '\0';
        end += strlen(endstr);
        nameEnd = strchr(end, '/');
        length = nameEnd -end;
        strncpy(podName, end, length);
        podName[length] = '\0';

        return 1;
}

// #lizard forgives
int get_cgroupV2_data(const char *pid_cgroup, char *pod_uid, char *container_id,
                    size_t size, char *pod_name) {
  
  char *prefix_pod = "/var/lib/kubelet/pods/";
  char *end_pod = "/containers/";
  //char *fakeContainer_id = "fakeContainerId";

  int ret = 1;
  FILE *cgroup_fd = NULL;
  char buffer[4096];
  
  cgroup_fd = fopen(pid_cgroup, "r");
  if (unlikely(!cgroup_fd)) {
    LOGGER(4, "can't open %s, error %s", pid_cgroup, strerror(errno));
    goto DONE;
  }
  while (!feof(cgroup_fd)){
    buffer[0] = '\0';
    if (fgets(buffer, sizeof(buffer), cgroup_fd) != NULL)
    {
      
    }

    if (getStr(buffer, prefix_pod, end_pod, pod_uid, pod_name)) {
      //strncpy(container_id, fakeContainer_id, strlen(fakeContainer_id));
      //container_id[strlen(fakeContainer_id)] = '\0';
      break;
    }
  }


  ret = 0;
DONE:
  if (cgroup_fd) {
    fclose(cgroup_fd);
  }
  return ret;
}

int get_cgroup_data(const char *pid_cgroup, char *pod_uid, char *container_id,
                    size_t size) {
  int ret = 1;
  FILE *cgroup_fd = NULL;
  char *token = NULL, *last_ptr = NULL, *last_second = NULL;
  char *cgroup_ptr = NULL;
  char buffer[4096];
  int is_systemd = 0;
  char *prune_pos = NULL;

  cgroup_fd = fopen(pid_cgroup, "r");
  if (unlikely(!cgroup_fd)) {
    LOGGER(4, "can't open %s, error %s", pid_cgroup, strerror(errno));
    goto DONE;
  }

  /**
   * find memory cgroup name
   */
  while (!feof(cgroup_fd)) {
    buffer[0] = '\0';
    if (unlikely(!fgets(buffer, sizeof(buffer), cgroup_fd))) {
      LOGGER(4, "can't get line from %s", pid_cgroup);
      goto DONE;
    }

    buffer[strlen(buffer) - 1] = '\0';

    last_ptr = NULL;
    token = buffer;
    for (token = strtok_r(token, ":", &last_ptr); token;
         token = NULL, token = strtok_r(token, ":", &last_ptr)) {
      if (!strcmp(token, "memory")) {
        cgroup_ptr = strtok_r(NULL, ":", &last_ptr);
        break;
      }
    }

    if (cgroup_ptr) {
      break;
    }
  }

  if (!cgroup_ptr) {
    LOGGER(4, "can't find memory cgroup from %s", pid_cgroup);
    goto DONE;
  }

  /**
   * find container id
   */
  last_ptr = NULL;
  last_second = NULL;
  token = cgroup_ptr;
  while (*token) {
    if (*token == '/') {
      last_second = last_ptr;
      last_ptr = token;
    }
    ++token;
  }

  if (!last_ptr) {
    goto DONE;
  }

  strncpy(container_id, last_ptr + 1, size);
  container_id[size - 1] = '\0';

  /**
   * if cgroup is systemd, cgroup pattern should be like
   * /kubepods.slice/kubepods-besteffort.slice/kubepods-besteffort-pod27882189_b4d9_11e9_b287_ec0d9ae89a20.slice/docker-4aa615892ab2a014d52178bdf3da1c4a45c8ddfb5171dd6e39dc910f96693e14.scope
   * /kubepods.slice/kubepods-pod019c1fe8_0d92_4aa0_b61c_4df58bdde71c.slice/cri-containerd-9e073649debeec6d511391c9ec7627ee67ce3a3fb508b0fa0437a97f8e58ba98.scope
   */
  if ((prune_pos = strstr(container_id, ".scope"))) {
    is_systemd = 1;
    *prune_pos = '\0';
  }

  /**
   * find pod uid
   */
  *last_ptr = '\0';
  if (!last_second) {
    goto DONE;
  }

  strncpy(pod_uid, last_second, size);
  pod_uid[size - 1] = '\0';

  if (is_systemd && (prune_pos = strstr(pod_uid, ".slice"))) {
    *prune_pos = '\0';
  }

  /**
   * remove unnecessary chars from $container_id and $pod_uid
   */
  if (is_systemd) {
    /**
     * For this kind of cgroup path, we need to find the last appearance of
     * slash
     * /kubepods.slice/kubepods-pod019c1fe8_0d92_4aa0_b61c_4df58bdde71c.slice/cri-containerd-9e073649debeec6d511391c9ec7627ee67ce3a3fb508b0fa0437a97f8e58ba98.scope
     */
    prune_pos = NULL;
    token = container_id;
    while (*token) {
      if (*token == '-') {
        prune_pos = token;
      }
      ++token;
    }

    if (!prune_pos) {
      LOGGER(4, "no - prefix");
      goto DONE;
    }

    memmove(container_id, prune_pos + 1, strlen(container_id));

    prune_pos = strstr(pod_uid, "-pod");
    if (!prune_pos) {
      LOGGER(4, "no pod string");
      goto DONE;
    }
    prune_pos += strlen("-pod");
    memmove(pod_uid, prune_pos, strlen(prune_pos));
    pod_uid[strlen(prune_pos)] = '\0';
    prune_pos = pod_uid;
    while (*prune_pos) {
      if (*prune_pos == '_') {
        *prune_pos = '-';
      }
      ++prune_pos;
    }
  } else {
    memmove(pod_uid, pod_uid + strlen("/pod"), strlen(pod_uid));
  }

  ret = 0;
DONE:
  if (cgroup_fd) {
    fclose(cgroup_fd);
  }
  return ret;
}

static int get_path_by_cgroup(const char *pid_cgroup) {
  int ret = 1;
  char pod_uid[4096], container_id[4096], cont_name[4096];

  cont_name[0] = '\0';

  if (is_custom_config_path()) {
    return 0;
  }

  if (cgroupVersion){
    if (unlikely(get_cgroupV2_data(pid_cgroup, pod_uid, container_id,
                               sizeof(container_id), cont_name))) {
    LOGGER(4, "can't find container id from %s", pid_cgroup);
    goto DONE;
    }
    snprintf(base_dir, sizeof(base_dir), "%s%s", VCUDA_CONFIG_PATH, cont_name);
    snprintf(config_path, sizeof(config_path), "%s/%s", base_dir,
           CONTROLLER_CONFIG_NAME);
    snprintf(pid_path, sizeof(pid_path), "%s/%s", base_dir, PIDS_CONFIG_NAME);
  }
  else{
    if (unlikely(get_cgroup_data(pid_cgroup, pod_uid, container_id,
                               sizeof(container_id)))) {
    LOGGER(4, "can't find container id from %s", pid_cgroup);
    goto DONE;
    }
    snprintf(base_dir, sizeof(base_dir), "%s%s", VCUDA_CONFIG_PATH, container_id);
    snprintf(config_path, sizeof(config_path), "%s/%s", base_dir,
           CONTROLLER_CONFIG_NAME);
    snprintf(pid_path, sizeof(pid_path), "%s/%s", base_dir, PIDS_CONFIG_NAME);
  }



  LOGGER(4, "config file: %s", config_path);
  LOGGER(4, "pid file: %s", pid_path);
  ret = 0;

  LOGGER(4, "register to remote: pod uid: %s, cont id: %s", pod_uid,
         container_id);
  register_to_remote_with_data("", pod_uid, container_id, cont_name);
DONE:
  return ret;
}

static int is_default_config_path() {
  int fd = -1;

  fd = open(config_path, O_RDONLY);
  if (fd == -1) {
    return 0;
  }

  close(fd);

  return 1;
}

static void matchRegex(const char *pattern, const char *matchString,
                       char *version) {
  regex_t regex;
  int reti;
  regmatch_t matches[1];
  char msgbuf[512];

  reti = regcomp(&regex, pattern, REG_EXTENDED);
  if (reti) {
    LOGGER(4, "Could not compile regex: %s", DRIVER_VERSION_MATCH_PATTERN);
    return;
  }

  reti = regexec(&regex, matchString, 1, matches, 0);
  switch (reti) {
  case 0:
    strncpy(version, matchString + matches[0].rm_so,
            matches[0].rm_eo - matches[0].rm_so);
    version[matches[0].rm_eo - matches[0].rm_so] = '\0';
    break;
  case REG_NOMATCH:
    LOGGER(4, "Regex does not match for string: %s", matchString);
    break;
  default:
    regerror(reti, &regex, msgbuf, sizeof(msgbuf));
    LOGGER(4, "Regex match failed: %s", msgbuf);
  }

  regfree(&regex);
  return;
}

static void read_version_from_proc(char *version) {
  char *line = NULL;
  size_t len = 0;

  FILE *fp = fopen(DRIVER_VERSION_PROC_PATH, "r");
  if (fp == NULL) {
    LOGGER(4, "can't open %s, error %s", DRIVER_VERSION_PROC_PATH,
           strerror(errno));
    return;
  }

  while ((getline(&line, &len, fp) != -1)) {
    if (strncmp(line, "NVRM", 4) == 0) {
      matchRegex(DRIVER_VERSION_MATCH_PATTERN, line, version);
      break;
    }
  }
  fclose(fp);
}

int checkCgroupVersion(){
  FILE *fp;
  char buffer[4096];
  char *check;
   
   // 执行 shell 命令 "mount | grep cgroup" 并打开其输出
  fp = popen("mount | grep cgroup", "r");
  if (unlikely(!fp)) {
    LOGGER(4, "popen error");
  }
  
  // 读取并打印输出内容
  while (fgets(buffer, sizeof(buffer), fp) != NULL) {
      check = strstr(buffer, "/sys/fs/cgroup/memory");
      if (check != NULL){
          cgroupVersion = 0;
          pclose(fp);
          return 0;
      }
  }
  // 关闭文件指针
  pclose(fp);
  cgroupVersion = 1;

  return 1;
}

int read_controller_configuration() {
  int fd = 0;
  int rsize;
  int ret = 1;

  if (!is_default_config_path()) {
    if (checkCgroupVersion()){
      if (get_path_by_cgroup("/proc/self/mountinfo")) {
        LOGGER(FATAL, "can't get config file path");
      }
    }
    else{
      if (get_path_by_cgroup("/proc/self/cgroup")) {
        LOGGER(FATAL, "can't get config file path");
      }
    }
  }

  fd = open(config_path, O_RDONLY);
  if (unlikely(fd == -1)) {
    LOGGER(4, "can't open %s, error %s", config_path, strerror(errno));
    goto DONE;
  }

  rsize = (int)read(fd, (void *)&g_vcuda_config, sizeof(resource_data_t));
  if (unlikely(rsize != sizeof(g_vcuda_config))) {
    LOGGER(4, "can't read %s, need %zu but got %d", CONTROLLER_CONFIG_PATH,
           sizeof(resource_data_t), rsize);
    goto DONE;
  }

  read_version_from_proc(driver_version);
  ret = 0;

  LOGGER(4, "pod uid          : %s", g_vcuda_config.pod_uid);
  LOGGER(4, "limit            : %d", g_vcuda_config.limit);
  LOGGER(4, "container name   : %s", g_vcuda_config.container_name);
  LOGGER(4, "total utilization: %d", g_vcuda_config.utilization);
  LOGGER(4, "total gpu memory : %" PRIu64, g_vcuda_config.gpu_memory);
  LOGGER(4, "driver version   : %s", driver_version);
  LOGGER(4, "hard limit mode  : %d", g_vcuda_config.hard_limit);
  LOGGER(4, "enable mode      : %d", g_vcuda_config.enable);
DONE:
  if (likely(fd)) {
    close(fd);
  }

  return ret;
}

void load_necessary_data() {
  read_controller_configuration();
  load_cuda_single_library(CUDA_ENTRY_ENUM(cuDriverGetVersion));

  pthread_once(&g_cuda_set, load_cuda_libraries);
  pthread_once(&g_driver_set, load_driver_libraries);
}

int is_custom_config_path() { return strcmp(base_dir, EMPTY_PREFIX) != 0; }
