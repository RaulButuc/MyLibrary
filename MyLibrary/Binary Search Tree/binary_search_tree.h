/**
 *  binary_search_tree.h
 *
 *  @author Raul Butuc.
 *  @version 1.0.1 01/11/2015
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
      void displayPreOrder();
      void displayInOrder();
      void displayPostOrder();
      bool empty();
      void insert(_Tp);
      void insert(std::vector<_Tp>);
      void remove(_Tp);
      void remove(std::vector<_Tp>);
      bool search(_Tp);
      ~binary_search_tree();

    private:
      binary_tree_node<_Tp>* m_pHead;

      void displayPreOrder(binary_tree_node<_Tp>*);
      void displayInOrder(binary_tree_node<_Tp>*);
      void displayPostOrder(binary_tree_node<_Tp>*);
      void displayNode(binary_tree_node<_Tp>*);
      binary_tree_node<_Tp>* getMinValueNode(binary_tree_node<_Tp>*);
      binary_tree_node<_Tp>* getNodeByValue(binary_tree_node<_Tp>*, _Tp);
      void getNodesInPostOrder(binary_tree_node<_Tp>*, std::queue<binary_tree_node<_Tp>*>&);
      void insert(binary_tree_node<_Tp>**, binary_tree_node<_Tp>*, _Tp, bool);
      binary_tree_node<_Tp>* remove(binary_tree_node<_Tp>*, _Tp);
      bool search(binary_tree_node<_Tp>*, _Tp);

  };

  template <class _Tp>
  binary_search_tree<_Tp>::binary_search_tree() : m_pHead(nullptr) {}

  template <class _Tp>
  void binary_search_tree<_Tp>::displayPreOrder() {
    if (m_pHead != nullptr) {
      this->displayPreOrder(m_pHead);
    }
  }

  template <class _Tp>
  void binary_search_tree<_Tp>::displayPreOrder(binary_tree_node<_Tp>* curr) {
    this->displayNode(curr);
  
    if (curr->left != nullptr) {
      this->displayPreOrder(curr->left);
    }

    if (curr->right != nullptr) {
      this->displayPreOrder(curr->right);
    }
  }

  template <class _Tp>
  void binary_search_tree<_Tp>::displayInOrder() {
    if (m_pHead != nullptr) {
      this->displayInOrder(m_pHead);
    }
  }

  template <class _Tp>
  void binary_search_tree<_Tp>::displayInOrder(binary_tree_node<_Tp>* curr) {
    if (curr->left != nullptr) {
      this->displayInOrder(curr->left);
    }

    this->displayNode(curr);

    if (curr->right != nullptr) {
      this->displayInOrder(curr->right);
    }
  }

  template <class _Tp>
  void binary_search_tree<_Tp>::displayPostOrder() {
    if (m_pHead != nullptr) {
      this->displayPostOrder(m_pHead);
    }
  }

  template <class _Tp>
  void binary_search_tree<_Tp>::displayPostOrder(binary_tree_node<_Tp>* curr) {
    if (curr->left != nullptr) {
      this->displayPostOrder(curr->left);
    }

    if (curr->right != nullptr) {
      this->displayPostOrder(curr->right);
    }

    this->displayNode(curr);
  }

  template <class _Tp>
  void binary_search_tree<_Tp>::displayNode(binary_tree_node<_Tp>* curr) {
    std::cout << curr->value << " ";
  }

  template <class _Tp>
  bool binary_search_tree<_Tp>::empty() {
    return m_pHead == nullptr;
  }

  template <class _Tp>
  binary_tree_node<_Tp>* binary_search_tree<_Tp>::getMinValueNode(binary_tree_node<_Tp>* curr) {
    while (curr->left != nullptr) {
      curr = curr->left;
    }

    return curr;
  }

  template <class _Tp>
  binary_tree_node<_Tp>* binary_search_tree<_Tp>::getNodeByValue(binary_tree_node<_Tp>* curr,
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
  void binary_search_tree<_Tp>::getNodesInPostOrder(binary_tree_node<_Tp>* curr,
      std::queue<binary_tree_node<_Tp>*>& nodes) {
    if (curr != nullptr) {
      this->getNodesInPostOrder(curr->left, nodes);
      this->getNodesInPostOrder(curr->right, nodes);
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
        binary_tree_node<_Tp>* temp = this->getMinValueNode(curr->right);
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
    
    this->getNodesInPostOrder(m_pHead, nodes);
    
    while (!nodes.empty()) {
      binary_tree_node<_Tp>* node = nodes.front();
      this->remove(node->value);
      nodes.pop();
    }
  }

}
