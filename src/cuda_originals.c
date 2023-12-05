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

//
// Created by thomas on 18-4-16.
//
#include <assert.h>

#include "include/cuda-helper.h"
#include "include/hijack.h"
#include <stdio.h>

extern entry_t cuda_library_entry[];



CUresult CUDAAPI cuGetErrorString(CUresult error, const char **pStr) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGetErrorString, error, pStr);
}

CUresult CUDAAPI cuGetErrorName(CUresult error, const char **pStr) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGetErrorName, error, pStr);
}


CUresult CUDAAPI cuDeviceGet(CUdevice *device, int ordinal) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGet, device, ordinal);
}

CUresult CUDAAPI cuDeviceGetCount(int *count) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetCount, count);
}

CUresult CUDAAPI cuDeviceGetName(char *name, int len, CUdevice dev) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetName, name, len, dev);
}

CUresult CUDAAPI cuDeviceGetUuid(CUuuid *uuid, CUdevice dev) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetUuid, uuid, dev);
}

CUresult CUDAAPI cuDeviceGetUuid_v2(CUuuid *uuid, CUdevice dev) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetUuid_v2, uuid, dev);
}

CUresult CUDAAPI cuDeviceGetLuid(char *luid, unsigned int *deviceNodeMask, CUdevice dev) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetLuid, luid, deviceNodeMask, dev);
}


CUresult CUDAAPI cuDeviceGetTexture1DLinearMaxWidth(size_t *maxWidthInElements, CUarray_format format, unsigned numChannels, CUdevice dev) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetTexture1DLinearMaxWidth, maxWidthInElements, format, numChannels, dev);
}

CUresult CUDAAPI cuDeviceGetAttribute(int *pi, CUdevice_attribute attrib, CUdevice dev) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetAttribute, pi, attrib, dev);
}

CUresult CUDAAPI cuDeviceGetNvSciSyncAttributes(void *nvSciSyncAttrList, CUdevice dev, int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetNvSciSyncAttributes, nvSciSyncAttrList, dev, flags);
}

CUresult CUDAAPI cuDeviceSetMemPool(CUdevice dev, CUmemoryPool pool) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceSetMemPool, dev, pool);
}

CUresult CUDAAPI cuDeviceGetMemPool(CUmemoryPool *pool, CUdevice dev) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetMemPool, pool, dev);
}

CUresult CUDAAPI cuDeviceGetDefaultMemPool(CUmemoryPool *pool_out, CUdevice dev) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetDefaultMemPool, pool_out, dev);
}

CUresult CUDAAPI cuFlushGPUDirectRDMAWrites(CUflushGPUDirectRDMAWritesTarget target, CUflushGPUDirectRDMAWritesScope scope) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuFlushGPUDirectRDMAWrites, target, scope);
}

__CUDA_DEPRECATED CUresult CUDAAPI cuDeviceGetProperties(CUdevprop *prop, CUdevice dev) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetProperties, prop, dev);
}

__CUDA_DEPRECATED CUresult CUDAAPI cuDeviceComputeCapability(int *major, int *minor, CUdevice dev) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceComputeCapability, major, minor, dev);
}


CUresult CUDAAPI cuDevicePrimaryCtxRetain(CUcontext *pctx, CUdevice dev) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDevicePrimaryCtxRetain, pctx, dev);
}

CUresult CUDAAPI cuDevicePrimaryCtxRelease(CUdevice dev) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDevicePrimaryCtxRelease, dev);
}

CUresult CUDAAPI cuDevicePrimaryCtxSetFlags(CUdevice dev, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDevicePrimaryCtxSetFlags, dev, flags);
}

CUresult CUDAAPI cuDevicePrimaryCtxGetState(CUdevice dev, unsigned int *flags, int *active) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDevicePrimaryCtxGetState, dev, flags, active);
}

CUresult CUDAAPI cuDevicePrimaryCtxReset(CUdevice dev) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDevicePrimaryCtxReset, dev);
}

CUresult CUDAAPI cuDeviceGetExecAffinitySupport(int *pi, CUexecAffinityType type, CUdevice dev) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetExecAffinitySupport, pi, type, dev);
}

CUresult CUDAAPI cuCtxCreate(CUcontext *pctx, unsigned int flags, CUdevice dev) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxCreate, pctx, flags, dev);
}

CUresult CUDAAPI cuCtxCreate_v3(CUcontext *pctx, CUexecAffinityParam *paramsArray, int numParams, unsigned int flags, CUdevice dev) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxCreate_v3, pctx, paramsArray, numParams, flags, dev);
}

CUresult CUDAAPI cuCtxDestroy(CUcontext ctx) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxDestroy, ctx);
}

CUresult CUDAAPI cuCtxPushCurrent(CUcontext ctx) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxPushCurrent, ctx);
}

CUresult CUDAAPI cuCtxPopCurrent(CUcontext *pctx) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxPopCurrent, pctx);
}

CUresult CUDAAPI cuCtxSetCurrent(CUcontext ctx) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxSetCurrent, ctx);
}

CUresult CUDAAPI cuCtxGetCurrent(CUcontext *pctx) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetCurrent, pctx);
}

CUresult CUDAAPI cuCtxGetDevice(CUdevice *device) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetDevice, device);
}

CUresult CUDAAPI cuCtxGetFlags(unsigned int *flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetFlags, flags);
}

CUresult CUDAAPI cuCtxSynchronize(void) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxSynchronize);
}

CUresult CUDAAPI cuCtxSetLimit(CUlimit limit, size_t value) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxSetLimit, limit, value);
}

CUresult CUDAAPI cuCtxGetLimit(size_t *pvalue, CUlimit limit) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetLimit, pvalue, limit);
}

CUresult CUDAAPI cuCtxGetCacheConfig(CUfunc_cache *pconfig) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetCacheConfig, pconfig);
}

CUresult CUDAAPI cuCtxSetCacheConfig(CUfunc_cache config) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxSetCacheConfig, config);
}

CUresult CUDAAPI cuCtxGetSharedMemConfig(CUsharedconfig *pConfig) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetSharedMemConfig, pConfig);
}

CUresult CUDAAPI cuCtxSetSharedMemConfig(CUsharedconfig config) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxSetSharedMemConfig, config);
}

CUresult CUDAAPI cuCtxGetApiVersion(CUcontext ctx, unsigned int *version) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetApiVersion, ctx, version);
}

CUresult CUDAAPI cuCtxGetStreamPriorityRange(int *leastPriority, int *greatestPriority) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetStreamPriorityRange, leastPriority, greatestPriority);
}

CUresult CUDAAPI cuCtxResetPersistingL2Cache(void) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxResetPersistingL2Cache);
}

CUresult CUDAAPI cuCtxGetExecAffinity(CUexecAffinityParam *pExecAffinity, CUexecAffinityType type) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetExecAffinity, pExecAffinity, type);
}

__CUDA_DEPRECATED CUresult CUDAAPI cuCtxAttach(CUcontext *pctx, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxAttach, pctx, flags);
}

__CUDA_DEPRECATED CUresult CUDAAPI cuCtxDetach(CUcontext ctx) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxDetach, ctx);
}

CUresult CUDAAPI cuModuleLoad(CUmodule *module, const char *fname) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleLoad, module, fname);
}

CUresult CUDAAPI cuModuleLoadData(CUmodule *module, const void *image) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleLoadData, module, image);
}

CUresult CUDAAPI cuModuleLoadDataEx(CUmodule *module, const void *image, unsigned int numOptions, CUjit_option *options, void **optionValues) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleLoadDataEx, module, image, numOptions, options, optionValues);
}

CUresult CUDAAPI cuModuleLoadFatBinary(CUmodule *module, const void *fatCubin) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleLoadFatBinary, module, fatCubin);
}

CUresult CUDAAPI cuModuleUnload(CUmodule hmod) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleUnload, hmod);
}

CUresult CUDAAPI cuModuleGetFunction(CUfunction *hfunc, CUmodule hmod, const char *name) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleGetFunction, hfunc, hmod, name);
}

CUresult CUDAAPI cuModuleGetGlobal(CUdeviceptr *dptr, size_t *bytes, CUmodule hmod, const char *name) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleGetGlobal, dptr, bytes, hmod, name);
}

CUresult CUDAAPI cuModuleGetTexRef(CUtexref *pTexRef, CUmodule hmod, const char *name) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleGetTexRef, pTexRef, hmod, name);
}

CUresult CUDAAPI cuModuleGetSurfRef(CUsurfref *pSurfRef, CUmodule hmod, const char *name) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleGetSurfRef, pSurfRef, hmod, name);
}

CUresult CUDAAPI cuLinkCreate(unsigned int numOptions, CUjit_option *options, void **optionValues, CUlinkState *stateOut) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuLinkCreate, numOptions, options, optionValues, stateOut);
}

CUresult CUDAAPI cuLinkAddData(CUlinkState state, CUjitInputType type, void *data, size_t size, const char *name,
                               unsigned int numOptions, CUjit_option *options, void **optionValues) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuLinkAddData, state, type, data, size, name, numOptions, options, optionValues);
}

CUresult CUDAAPI cuLinkAddFile(CUlinkState state, CUjitInputType type, const char *path,
                               unsigned int numOptions, CUjit_option *options, void **optionValues) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuLinkAddFile, state, type, path, numOptions, options, optionValues);
}

CUresult CUDAAPI cuLinkComplete(CUlinkState state, void **cubinOut, size_t *sizeOut) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuLinkComplete, state, cubinOut, sizeOut);
}

CUresult CUDAAPI cuLinkDestroy(CUlinkState state) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuLinkDestroy, state);
}
/*
CUresult CUDAAPI cuMemAlloc(CUdeviceptr *dptr, size_t bytesize) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemAlloc, dptr, bytesize);
}

CUresult CUDAAPI cuMemAllocPitch(CUdeviceptr *dptr, size_t *pPitch, size_t WidthInBytes, size_t Height, unsigned int ElementSizeBytes) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemAllocPitch, dptr, pPitch, WidthInBytes, Height, ElementSizeBytes);
}
*/
CUresult CUDAAPI cuMemFree(CUdeviceptr dptr) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemFree, dptr);
}

CUresult CUDAAPI cuMemGetAddressRange(CUdeviceptr *pbase, size_t *psize, CUdeviceptr dptr) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemGetAddressRange, pbase, psize, dptr);
}

CUresult CUDAAPI cuMemAllocHost(void **pp, size_t bytesize) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemAllocHost, pp, bytesize);
}

CUresult CUDAAPI cuMemFreeHost(void *p) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemFreeHost, p);
}

CUresult CUDAAPI cuMemHostAlloc(void **pp, size_t bytesize, unsigned int Flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemHostAlloc, pp, bytesize, Flags);
}

CUresult CUDAAPI cuMemHostGetDevicePointer(CUdeviceptr *pdptr, void *p, unsigned int Flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemHostGetDevicePointer, pdptr, p, Flags);
}

CUresult CUDAAPI cuMemHostGetFlags(unsigned int *pFlags, void *p) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemHostGetFlags, pFlags, p);
}
/*
CUresult CUDAAPI cuMemAllocManaged(CUdeviceptr *dptr, size_t bytesize, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemAllocManaged, dptr, bytesize, flags);
}
*/
CUresult CUDAAPI cuDeviceGetByPCIBusId(CUdevice *dev, const char *pciBusId) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetByPCIBusId, dev, pciBusId);
}

CUresult CUDAAPI cuDeviceGetPCIBusId(char *pciBusId, int len, CUdevice dev) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetPCIBusId, pciBusId, len, dev);
}

CUresult CUDAAPI cuIpcGetEventHandle(CUipcEventHandle *pHandle, CUevent event) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuIpcGetEventHandle, pHandle, event);
}

CUresult CUDAAPI cuIpcOpenEventHandle(CUevent *phEvent, CUipcEventHandle handle) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuIpcOpenEventHandle, phEvent, handle);
}

CUresult CUDAAPI cuIpcGetMemHandle(CUipcMemHandle *pHandle, CUdeviceptr dptr) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuIpcGetMemHandle, pHandle, dptr);
}

CUresult CUDAAPI cuIpcOpenMemHandle(CUdeviceptr *pdptr, CUipcMemHandle handle, unsigned int Flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuIpcOpenMemHandle, pdptr, handle, Flags);
}

CUresult CUDAAPI cuIpcCloseMemHandle(CUdeviceptr dptr) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuIpcCloseMemHandle, dptr);
}

CUresult CUDAAPI cuMemHostRegister(void *p, size_t bytesize, unsigned int Flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemHostRegister, p, bytesize, Flags);
}

CUresult CUDAAPI cuMemHostUnregister(void *p) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemHostUnregister, p);
}

CUresult CUDAAPI cuMemcpy(CUdeviceptr dst, CUdeviceptr src, size_t ByteCount) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy, dst, src, ByteCount);
}

CUresult CUDAAPI cuMemcpyPeer(CUdeviceptr dstDevice, CUcontext dstContext, CUdeviceptr srcDevice, CUcontext srcContext, size_t ByteCount) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyPeer, dstDevice, dstContext, srcDevice, srcContext, ByteCount);
}

CUresult CUDAAPI cuMemcpyHtoD(CUdeviceptr dstDevice, const void *srcHost, size_t ByteCount) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyHtoD, dstDevice, srcHost, ByteCount);
}

CUresult CUDAAPI cuMemcpyDtoH(void *dstHost, CUdeviceptr srcDevice, size_t ByteCount) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyDtoH, dstHost, srcDevice, ByteCount);
}

CUresult CUDAAPI cuMemcpyDtoD(CUdeviceptr dstDevice, CUdeviceptr srcDevice, size_t ByteCount) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyDtoD, dstDevice, srcDevice, ByteCount);
}

CUresult CUDAAPI cuMemcpyDtoA(CUarray dstArray, size_t dstOffset, CUdeviceptr srcDevice, size_t ByteCount) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyDtoA, dstArray, dstOffset, srcDevice, ByteCount);
}

CUresult CUDAAPI cuMemcpyAtoD(CUdeviceptr dstDevice, CUarray srcArray, size_t srcOffset, size_t ByteCount) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyAtoD, dstDevice, srcArray, srcOffset, ByteCount);
}

CUresult CUDAAPI cuMemcpyHtoA(CUarray dstArray, size_t dstOffset, const void *srcHost, size_t ByteCount) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyHtoA, dstArray, dstOffset, srcHost, ByteCount);
}

CUresult CUDAAPI cuMemcpyAtoH(void *dstHost, CUarray srcArray, size_t srcOffset, size_t ByteCount) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyAtoH, dstHost, srcArray, srcOffset, ByteCount);
}

CUresult CUDAAPI cuMemcpyAtoA(CUarray dstArray, size_t dstOffset, CUarray srcArray, size_t srcOffset, size_t ByteCount) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyAtoA, dstArray, dstOffset, srcArray, srcOffset, ByteCount);
}

CUresult CUDAAPI cuMemcpy2D(const CUDA_MEMCPY2D *pCopy) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy2D, pCopy);
}


CUresult CUDAAPI cuMemcpy2DUnaligned(const CUDA_MEMCPY2D *pCopy) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy2DUnaligned, pCopy);
}

CUresult CUDAAPI cuMemcpy3D(const CUDA_MEMCPY3D *pCopy) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy3D, pCopy);
}

CUresult CUDAAPI cuMemcpy3DPeer(const CUDA_MEMCPY3D_PEER *pCopy) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy3DPeer, pCopy);
}

CUresult CUDAAPI cuMemcpyAsync(CUdeviceptr dst, CUdeviceptr src, size_t ByteCount, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyAsync, dst, src, ByteCount, hStream);
}

CUresult CUDAAPI cuMemcpyPeerAsync(CUdeviceptr dstDevice, CUcontext dstContext, CUdeviceptr srcDevice, CUcontext srcContext, size_t ByteCount, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyPeerAsync, dstDevice, dstContext, srcDevice, srcContext, ByteCount, hStream);
}

CUresult CUDAAPI cuMemcpyHtoDAsync(CUdeviceptr dstDevice, const void *srcHost, size_t ByteCount, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyHtoDAsync, dstDevice, srcHost, ByteCount, hStream);
}

CUresult CUDAAPI cuMemcpyDtoHAsync(void *dstHost, CUdeviceptr srcDevice, size_t ByteCount, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyDtoHAsync, dstHost, srcDevice, ByteCount, hStream);
}

CUresult CUDAAPI cuMemcpyDtoDAsync(CUdeviceptr dstDevice, CUdeviceptr srcDevice, size_t ByteCount, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyDtoDAsync, dstDevice, srcDevice, ByteCount, hStream);
}

CUresult CUDAAPI cuMemcpyHtoAAsync(CUarray dstArray, size_t dstOffset, const void *srcHost, size_t ByteCount, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyHtoAAsync, dstArray, dstOffset, srcHost, ByteCount, hStream);
}

CUresult CUDAAPI cuMemcpyAtoHAsync(void *dstHost, CUarray srcArray, size_t srcOffset, size_t ByteCount, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyAtoHAsync, dstHost, srcArray, srcOffset, ByteCount, hStream);
}

CUresult CUDAAPI cuMemcpy2DAsync(const CUDA_MEMCPY2D *pCopy, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy2DAsync, pCopy, hStream);
}

CUresult CUDAAPI cuMemcpy3DAsync(const CUDA_MEMCPY3D *pCopy, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy3DAsync, pCopy, hStream);
}

CUresult CUDAAPI cuMemcpy3DPeerAsync(const CUDA_MEMCPY3D_PEER *pCopy, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy3DPeerAsync, pCopy, hStream);
}

CUresult CUDAAPI cuMemsetD8(CUdeviceptr dstDevice, unsigned char uc, size_t N) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD8, dstDevice, uc, N);
}

CUresult CUDAAPI cuMemsetD16(CUdeviceptr dstDevice, unsigned short us, size_t N) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD16, dstDevice, us, N);
}

CUresult CUDAAPI cuMemsetD32(CUdeviceptr dstDevice, unsigned int ui, size_t N) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD32, dstDevice, ui, N);
}

CUresult CUDAAPI cuMemsetD2D8(CUdeviceptr dstDevice, size_t dstPitch, unsigned char uc, size_t Width, size_t Height) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD2D8, dstDevice, dstPitch, uc, Width, Height);
}

CUresult CUDAAPI cuMemsetD2D16(CUdeviceptr dstDevice, size_t dstPitch, unsigned short us, size_t Width, size_t Height) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD2D16, dstDevice, dstPitch, us, Width, Height);
}

CUresult CUDAAPI cuMemsetD2D32(CUdeviceptr dstDevice, size_t dstPitch, unsigned int ui, size_t Width, size_t Height) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD2D32, dstDevice, dstPitch, ui, Width, Height);
}

CUresult CUDAAPI cuMemsetD8Async(CUdeviceptr dstDevice, unsigned char uc, size_t N, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD8Async, dstDevice, uc, N, hStream);
}

CUresult CUDAAPI cuMemsetD16Async(CUdeviceptr dstDevice, unsigned short us, size_t N, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD16Async, dstDevice, us, N, hStream);
}

CUresult CUDAAPI cuMemsetD32Async(CUdeviceptr dstDevice, unsigned int ui, size_t N, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD32Async, dstDevice, ui, N, hStream);
}

CUresult CUDAAPI cuMemsetD2D8Async(CUdeviceptr dstDevice, size_t dstPitch, unsigned char uc, size_t Width, size_t Height, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD2D8Async, dstDevice, dstPitch, uc, Width, Height, hStream);
}

CUresult CUDAAPI cuMemsetD2D16Async(CUdeviceptr dstDevice, size_t dstPitch, unsigned short us, size_t Width, size_t Height, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD2D16Async, dstDevice, dstPitch, us, Width, Height, hStream);
}

CUresult CUDAAPI cuMemsetD2D32Async(CUdeviceptr dstDevice, size_t dstPitch, unsigned int ui, size_t Width, size_t Height, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD2D32Async, dstDevice, dstPitch, ui, Width, Height, hStream);
}
/*
CUresult CUDAAPI cuArrayCreate(CUarray *pHandle, const CUDA_ARRAY_DESCRIPTOR *pAllocateArray) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuArrayCreate, pHandle, pAllocateArray);
}
*/
CUresult CUDAAPI cuArrayGetDescriptor(CUDA_ARRAY_DESCRIPTOR *pArrayDescriptor, CUarray hArray) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuArrayGetDescriptor, pArrayDescriptor, hArray);
}

CUresult CUDAAPI cuArrayGetSparseProperties(CUDA_ARRAY_SPARSE_PROPERTIES *sparseProperties, CUarray array) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuArrayGetSparseProperties, sparseProperties, array);
}

CUresult CUDAAPI cuMipmappedArrayGetSparseProperties(CUDA_ARRAY_SPARSE_PROPERTIES *sparseProperties, CUmipmappedArray mipmap) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMipmappedArrayGetSparseProperties, sparseProperties, mipmap);
}

CUresult CUDAAPI cuArrayGetMemoryRequirements(CUDA_ARRAY_MEMORY_REQUIREMENTS *memoryRequirements, CUarray array, CUdevice device) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuArrayGetMemoryRequirements, memoryRequirements, array, device);
}

CUresult CUDAAPI cuMipmappedArrayGetMemoryRequirements(CUDA_ARRAY_MEMORY_REQUIREMENTS *memoryRequirements, CUmipmappedArray mipmap, CUdevice device) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMipmappedArrayGetMemoryRequirements, memoryRequirements, mipmap, device);
}

CUresult CUDAAPI cuArrayGetPlane(CUarray *pPlaneArray, CUarray hArray, unsigned int planeIdx) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuArrayGetPlane, pPlaneArray, hArray, planeIdx);
}

CUresult CUDAAPI cuArrayDestroy(CUarray hArray) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuArrayDestroy, hArray);
}
/*
CUresult CUDAAPI cuArray3DCreate(CUarray *pHandle, const CUDA_ARRAY3D_DESCRIPTOR *pAllocateArray) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuArray3DCreate, pHandle, pAllocateArray);
}
*/
CUresult CUDAAPI cuArray3DGetDescriptor(CUDA_ARRAY3D_DESCRIPTOR *pArrayDescriptor, CUarray hArray) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuArray3DGetDescriptor, pArrayDescriptor, hArray);
}
/*
CUresult CUDAAPI cuMipmappedArrayCreate(CUmipmappedArray *pHandle, const CUDA_ARRAY3D_DESCRIPTOR *pMipmappedArrayDesc, unsigned int numMipmapLevels) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMipmappedArrayCreate, pHandle, pMipmappedArrayDesc, numMipmapLevels);
}
*/
CUresult CUDAAPI cuMipmappedArrayGetLevel(CUarray *pLevelArray, CUmipmappedArray hMipmappedArray, unsigned int level) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMipmappedArrayGetLevel, pLevelArray, hMipmappedArray, level);
}

CUresult CUDAAPI cuMipmappedArrayDestroy(CUmipmappedArray hMipmappedArray) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMipmappedArrayDestroy, hMipmappedArray);
}

CUresult CUDAAPI cuMemAddressReserve(CUdeviceptr *ptr, size_t size, size_t alignment, CUdeviceptr addr, unsigned long long flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemAddressReserve, ptr, size, alignment, addr, flags);
}

CUresult CUDAAPI cuMemAddressFree(CUdeviceptr ptr, size_t size) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemAddressFree, ptr, size);
}

CUresult CUDAAPI cuMemCreate(CUmemGenericAllocationHandle *handle, size_t size, const CUmemAllocationProp *prop, unsigned long long flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemCreate, handle, size, prop, flags);
}

CUresult CUDAAPI cuMemRelease(CUmemGenericAllocationHandle handle) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemRelease, handle);
}

CUresult CUDAAPI cuMemMap(CUdeviceptr ptr, size_t size, size_t offset, CUmemGenericAllocationHandle handle, unsigned long long flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemMap, ptr, size, offset, handle, flags);
}

CUresult CUDAAPI cuMemMapArrayAsync(CUarrayMapInfo *mapInfoList, unsigned int count, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemMapArrayAsync, mapInfoList, count, hStream);
}

CUresult CUDAAPI cuMemUnmap(CUdeviceptr ptr, size_t size) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemUnmap, ptr, size);
}

CUresult CUDAAPI cuMemSetAccess(CUdeviceptr ptr, size_t size, const CUmemAccessDesc *desc, size_t count) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemSetAccess, ptr, size, desc, count);
}

CUresult CUDAAPI cuMemGetAccess(unsigned long long *flags, const CUmemLocation *location, CUdeviceptr ptr) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemGetAccess, flags, location, ptr);
}

CUresult CUDAAPI cuMemExportToShareableHandle(void *shareableHandle, CUmemGenericAllocationHandle handle, CUmemAllocationHandleType handleType, unsigned long long flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemExportToShareableHandle, shareableHandle, handle, handleType, flags);
}

CUresult CUDAAPI cuMemImportFromShareableHandle(CUmemGenericAllocationHandle *handle, void *osHandle, CUmemAllocationHandleType shHandleType) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemImportFromShareableHandle, handle, osHandle, shHandleType);
}

CUresult CUDAAPI cuMemGetAllocationGranularity(size_t *granularity, const CUmemAllocationProp *prop, CUmemAllocationGranularity_flags option) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemGetAllocationGranularity, granularity, prop, option);
}

CUresult CUDAAPI cuMemGetAllocationPropertiesFromHandle(CUmemAllocationProp *prop, CUmemGenericAllocationHandle handle) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemGetAllocationPropertiesFromHandle, prop, handle);
}

CUresult CUDAAPI cuMemRetainAllocationHandle(CUmemGenericAllocationHandle *handle, void *addr) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemRetainAllocationHandle, handle, addr);
}

CUresult CUDAAPI cuMemFreeAsync(CUdeviceptr dptr, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemFreeAsync, dptr, hStream);
}

CUresult CUDAAPI cuMemAllocAsync(CUdeviceptr *dptr, size_t bytesize, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemAllocAsync, dptr, bytesize, hStream);
}

CUresult CUDAAPI cuMemPoolTrimTo(CUmemoryPool pool, size_t minBytesToKeep) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolTrimTo, pool, minBytesToKeep);
}

CUresult CUDAAPI cuMemPoolSetAttribute(CUmemoryPool pool, CUmemPool_attribute attr, void *value) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolSetAttribute, pool, attr, value);
}

CUresult CUDAAPI cuMemPoolGetAttribute(CUmemoryPool pool, CUmemPool_attribute attr, void *value) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolGetAttribute, pool, attr, value);
}

CUresult CUDAAPI cuMemPoolSetAccess(CUmemoryPool pool, const CUmemAccessDesc *map, size_t count) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolSetAccess, pool, map, count);
}

CUresult CUDAAPI cuMemPoolGetAccess(CUmemAccess_flags *flags, CUmemoryPool memPool, CUmemLocation *location) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolGetAccess, flags, memPool, location);
}

CUresult CUDAAPI cuMemPoolCreate(CUmemoryPool *pool, const CUmemPoolProps *poolProps) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolCreate, pool, poolProps);
}

CUresult CUDAAPI cuMemPoolDestroy(CUmemoryPool pool) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolDestroy, pool);
}

CUresult CUDAAPI cuMemAllocFromPoolAsync(CUdeviceptr *dptr, size_t bytesize, CUmemoryPool pool, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemAllocFromPoolAsync, dptr, bytesize, pool, hStream);
}

CUresult CUDAAPI cuMemPoolExportToShareableHandle(void *handle_out, CUmemoryPool pool, CUmemAllocationHandleType handleType, unsigned long long flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolExportToShareableHandle, handle_out, pool, handleType, flags);
}

CUresult CUDAAPI cuMemPoolImportFromShareableHandle(
        CUmemoryPool *pool_out,
        void *handle,
        CUmemAllocationHandleType handleType,
        unsigned long long flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolImportFromShareableHandle, pool_out, handle, handleType, flags);
}

CUresult CUDAAPI cuMemPoolExportPointer(CUmemPoolPtrExportData *shareData_out, CUdeviceptr ptr) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolExportPointer, shareData_out, ptr);
}

CUresult CUDAAPI cuMemPoolImportPointer(CUdeviceptr *ptr_out, CUmemoryPool pool, CUmemPoolPtrExportData *shareData) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolImportPointer, ptr_out, pool, shareData);
}

CUresult CUDAAPI cuPointerGetAttribute(void *data, CUpointer_attribute attribute, CUdeviceptr ptr) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuPointerGetAttribute, data, attribute, ptr);
}

CUresult CUDAAPI cuMemPrefetchAsync(CUdeviceptr devPtr, size_t count, CUdevice dstDevice, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPrefetchAsync, devPtr, count, dstDevice, hStream);
}

CUresult CUDAAPI cuMemAdvise(CUdeviceptr devPtr, size_t count, CUmem_advise advice, CUdevice device) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemAdvise, devPtr, count, advice, device);
}

CUresult CUDAAPI cuMemRangeGetAttribute(void *data, size_t dataSize, CUmem_range_attribute attribute, CUdeviceptr devPtr, size_t count) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemRangeGetAttribute, data, dataSize, attribute, devPtr, count);
}

CUresult CUDAAPI cuMemRangeGetAttributes(void **data, size_t *dataSizes, CUmem_range_attribute *attributes, size_t numAttributes, CUdeviceptr devPtr, size_t count) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemRangeGetAttributes, data, dataSizes, attributes, numAttributes, devPtr, count);
}

CUresult CUDAAPI cuPointerSetAttribute(const void *value, CUpointer_attribute attribute, CUdeviceptr ptr) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuPointerSetAttribute, value, attribute, ptr);
}

CUresult CUDAAPI cuPointerGetAttributes(unsigned int numAttributes, CUpointer_attribute *attributes, void **data, CUdeviceptr ptr) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuPointerGetAttributes, numAttributes, attributes, data, ptr);
}

CUresult CUDAAPI cuStreamCreate(CUstream *phStream, unsigned int Flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamCreate, phStream, Flags);
}

CUresult CUDAAPI cuStreamCreateWithPriority(CUstream *phStream, unsigned int flags, int priority) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamCreateWithPriority, phStream, flags, priority);
}

CUresult CUDAAPI cuStreamGetPriority(CUstream hStream, int *priority) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamGetPriority, hStream, priority);
}

CUresult CUDAAPI cuStreamGetFlags(CUstream hStream, unsigned int *flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamGetFlags, hStream, flags);
}

CUresult CUDAAPI cuStreamGetCtx(CUstream hStream, CUcontext *pctx) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamGetCtx, hStream, pctx);
}

CUresult CUDAAPI cuStreamWaitEvent(CUstream hStream, CUevent hEvent, unsigned int Flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamWaitEvent, hStream, hEvent, Flags);
}

CUresult CUDAAPI cuStreamAddCallback(CUstream hStream, CUstreamCallback callback, void *userData, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamAddCallback, hStream, callback, userData, flags);
}

CUresult CUDAAPI cuStreamBeginCapture(CUstream hStream, CUstreamCaptureMode mode) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamBeginCapture, hStream, mode);
}

CUresult CUDAAPI cuThreadExchangeStreamCaptureMode(CUstreamCaptureMode *mode) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuThreadExchangeStreamCaptureMode, mode);
}

CUresult CUDAAPI cuStreamEndCapture(CUstream hStream, CUgraph *phGraph) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamEndCapture, hStream, phGraph);
}

CUresult CUDAAPI cuStreamIsCapturing(CUstream hStream, CUstreamCaptureStatus *captureStatus) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamIsCapturing, hStream, captureStatus);
}

CUresult CUDAAPI cuStreamGetCaptureInfo(CUstream hStream, CUstreamCaptureStatus *captureStatus_out, cuuint64_t *id_out) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamGetCaptureInfo, hStream, captureStatus_out, id_out);
}

CUresult CUDAAPI cuStreamGetCaptureInfo_v2(CUstream hStream, CUstreamCaptureStatus *captureStatus_out,
                                           cuuint64_t *id_out, CUgraph *graph_out,
                                           const CUgraphNode **dependencies_out, size_t *numDependencies_out) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamGetCaptureInfo_v2, hStream, captureStatus_out,
                           id_out, graph_out, dependencies_out, numDependencies_out);
}

CUresult CUDAAPI cuStreamUpdateCaptureDependencies(CUstream hStream, CUgraphNode *dependencies,
                                                  size_t numDependencies, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamUpdateCaptureDependencies, hStream, dependencies,
                           numDependencies, flags);
}

CUresult CUDAAPI cuStreamAttachMemAsync(CUstream hStream, CUdeviceptr dptr, size_t length, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamAttachMemAsync, hStream, dptr, length, flags);
}

CUresult CUDAAPI cuStreamQuery(CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamQuery, hStream);
}

CUresult CUDAAPI cuStreamSynchronize(CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamSynchronize, hStream);
}

CUresult CUDAAPI cuStreamDestroy(CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamDestroy, hStream);
}

CUresult CUDAAPI cuStreamCopyAttributes(CUstream dst, CUstream src) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamCopyAttributes, dst, src);
}

CUresult CUDAAPI cuStreamGetAttribute(CUstream hStream, CUstreamAttrID attr,
                                      CUstreamAttrValue *value_out) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamGetAttribute, hStream, attr, value_out);
}


CUresult CUDAAPI cuStreamSetAttribute(CUstream hStream, CUstreamAttrID attr, const CUstreamAttrValue *value) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamSetAttribute, hStream, attr, value);
}

CUresult CUDAAPI cuEventCreate(CUevent *phEvent, unsigned int Flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuEventCreate, phEvent, Flags);
}

CUresult CUDAAPI cuEventRecord(CUevent hEvent, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuEventRecord, hEvent, hStream);
}

CUresult CUDAAPI cuEventRecordWithFlags(CUevent hEvent, CUstream hStream, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuEventRecordWithFlags, hEvent, hStream, flags);
}

CUresult CUDAAPI cuEventQuery(CUevent hEvent) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuEventQuery, hEvent);
}

CUresult CUDAAPI cuEventSynchronize(CUevent hEvent) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuEventSynchronize, hEvent);
}

CUresult CUDAAPI cuEventDestroy(CUevent hEvent) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuEventDestroy, hEvent);
}

CUresult CUDAAPI cuEventElapsedTime(float *pMilliseconds, CUevent hStart, CUevent hEnd) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuEventElapsedTime, pMilliseconds, hStart, hEnd);
}

CUresult CUDAAPI cuImportExternalMemory(CUexternalMemory *extMem_out, const CUDA_EXTERNAL_MEMORY_HANDLE_DESC *memHandleDesc) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuImportExternalMemory, extMem_out, memHandleDesc);
}

CUresult CUDAAPI cuExternalMemoryGetMappedBuffer(CUdeviceptr *devPtr, CUexternalMemory extMem, const CUDA_EXTERNAL_MEMORY_BUFFER_DESC *bufferDesc) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuExternalMemoryGetMappedBuffer, devPtr, extMem, bufferDesc);
}

CUresult CUDAAPI cuExternalMemoryGetMappedMipmappedArray(CUmipmappedArray *mipmap, CUexternalMemory extMem, const CUDA_EXTERNAL_MEMORY_MIPMAPPED_ARRAY_DESC *mipmapDesc) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuExternalMemoryGetMappedMipmappedArray, mipmap, extMem, mipmapDesc);
}


CUresult CUDAAPI cuDestroyExternalMemory(CUexternalMemory extMem) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDestroyExternalMemory, extMem);
}

CUresult CUDAAPI cuImportExternalSemaphore(CUexternalSemaphore *extSem_out, const CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC *semHandleDesc) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuImportExternalSemaphore, extSem_out, semHandleDesc);
}

CUresult CUDAAPI cuSignalExternalSemaphoresAsync(const CUexternalSemaphore *extSemArray, const CUDA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS *paramsArray, unsigned int numExtSems, CUstream stream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuSignalExternalSemaphoresAsync, extSemArray, paramsArray, numExtSems, stream);
}

CUresult CUDAAPI cuWaitExternalSemaphoresAsync(const CUexternalSemaphore *extSemArray, const CUDA_EXTERNAL_SEMAPHORE_WAIT_PARAMS *paramsArray, unsigned int numExtSems, CUstream stream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuWaitExternalSemaphoresAsync, extSemArray, paramsArray, numExtSems, stream);
}


CUresult CUDAAPI cuDestroyExternalSemaphore(CUexternalSemaphore extSem) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDestroyExternalSemaphore, extSem);
}

CUresult CUDAAPI cuStreamWaitValue32(CUstream stream, CUdeviceptr addr, cuuint32_t value, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamWaitValue32, stream, addr, value, flags);
}

CUresult CUDAAPI cuStreamWaitValue64(CUstream stream, CUdeviceptr addr, cuuint64_t value, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamWaitValue64, stream, addr, value, flags);
}

CUresult CUDAAPI cuStreamWriteValue32(CUstream stream, CUdeviceptr addr, cuuint32_t value, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamWriteValue32, stream, addr, value, flags);
}

CUresult CUDAAPI cuStreamWriteValue64(CUstream stream, CUdeviceptr addr, cuuint64_t value, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamWriteValue64, stream, addr, value, flags);
}


CUresult CUDAAPI cuStreamBatchMemOp(CUstream stream, unsigned int count, CUstreamBatchMemOpParams *paramArray, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamBatchMemOp, stream, count, paramArray, flags);
}

CUresult CUDAAPI cuStreamWaitValue32_v2(CUstream stream, CUdeviceptr addr, cuuint32_t value, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamWaitValue32_v2, stream, addr, value, flags);
}

CUresult CUDAAPI cuStreamWaitValue64_v2(CUstream stream, CUdeviceptr addr, cuuint64_t value, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamWaitValue64_v2, stream, addr, value, flags);
}

CUresult CUDAAPI cuStreamWriteValue32_v2(CUstream stream, CUdeviceptr addr, cuuint32_t value, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamWriteValue32_v2, stream, addr, value, flags);
}

CUresult CUDAAPI cuStreamWriteValue64_v2(CUstream stream, CUdeviceptr addr, cuuint64_t value, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamWriteValue64_v2, stream, addr, value, flags);
}

CUresult CUDAAPI cuStreamBatchMemOp_v2(CUstream stream, unsigned int count, CUstreamBatchMemOpParams *paramArray, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamBatchMemOp_v2, stream, count, paramArray, flags);
}

CUresult CUDAAPI cuFuncGetAttribute(int *pi, CUfunction_attribute attrib, CUfunction hfunc) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuFuncGetAttribute, pi, attrib, hfunc);
}

CUresult CUDAAPI cuFuncSetAttribute(CUfunction hfunc, CUfunction_attribute attrib, int value) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuFuncSetAttribute, hfunc, attrib, value);
}

CUresult CUDAAPI cuFuncSetCacheConfig(CUfunction hfunc, CUfunc_cache config) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuFuncSetCacheConfig, hfunc, config);
}

CUresult CUDAAPI cuFuncSetSharedMemConfig(CUfunction hfunc, CUsharedconfig config) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuFuncSetSharedMemConfig, hfunc, config);
}

CUresult CUDAAPI cuFuncGetModule(CUmodule *hmod, CUfunction hfunc) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuFuncGetModule, hmod, hfunc);
}



__CUDA_DEPRECATED CUresult CUDAAPI cuLaunchCooperativeKernelMultiDevice(CUDA_LAUNCH_PARAMS *launchParamsList, unsigned int numDevices, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuLaunchCooperativeKernelMultiDevice, launchParamsList, numDevices, flags);
}

CUresult CUDAAPI cuLaunchHostFunc(CUstream hStream, CUhostFn fn, void *userData) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuLaunchHostFunc, hStream, fn, userData);
}


__CUDA_DEPRECATED CUresult CUDAAPI cuFuncSetSharedSize(CUfunction hfunc, unsigned int bytes) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuFuncSetSharedSize, hfunc, bytes);
}

__CUDA_DEPRECATED CUresult CUDAAPI cuParamSetSize(CUfunction hfunc, unsigned int numbytes) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuParamSetSize, hfunc, numbytes);
}

__CUDA_DEPRECATED CUresult CUDAAPI cuParamSeti(CUfunction hfunc, int offset, unsigned int value) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuParamSeti, hfunc, offset, value);
}

__CUDA_DEPRECATED CUresult CUDAAPI cuParamSetf(CUfunction hfunc, int offset, float value) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuParamSetf, hfunc, offset, value);
}


__CUDA_DEPRECATED CUresult CUDAAPI cuParamSetv(CUfunction hfunc, int offset, void *ptr, unsigned int numbytes) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuParamSetv, hfunc, offset, ptr, numbytes);
}



__CUDA_DEPRECATED CUresult CUDAAPI cuParamSetTexRef(CUfunction hfunc, int texunit, CUtexref hTexRef) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuParamSetTexRef, hfunc, texunit, hTexRef);
}

CUresult CUDAAPI cuGraphCreate(CUgraph *phGraph, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphCreate, phGraph, flags);
}

CUresult CUDAAPI cuGraphAddKernelNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, const CUDA_KERNEL_NODE_PARAMS *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddKernelNode, phGraphNode, hGraph, dependencies, numDependencies, nodeParams);
}

CUresult CUDAAPI cuGraphKernelNodeGetParams(CUgraphNode hNode, CUDA_KERNEL_NODE_PARAMS *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphKernelNodeGetParams, hNode, nodeParams);
}

CUresult CUDAAPI cuGraphKernelNodeSetParams(CUgraphNode hNode, const CUDA_KERNEL_NODE_PARAMS *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphKernelNodeSetParams, hNode, nodeParams);
}

CUresult CUDAAPI cuGraphAddMemcpyNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, const CUDA_MEMCPY3D *copyParams, CUcontext ctx) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddMemcpyNode, phGraphNode, hGraph, dependencies, numDependencies, copyParams, ctx);
}

CUresult CUDAAPI cuGraphMemcpyNodeGetParams(CUgraphNode hNode, CUDA_MEMCPY3D *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphMemcpyNodeGetParams, hNode, nodeParams);
}

CUresult CUDAAPI cuGraphMemcpyNodeSetParams(CUgraphNode hNode, const CUDA_MEMCPY3D *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphMemcpyNodeSetParams, hNode, nodeParams);
}

CUresult CUDAAPI cuGraphAddMemsetNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, const CUDA_MEMSET_NODE_PARAMS *memsetParams, CUcontext ctx) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddMemsetNode, phGraphNode, hGraph, dependencies, numDependencies, memsetParams, ctx);
}

CUresult CUDAAPI cuGraphMemsetNodeGetParams(CUgraphNode hNode, CUDA_MEMSET_NODE_PARAMS *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphMemsetNodeGetParams, hNode, nodeParams);
}

CUresult CUDAAPI cuGraphMemsetNodeSetParams(CUgraphNode hNode, const CUDA_MEMSET_NODE_PARAMS *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphMemsetNodeSetParams, hNode, nodeParams);
}

CUresult CUDAAPI cuGraphAddHostNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, const CUDA_HOST_NODE_PARAMS *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddHostNode, phGraphNode, hGraph, dependencies, numDependencies, nodeParams);
}

CUresult CUDAAPI cuGraphHostNodeGetParams(CUgraphNode hNode, CUDA_HOST_NODE_PARAMS *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphHostNodeGetParams, hNode, nodeParams);
}

CUresult CUDAAPI cuGraphHostNodeSetParams(CUgraphNode hNode, const CUDA_HOST_NODE_PARAMS *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphHostNodeSetParams, hNode, nodeParams);
}

CUresult CUDAAPI cuGraphAddChildGraphNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, CUgraph childGraph) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddChildGraphNode, phGraphNode, hGraph, dependencies, numDependencies, childGraph);
}

CUresult CUDAAPI cuGraphChildGraphNodeGetGraph(CUgraphNode hNode, CUgraph *phGraph) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphChildGraphNodeGetGraph, hNode, phGraph);
}

CUresult CUDAAPI cuGraphAddEmptyNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddEmptyNode, phGraphNode, hGraph, dependencies, numDependencies);
}

CUresult CUDAAPI cuGraphAddEventRecordNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, CUevent event) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddEventRecordNode, phGraphNode, hGraph, dependencies, numDependencies, event);
}

CUresult CUDAAPI cuGraphEventRecordNodeGetEvent(CUgraphNode hNode, CUevent *event_out) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphEventRecordNodeGetEvent, hNode, event_out);
}

CUresult CUDAAPI cuGraphEventRecordNodeSetEvent(CUgraphNode hNode, CUevent event) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphEventRecordNodeSetEvent, hNode, event);
}


CUresult CUDAAPI cuGraphAddEventWaitNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, CUevent event) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddEventWaitNode, phGraphNode, hGraph, dependencies, numDependencies, event);
}

CUresult CUDAAPI cuGraphEventWaitNodeGetEvent(CUgraphNode hNode, CUevent *event_out) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphEventWaitNodeGetEvent, hNode, event_out);
}

CUresult CUDAAPI cuGraphEventWaitNodeSetEvent(CUgraphNode hNode, CUevent event) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphEventWaitNodeSetEvent, hNode, event);
}

CUresult CUDAAPI cuGraphAddExternalSemaphoresSignalNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, const CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddExternalSemaphoresSignalNode, phGraphNode, hGraph, dependencies, numDependencies, nodeParams);
}

CUresult CUDAAPI cuGraphExternalSemaphoresSignalNodeGetParams(CUgraphNode hNode, CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *params_out) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExternalSemaphoresSignalNodeGetParams, hNode, params_out);
}

CUresult CUDAAPI cuGraphExternalSemaphoresSignalNodeSetParams(CUgraphNode hNode, const CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExternalSemaphoresSignalNodeSetParams, hNode, nodeParams);
}

CUresult CUDAAPI cuGraphAddExternalSemaphoresWaitNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, const CUDA_EXT_SEM_WAIT_NODE_PARAMS *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddExternalSemaphoresWaitNode, phGraphNode, hGraph, dependencies, numDependencies, nodeParams);
}

CUresult CUDAAPI cuGraphExternalSemaphoresWaitNodeGetParams(CUgraphNode hNode, CUDA_EXT_SEM_WAIT_NODE_PARAMS *params_out) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExternalSemaphoresWaitNodeGetParams, hNode, params_out);
}

CUresult CUDAAPI cuGraphExternalSemaphoresWaitNodeSetParams(CUgraphNode hNode, const CUDA_EXT_SEM_WAIT_NODE_PARAMS *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExternalSemaphoresWaitNodeSetParams, hNode, nodeParams);
}

CUresult CUDAAPI cuGraphAddBatchMemOpNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, const CUDA_BATCH_MEM_OP_NODE_PARAMS *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddBatchMemOpNode, phGraphNode, hGraph, dependencies, numDependencies, nodeParams);
}

CUresult CUDAAPI cuGraphBatchMemOpNodeGetParams(CUgraphNode hNode, CUDA_BATCH_MEM_OP_NODE_PARAMS *nodeParams_out) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphBatchMemOpNodeGetParams, hNode, nodeParams_out);
}

CUresult CUDAAPI cuGraphBatchMemOpNodeSetParams(CUgraphNode hNode, const CUDA_BATCH_MEM_OP_NODE_PARAMS *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphBatchMemOpNodeSetParams, hNode, nodeParams);
}

CUresult CUDAAPI cuGraphExecBatchMemOpNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, const CUDA_BATCH_MEM_OP_NODE_PARAMS *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecBatchMemOpNodeSetParams, hGraphExec, hNode, nodeParams);
}

CUresult CUDAAPI cuGraphAddMemAllocNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, CUDA_MEM_ALLOC_NODE_PARAMS *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddMemAllocNode, phGraphNode, hGraph, dependencies, numDependencies, nodeParams);
}

CUresult CUDAAPI cuGraphMemAllocNodeGetParams(CUgraphNode hNode, CUDA_MEM_ALLOC_NODE_PARAMS *params_out) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphMemAllocNodeGetParams, hNode, params_out);
}

CUresult CUDAAPI cuGraphAddMemFreeNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, CUdeviceptr dptr) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddMemFreeNode, phGraphNode, hGraph, dependencies, numDependencies, dptr);
}

CUresult CUDAAPI cuGraphMemFreeNodeGetParams(CUgraphNode hNode, CUdeviceptr *dptr_out) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphMemFreeNodeGetParams, hNode, dptr_out);
}






CUresult CUDAAPI cuDeviceGraphMemTrim(CUdevice device) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGraphMemTrim, device);
}

CUresult CUDAAPI cuDeviceGetGraphMemAttribute(CUdevice device, CUgraphMem_attribute attr, void* value) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetGraphMemAttribute, device, attr, value);
}

CUresult CUDAAPI cuDeviceSetGraphMemAttribute(CUdevice device, CUgraphMem_attribute attr, void* value) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceSetGraphMemAttribute, device, attr, value);
}

CUresult CUDAAPI cuGraphClone(CUgraph *phGraphClone, CUgraph originalGraph) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphClone, phGraphClone, originalGraph);
}


CUresult CUDAAPI cuGraphNodeFindInClone(CUgraphNode *phNode, CUgraphNode hOriginalNode, CUgraph hClonedGraph) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphNodeFindInClone, phNode, hOriginalNode, hClonedGraph);
}

CUresult CUDAAPI cuGraphNodeGetType(CUgraphNode hNode, CUgraphNodeType *type) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphNodeGetType, hNode, type);
}

CUresult CUDAAPI cuGraphGetNodes(CUgraph hGraph, CUgraphNode *nodes, size_t *numNodes) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphGetNodes, hGraph, nodes, numNodes);
}

CUresult CUDAAPI cuGraphGetRootNodes(CUgraph hGraph, CUgraphNode *rootNodes, size_t *numRootNodes) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphGetRootNodes, hGraph, rootNodes, numRootNodes);
}

CUresult CUDAAPI cuGraphGetEdges(CUgraph hGraph, CUgraphNode *from, CUgraphNode *to, size_t *numEdges) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphGetEdges, hGraph, from, to, numEdges);
}

CUresult CUDAAPI cuGraphNodeGetDependencies(CUgraphNode hNode, CUgraphNode *dependencies, size_t *numDependencies) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphNodeGetDependencies, hNode, dependencies, numDependencies);
}

CUresult CUDAAPI cuGraphNodeGetDependentNodes(CUgraphNode hNode, CUgraphNode *dependentNodes, size_t *numDependentNodes) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphNodeGetDependentNodes, hNode, dependentNodes, numDependentNodes);
}

CUresult CUDAAPI cuGraphAddDependencies(CUgraph hGraph, const CUgraphNode *from, const CUgraphNode *to, size_t numDependencies) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddDependencies, hGraph, from, to, numDependencies);
}

CUresult CUDAAPI cuGraphRemoveDependencies(CUgraph hGraph, const CUgraphNode *from, const CUgraphNode *to, size_t numDependencies) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphRemoveDependencies, hGraph, from, to, numDependencies);
}

CUresult CUDAAPI cuGraphDestroyNode(CUgraphNode hNode) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphDestroyNode, hNode);
}

CUresult CUDAAPI cuGraphInstantiate(CUgraphExec *phGraphExec, CUgraph hGraph, CUgraphNode *phErrorNode, char *logBuffer, size_t bufferSize) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphInstantiate, phGraphExec, hGraph, phErrorNode, logBuffer, bufferSize);
}

CUresult CUDAAPI cuGraphInstantiateWithFlags(CUgraphExec *phGraphExec, CUgraph hGraph, unsigned long long flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphInstantiateWithFlags, phGraphExec, hGraph, flags);
}

CUresult CUDAAPI cuGraphExecKernelNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, const CUDA_KERNEL_NODE_PARAMS *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecKernelNodeSetParams, hGraphExec, hNode, nodeParams);
}

CUresult CUDAAPI cuGraphExecMemcpyNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, const CUDA_MEMCPY3D *copyParams, CUcontext ctx) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecMemcpyNodeSetParams, hGraphExec, hNode, copyParams, ctx);
}

CUresult CUDAAPI cuGraphExecMemsetNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, const CUDA_MEMSET_NODE_PARAMS *memsetParams, CUcontext ctx) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecMemsetNodeSetParams, hGraphExec, hNode, memsetParams, ctx);
}

CUresult CUDAAPI cuGraphExecHostNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, const CUDA_HOST_NODE_PARAMS *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecHostNodeSetParams, hGraphExec, hNode, nodeParams);
}

CUresult CUDAAPI cuGraphExecChildGraphNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, CUgraph childGraph) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecChildGraphNodeSetParams, hGraphExec, hNode, childGraph);
}

CUresult CUDAAPI cuGraphExecEventRecordNodeSetEvent(CUgraphExec hGraphExec, CUgraphNode hNode, CUevent event) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecEventRecordNodeSetEvent, hGraphExec, hNode, event);
}

CUresult CUDAAPI cuGraphExecEventWaitNodeSetEvent(CUgraphExec hGraphExec, CUgraphNode hNode, CUevent event) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecEventWaitNodeSetEvent, hGraphExec, hNode, event);
}

CUresult CUDAAPI cuGraphExecExternalSemaphoresSignalNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, const CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecExternalSemaphoresSignalNodeSetParams, hGraphExec, hNode, nodeParams);
}


CUresult CUDAAPI cuGraphExecExternalSemaphoresWaitNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, const CUDA_EXT_SEM_WAIT_NODE_PARAMS *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecExternalSemaphoresWaitNodeSetParams, hGraphExec, hNode, nodeParams);
}

CUresult CUDAAPI cuGraphNodeSetEnabled(CUgraphExec hGraphExec, CUgraphNode hNode, unsigned int isEnabled) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphNodeSetEnabled, hGraphExec, hNode, isEnabled);
}

CUresult CUDAAPI cuGraphNodeGetEnabled(CUgraphExec hGraphExec, CUgraphNode hNode, unsigned int *isEnabled) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphNodeGetEnabled, hGraphExec, hNode, isEnabled);
}

CUresult CUDAAPI cuGraphUpload(CUgraphExec hGraphExec, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphUpload, hGraphExec, hStream);
}

CUresult CUDAAPI cuGraphLaunch(CUgraphExec hGraphExec, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphLaunch, hGraphExec, hStream);
}

CUresult CUDAAPI cuGraphExecDestroy(CUgraphExec hGraphExec) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecDestroy, hGraphExec);
}

CUresult CUDAAPI cuGraphDestroy(CUgraph hGraph) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphDestroy, hGraph);
}

CUresult CUDAAPI cuGraphExecUpdate(CUgraphExec hGraphExec, CUgraph hGraph, CUgraphNode *hErrorNode_out, CUgraphExecUpdateResult *updateResult_out) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecUpdate, hGraphExec, hGraph, hErrorNode_out, updateResult_out);
}

CUresult CUDAAPI cuGraphKernelNodeCopyAttributes(CUgraphNode dst, CUgraphNode src) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphKernelNodeCopyAttributes, dst, src);
}

CUresult CUDAAPI cuGraphKernelNodeGetAttribute(CUgraphNode hNode, CUkernelNodeAttrID attr, CUkernelNodeAttrValue *value_out) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphKernelNodeGetAttribute, hNode, attr, value_out);
}

CUresult CUDAAPI cuGraphKernelNodeSetAttribute(CUgraphNode hNode, CUkernelNodeAttrID attr, const CUkernelNodeAttrValue *value) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphKernelNodeSetAttribute, hNode, attr, value);
}

CUresult CUDAAPI cuGraphDebugDotPrint(CUgraph hGraph, const char *path, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphDebugDotPrint, hGraph, path, flags);
}

CUresult CUDAAPI cuUserObjectCreate(CUuserObject *object_out, void *ptr, CUhostFn destroy, unsigned int initialRefcount, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuUserObjectCreate, object_out, ptr, destroy, initialRefcount, flags);
}

CUresult CUDAAPI cuUserObjectRetain(CUuserObject object, unsigned int count) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuUserObjectRetain, object, count);
}

CUresult CUDAAPI cuUserObjectRelease(CUuserObject object, unsigned int count) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuUserObjectRelease, object, count);
}

CUresult CUDAAPI cuGraphRetainUserObject(CUgraph graph, CUuserObject object, unsigned int count, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphRetainUserObject, graph, object, count, flags);
}

CUresult CUDAAPI cuGraphReleaseUserObject(CUgraph graph, CUuserObject object, unsigned int count) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphReleaseUserObject, graph, object, count);
}

CUresult CUDAAPI cuOccupancyMaxActiveBlocksPerMultiprocessor(int *numBlocks, CUfunction func, int blockSize, size_t dynamicSMemSize) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuOccupancyMaxActiveBlocksPerMultiprocessor, numBlocks, func, blockSize, dynamicSMemSize);
}

CUresult CUDAAPI cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(int *numBlocks, CUfunction func, int blockSize, size_t dynamicSMemSize, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags, numBlocks, func, blockSize, dynamicSMemSize, flags);
}

CUresult CUDAAPI cuOccupancyMaxPotentialBlockSize(int *minGridSize, int *blockSize, CUfunction func, CUoccupancyB2DSize blockSizeToDynamicSMemSize, size_t dynamicSMemSize, int blockSizeLimit) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuOccupancyMaxPotentialBlockSize, minGridSize, blockSize, func, blockSizeToDynamicSMemSize, dynamicSMemSize, blockSizeLimit);
}

CUresult CUDAAPI cuOccupancyMaxPotentialBlockSizeWithFlags(int *minGridSize, int *blockSize, CUfunction func, CUoccupancyB2DSize blockSizeToDynamicSMemSize, size_t dynamicSMemSize, int blockSizeLimit, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuOccupancyMaxPotentialBlockSizeWithFlags, minGridSize, blockSize, func, blockSizeToDynamicSMemSize, dynamicSMemSize, blockSizeLimit, flags);
}

CUresult CUDAAPI cuOccupancyAvailableDynamicSMemPerBlock(size_t *dynamicSmemSize, CUfunction func, int numBlocks, int blockSize) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuOccupancyAvailableDynamicSMemPerBlock, dynamicSmemSize, func, numBlocks, blockSize);
}

CUresult CUDAAPI cuTexRefSetArray(CUtexref hTexRef, CUarray hArray, unsigned int Flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetArray, hTexRef, hArray, Flags);
}

CUresult CUDAAPI cuTexRefSetMipmappedArray(CUtexref hTexRef, CUmipmappedArray hMipmappedArray, unsigned int Flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetMipmappedArray, hTexRef, hMipmappedArray, Flags);
}

CUresult CUDAAPI cuTexRefSetAddress(size_t *ByteOffset, CUtexref hTexRef, CUdeviceptr dptr, size_t bytes) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetAddress, ByteOffset, hTexRef, dptr, bytes);
}

CUresult CUDAAPI cuTexRefSetAddress2D(CUtexref hTexRef, const CUDA_ARRAY_DESCRIPTOR *desc, CUdeviceptr dptr, size_t Pitch) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetAddress2D, hTexRef, desc, dptr, Pitch);
}

CUresult CUDAAPI cuTexRefSetFormat(CUtexref hTexRef, CUarray_format fmt, int NumPackedComponents) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetFormat, hTexRef, fmt, NumPackedComponents);
}

CUresult CUDAAPI cuTexRefSetAddressMode(CUtexref hTexRef, int dim, CUaddress_mode am) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetAddressMode, hTexRef, dim, am);
}

CUresult CUDAAPI cuTexRefSetFilterMode(CUtexref hTexRef, CUfilter_mode fm) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetFilterMode, hTexRef, fm);
}


CUresult CUDAAPI cuTexRefSetMipmapFilterMode(CUtexref hTexRef, CUfilter_mode fm) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetMipmapFilterMode, hTexRef, fm);
}

CUresult CUDAAPI cuTexRefSetMipmapLevelBias(CUtexref hTexRef, float bias) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetMipmapLevelBias, hTexRef, bias);
}

CUresult CUDAAPI cuTexRefSetMipmapLevelClamp(CUtexref hTexRef, float minMipmapLevelClamp, float maxMipmapLevelClamp) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetMipmapLevelClamp, hTexRef, minMipmapLevelClamp, maxMipmapLevelClamp);
}

CUresult CUDAAPI cuTexRefSetMaxAnisotropy(CUtexref hTexRef, unsigned int maxAniso) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetMaxAnisotropy, hTexRef, maxAniso);
}

CUresult CUDAAPI cuTexRefSetBorderColor(CUtexref hTexRef, float *pBorderColor) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetBorderColor, hTexRef, pBorderColor);
}

CUresult CUDAAPI cuTexRefSetFlags(CUtexref hTexRef, unsigned int Flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetFlags, hTexRef, Flags);
}

CUresult CUDAAPI cuTexRefGetAddress(CUdeviceptr *pdptr, CUtexref hTexRef) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetAddress, pdptr, hTexRef);
}

CUresult CUDAAPI cuTexRefGetArray(CUarray *phArray, CUtexref hTexRef) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetArray, phArray, hTexRef);
}

CUresult CUDAAPI cuTexRefGetMipmappedArray(CUmipmappedArray *phMipmappedArray, CUtexref hTexRef) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetMipmappedArray, phMipmappedArray, hTexRef);
}

CUresult CUDAAPI cuTexRefGetAddressMode(CUaddress_mode *pam, CUtexref hTexRef, int dim) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetAddressMode, pam, hTexRef, dim);
}


__CUDA_DEPRECATED CUresult CUDAAPI cuTexRefGetFilterMode(CUfilter_mode *pfm, CUtexref hTexRef) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetFilterMode, pfm, hTexRef);
}

__CUDA_DEPRECATED CUresult CUDAAPI cuTexRefGetFormat(CUarray_format *pFormat, int *pNumChannels, CUtexref hTexRef) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetFormat, pFormat, pNumChannels, hTexRef);
}

__CUDA_DEPRECATED CUresult CUDAAPI cuTexRefGetMipmapFilterMode(CUfilter_mode *pfm, CUtexref hTexRef) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetMipmapFilterMode, pfm, hTexRef);
}

__CUDA_DEPRECATED CUresult CUDAAPI cuTexRefGetMipmapLevelBias(float *pbias, CUtexref hTexRef) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetMipmapLevelBias, pbias, hTexRef);
}

__CUDA_DEPRECATED CUresult CUDAAPI cuTexRefGetMipmapLevelClamp(float *pminMipmapLevelClamp, float *pmaxMipmapLevelClamp, CUtexref hTexRef) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetMipmapLevelClamp, pminMipmapLevelClamp, pmaxMipmapLevelClamp, hTexRef);
}

__CUDA_DEPRECATED CUresult CUDAAPI cuTexRefGetMaxAnisotropy(int *pmaxAniso, CUtexref hTexRef) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetMaxAnisotropy, pmaxAniso, hTexRef);
}

__CUDA_DEPRECATED CUresult CUDAAPI cuTexRefGetBorderColor(float *pBorderColor, CUtexref hTexRef) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetBorderColor, pBorderColor, hTexRef);
}

__CUDA_DEPRECATED CUresult CUDAAPI cuTexRefGetFlags(unsigned int *pFlags, CUtexref hTexRef) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetFlags, pFlags, hTexRef);
}

__CUDA_DEPRECATED CUresult CUDAAPI cuTexRefCreate(CUtexref *pTexRef) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefCreate, pTexRef);
}

__CUDA_DEPRECATED CUresult CUDAAPI cuTexRefDestroy(CUtexref hTexRef) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefDestroy, hTexRef);
}

__CUDA_DEPRECATED CUresult CUDAAPI cuSurfRefSetArray(CUsurfref hSurfRef, CUarray hArray, unsigned int Flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuSurfRefSetArray, hSurfRef, hArray, Flags);
}

__CUDA_DEPRECATED CUresult CUDAAPI cuSurfRefGetArray(CUarray *phArray, CUsurfref hSurfRef) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuSurfRefGetArray, phArray, hSurfRef);
}

CUresult CUDAAPI cuTexObjectCreate(CUtexObject *pTexObject, const CUDA_RESOURCE_DESC *pResDesc, const CUDA_TEXTURE_DESC *pTexDesc, const CUDA_RESOURCE_VIEW_DESC *pResViewDesc) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexObjectCreate, pTexObject, pResDesc, pTexDesc, pResViewDesc);
}

CUresult CUDAAPI cuTexObjectDestroy(CUtexObject texObject) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexObjectDestroy, texObject);
}

CUresult CUDAAPI cuTexObjectGetResourceDesc(CUDA_RESOURCE_DESC *pResDesc, CUtexObject texObject) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexObjectGetResourceDesc, pResDesc, texObject);
}

CUresult CUDAAPI cuTexObjectGetTextureDesc(CUDA_TEXTURE_DESC *pTexDesc, CUtexObject texObject) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexObjectGetTextureDesc, pTexDesc, texObject);
}

CUresult CUDAAPI cuTexObjectGetResourceViewDesc(CUDA_RESOURCE_VIEW_DESC *pResViewDesc, CUtexObject texObject) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexObjectGetResourceViewDesc, pResViewDesc, texObject);
}


CUresult CUDAAPI cuSurfObjectCreate(CUsurfObject *pSurfObject, const CUDA_RESOURCE_DESC *pResDesc) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuSurfObjectCreate, pSurfObject, pResDesc);
}

CUresult CUDAAPI cuSurfObjectDestroy(CUsurfObject surfObject) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuSurfObjectDestroy, surfObject);
}

CUresult CUDAAPI cuSurfObjectGetResourceDesc(CUDA_RESOURCE_DESC *pResDesc, CUsurfObject surfObject) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuSurfObjectGetResourceDesc, pResDesc, surfObject);
}

CUresult CUDAAPI cuDeviceCanAccessPeer(int *canAccessPeer, CUdevice dev, CUdevice peerDev) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceCanAccessPeer, canAccessPeer, dev, peerDev);
}

CUresult CUDAAPI cuCtxEnablePeerAccess(CUcontext peerContext, unsigned int Flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxEnablePeerAccess, peerContext, Flags);
}

CUresult CUDAAPI cuCtxDisablePeerAccess(CUcontext peerContext) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxDisablePeerAccess, peerContext);
}

CUresult CUDAAPI cuDeviceGetP2PAttribute(int* value, CUdevice_P2PAttribute attrib, CUdevice srcDevice, CUdevice dstDevice) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetP2PAttribute, value, attrib, srcDevice, dstDevice);
}

CUresult CUDAAPI cuGraphicsUnregisterResource(CUgraphicsResource resource) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsUnregisterResource, resource);
}

CUresult CUDAAPI cuGraphicsSubResourceGetMappedArray(CUarray *pArray, CUgraphicsResource resource, unsigned int arrayIndex, unsigned int mipLevel) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsSubResourceGetMappedArray, pArray, resource, arrayIndex, mipLevel);
}

CUresult CUDAAPI cuGraphicsResourceGetMappedMipmappedArray(CUmipmappedArray *pMipmappedArray, CUgraphicsResource resource) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsResourceGetMappedMipmappedArray, pMipmappedArray, resource);
}

CUresult CUDAAPI cuGraphicsResourceGetMappedPointer(CUdeviceptr *pDevPtr, size_t *pSize, CUgraphicsResource resource) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsResourceGetMappedPointer, pDevPtr, pSize, resource);
}

CUresult CUDAAPI cuGraphicsResourceSetMapFlags(CUgraphicsResource resource, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsResourceSetMapFlags, resource, flags);
}

CUresult CUDAAPI cuGraphicsMapResources(unsigned int count, CUgraphicsResource *resources, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsMapResources, count, resources, hStream);
}

CUresult CUDAAPI cuGraphicsUnmapResources(unsigned int count, CUgraphicsResource *resources, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsUnmapResources, count, resources, hStream);
}

CUresult CUDAAPI cuModuleGetLoadingMode(CUmoduleLoadingMode *mode) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleGetLoadingMode, mode);
}

CUresult CUDAAPI cuMemGetHandleForAddressRange(void *handle, CUdeviceptr dptr, size_t size, CUmemRangeHandleType handleType, unsigned long long flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemGetHandleForAddressRange, handle, dptr, size, handleType, flags);
}

CUresult CUDAAPI cuGetExportTable(const void **ppExportTable, const CUuuid *pExportTableId) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGetExportTable, ppExportTable, pExportTableId);
}


/*
 *GL
*/
/*
CUresult cuCtxResetPersistingL2Cache(void) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxResetPersistingL2Cache);
}

CUresult cuModuleGetGlobal_v2(CUdeviceptr *dptr, size_t *bytes, CUmodule hmod,
                              const char *name) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleGetGlobal_v2, dptr, bytes,
                         hmod, name);
}

CUresult cuModuleGetGlobal(CUdeviceptr *dptr, size_t *bytes, CUmodule hmod,
                           const char *name) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleGetGlobal, dptr, bytes,
                         hmod, name);
}

CUresult cuGLCtxCreate_v2(CUcontext *pCtx, unsigned int Flags,
                          CUdevice device) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGLCtxCreate_v2, pCtx, Flags,
                         device);
}

CUresult cuGLCtxCreate(CUcontext *pCtx, unsigned int Flags, CUdevice device) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGLCtxCreate, pCtx, Flags,
                         device);
}

CUresult cuGLInit(void) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGLInit);
}

CUresult cuGLGetDevices_v2(unsigned int *pCudaDeviceCount,
                           CUdevice *pCudaDevices, unsigned int cudaDeviceCount,
                           CUGLDeviceList deviceList) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGLGetDevices_v2,
                         pCudaDeviceCount, pCudaDevices, cudaDeviceCount,
                         deviceList);
}

CUresult cuGLGetDevices(unsigned int *pCudaDeviceCount, CUdevice *pCudaDevices,
                        unsigned int cudaDeviceCount,
                        CUGLDeviceList deviceList) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGLGetDevices, pCudaDeviceCount,
                         pCudaDevices, cudaDeviceCount, deviceList);
}

CUresult cuGLRegisterBufferObject(GLuint buffer) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGLRegisterBufferObject, buffer);
}

CUresult cuGLMapBufferObject_v2_ptds(CUdeviceptr *dptr, size_t *size,
                                     GLuint buffer) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGLMapBufferObject_v2_ptds, dptr,
                         size, buffer);
}

CUresult cuGLMapBufferObject_v2(CUdeviceptr *dptr, size_t *size,
                                GLuint buffer) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGLMapBufferObject_v2, dptr, size,
                         buffer);
}

CUresult cuGLMapBufferObject(CUdeviceptr *dptr, size_t *size, GLuint buffer) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGLMapBufferObject, dptr, size,
                         buffer);
}

CUresult cuGLMapBufferObjectAsync_v2_ptsz(CUdeviceptr *dptr, size_t *size,
                                          GLuint buffer, CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGLMapBufferObjectAsync_v2_ptsz,
                         dptr, size, buffer, hStream);
}

CUresult cuGLMapBufferObjectAsync_v2(CUdeviceptr *dptr, size_t *size,
                                     GLuint buffer, CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGLMapBufferObjectAsync_v2, dptr,
                         size, buffer, hStream);
}

CUresult cuGLMapBufferObjectAsync(CUdeviceptr *dptr, size_t *size,
                                  GLuint buffer, CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGLMapBufferObjectAsync, dptr,
                         size, buffer, hStream);
}

CUresult cuGLUnmapBufferObject(GLuint buffer) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGLUnmapBufferObject, buffer);
}

CUresult cuGLUnmapBufferObjectAsync(GLuint buffer, CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGLUnmapBufferObjectAsync, buffer,
                         hStream);
}

CUresult cuGLUnregisterBufferObject(GLuint buffer) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGLUnregisterBufferObject,
                         buffer);
}

CUresult cuGLSetBufferObjectMapFlags(GLuint buffer, unsigned int Flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGLSetBufferObjectMapFlags,
                         buffer, Flags);
}

CUresult cuGraphicsGLRegisterImage(CUgraphicsResource *pCudaResource,
                                   GLuint image, GLenum target,
                                   unsigned int Flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsGLRegisterImage,
                         pCudaResource, image, target, Flags);
}

CUresult cuGraphicsGLRegisterBuffer(CUgraphicsResource *pCudaResource,
                                    GLuint buffer, unsigned int Flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsGLRegisterBuffer,
                         pCudaResource, buffer, Flags);
}

CUresult cuGraphicsEGLRegisterImage(CUgraphicsResource *pCudaResource,
                                    EGLImageKHR image, unsigned int flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsEGLRegisterImage,
                         pCudaResource, image, flags);
}

CUresult cuGraphicsResourceGetMappedEglFrame(CUeglFrame *eglFrame,
                                             CUgraphicsResource resource,
                                             unsigned int index,
                                             unsigned int mipLevel) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsEGLRegisterImage,
                         cuGraphicsResourceGetMappedEglFrame, eglFrame,
                         resource, index, mipLevel);
}
*/
/*
* EGL
*/

/*
CUresult cuEGLInit(void) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuEGLInit);
}

CUresult cuEGLApiInit(void) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuEGLApiInit);
}

CUresult cuEGLStreamConsumerAcquireFrame(CUeglStreamConnection *conn,
                                         CUgraphicsResource *pCudaResource,
                                         CUstream *pStream,
                                         unsigned int timeout) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuEGLStreamConsumerAcquireFrame,
                         conn, pCudaResource, pStream, timeout);
}

CUresult cuEGLStreamConsumerConnect(CUeglStreamConnection *conn,
                                    EGLStreamKHR stream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuEGLStreamConsumerConnect, conn,
                         stream);
}

CUresult cuEGLStreamConsumerConnectWithFlags(CUeglStreamConnection *conn,
                                             EGLStreamKHR stream,
                                             unsigned int flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry,
                         cuEGLStreamConsumerConnectWithFlags, conn, stream,
                         flags);
}

CUresult cuEGLStreamConsumerDisconnect(CUeglStreamConnection *conn) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuEGLStreamConsumerDisconnect,
                         conn);
}

CUresult cuEGLStreamConsumerReleaseFrame(CUeglStreamConnection *conn,
                                         CUgraphicsResource pCudaResource,
                                         CUstream *pStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuEGLStreamConsumerReleaseFrame,
                         conn, pCudaResource, pStream);
}

CUresult cuEGLStreamProducerConnect(CUeglStreamConnection *conn,
                                    EGLStreamKHR stream, EGLint width,
                                    EGLint height) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuEGLStreamProducerConnect, conn,
                         stream, width, height);
}

CUresult cuEGLStreamProducerDisconnect(CUeglStreamConnection *conn) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuEGLStreamProducerDisconnect,
                         conn);
}

CUresult cuEGLStreamProducerPresentFrame(CUeglStreamConnection *conn,
                                         CUeglFrame eglframe,
                                         CUstream *pStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuEGLStreamProducerPresentFrame,
                         conn, eglframe, pStream);
}

CUresult cuEGLStreamProducerReturnFrame(CUeglStreamConnection *conn,
                                        CUeglFrame *eglframe,
                                        CUstream *pStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuEGLStreamProducerReturnFrame,
                         conn, eglframe, pStream);
}
*/
