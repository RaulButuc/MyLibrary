/**
 *  list.h
 *
 *  @author Raul Butuc.
 *  @version 1.0.0 19/09/2015
 */

#pragma once

#include <utility>
#include "list_node.h"
#include "list_iterator.h"
#include "list_const_iterator.h"

#ifndef _MSC_VER
#define NOEXCEPT  noexcept
#else
#define NOEXCEPT 
#endif

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
      _Tp& back();
      const _Tp& back() const;
      iterator before_begin() NOEXCEPT ;
      const_iterator before_begin() const NOEXCEPT ;
      iterator before_end() NOEXCEPT ;
      const_iterator before_end() const NOEXCEPT ;
      iterator begin() NOEXCEPT ;
      const_iterator begin() const NOEXCEPT ;
      const_iterator cbefore_begin() NOEXCEPT ;
      const_iterator cbegin() const NOEXCEPT ;
      const_iterator cend() const NOEXCEPT ;
      void clear() NOEXCEPT ;
      bool empty() const NOEXCEPT ;
      iterator end() NOEXCEPT ;
      const_iterator end() const NOEXCEPT ;
      iterator erase_after(const_iterator);
      iterator erase_after(const_iterator, const_iterator);
      iterator erase_before(const_iterator);
      iterator erase_before(const_iterator, const_iterator);
      _Tp& front();
      const _Tp& front() const;
      void insert_after(const_iterator, const _Tp&);
      void insert_after(const_iterator, _Tp&&);
      void insert_after(const_iterator, size_t, const _Tp&);
      void insert_after(const_iterator, iterator, iterator);
      void insert_after(const_iterator, const_iterator, const_iterator);
      void insert_before(const_iterator, const _Tp&);
      void insert_before(const_iterator, _Tp&&);
      void insert_before(const_iterator, size_t, const _Tp&);
      void insert_before(const_iterator, iterator, iterator);
      void insert_before(const_iterator, const_iterator, const_iterator);
      list<_Tp>& operator=(const list<_Tp>&);
      list<_Tp>& operator=(list<_Tp>&&);
      void pop_back();
      void pop_front();
      void push_back(const _Tp&);
      void push_back(_Tp&&);
      void push_front(const _Tp&);
      void push_front(_Tp&&);
      void remove(const _Tp&);
      void reverse() NOEXCEPT ;
      void swap(list<_Tp>&);

    private:
      list_node_base m_pHead, m_pTail;
  };

  template <class _Tp>
  list<_Tp>::list() {
    m_pHead.m_pNext = nullptr;
    m_pTail.m_pPrev = nullptr;
  }

  template <class _Tp>
  list<_Tp>::list(size_t _num, const _Tp& _value)
      : m_pHead(), m_pTail() {
    this->insert_after(this->cbefore_begin(), _num, _value);
  }

  template <class _Tp>
  list<_Tp>::list(iterator _first, iterator _last)
      : m_pHead(), m_pTail() {
    this->insert_after(this->cbefore_begin(), _first, _last);
  }

  template <class _Tp>
  list<_Tp>::list(const_iterator _first,
      const_iterator _last) : m_pHead(), m_pTail() {
    this->insert_after(this->cbefore_begin(), _first, _last);
  }

  template <class _Tp>
  list<_Tp>::list(const list<_Tp>& _list)
      : m_pHead(), m_pTail() {
    this->insert_after(this->cbefore_begin(), _list.cbegin(),
      _list.cend());
  }

  template <class _Tp>
  list<_Tp>::list(list<_Tp>&& _list)
      : m_pHead(), m_pTail() {
    *this = std::move(_list);
    _list.m_pHead.m_pNext = nullptr;
  }

  template <class _Tp>
  list<_Tp>::~list() {
    list_node_base* _node = m_pHead.m_pNext;
    while (_node != nullptr) {
      list_node_base* _temp =
        static_cast<list_node<_Tp>*>(_node);
      _node = _node->m_pNext;
      delete _temp;
    }
  }

  template <class _Tp>
  void list<_Tp>::assign(size_t _num, const _Tp& _value) {
    this->clear();
    this->insert_after(this->cbefore_begin(), _num, _value);
  }

  template <class _Tp>
  void list<_Tp>::assign(iterator _first, iterator _last) {
    this->clear();
    this->insert_after(this->cbefore_begin(), _first, _last);
  }

  template <class _Tp>
  void list<_Tp>::assign(const_iterator _first, const_iterator _last) {
    this->clear();
    this->insert_after(this->cbefore_begin(), _first, _last);
  }

  template <class _Tp>
  _Tp& list<_Tp>::back() {
    return static_cast<list_node<_Tp>*>(m_pTail)->m_Value;
  }

  template <class _Tp>
  const _Tp& list<_Tp>::back() const {
    return static_cast<list_node<_Tp>*>(m_pTail)->m_Value;
  }

  template <class _Tp>
  typename list<_Tp>::iterator
    list<_Tp>::before_begin() NOEXCEPT {
    return list_iterator<_Tp>(&m_pHead);
  }

    template <class _Tp>
  typename list<_Tp>::const_iterator
    list<_Tp>::before_begin() const NOEXCEPT {
    return list_const_iterator<_Tp>(&m_pHead);
  }

  template <class _Tp>
  typename list<_Tp>::iterator
    list<_Tp>::before_end() NOEXCEPT {
    return list_iterator<_Tp>(&m_pTail);
  }

  template <class _Tp>
  typename list<_Tp>::const_iterator
    list<_Tp>::before_end() const NOEXCEPT {
    return list_const_iterator<_Tp>(&m_pTail);
  }

    template <class _Tp>
  typename list<_Tp>::iterator list<_Tp>::begin() NOEXCEPT {
    return list_iterator<_Tp>(m_pHead.m_pNext);
  }

    template <class _Tp>
  typename list<_Tp>::const_iterator
    list<_Tp>::begin() const NOEXCEPT {
    return list_const_iterator<_Tp>(m_pHead.m_pNext);
  }

    template <class _Tp>
  typename list<_Tp>::const_iterator
    list<_Tp>::cbefore_begin() NOEXCEPT {
    return list_const_iterator<_Tp>(&m_pHead);
  }

    template <class _Tp>
  typename list<_Tp>::const_iterator
    list<_Tp>::cbegin() const NOEXCEPT {
    return list_const_iterator<_Tp>(m_pHead.m_pNext);
  }

    template <class _Tp>
  typename list<_Tp>::const_iterator
    list<_Tp>::cend() const NOEXCEPT {
    return list_const_iterator<_Tp>(nullptr);
  }

    template <class _Tp>
  void list<_Tp>::clear() NOEXCEPT {
    while (!this->empty())
    this->pop_front();
  }

    template <class _Tp>
  bool list<_Tp>::empty() const NOEXCEPT {
    return m_pHead.m_pNext == nullptr;
  }

    template <class _Tp>
  typename list<_Tp>::iterator list<_Tp>::end() NOEXCEPT {
    return list_iterator<_Tp>(
    static_cast<list_node_base*>(nullptr));
  }

    template <class _Tp>
  typename list<_Tp>::const_iterator
    list<_Tp>::end() const NOEXCEPT {
    return list_const_iterator<_Tp>(
    static_cast<list_node_base*>(nullptr));
  }

    template <class _Tp>
  typename list<_Tp>::iterator
    list<_Tp>::erase_after(const_iterator _position) {
    list_node<_Tp>* _temp =
      static_cast<list_node<_Tp>*>(_position.m_pNode->m_pNext);
    _position.m_pNode->m_pNext = _temp->m_pNext;
    delete _temp;
    return list_iterator<_Tp>(_position.m_pNode->m_pNext);
  }

  template <class _Tp>
  typename list<_Tp>::iterator
    list<_Tp>::erase_after(const_iterator _first, const_iterator _last) {
    list_node<_Tp>* _node_first =
      static_cast<list_node<_Tp>*>(_first.m_pNode->m_pNext);
    list_node<_Tp>* _node_last =
      static_cast<list_node<_Tp>*>(_last.m_pNode);
    while (_node_first != _node_last) {
      list_node<_Tp>* _temp =
        static_cast<list_node<_Tp>*>(_first.m_pNode->m_pNext);
      _first.m_pNode->m_pNext = _temp->m_pNext;
      delete _temp;
      _node_first =
        static_cast<list_node<_Tp>*>(_first.m_pNode->m_pNext);
    }
    return list_iterator<_Tp>(_first.m_pNode->m_pNext);
  }

  template <class _Tp>
  _Tp& list<_Tp>::front() {
    return static_cast<list_node<_Tp>*>(m_pHead.m_pNext)->m_Value;
  }

  template <class _Tp>
  const _Tp& list<_Tp>::front() const {
    return static_cast<list_node<_Tp>*>(m_pHead.m_pNext)->m_Value;
  }

  template <class _Tp>
  void list<_Tp>::insert_after(const_iterator _position,
      const _Tp& _value) {
    list_node<_Tp>* _node = new list_node<_Tp>(_value);
    _node->m_pNext = _position.m_pNode->m_pNext;
    _position.m_pNode->m_pNext = _node;
  }

  template <class _Tp>
  void list<_Tp>::insert_after(const_iterator _position,
      _Tp&& _value) {
    list_node<_Tp>* _node =
      new list_node<_Tp>(std::move(_value));
    _node->m_pNext = _position.m_pNode->m_pNext;
    _position.m_pNode->m_pNext = _node;
  }

  template <class _Tp>
  void list<_Tp>::insert_after(const_iterator _position, size_t _num,
      const _Tp& _value) {
    for (size_t i = 0; i < _num; ++i)
      this->insert_after(_position, _value);
  }

  template <class _Tp>
  void list<_Tp>::insert_after(const_iterator _position,
      iterator _first, iterator _last) {
    for (; _first != _last; ++_position, ++_first) {
      this->insert_after(_position,
        static_cast<list_node<_Tp>*>(_first.m_pNode)->m_Value);
    }
  }

  template <class _Tp>
  void list<_Tp>::insert_after(const_iterator _position,
      const_iterator _first, const_iterator _last) {
    for (; _first != _last; ++_position, ++_first) {
      this->insert_after(_position,
        static_cast<list_node<_Tp>*>(_first.m_pNode)->m_Value);
    }
  }

  template <class _Tp>
  void list<_Tp>::insert_before(const_iterator _position,
      const _Tp& _value) {
    list_node<_Tp>* _node = new list_node<_Tp>(_value);
    _node->m_pPrev = _position.m_pNode->m_pPrev;
    _node->m_pNext = _position.m_pNode;
    _position.m_pNode->m_pPrev->m_pNext = _node;
    _position.m_pNode->m_pPrev = _node;
  }

  template <class _Tp>
  void list<_Tp>::insert_before(const_iterator _position,
      _Tp&& _value) {
    list_node<_Tp>* _node =
      new list_node<_Tp>(std::move(_value));
    _node->m_pPrev = _position.m_pNode->m_pPrev;
    _node->m_pNext = _position.m_pNode;
    _position.m_pNode->m_pPrev->m_pNext = _node;
    _position.m_pNode->m_pPrev = _node;
  }

  template <class _Tp>
  void list<_Tp>::insert_before(const_iterator _position, size_t _num,
      const _Tp& _value) {
    for (size_t i = 0; i < _num; ++i)
      this->insert_before(_position, _value);
  }

  template <class _Tp>
  void list<_Tp>::insert_before(const_iterator _position,
      iterator _first, iterator _last) {
    for (; _first != _last; ++_position, ++_first) {
      this->insert_before(_position,
        static_cast<list_node<_Tp>*>(_first.m_pNode)->m_Value);
    }
  }

  template <class _Tp>
  void list<_Tp>::insert_before(const_iterator _position,
      const_iterator _first, const_iterator _last) {
    for (; _first != _last; ++_position, ++_first) {
      this->insert_before(_position,
        static_cast<list_node<_Tp>*>(_first.m_pNode)->m_Value);
    }
  }

  template <class _Tp>
  list<_Tp>& list<_Tp>::operator=(
    const list<_Tp>& _list) {
    if (this != &_list) {
      list<_Tp> _temp(_list);
      this->swap(_temp);
    }
    return *this;
  }

  template <class _Tp>
  list<_Tp>& list<_Tp>::operator=(
      list<_Tp>&& _list) {
    if (this != &_list) {
      m_pHead.m_pNext = std::move(_list.m_pHead).m_pNext;
      _list.m_pHead.m_pNext = nullptr;
    }
    return *this;
  }

  template <class _Tp>
  void list<_Tp>::pop_front() {
    m_pHead.m_pNext = m_pHead.m_pNext->m_pNext;
  }

  template <class _Tp>
  void list<_Tp>::push_front(const _Tp& _value) {
    list_node<_Tp>* _node = new list_node<_Tp>(_value);
    _node->m_pNext = m_pHead.m_pNext;
    m_pHead.m_pNext = _node;
  }

  template <class _Tp>
  void list<_Tp>::push_front(_Tp&& _value) {
    list_node<_Tp>* _node =
      new list_node<_Tp>(std::move(_value));
    _node->m_pNext = m_pHead.m_pNext;
    m_pHead.m_pNext = _node;
  }

  template <class _Tp>
  void list<_Tp>::remove(const _Tp& _value) {
    list_node<_Tp>* _node = m_pHead.m_pNext;

    do {
      if (_node->m_Value == _value) {
        _node->m_pPrev->m_pNext = _node->m_pNext;
        break;
      }

      _node = _node->m_pNext;
    } while(_node != nullptr);
  }

  template <class _Tp>
  void list<_Tp>::reverse() NOEXCEPT {
    list_node_base* _tail = m_pHead.m_pNext;
    if (!_tail)
      return;
    while (list_node_base* _temp = _tail->m_pNext) {
      list_node_base* _keep = m_pHead.m_pNext;
      m_pHead.m_pNext = _temp;
      _tail->m_pNext = _temp->m_pNext;
      m_pHead.m_pNext->m_pNext = _keep;
    }
  }

  template <class _Tp>
  void list<_Tp>::swap(list<_Tp>& _list) {
    std::swap(this->m_pHead.m_pNext, _list.m_pHead.m_pNext);
  }

}
