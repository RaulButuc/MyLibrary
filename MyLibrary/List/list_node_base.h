/**
 *  list_node_base.h
 *
 *  @author Raul Butuc.
 *  @version 1.0.0 16/08/2015
 */

#pragma once

namespace my_library {
  
  class list_node_base {
    
    public:
      list_node_base* m_pNext;
      list_node_base* m_pPrev;

      list_node_base();

  };

  list_node_base::list_node_base()
    : m_pNext(nullptr), m_pPrev(nullptr) {}

}
