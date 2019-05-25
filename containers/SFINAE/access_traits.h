//////////////////////////////////////////////////////////////////////////////////////
// This file is distributed under the University of Illinois/NCSA Open Source License.
// See LICENSE file in top directory for details.
//
// Copyright (c) 2016 Jeongnim Kim and QMCPACK developers.
//
// File developed by: Ye Luo, yeluo@anl.gov, Argonne National Laboratory
//
// File created by: Ye Luo, yeluo@anl.gov, Argonne National Laboratory
//////////////////////////////////////////////////////////////////////////////////////


#ifndef QMCPLUSPLUS_ACCESS_TRAITS_H
#define QMCPLUSPLUS_ACCESS_TRAITS_H

namespace qmcplusplus
{

template<class Allocator>
struct is_host_accessible
{
  const static bool value = true;
};

template<class Allocator>
using IsNotHostSafe = std::enable_if_t<!is_host_accessible<Allocator>::value>;

template<class Allocator>
using IsHostSafe = std::enable_if_t<is_host_accessible<Allocator>::value>;

} // namespace qmcplusplus

#endif // QMCPLUSPLUS_ACCESS_TRAITS_H
