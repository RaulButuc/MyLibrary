/**
 *  forward_list.h
 *
 *  @author Raul Butuc.
 *  @version 1.2.0 23/03/2015
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
      _Tp& front();
      const _Tp& front() const;
      iterator begin();
      const_iterator begin() const;
      void clear();
      bool empty() const;
      iterator end();
      const_iterator end() const;
      void push_front(const _Tp&);
      void pop_front();
      void reverse();
      size_t size() const;

    private:
      forward_list_node<_Tp>* m_pHead;
      size_t m_Size;
  };
  
  template <class _Tp>
  forward_list<_Tp>::forward_list() : m_pHead(nullptr), m_Size(0) {}

  template <class _Tp>
  forward_list<_Tp>::forward_list(size_t nr, const _Tp& value) : m_pHead(nullptr), m_Size(0) {
    for (size_t index = 0; index < nr; ++index) {
      push_front(value);
    }
  }

  template <class _Tp>
  forward_list<_Tp>::forward_list(iterator first, iterator last) : m_pHead(nullptr), m_Size(0) {
    for (; first != last; ++first) {
      push_front(*first);
    }
  }

  template <class _Tp>
  forward_list<_Tp>::forward_list(const_iterator first, const_iterator last) : m_pHead(nullptr), m_Size(0) {
    for (; first != last; ++first) {
      push_front(*first);
    }
  }

  template <class _Tp>
  forward_list<_Tp>::forward_list(const forward_list<_Tp>& _forward_list) : m_pHead(nullptr), m_Size(0) {
    const_iterator it = _forward_list.begin();
    for (; it != _forward_list.end(); ++it) {
      push_front(*it);
    }
  }

  template <class _Tp>
  forward_list<_Tp>::forward_list(forward_list<_Tp>&& _forward_list) : m_pHead(nullptr), m_Size(0) {
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
      push_front(value);
    }
  }

  template <class _Tp>
  void forward_list<_Tp>::assign(iterator first, iterator last) {
    clear();
    for (; first != last; ++first) { 
      push_front(*first);
    }
  }

  template <class _Tp>
  void forward_list<_Tp>::assign(const_iterator first, const_iterator last) {
    clear();
    for (; first != last; ++first) {
      push_front(*first);
    }
  }

  template <class _Tp>
  _Tp& forward_list<_Tp>::front() {
    return m_pHead->m_Data;
  }

  template <class _Tp>
  const _Tp& forward_list<_Tp>::front() const {
    return m_pHead->m_Data;
  }

  template <class _Tp>
  void forward_list<_Tp>::clear() {
    while (m_pHead != nullptr) { pop_front(); }
  }

  template <class _Tp>
  bool forward_list<_Tp>::empty() const {
    return m_pHead == nullptr;
  }
  
  template <class _Tp>
  void forward_list<_Tp>::push_front(const _Tp& data) {
    forward_list_node<_Tp>* _node = new forward_list_node<_Tp>(data, m_pHead);
    m_pHead = _node;
    m_Size++;
  }

  template <class _Tp>
  void forward_list<_Tp>::pop_front() {
    m_pHead = m_pHead->m_pNext;
    m_Size--;
  }

  template <class _Tp>
  void forward_list<_Tp>::reverse() {
    
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