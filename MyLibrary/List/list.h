/**
 *  list.h
 *
 *  @author Raul Butuc
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
      explicit list(size_t, _Tp const&);
      list(iterator, iterator);
      list(const_iterator, const_iterator);
      list(list<_Tp> const&);
      list(list<_Tp>&&);
      ~list();

      auto assign(size_t, _Tp const&) -> void;
      auto assign(iterator, iterator) -> void;
      auto assign(const_iterator, const_iterator) -> void;
      auto back() -> _Tp&;
      auto back() const -> _Tp const&;
      auto before_begin() NOEXCEPT -> iterator;
      auto before_begin() const NOEXCEPT -> const_iterator;
      auto before_end() NOEXCEPT -> iterator;
      auto before_end() const NOEXCEPT -> const_iterator;
      auto begin() NOEXCEPT -> iterator;
      auto begin() const NOEXCEPT -> const_iterator;
      auto cbefore_begin() NOEXCEPT -> const_iterator;
      auto cbegin() const NOEXCEPT -> const_iterator;
      auto cend() const NOEXCEPT -> const_iterator;
      auto clear() NOEXCEPT -> void;
      auto empty() const NOEXCEPT -> bool;
      auto end() NOEXCEPT -> iterator;
      auto end() const NOEXCEPT -> const_iterator;
      auto erase_after(const_iterator) -> iterator;
      auto erase_after(const_iterator, const_iterator) -> iterator;
      auto erase_before(const_iterator) -> iterator;
      auto erase_before(const_iterator, const_iterator) -> iterator;
      auto front() -> _Tp&;
      auto const& front() const -> _Tp;
      auto insert_after(const_iterator, _Tp const&) -> void;
      auto insert_after(const_iterator, _Tp&&) -> void;
      auto insert_after(const_iterator, size_t, _Tp const&) -> void;
      auto insert_after(const_iterator, iterator, iterator) -> void;
      auto insert_after(const_iterator, const_iterator, const_iterator) -> void;
      auto insert_before(const_iterator, _Tp const&) -> void;
      auto insert_before(const_iterator, _Tp&&) -> void;
      auto insert_before(const_iterator, size_t, _Tp const&) -> void;
      auto insert_before(const_iterator, iterator, iterator) -> void;
      auto insert_before(const_iterator, const_iterator, const_iterator) -> void;
      auto operator=(list<_Tp> const&) -> list<_Tp>&;
      auto operator=(list<_Tp>&&) -> list<_Tp>&;
      auto pop_back() -> void;
      auto pop_front() -> void;
      auto push_back(_Tp const&) -> void;
      auto push_back(_Tp&&) -> void;
      auto push_front(_Tp const&) -> void;
      auto push_front(_Tp&&) -> void;
      auto remove(_Tp const&) -> void;
      auto reverse() NOEXCEPT -> void;
      auto swap(list<_Tp>&) -> void;

    private:

      list_node_base m_pHead, m_pTail;
  };

  template <class _Tp>
  list<_Tp>::list() {
    m_pHead.m_pNext = nullptr;
    m_pTail.m_pPrev = nullptr;
  }

  template <class _Tp>
  list<_Tp>::list(size_t _num, _Tp const& _value)
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
  list<_Tp>::list(list<_Tp> const& _list)
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
  auto list<_Tp>::assign(size_t _num, _Tp const& _value) -> void {
    this->clear();
    this->insert_after(this->cbefore_begin(), _num, _value);
  }

  template <class _Tp>
  void list<_Tp>::assign(iterator _first, iterator _last) -> void {
    this->clear();
    this->insert_after(this->cbefore_begin(), _first, _last);
  }

  template <class _Tp>
  void list<_Tp>::assign(const_iterator _first, const_iterator _last) -> void {
    this->clear();
    this->insert_after(this->cbefore_begin(), _first, _last);
  }

  template <class _Tp>
  auto list<_Tp>::back() -> _Tp& {
    return static_cast<list_node<_Tp>*>(m_pTail)->m_Value;
  }

  template <class _Tp>
  auto list<_Tp>::back() const -> _Tp const& {
    return static_cast<list_node<_Tp>*>(m_pTail)->m_Value;
  }

  template <class _Tp>
  auto list<_Tp>::before_begin() NOEXCEPT -> typename list<_Tp>::iterator {
    return list_iterator<_Tp>(&m_pHead);
  }

  template <class _Tp>
  auto list<_Tp>::before_begin() const NOEXCEPT -> typename list<_Tp>::const_iterator {
    return list_const_iterator<_Tp>(&m_pHead);
  }

  template <class _Tp>
  auto list<_Tp>::before_end() NOEXCEPT -> typename list<_Tp>::iterator {
    return list_iterator<_Tp>(&m_pTail);
  }

  template <class _Tp>
  auto list<_Tp>::before_end() const NOEXCEPT -> typename list<_Tp>::const_iterator {
    return list_const_iterator<_Tp>(&m_pTail);
  }

  template <class _Tp>
  auto list<_Tp>::begin() NOEXCEPT -> typename list<_Tp>::iterator {
    return list_iterator<_Tp>(m_pHead.m_pNext);
  }

  template <class _Tp>
  auto list<_Tp>::begin() const NOEXCEPT -> typename list<_Tp>::const_iterator {
    return list_const_iterator<_Tp>(m_pHead.m_pNext);
  }

  template <class _Tp>
  auto list<_Tp>::cbefore_begin() NOEXCEPT -> typename list<_Tp>::const_iterator{
    return list_const_iterator<_Tp>(&m_pHead);
  }

  template <class _Tp>
  auto list<_Tp>::cbegin() const NOEXCEPT -> typename list<_Tp>::const_iterator {
    return list_const_iterator<_Tp>(m_pHead.m_pNext);
  }

  template <class _Tp>
  auto list<_Tp>::cend() const NOEXCEPT -> typename list<_Tp>::const_iterator {
    return list_const_iterator<_Tp>(nullptr);
  }

  template <class _Tp>
  auto list<_Tp>::clear() NOEXCEPT -> void {
    while (!this->empty())
    this->pop_front();
  }

  template <class _Tp>
  auto list<_Tp>::empty() const NOEXCEPT -> bool {
    return m_pHead.m_pNext == nullptr;
  }

  template <class _Tp>
  auto list<_Tp>::end() NOEXCEPT -> typename list<_Tp>::iterator {
    return list_iterator<_Tp>(
    static_cast<list_node_base*>(nullptr));
  }

  template <class _Tp>
  auto list<_Tp>::end() const NOEXCEPT -> typename list<_Tp>::const_iterator {
    return list_const_iterator<_Tp>(
    static_cast<list_node_base*>(nullptr));
  }

  template <class _Tp>
  auto list<_Tp>::erase_after(const_iterator _position) -> typename list<_Tp>::iterator {
    list_node<_Tp>* _temp =
      static_cast<list_node<_Tp>*>(_position.m_pNode->m_pNext);
    _position.m_pNode->m_pNext = _temp->m_pNext;
    delete _temp;
    return list_iterator<_Tp>(_position.m_pNode->m_pNext);
  }

  template <class _Tp>
  auto list<_Tp>::erase_after(const_iterator _first, const_iterator _last) -> typename list<_Tp>::iterator {
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
  auto list<_Tp>::front() -> _Tp& {
    return static_cast<list_node<_Tp>*>(m_pHead.m_pNext)->m_Value;
  }

  template <class _Tp>
  auto list<_Tp>::front() const -> _Tp const& {
    return static_cast<list_node<_Tp>*>(m_pHead.m_pNext)->m_Value;
  }

  template <class _Tp>
  auto list<_Tp>::insert_after(const_iterator _position,
      _Tp const& _value) -> void {
    list_node<_Tp>* _node = new list_node<_Tp>(_value);
    _node->m_pNext = _position.m_pNode->m_pNext;
    _position.m_pNode->m_pNext = _node;
  }

  template <class _Tp>
  auto list<_Tp>::insert_after(const_iterator _position,
      _Tp&& _value) -> void {
    list_node<_Tp>* _node =
      new list_node<_Tp>(std::move(_value));
    _node->m_pNext = _position.m_pNode->m_pNext;
    _position.m_pNode->m_pNext = _node;
  }

  template <class _Tp>
  auto list<_Tp>::insert_after(const_iterator _position, size_t _num,
      _Tp const& _value) -> void {
    for (size_t i = 0; i < _num; ++i)
      this->insert_after(_position, _value);
  }

  template <class _Tp>
  auto list<_Tp>::insert_after(const_iterator _position,
      iterator _first, iterator _last) -> void {
    for (; _first != _last; ++_position, ++_first) {
      this->insert_after(_position,
        static_cast<list_node<_Tp>*>(_first.m_pNode)->m_Value);
    }
  }

  template <class _Tp>
  auto list<_Tp>::insert_after(const_iterator _position,
      const_iterator _first, const_iterator _last) -> void {
    for (; _first != _last; ++_position, ++_first) {
      this->insert_after(_position,
        static_cast<list_node<_Tp>*>(_first.m_pNode)->m_Value);
    }
  }

  template <class _Tp>
  auto list<_Tp>::insert_before(const_iterator _position,
      _Tp const& _value) -> void {
    list_node<_Tp>* _node = new list_node<_Tp>(_value);
    _node->m_pPrev = _position.m_pNode->m_pPrev;
    _node->m_pNext = _position.m_pNode;
    _position.m_pNode->m_pPrev->m_pNext = _node;
    _position.m_pNode->m_pPrev = _node;
  }

  template <class _Tp>
  auto list<_Tp>::insert_before(const_iterator _position,
      _Tp&& _value) -> void {
    list_node<_Tp>* _node =
      new list_node<_Tp>(std::move(_value));
    _node->m_pPrev = _position.m_pNode->m_pPrev;
    _node->m_pNext = _position.m_pNode;
    _position.m_pNode->m_pPrev->m_pNext = _node;
    _position.m_pNode->m_pPrev = _node;
  }

  template <class _Tp>
  auto list<_Tp>::insert_before(const_iterator _position, size_t _num,
      _Tp const& _value) -> void {
    for (size_t i = 0; i < _num; ++i)
      this->insert_before(_position, _value);
  }

  template <class _Tp>
  auto list<_Tp>::insert_before(const_iterator _position,
      iterator _first, iterator _last) -> void {
    for (; _first != _last; ++_position, ++_first) {
      this->insert_before(_position,
        static_cast<list_node<_Tp>*>(_first.m_pNode)->m_Value);
    }
  }

  template <class _Tp>
  auto list<_Tp>::insert_before(const_iterator _position,
      const_iterator _first, const_iterator _last) -> void {
    for (; _first != _last; ++_position, ++_first) {
      this->insert_before(_position,
        static_cast<list_node<_Tp>*>(_first.m_pNode)->m_Value);
    }
  }

  template <class _Tp>
  auto list<_Tp>::operator=(list<_Tp> const& _list) -> list<_Tp>& {
    if (this != &_list) {
      list<_Tp> _temp(_list);
      this->swap(_temp);
    }
    return *this;
  }

  template <class _Tp>
  auto list<_Tp>::operator=(list<_Tp>&& _list) -> list<_Tp>& {
    if (this != &_list) {
      m_pHead.m_pNext = std::move(_list.m_pHead).m_pNext;
      _list.m_pHead.m_pNext = nullptr;
    }
    return *this;
  }

  template <class _Tp>
  auto list<_Tp>::pop_front() -> void {
    m_pHead.m_pNext = m_pHead.m_pNext->m_pNext;
  }

  template <class _Tp>
  auto list<_Tp>::push_front(_Tp const& _value) -> void {
    list_node<_Tp>* _node = new list_node<_Tp>(_value);
    _node->m_pNext = m_pHead.m_pNext;
    m_pHead.m_pNext = _node;
  }

  template <class _Tp>
  auto list<_Tp>::push_front(_Tp&& _value) -> void {
    list_node<_Tp>* _node =
      new list_node<_Tp>(std::move(_value));
    _node->m_pNext = m_pHead.m_pNext;
    m_pHead.m_pNext = _node;
  }

  template <class _Tp>
  auto list<_Tp>::remove(_Tp const& _value) -> void {
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
  auto list<_Tp>::reverse() NOEXCEPT -> void {
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
  auto list<_Tp>::swap(list<_Tp>& _list) -> void {
    std::swap(this->m_pHead.m_pNext, _list.m_pHead.m_pNext);
  }

}
