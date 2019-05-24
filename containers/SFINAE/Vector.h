//////////////////////////////////////////////////////////////////////////////////////
// This file is distributed under the University of Illinois/NCSA Open Source License.
// See LICENSE file in top directory for details.
//
// Copyright (c) 2016 Jeongnim Kim and QMCPACK developers.
//
// File developed by: Jeongnim Kim, jeongnim.kim@intel.com, Intel Corp.
//                    Ye Luo, yeluo@anl.gov, Argonne National Laboratory
//
// File created by: Jeongnim Kim, jeongnim.kim@intel.com, Intel Corp.
//////////////////////////////////////////////////////////////////////////////////////


/** @file Vector.h
 *
 *  Declaraton of Vector<T,Alloc>
 *  Manage memory through Alloc directly and allow referencing an existing memory.
 */

#ifndef OHMMS_NEW_VECTOR_H
#define OHMMS_NEW_VECTOR_H
#include <algorithm>
#include <vector>
#include <iostream>
#include <type_traits>
#include <stdexcept>

namespace qmcplusplus
{
template<class T, typename Alloc = std::allocator<T>>
class Vector
{
public:
  typedef T Type_t;
  typedef T value_type;
  typedef T* iterator;
  typedef const T* const_iterator;
  typedef typename Alloc::size_type size_type;
  typedef typename Alloc::pointer pointer;
  typedef typename Alloc::const_pointer const_pointer;
  typedef Vector<T, Alloc> This_t;

  /** constructor with size n*/
  template<typename Allocator = Alloc, typename Allocator::host_unsafe = 0>
  inline Vector(size_t n = 0) : nLocal(n), nAllocated(0), X(nullptr)
  {
    if (n)
    {
      resize_impl(n);
    }
    std::cout << "Without initialization!" << std::endl;
  }

  /** constructor with size n*/
  inline Vector(size_t n = 0, Type_t val = Type_t()) : nLocal(n), nAllocated(0), X(nullptr)
  {
    if (n)
    {
      resize_impl(n);
      std::fill_n(X, n, val);
    }
    std::cout << "With initialization!" << std::endl;
  }

  //! Destructor
  virtual ~Vector()
  {
    if (nAllocated)
    {
      mAllocator.deallocate(X, nAllocated);
    }
  }

  template<typename Allocator = Alloc, typename Allocator::host_unsafe = 0>
  inline const Type_t& operator[](size_t i) const
  {
    return X[i];
  }

private:
  ///size
  size_t nLocal;
  ///The number of allocated
  size_t nAllocated;
  ///pointer to the data managed by this object
  T* X;
  ///allocator
  Alloc mAllocator;

  inline void resize_impl(size_t n)
  {
    if (nAllocated)
    {
      mAllocator.deallocate(X, nAllocated);
    }
    X          = mAllocator.allocate(n);
    nLocal     = n;
    nAllocated = n;
  }
};

} // namespace qmcplusplus

#endif // OHMMS_PARTICLEATTRIB_PEPE_H
