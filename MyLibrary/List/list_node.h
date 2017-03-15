/**
 *  list_node.h
 *
 *  @author Raul Butuc
 */

#pragma once

#include "list_node_base.h"

namespace my_library {
  
  template <class _Tp>
  class list_node : public list_node_base {
    
    private:

      _Tp m_Value;

      list_node(_Tp const&);

  };

  template <class _Tp>
  list_node<_Tp>::list_node(_Tp const& _value)
    : m_Value(_value), list_node_base() {}

}
