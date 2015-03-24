/**
 *  forward_list.h
 *
 *  @author Raul Butuc.
 *  @version 1.2.1 24/03/2015
 */

#pragma once

#include <algorithm>
#include "forward_list_node.h"
#include "forward_list_iterator.h"
#include "forward_list_const_iterator.h"

#ifndef _MSC_VER
#define NOEXCEPT noexcept
#else
#define NOEXCEPT
#endif

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
      iterator begin() NOEXCEPT;
      const_iterator begin() const NOEXCEPT;
      void clear() NOEXCEPT;
      bool empty() const NOEXCEPT;
      iterator end() NOEXCEPT;
      const_iterator end() const NOEXCEPT;
      _Tp& front();
      const _Tp& front() const;
      forward_list<_Tp>& operator=(const forward_list<_Tp>&);
      forward_list<_Tp>& operator=(forward_list<_Tp>&&);
      void pop_front();
      void push_front(const _Tp&);
      void push_front(_Tp&&);
      void reverse() NOEXCEPT;

    private:
      forward_list_node<_Tp>* m_pHead;
  };
  
  template <class _Tp>
  forward_list<_Tp>::forward_list() : m_pHead(nullptr) {}

  template <class _Tp>
  forward_list<_Tp>::forward_list(size_t nr, const _Tp& value) : m_pHead(nullptr) {
    for (size_t index = 0; index < nr; ++index)
      this->push_front(value);
  }

  template <class _Tp>
  forward_list<_Tp>::forward_list(iterator first, iterator last) : m_pHead(nullptr) {
    for (; first != last; ++first)
      this->push_front(*first);
    this->reverse();
  }

  template <class _Tp>
  forward_list<_Tp>::forward_list(const_iterator first, const_iterator last) : m_pHead(nullptr) {
    for (; first != last; ++first)
      this->push_front(*first);
    this->reverse();
  }

  template <class _Tp>
  forward_list<_Tp>::forward_list(const forward_list<_Tp>& _forward_list) : m_pHead(nullptr) {
    const_iterator it = _forward_list.begin();
    for (; it != _forward_list.end(); ++it)
      this->push_front(*it);
    this->reverse();
  }

  template <class _Tp>
  forward_list<_Tp>::forward_list(forward_list<_Tp>&& _forward_list) : m_pHead(nullptr) {
    std::move(_forward_list.begin(), _forward_list.end(), *this);
    _forward_list.~forward_list();
  }

  template <class _Tp>
  forward_list<_Tp>::~forward_list() {
    delete m_pHead;
  }

  template <class _Tp>
  void forward_list<_Tp>::assign(size_t nr, const _Tp& value) {
    this->clear();
    for (size_t index = 0; index < nr; ++index)
      push_front(value);
    this->reverse();
  }

  template <class _Tp>
  void forward_list<_Tp>::assign(iterator first, iterator last) {
    this->clear();
    for (; first != last; ++first)
      push_front(*first);
    this->reverse();
  }

  template <class _Tp>
  void forward_list<_Tp>::assign(const_iterator first, const_iterator last) {
    this->clear();
    for (; first != last; ++first)
      push_front(*first);
    this->reverse();
  }
  
  template <class _Tp>
  typename forward_list<_Tp>::iterator forward_list<_Tp>::begin() NOEXCEPT {
    return forward_list_iterator<_Tp>(m_pHead);
  }

  template <class _Tp>
  typename forward_list<_Tp>::const_iterator forward_list<_Tp>::begin() const NOEXCEPT{
    return forward_list_const_iterator<_Tp>(m_pHead);
  }

  template <class _Tp>
  void forward_list<_Tp>::clear() NOEXCEPT {
    while (m_pHead != nullptr)
      this->pop_front();
  }

  template <class _Tp>
  bool forward_list<_Tp>::empty() const NOEXCEPT {
    return m_pHead == nullptr;
  }
  
  template <class _Tp>
  typename forward_list<_Tp>::iterator forward_list<_Tp>::end() NOEXCEPT {
    return forward_list_iterator<_Tp>(nullptr);
  }

  template <class _Tp>
  typename forward_list<_Tp>::const_iterator forward_list<_Tp>::end() const NOEXCEPT {
    return forward_list_const_iterator<_Tp>(nullptr);
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
  forward_list<_Tp>& forward_list<_Tp>::operator=(const forward_list<_Tp>& _forward_list) {
    this->assign(_forward_list.begin(), _forward_list.end());
    return *this;
  }

  template <class _Tp>
  forward_list<_Tp>& forward_list<_Tp>::operator=(forward_list<_Tp>&& _forward_list) {
    std::move(_forward_list.begin(), _forward_list.end(), *this);
    _forward_list.~forward_list();
    return *this;
  }

  template <class _Tp>
  void forward_list<_Tp>::pop_front() {
    m_pHead = m_pHead->m_pNext;
  }

  template <class _Tp>
  void forward_list<_Tp>::push_front(const _Tp& data) {
    forward_list_node<_Tp>* _node = new forward_list_node<_Tp>(data, m_pHead);
    m_pHead = _node;
  }

  template <class _Tp>
  void forward_list<_Tp>::push_front(_Tp&& data) {
    forward_list_node<_Tp>* _node = new forward_list_node<_Tp>(std::move(data), m_pHead);
    m_pHead = _node;
  }

  template <class _Tp>
  void forward_list<_Tp>::reverse() NOEXCEPT {
    forward_list_node<_Tp>* _tail = m_pHead;
    if (!_tail)
      return;
    while (forward_list_node<_Tp>* _temp = _tail->m_pNext) {
      forward_list_node<_Tp>* _keep = m_pHead;
      m_pHead = _temp;
      _tail->m_pNext = _temp->m_pNext;
      m_pHead->m_pNext = _keep;
    }
  }

}