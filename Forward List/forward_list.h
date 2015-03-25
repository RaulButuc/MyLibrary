/**
 *  forward_list.h
 *
 *  @author Raul Butuc.
 *  @version 1.2.3 25/03/2015
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

using std::move;

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
    const_iterator cbegin() const NOEXCEPT;
    void clear() NOEXCEPT;
    bool empty() const NOEXCEPT;
    iterator end() NOEXCEPT;
    const_iterator end() const NOEXCEPT;
    const_iterator cend() const NOEXCEPT;
    _Tp& front();
    const _Tp& front() const;
    void insert_after(const_iterator, const _Tp&);
    void insert_after(const_iterator, _Tp&&);
    void insert_after(const_iterator, size_t, const _Tp&);
    void insert_after(const_iterator, iterator, iterator);
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
forward_list<_Tp>::forward_list(size_t _num, const _Tp& _value) : m_pHead(nullptr) {
  for (size_t i = 0; i < _num; ++i)
    this->push_front(_value);
}

template <class _Tp>
forward_list<_Tp>::forward_list(iterator _first, iterator _last) : m_pHead(nullptr) {
  for (; _first != _last; ++_first)
    this->push_front(*_first);
  this->reverse();
}

template <class _Tp>
forward_list<_Tp>::forward_list(const_iterator _first, const_iterator _last) : m_pHead(nullptr) {
  for (; _first != _last; ++_first)
    this->push_front(*_first);
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
  *this = move(_forward_list);
  _forward_list.m_pHead = nullptr;
}

template <class _Tp>
forward_list<_Tp>::~forward_list() {
  delete m_pHead;
}

template <class _Tp>
void forward_list<_Tp>::assign(size_t _num, const _Tp& _value) {
  this->clear();
  for (size_t i = 0; i < _num; ++i)
    push_front(_value);
  this->reverse();
}

template <class _Tp>
void forward_list<_Tp>::assign(iterator _first, iterator _last) {
  this->clear();
  for (; _first != _last; ++_first)
    push_front(*_first);
  this->reverse();
}

template <class _Tp>
void forward_list<_Tp>::assign(const_iterator _first, const_iterator _last) {
  this->clear();
  for (; _first != _last; ++_first)
    push_front(*_first);
  this->reverse();
}
  
template <class _Tp>
typename forward_list<_Tp>::iterator forward_list<_Tp>::begin() NOEXCEPT {
  return forward_list_iterator<_Tp>(m_pHead);
}

template <class _Tp>
typename forward_list<_Tp>::const_iterator forward_list<_Tp>::begin() const NOEXCEPT {
  return forward_list_const_iterator<_Tp>(m_pHead);
}

template <class _Tp>
typename forward_list<_Tp>::const_iterator forward_list<_Tp>::cbegin() const NOEXCEPT {
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
typename forward_list<_Tp>::const_iterator forward_list<_Tp>::cend() const NOEXCEPT{
  return forward_list_const_iterator<_Tp>(nullptr);
}

template <class _Tp>
_Tp& forward_list<_Tp>::front() {
  return m_pHead->m_Value;
}

template <class _Tp>
const _Tp& forward_list<_Tp>::front() const {
  return m_pHead->m_Value;
}

template <class _Tp>
void forward_list<_Tp>::insert_after(const_iterator _position, const _Tp& _value) {
  forward_list_node<_Tp>* _node = new forward_list_node<_Tp>(_value, _position.m_pNode->m_pNext);
  _position.m_pNode->m_pNext = _node;
}

template <class _Tp>
void forward_list<_Tp>::insert_after(const_iterator _position, _Tp&& _value) {
  forward_list_node<_Tp>* _node = new forward_list_node<_Tp>(move(_value), _position.m_pNode->m_pNext);
  _position.m_pNode->m_pNext = _node;
}

template <class _Tp>
void forward_list<_Tp>::insert_after(const_iterator _position, size_t _num, const _Tp& _value) {
  for (size_t i = 0; i < _num; ++i)
    this->insert_after(_position, _value);
}

template <class _Tp>
void forward_list<_Tp>::insert_after(const_iterator _position, iterator _first, iterator _last){
  for (; _first != _last; ++_position, ++_first) {
    this->insert_after(_position, *_first);
  }
}
  
template <class _Tp>
forward_list<_Tp>& forward_list<_Tp>::operator=(const forward_list<_Tp>& _forward_list) {
  this->assign(_forward_list.begin(), _forward_list.end());
  return *this;
}

template <class _Tp>
forward_list<_Tp>& forward_list<_Tp>::operator=(forward_list<_Tp>&& _forward_list) {
  if (this != &_forward_list) {
    m_pHead = move(_forward_list).m_pHead;
    _forward_list.m_pHead = nullptr;
  }
  return *this;
}

template <class _Tp>
void forward_list<_Tp>::pop_front() {
  m_pHead = m_pHead->m_pNext;
}

template <class _Tp>
void forward_list<_Tp>::push_front(const _Tp& _value) {
  forward_list_node<_Tp>* _node = new forward_list_node<_Tp>(_value, m_pHead);
  m_pHead = _node;
}

template <class _Tp>
void forward_list<_Tp>::push_front(_Tp&& _value) {
  forward_list_node<_Tp>* _node = new forward_list_node<_Tp>(move(_value), m_pHead);
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