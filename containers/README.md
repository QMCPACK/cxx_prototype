Need a container for the following case.

    std::allocator, from standard library, host safe
    Mallocator, for aligned allocation, host safe
    OMPallocator, for host and device allocation with OpenMP mapping, host safe
    CUDAHostAllocator, for pinned host memory, host safe
    CUDAManagedAllocator, for CUDA manged memory, host safe
    CUDAAllocator, for CUDA device, memory, host unsafe
    hipAllocator, for device memory, host unsafe
    OpenCLAllocator, for hip device, memory, host unsafe

1-6 is currently in use. 7-8 may be needed in the future.
I'd like 1-5 go to implementation A which allows accessing data on the host.
6-7 go to implementation B which excludes all member function accessing data on the host.
The goal is to have maximal flexibility and hopefully minimal code.

So far, tried
1. static_assert
Working.
2. SFINAE
Not working yet
3. MultiSpecialization
Working.