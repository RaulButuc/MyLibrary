/**
 *  forward_list_node_base.h
 *
 *  @author Raul Butuc.
 *  @version 1.0.0 26/03/2015
 */

#pragma once

namespace my_library {
  
  class forward_list_node_base {
    
    public:
      forward_list_node_base* m_pNext;

      forward_list_node_base();
      ~forward_list_node_base();

  };

  forward_list_node_base::forward_list_node_base()
      : m_pNext(nullptr) {}
  
  forward_list_node_base::~forward_list_node_base() {
    delete m_pNext;
  }
}