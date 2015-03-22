/**
 *  forward_list.h
 *
 *  @author Raul Butuc.
 *  @version 1.1.0 21/03/2015
 */

#pragma once

#include <algorithm>
#include "forward_list_node.h"
#include "forward_list_iterator.h"
#include "forward_list_const_iterator.h"

namespace my_library {

  template <class _Tp>
  class forward_list {

    public:
      typedef forward_list_iterator<_Tp> iterator;
      typedef forward_list_const_iterator<_Tp> const_iterator;

      forward_list();
      explicit forward_list(size_t, const _Tp&);
      forward_list(iterator, iterator);
      forward_list(const_iterator, const_iterator);
      forward_list(const forward_list<_Tp>&);
      forward_list(forward_list<_Tp>&&);
      ~forward_list();

      void assign(size_t, const _Tp&);
      void assign(iterator, iterator);
      void assign(const_iterator, const_iterator);
      _Tp& back();
      const _Tp& back() const;
      iterator begin();
      const_iterator begin() const;
      void clear();
      bool empty() const;
      iterator end();
      const_iterator end() const;
      void push_back(const _Tp&);
      void pop_back();
      size_t size() const;

    private:
      forward_list_node<_Tp>* m_pHead;
      forward_list_node<_Tp>* m_pTail;
      size_t m_Size;
  };
  
  template <class _Tp>
  forward_list<_Tp>::forward_list() : m_pHead(nullptr), m_pTail(nullptr), m_Size(0) {}

  template <class _Tp>
  forward_list<_Tp>::forward_list(size_t nr, const _Tp& value) : m_pHead(nullptr), m_pTail(nullptr), m_Size(0) {
    for (size_t index = 0; index < nr; ++index) {
      push_back(value);
    }
  }

  template <class _Tp>
  forward_list<_Tp>::forward_list(iterator first, iterator last) : m_pHead(nullptr), m_pTail(nullptr), m_Size(0) {
    for (; first != last; ++first) {
      push_back(*first);
    }
  }

  template <class _Tp>
  forward_list<_Tp>::forward_list(const_iterator first, const_iterator last) : m_pHead(nullptr), m_pTail(nullptr), m_Size(0) {
    for (; first != last; ++first) {
      push_back(*first);
    }
  }

  template <class _Tp>
  forward_list<_Tp>::forward_list(const forward_list<_Tp>& _forward_list) : m_pHead(nullptr), m_pTail(nullptr), m_Size(0) {
    const_iterator it = _forward_list.begin();
    for (; it != _forward_list.end(); ++it) {
      push_back(*it);
    }
  }

  template <class _Tp>
  forward_list<_Tp>::forward_list(forward_list<_Tp>&& _forward_list) : m_pHead(nullptr), m_pTail(nullptr), m_Size(0) {
    std::move(_forward_list.begin(), _forward_list.end(), *this);
    _forward_list.~forward_list();
  }

  template <class _Tp>
  forward_list<_Tp>::~forward_list() {
    delete m_pHead;
  }

  template <class _Tp>
  void forward_list<_Tp>::assign(size_t nr, const _Tp& value) {
    clear();
    for (size_t index = 0; index < nr; ++index) {
      push_back(value);
    }
  }

  template <class _Tp>
  void forward_list<_Tp>::assign(iterator first, iterator last) {
    clear();
    for (; first != last; ++first) { 
      push_back(*first);
    }
  }

  template <class _Tp>
  void forward_list<_Tp>::assign(const_iterator first, const_iterator last) {
    clear();
    for (; first != last; ++first) {
      push_back(*first);
    }
  }

  template <class _Tp>
  _Tp& forward_list<_Tp>::back() {
    return m_pTail->m_Node;
  }

  template <class _Tp>
  const _Tp& forward_list<_Tp>::back() const {
    return m_pTail->m_Node;
  }

  template <class _Tp>
  void forward_list<_Tp>::clear() {
    while (m_pHead != nullptr) { pop_back(); }
  }

  template <class _Tp>
  bool forward_list<_Tp>::empty() const {
    return m_pHead == nullptr;
  }
  
  template <class _Tp>
  void forward_list<_Tp>::push_back(const _Tp& node) {
    forward_list_node<_Tp>* _node = new forward_list_node<_Tp>(node, nullptr);

    if (m_pHead == nullptr) { m_pHead = _node; }
    else { m_pTail->m_pNext = _node; }

    m_pTail = _node;
    m_Size++;
  }

  template <class _Tp>
  void forward_list<_Tp>::pop_back() {
    iterator current = begin();
    iterator prev = nullptr;
    iterator last = current;
    
    while (current != end()) {
      prev = last;
      last = current;
      ++current;
    }

    delete last.m_pNode;
    prev.m_pNode->m_pNext = nullptr;
    m_Size--;
  }

  template <class _Tp>
  size_t forward_list<_Tp>::size() const {
    return m_Size;
  }

  template <class _Tp>
  typename forward_list<_Tp>::iterator forward_list<_Tp>::begin() {
    return forward_list_iterator<_Tp>(m_pHead);
  }

  template <class _Tp>
  typename forward_list<_Tp>::iterator forward_list<_Tp>::end() {
    return forward_list_iterator<_Tp>(nullptr);
  }

  template <class _Tp>
  typename forward_list<_Tp>::const_iterator forward_list<_Tp>::begin() const {
    return forward_list_const_iterator<_Tp>(m_pHead);
  }

  template <class _Tp>
  typename forward_list<_Tp>::const_iterator forward_list<_Tp>::end() const {
    return forward_list_const_iterator<_Tp>(nullptr);
  }

}