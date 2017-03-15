/**
 *  forward_list_node_base.h
 *
 *  @author Raul Butuc
 */

#pragma once

namespace my_library {
  
  class forward_list_node_base {

    public:

      forward_list_node_base* m_pNext;

      forward_list_node_base();

  };

  forward_list_node_base::forward_list_node_base()
      : m_pNext(nullptr) {}

}
