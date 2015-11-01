/**
 *  binary_tree_node.h
 *
 *  @author Raul Butuc.
 *  @version 1.0.0 14/10/2015
 */

#pragma once

#include "binary_search_tree.h"

template <class _Tp> class binary_search_tree;

namespace my_library {
  
  template <class _Tp>
  class binary_tree_node {

    friend class binary_search_tree<_Tp>;

    private:
      binary_tree_node<_Tp>* left;
      binary_tree_node<_Tp>* right;
      _Tp value;

    public:
      binary_tree_node();
      ~binary_tree_node();

  };

  template <class _Tp>
  binary_tree_node<_Tp>::binary_tree_node()
    : left(nullptr), right(nullptr) {}

  template <class _Tp>
  binary_tree_node<_Tp>::~binary_tree_node() {}

}
