/**
 *  forward_list.h
 *
 *  @author Raul Butuc
 */

#pragma once

#include <utility>
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
      explicit forward_list(size_t, _Tp const&);
      forward_list(iterator, iterator);
      forward_list(const_iterator, const_iterator);
      forward_list(forward_list<_Tp> const&);
      forward_list(forward_list<_Tp>&&);
      ~forward_list();

      auto assign(size_t, _Tp const&) -> void;
      auto assign(iterator, iterator) -> void;
      auto assign(const_iterator, const_iterator) -> void;
      auto before_begin() NOEXCEPT -> iterator;
      auto before_begin() const NOEXCEPT -> const_iterator;
      auto begin() NOEXCEPT -> iterator;
      auto begin() const NOEXCEPT -> const_iterator;
      auto cbefore_begin() NOEXCEPT -> const_iterator;
      auto cbegin() const NOEXCEPT -> const_iterator;
      auto cend() const NOEXCEPT -> const_iterator;
      auto clear() NOEXCEPT -> void;
      auto empty() const NOEXCEPT -> bool;
      auto end() NOEXCEPT ->iterator;
      auto end() const NOEXCEPT -> const_iterator;
      auto erase_after(const_iterator) -> iterator;
      auto erase_after(const_iterator, const_iterator) -> iterator;
      auto front() ->_Tp&;
      auto front() const ->_Tp const&;
      auto insert_after(const_iterator, _Tp const&) -> void;
      auto insert_after(const_iterator, _Tp&&) -> void;
      auto insert_after(const_iterator, size_t, _Tp const&) -> void;
      auto insert_after(const_iterator, iterator, iterator) -> void;
      auto insert_after(const_iterator, const_iterator, const_iterator) -> void;
      auto operator=(forward_list<_Tp> const&) -> forward_list<_Tp>&;
      auto operator=(forward_list<_Tp>&&) -> forward_list<_Tp>&;
      auto pop_front() -> void;
      auto push_front(_Tp const&) -> void;
      auto push_front(_Tp&&) -> void;
      auto reverse() NOEXCEPT -> void;
      auto swap(forward_list<_Tp>&) -> void;

    private:

      forward_list_node_base m_pHead;

  };

  template <class _Tp>
  forward_list<_Tp>::forward_list() { 
    m_pHead.m_pNext = nullptr; 
  }

  template <class _Tp>
  forward_list<_Tp>::forward_list(size_t _num, _Tp const& _value)
      : m_pHead() {
    this->insert_after(this->cbefore_begin(), _num, _value);
  }

  template <class _Tp>
  forward_list<_Tp>::forward_list(iterator _first, iterator _last)
      : m_pHead() {
    this->insert_after(this->cbefore_begin(), _first, _last);
  }

  template <class _Tp>
  forward_list<_Tp>::forward_list(const_iterator _first, 
      const_iterator _last) : m_pHead() {
    this->insert_after(this->cbefore_begin(), _first, _last);
  }

  template <class _Tp>
  forward_list<_Tp>::forward_list(forward_list<_Tp> const& _forward_list)
      : m_pHead() {
    this->insert_after(this->cbefore_begin(), _forward_list.cbegin(),
      _forward_list.cend());
  }

  template <class _Tp>
  forward_list<_Tp>::forward_list(forward_list<_Tp>&& _forward_list)
      : m_pHead() {
    *this = std::move(_forward_list);
    _forward_list.m_pHead.m_pNext = nullptr;
  }

  template <class _Tp>
  forward_list<_Tp>::~forward_list() {
    forward_list_node_base* _node = m_pHead.m_pNext;
    while (_node != nullptr) {
      forward_list_node_base* _temp = 
        static_cast<forward_list_node<_Tp>*>(_node);
      _node = _node->m_pNext;
      delete _temp;
    }
  }

  template <class _Tp>
  auto forward_list<_Tp>::assign(size_t _num, _Tp const& _value) -> void {
    this->clear();
    this->insert_after(this->cbefore_begin(), _num, _value);
  }

  template <class _Tp>
  auto forward_list<_Tp>::assign(iterator _first, iterator _last) -> void {
    this->clear();
    this->insert_after(this->cbefore_begin(), _first, _last);
  }

  template <class _Tp>
  auto forward_list<_Tp>::assign(const_iterator _first, const_iterator _last) -> void {
    this->clear();
    this->insert_after(this->cbefore_begin(), _first, _last);
  }

  template <class _Tp>
  auto forward_list<_Tp>::before_begin() NOEXCEPT
      -> typename forward_list<_Tp>::iterator {
    return forward_list_iterator<_Tp>(&m_pHead);
  }

  template <class _Tp>
  auto forward_list<_Tp>::before_begin() const NOEXCEPT
      -> typename forward_list<_Tp>::const_iterator {
    return forward_list_const_iterator<_Tp>(&m_pHead);
  }

  template <class _Tp>
  auto forward_list<_Tp>::begin() NOEXCEPT
      -> typename forward_list<_Tp>::iterator {
    return forward_list_iterator<_Tp>(m_pHead.m_pNext);
  }

  template <class _Tp>
  auto forward_list<_Tp>::begin() const NOEXCEPT
      -> typename forward_list<_Tp>::const_iterator {
    return forward_list_const_iterator<_Tp>(m_pHead.m_pNext);
  }

  template <class _Tp>
  auto forward_list<_Tp>::cbefore_begin() NOEXCEPT
      -> typename forward_list<_Tp>::const_iterator {
    return forward_list_const_iterator<_Tp>(&m_pHead);
  }

  template <class _Tp>
  auto forward_list<_Tp>::cbegin() const NOEXCEPT
      -> typename forward_list<_Tp>::const_iterator {
    return forward_list_const_iterator<_Tp>(m_pHead.m_pNext);
  }

  template <class _Tp>
  auto forward_list<_Tp>::cend() const NOEXCEPT
      -> typename forward_list<_Tp>::const_iterator {
    return forward_list_const_iterator<_Tp>(nullptr);
  }

  template <class _Tp>
  auto forward_list<_Tp>::clear() NOEXCEPT -> void {
    while (!this->empty())
      this->pop_front();
  }

  template <class _Tp>
  auto forward_list<_Tp>::empty() const NOEXCEPT -> bool {
    return m_pHead.m_pNext == nullptr;
  }
  
  template <class _Tp>
  auto forward_list<_Tp>::end() NOEXCEPT 
      -> typename forward_list<_Tp>::iterator {
    return forward_list_iterator<_Tp>(
      static_cast<forward_list_node_base*>(nullptr));
  }

  template <class _Tp>
  auto forward_list<_Tp>::end() const NOEXCEPT
      -> typename forward_list<_Tp>::const_iterator {
    return forward_list_const_iterator<_Tp>(
      static_cast<forward_list_node_base*>(nullptr));
  }

  template <class _Tp>
  auto forward_list<_Tp>::erase_after(const_iterator _position)
      -> typename forward_list<_Tp>::iterator {
    forward_list_node<_Tp>* _temp =
      static_cast<forward_list_node<_Tp>*>(_position.m_pNode->m_pNext);
    _position.m_pNode->m_pNext = _temp->m_pNext;
    delete _temp;
    return forward_list_iterator<_Tp>(_position.m_pNode->m_pNext);
  }
  
  template <class _Tp>
  auto forward_list<_Tp>::erase_after(const_iterator _first,
      const_iterator _last) -> typename forward_list<_Tp>::iterator {
    forward_list_node<_Tp>* _node_first =
      static_cast<forward_list_node<_Tp>*>(_first.m_pNode->m_pNext);
    forward_list_node<_Tp>* _node_last =
      static_cast<forward_list_node<_Tp>*>(_last.m_pNode);
    while (_node_first != _node_last) {
      forward_list_node<_Tp>* _temp =
        static_cast<forward_list_node<_Tp>*>(_first.m_pNode->m_pNext);
      _first.m_pNode->m_pNext = _temp->m_pNext;
      delete _temp;
      _node_first =
        static_cast<forward_list_node<_Tp>*>(_first.m_pNode->m_pNext);
    }
    return forward_list_iterator<_Tp>(_first.m_pNode->m_pNext);
  }

  template <class _Tp>
  auto forward_list<_Tp>::front() -> _Tp& {
    return static_cast<forward_list_node<_Tp>*>(m_pHead.m_pNext)->m_Value;
  }

  template <class _Tp>
  auto forward_list<_Tp>::front() const -> _Tp const& {
    return static_cast<forward_list_node<_Tp>*>(m_pHead.m_pNext)->m_Value;
  }

  template <class _Tp>
  auto forward_list<_Tp>::insert_after(const_iterator _position,
      _Tp const& _value) -> void {
    forward_list_node<_Tp>* _node = new forward_list_node<_Tp>(_value);
    _node->m_pNext = _position.m_pNode->m_pNext;
    _position.m_pNode->m_pNext = _node;
  }

  template <class _Tp>
  auto forward_list<_Tp>::insert_after(const_iterator _position,
      _Tp&& _value) -> void {
    forward_list_node<_Tp>* _node = 
      new forward_list_node<_Tp>(std::move(_value));
    _node->m_pNext = _position.m_pNode->m_pNext;
    _position.m_pNode->m_pNext = _node;
  }

  template <class _Tp>
  auto forward_list<_Tp>::insert_after(const_iterator _position, size_t _num,
      _Tp const& _value) -> void {
    for (size_t i = 0; i < _num; ++i)
      this->insert_after(_position, _value);
  }

  template <class _Tp>
  auto forward_list<_Tp>::insert_after(const_iterator _position,
      iterator _first, iterator _last) -> void {
    for (; _first != _last; ++_position, ++_first) {
      this->insert_after(_position, 
        static_cast<forward_list_node<_Tp>*>(_first.m_pNode)->m_Value);
    }
  }
  
  template <class _Tp>
  auto forward_list<_Tp>::insert_after(const_iterator _position,
    const_iterator _first, const_iterator _last) -> void {
    for (; _first != _last; ++_position, ++_first) {
      this->insert_after(_position, 
        static_cast<forward_list_node<_Tp>*>(_first.m_pNode)->m_Value);
    }
  }

  template <class _Tp>
  auto forward_list<_Tp>::operator=(
      forward_list<_Tp> const& _forward_list) -> forward_list<_Tp>& {
    if (this != &_forward_list) {
      forward_list<_Tp> _temp(_forward_list);
      this->swap(_temp);
    }
    return *this;
  }

  template <class _Tp>
  auto forward_list<_Tp>::operator=(
      forward_list<_Tp>&& _forward_list) -> forward_list<_Tp>& {
    if (this != &_forward_list) {
      m_pHead.m_pNext = std::move(_forward_list.m_pHead).m_pNext;
      _forward_list.m_pHead.m_pNext = nullptr;
    }
    return *this;
  }

  template <class _Tp>
  auto forward_list<_Tp>::pop_front() -> void {
    m_pHead.m_pNext = m_pHead.m_pNext->m_pNext;
  }

  template <class _Tp>
  auto forward_list<_Tp>::push_front(_Tp const& _value) -> void {
    forward_list_node<_Tp>* _node = new forward_list_node<_Tp>(_value);
    _node->m_pNext = m_pHead.m_pNext;
    m_pHead.m_pNext = _node;
  }

  template <class _Tp>
  auto forward_list<_Tp>::push_front(_Tp&& _value) -> void {
    forward_list_node<_Tp>* _node =
      new forward_list_node<_Tp>(std::move(_value));
    _node->m_pNext = m_pHead.m_pNext;
    m_pHead.m_pNext = _node;
  }

  template <class _Tp>
  auto forward_list<_Tp>::reverse() NOEXCEPT -> void {
    forward_list_node_base* _tail = m_pHead.m_pNext;
    if (!_tail)
      return;
    while (forward_list_node_base* _temp = _tail->m_pNext) {
      forward_list_node_base* _keep = m_pHead.m_pNext;
      m_pHead.m_pNext = _temp;
      _tail->m_pNext = _temp->m_pNext;
      m_pHead.m_pNext->m_pNext = _keep;
    }
  }

  template <class _Tp>
  auto forward_list<_Tp>::swap(forward_list<_Tp>& _forward_list) -> void {
    std::swap(this->m_pHead.m_pNext, _forward_list.m_pHead.m_pNext);
  }

}
