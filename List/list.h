/**
 *  list.h
 *
 *  @author Raul Butuc.
 *  @version 1.0.3 19/03/2015
 */

#pragma once

#include <algorithm>
#include "list_node.h"
#include "list_iterator.h"
#include "list_const_iterator.h"

namespace my_library {

  template <class _Tp>
  class list {

    public:
      typedef list_iterator<_Tp> iterator;
      typedef list_const_iterator<_Tp> const_iterator;

      list();
      explicit list(size_t, const _Tp&);
      list(iterator, iterator);
      list(const_iterator, const_iterator);
      list(const list<_Tp>&);
      list(list<_Tp>&&);
      ~list();

      void assign(size_t, const _Tp&);
      void assign(iterator, iterator);
      void assign(const_iterator, const_iterator);
      void clear();
      bool empty() const;
      void push(const _Tp&);
      void pop();
      size_t size() const;

      iterator begin();
      iterator end();
      const_iterator begin() const;
      const_iterator end() const;

    private:
      list_node<_Tp>* m_pHead;
      list_node<_Tp>* m_pTail;
      size_t m_Size;
  };
  
  template <class _Tp>
  list<_Tp>::list() : m_pHead(nullptr), m_pTail(nullptr), m_Size(0) {}

  template <class _Tp>
  list<_Tp>::list(size_t nr, const _Tp& value) : m_pHead(nullptr), m_pTail(nullptr), m_Size(0) {
    for (size_t index = 0; index < nr; ++index) {
      push(value);
    }
  }

  template <class _Tp>
  list<_Tp>::list(iterator first, iterator last) : m_pHead(nullptr), m_pTail(nullptr), m_Size(0) {
    for (; first != last; ++first) {
      push(*first);
    }
  }

  template <class _Tp>
  list<_Tp>::list(const_iterator first, const_iterator last) : m_pHead(nullptr), m_pTail(nullptr), m_Size(0) {
    for (; first != last; ++first) {
      push(*first);
    }
  }

  template <class _Tp>
  list<_Tp>::list(const list<_Tp>& _list) : m_pHead(nullptr), m_pTail(nullptr), m_Size(0) {
    const_iterator it = _list.begin();
    for (; it != _list.end(); ++it) {
      push(*it);
    }
  }

  template <class _Tp>
  list<_Tp>::list(list<_Tp>&& _list) : m_pHead(nullptr), m_pTail(nullptr), m_Size(0) {
    std::move(_list.begin(), _list.end(), *this);
    _list.~list();
  }

  template <class _Tp>
  list<_Tp>::~list() {
    delete m_pHead;
  }

  template <class _Tp>
  void list<_Tp>::assign(size_t nr, const _Tp& value) {
    clear();
    for (size_t index = 0; index < nr; ++index) {
      push(value);
    }
  }

  template <class _Tp>
  void list<_Tp>::assign(iterator first, iterator last) {
    clear();
    for (; first != last; ++first) { 
      push(*first);
    }
  }

  template <class _Tp>
  void list<_Tp>::assign(const_iterator first, const_iterator last) {
    clear();
    for (; first != last; ++first) {
      push(*first);
    }
  }

  template <class _Tp>
  void list<_Tp>::clear() {
    while (m_pHead != nullptr) {
      pop();
    }
  }

  template <class _Tp>
  bool list<_Tp>::empty() const {
    return m_pHead == nullptr;
  }
  
  template <class _Tp>
  void list<_Tp>::push(const _Tp& node) {
    list_node<_Tp>* _node = new list_node<_Tp>(node, nullptr);

    if (m_pHead == nullptr) m_pHead = _node;
    else m_pTail->m_pNext = _node;

    m_pTail = _node;
    m_Size++;
  }

  template <class _Tp>
  void list<_Tp>::pop() {
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
  size_t list<_Tp>::size() const {
    return m_Size;
  }

  template <class _Tp>
  typename list<_Tp>::iterator list<_Tp>::begin() {
    return list_iterator<_Tp>(m_pHead);
  }

  template <class _Tp>
  typename list<_Tp>::iterator list<_Tp>::end() {
    return list_iterator<_Tp>(nullptr);
  }

  template <class _Tp>
  typename list<_Tp>::const_iterator list<_Tp>::begin() const {
    return list_const_iterator<_Tp>(m_pHead);
  }

  template <class _Tp>
  typename list<_Tp>::const_iterator list<_Tp>::end() const {
    return list_const_iterator<_Tp>(nullptr);
  }

}
