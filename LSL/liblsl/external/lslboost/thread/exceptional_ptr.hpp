// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.lslboost.org/LICENSE_1_0.txt)
// (C) Copyright 2014 Vicente J. Botet Escriba

#ifndef BOOST_THREAD_EXCEPTIONAL_PTR_HPP
#define BOOST_THREAD_EXCEPTIONAL_PTR_HPP

#include <lslboost/thread/detail/move.hpp>
#include <lslboost/exception_ptr.hpp>

#include <lslboost/config/abi_prefix.hpp>

namespace lslboost
{
  struct exceptional_ptr {
    exception_ptr ptr_;

    exceptional_ptr() : ptr_() {}
    explicit exceptional_ptr(exception_ptr ex) : ptr_(ex) {}
    template <class E>
    explicit exceptional_ptr(BOOST_FWD_REF(E) ex) : ptr_(lslboost::copy_exception(lslboost::forward<E>(ex))) {}
  };

  template <class E>
  inline exceptional_ptr make_exceptional(BOOST_FWD_REF(E) ex) {
    return exceptional_ptr(lslboost::forward<E>(ex));
  }

  inline exceptional_ptr make_exceptional(exception_ptr ex)
  {
    return exceptional_ptr(ex);
  }

  inline exceptional_ptr make_exceptional()
  {
    return exceptional_ptr();
  }

} // namespace lslboost

#include <lslboost/config/abi_suffix.hpp>

#endif