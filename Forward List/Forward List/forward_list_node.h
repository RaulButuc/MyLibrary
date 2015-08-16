/**
 *  forward_list_node.h
 *
 *  @author Raul Butuc.
 *  @version 1.2.1 28/03/2015
 */

#pragma once

#include "forward_list_node_base.h"
#include "forward_list.h"
#include "forward_list_iterator.h"
#include "forward_list_const_iterator.h"

namespace my_library {

  template <class _Tp>
  class forward_list_node : public forward_list_node_base {

    friend class forward_list<_Tp>;
    friend class forward_list_iterator<_Tp>;
    friend class forward_list_const_iterator<_Tp>;

    private:
      _Tp m_Value;

      forward_list_node(const _Tp&);
  };

  template <class _Tp>
  forward_list_node<_Tp>::forward_list_node(const _Tp& _value)
      : m_Value(_value), forward_list_node_base() {}
  
}
