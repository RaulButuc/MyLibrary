/**
 *  binary_tree_node.h
 *
 *  @author Raul Butuc
 */

#pragma once

#include "binary_search_tree.h"

namespace my_library {
  
  template <class _Tp> class binary_search_tree;

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
