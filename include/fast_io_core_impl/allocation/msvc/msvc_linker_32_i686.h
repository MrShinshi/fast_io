﻿#pragma once
// clang-format off

#pragma comment(linker, "/alternatename:__imp_?HeapAlloc@win32@fast_io@@YGPAXPAXII@Z=__imp__HeapAlloc@12")
#pragma comment(linker, "/alternatename:__imp_?HeapFree@win32@fast_io@@YGHPAXI0@Z=__imp__HeapFree@12")
#pragma comment(linker, "/alternatename:__imp_?GetProcessHeap@win32@fast_io@@YGPAXXZ=__imp__GetProcessHeap@0")
#pragma comment(linker, "/alternatename:__imp_?HeapReAlloc@win32@fast_io@@YGPAXPAXI0I@Z=__imp__HeapReAlloc@16")
#pragma comment(linker, "/alternatename:__imp_?HeapSize@win32@fast_io@@YGIPAXIPBX@Z=__imp__HeapSize@12")
#pragma comment(linker, "/alternatename:__imp_?RtlAllocateHeap@nt@win32@fast_io@@YGPAXPAXII@Z=__imp__RtlAllocateHeap@12")
#pragma comment(linker, "/alternatename:__imp_?RtlFreeHeap@nt@win32@fast_io@@YGEPAXI0@Z=__imp__RtlFreeHeap@12")
#pragma comment(linker, "/alternatename:__imp_?RtlGetCurrentPeb@nt@win32@fast_io@@YGPAUpeb@123@XZ=__imp__RtlGetCurrentPeb@0")
#pragma comment(linker, "/alternatename:__imp_?RtlReAllocateHeap@nt@win32@fast_io@@YGPAXPAXI0I@Z=__imp__RtlReAllocateHeap@16")
#pragma comment(linker, "/alternatename:__imp_?RtlSizeHeap@nt@win32@fast_io@@YGIPAXI0@Z=__imp__RtlSizeHeap@12")

// clang-format on
