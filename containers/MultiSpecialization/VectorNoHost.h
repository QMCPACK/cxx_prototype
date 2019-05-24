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

#ifndef OHMMS_VECTOR_NOHOST_H
#define OHMMS_VECTOR_NOHOST_H
#include <algorithm>
#include <vector>
#include <iostream>
#include <type_traits>
#include <stdexcept>
#include "Vector.h"

namespace qmcplusplus
{

template<class T, size_t ALIGN>
class Vector<T, NoHostallocator<T, ALIGN>>
{
public:
  typedef T Type_t;
  typedef T value_type;
  typedef T* iterator;
  typedef const T* const_iterator;
  typedef typename NoHostallocator<T, ALIGN>::size_type size_type;
  typedef typename NoHostallocator<T, ALIGN>::pointer pointer;
  typedef typename NoHostallocator<T, ALIGN>::const_pointer const_pointer;
  typedef Vector<T, NoHostallocator<T, ALIGN>> This_t;

  /** constructor with size n*/
  explicit inline Vector(size_t n = 0, Type_t val = Type_t()) : nLocal(n), nAllocated(0), X(nullptr)
  {
    if (n)
    {
      resize_impl(n);
    }
  }

  //! Destructor
  virtual ~Vector()
  {
    if (nAllocated)
    {
      mAllocator.deallocate(X, nAllocated);
    }
  }

private:
  ///size
  size_t nLocal;
  ///The number of allocated
  size_t nAllocated;
  ///pointer to the data managed by this object
  T* X;
  ///allocator
  NoHostallocator<T, ALIGN> mAllocator;

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
