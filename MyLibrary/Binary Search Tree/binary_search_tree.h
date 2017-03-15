/**
 *  binary_search_tree.h
 *
 *  @author Raul Butuc
 */

#pragma once

#include <iostream>
#include <queue>
#include "binary_tree_node.h"

namespace my_library {

  template <class _Tp>
  class binary_search_tree {

    public:
      binary_search_tree();
      void display_pre_order();
      void display_in_order();
      void display_post_order();
      bool empty();
      void insert(_Tp);
      void insert(std::vector<_Tp>);
      void remove(_Tp);
      void remove(std::vector<_Tp>);
      bool search(_Tp);
      ~binary_search_tree();

    private:
      binary_tree_node<_Tp>* m_pHead;

      void display_pre_order(binary_tree_node<_Tp>*);
      void display_in_order(binary_tree_node<_Tp>*);
      void display_post_order(binary_tree_node<_Tp>*);
      void display_node(binary_tree_node<_Tp>*);
      binary_tree_node<_Tp>* get_min_value_node(binary_tree_node<_Tp>*);
      binary_tree_node<_Tp>* get_node_by_value(binary_tree_node<_Tp>*, _Tp);
      void get_nodes_in_post_order(binary_tree_node<_Tp>*, std::queue<binary_tree_node<_Tp>*>&);
      void insert(binary_tree_node<_Tp>**, binary_tree_node<_Tp>*, _Tp, bool);
      binary_tree_node<_Tp>* remove(binary_tree_node<_Tp>*, _Tp);
      bool search(binary_tree_node<_Tp>*, _Tp);

  };

  template <class _Tp>
  binary_search_tree<_Tp>::binary_search_tree() : m_pHead(nullptr) {}

  template <class _Tp>
  void binary_search_tree<_Tp>::display_pre_order() {
    if (m_pHead != nullptr) {
      this->display_pre_order(m_pHead);
    }
  }

  template <class _Tp>
  void binary_search_tree<_Tp>::display_pre_order(binary_tree_node<_Tp>* curr) {
    this->display_node(curr);
  
    if (curr->left != nullptr) {
      this->display_pre_order(curr->left);
    }

    if (curr->right != nullptr) {
      this->display_pre_order(curr->right);
    }
  }

  template <class _Tp>
  void binary_search_tree<_Tp>::display_in_order() {
    if (m_pHead != nullptr) {
      this->display_in_order(m_pHead);
    }
  }

  template <class _Tp>
  void binary_search_tree<_Tp>::display_in_order(binary_tree_node<_Tp>* curr) {
    if (curr->left != nullptr) {
      this->display_in_order(curr->left);
    }

    this->display_node(curr);

    if (curr->right != nullptr) {
      this->display_in_order(curr->right);
    }
  }

  template <class _Tp>
  void binary_search_tree<_Tp>::display_post_order() {
    if (m_pHead != nullptr) {
      this->display_post_order(m_pHead);
    }
  }

  template <class _Tp>
  void binary_search_tree<_Tp>::display_post_order(binary_tree_node<_Tp>* curr) {
    if (curr->left != nullptr) {
      this->display_post_order(curr->left);
    }

    if (curr->right != nullptr) {
      this->display_post_order(curr->right);
    }

    this->display_node(curr);
  }

  template <class _Tp>
  void binary_search_tree<_Tp>::display_node(binary_tree_node<_Tp>* curr) {
    std::cout << curr->value << " ";
  }

  template <class _Tp>
  bool binary_search_tree<_Tp>::empty() {
    return m_pHead == nullptr;
  }

  template <class _Tp>
  binary_tree_node<_Tp>* binary_search_tree<_Tp>::get_min_value_node(binary_tree_node<_Tp>* curr) {
    while (curr->left != nullptr) {
      curr = curr->left;
    }

    return curr;
  }

  template <class _Tp>
  binary_tree_node<_Tp>* binary_search_tree<_Tp>::get_node_by_value(binary_tree_node<_Tp>* curr,
      _Tp val){
    if (curr != nullptr) {
      if (curr->value == val) {
        return curr;
      }

      if (curr->value > val) {
        this->search(curr->left, val);
      }
      else {
        this->search(curr->right, val);
      }
    }

    return nullptr;
  }

  template <class _Tp>
  void binary_search_tree<_Tp>::get_nodes_in_post_order(binary_tree_node<_Tp>* curr,
      std::queue<binary_tree_node<_Tp>*>& nodes) {
    if (curr != nullptr) {
      this->get_nodes_in_post_order(curr->left, nodes);
      this->get_nodes_in_post_order(curr->right, nodes);
      nodes.push(curr);
    }
  }

  template <class _Tp>
  void binary_search_tree<_Tp>::insert(_Tp val) {
    this->insert(&m_pHead, nullptr, val, false);
  }

  template <class _Tp>
  void binary_search_tree<_Tp>::insert(std::vector<_Tp> vals) {
    vals = std::vector<_Tp>(vals.rbegin(), vals.rend());
    
    while (!vals.empty()) {
      _Tp val = vals.back();
      vals.pop_back();
      this->insert(&m_pHead, nullptr, val, false);
    }
  }

  template <class _Tp>
  void binary_search_tree<_Tp>::insert(binary_tree_node<_Tp>** curr, binary_tree_node<_Tp>* parent,
      _Tp val, bool isLeftChild) {
    if (*curr == nullptr) {
      *curr = new binary_tree_node<_Tp>();
      (*curr)->value = val;

      if (parent != nullptr) {
        if (isLeftChild) {
          parent->left = *curr;
        }
        else {
          parent->right = *curr;
        }
      }
    }
    else {
      if ((*curr)->value > val) {
        this->insert(&((*curr)->left), *curr, val, true);
      }
      else {
        this->insert(&((*curr)->right), *curr, val, false);
      }
    }
  }

  template <class _Tp>
  void binary_search_tree<_Tp>::remove(_Tp val) {
    if (m_pHead != nullptr) {
      binary_tree_node<_Tp>* node = this->remove(m_pHead, val);
    }
  }

  template <class _Tp>
  void binary_search_tree<_Tp>::remove(std::vector<_Tp> vals) {
    if (m_pHead != nullptr) {
      binary_tree_node<_Tp>* node;
      vals = std::vector<_Tp>(vals.rbegin(), vals.rend());
      
      while (!vals.empty()) {
        _Tp val = vals.back();
        vals.pop_back();
        node = this->remove(m_pHead, val);
      }
    }
  }

  template <class _Tp>
  binary_tree_node<_Tp>* binary_search_tree<_Tp>::remove(binary_tree_node<_Tp>* curr, _Tp val) {
    if (curr == nullptr) {
      return curr;
    }
    
    if (curr->value > val) {
      curr->left = this->remove(curr->left, val);
    }
    else if (curr->value < val) {
      curr->right = this->remove(curr->right, val);
    }
    else {
      if (curr->left == nullptr && curr->right == nullptr) {
        delete curr;
        curr = nullptr;
      }
      else if (curr->left == nullptr) {
        binary_tree_node<_Tp>* temp = curr;
        curr = curr->right;
        delete temp;
      }
      else if (curr->right == nullptr) {
        binary_tree_node<_Tp>* temp = curr;
        curr = curr->left;
        delete temp;
      }
      else {
        binary_tree_node<_Tp>* temp = this->get_min_value_node(curr->right);
        curr->value = temp->value;
        curr->right = this->remove(curr->right, temp->value);
      }
    }

    return curr;
  }

  template <class _Tp>
  bool binary_search_tree<_Tp>::search(_Tp val) {
    return this->search(m_pHead, val);
  }

  template <class _Tp>
  bool binary_search_tree<_Tp>::search(binary_tree_node<_Tp>* curr, _Tp val) {
    if (curr != nullptr) {
      if (curr->value == val) {
        return true;
      }

      if (curr->value > val) {
        this->search(curr->left, val);
      }
      else {
        this->search(curr->right, val);
      }
    }
    
    return false;
  }

  template <class _Tp>
  binary_search_tree<_Tp>::~binary_search_tree() {
    std::queue<binary_tree_node<_Tp>*> nodes;
    
    this->get_nodes_in_post_order(m_pHead, nodes);
    
    while (!nodes.empty()) {
      binary_tree_node<_Tp>* node = nodes.front();
      this->remove(node->value);
      nodes.pop();
    }
  }

}
