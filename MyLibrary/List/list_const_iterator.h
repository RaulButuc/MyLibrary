/**
 *  list_const_interator.h
 *
 *  @author Raul Butuc.
 *  @version 1.0.0 18/09/2015
 */

#pragma once

#include <cassert>
#include <iterator>
#include "list_node.h"

namespace my_library {

  template <class _Tp> class list_node;

  template <class _Tp>
  class list_const_iterator {
    
    public:
      typedef list_const_iterator<_Tp> const_iterator;
      typedef size_t size_type;
      typedef _Tp value_type;
      typedef _Tp& reference;
      typedef _Tp* pointer;
      typedef std::bidirectional_iterator_tag iterator_category;
      typedef size_t difference_type;

      const const_iterator& operator++();
      const const_iterator& operator++(int);
      const const_iterator& operator+=(int);
      const const_iterator& operator--();
      const const_iterator& operator--(int);
      const const_iterator& operator-=(int);
      reference operator*() const;
      pointer operator->() const;
      bool operator==(const const_iterator&) const;
      bool operator!=(const const_iterator&) const;

    private:
      list_node_base* m_pNode;

      list_const_iterator(list_node_base*);

  };

  template <class _Tp>
  list_const_iterator<_Tp>::list_const_iterator(list_node_base* _node)
    : m_pNode(_node) {}

  template <class _Tp>
  const typename list_const_iterator<_Tp>::const_iterator&
  list_const_iterator<_Tp>::operator++() {
    assert(m_pNode != nullptr);
    m_pNode = m_pNode->m_pNext;
    return *this;
  }

  template <class _Tp>
  const typename list_const_iterator<_Tp>::const_iterator&
  list_const_iterator<_Tp>::operator++(int) {
    list_const_iterator<_Tp> _temp(*this);
    ++(*this);
    return _temp;
  }

  template <class _Tp>
  const typename list_const_iterator<_Tp>::const_iterator&
  list_const_iterator<_Tp>::operator+=(int _num) {
    for (int i = 0; i < _num; ++i, ++(*this));
    return *this;
  }

  template <class _Tp>
  const typename list_const_iterator<_Tp>::const_iterator&
  list_const_iterator<_Tp>::operator--() {
    assert(m_pNode != nullptr);
    m_pNode = m_pNode->m_pPrev;
    return *this;
  }

  template <class _Tp>
  const typename list_const_iterator<_Tp>::const_iterator&
    list_const_iterator<_Tp>::operator--(int) {
    list_const_iterator<_Tp> _temp(*this);
    --(*this);
    return _temp;
  }

  template <class _Tp>
  const typename list_const_iterator<_Tp>::const_iterator&
    list_const_iterator<_Tp>::operator-=(int _num) {
    for (int i = 0; i < _num; ++i, --(*this));
    return *this;
  }

  template <class _Tp>
  typename list_const_iterator<_Tp>::reference
  list_const_iterator<_Tp>::operator*() const {
    return static_cast<list_node<_Tp>*>(m_pNode)->m_Value;
  }

  template <class _Tp>
  typename list_const_iterator<_Tp>::pointer
  list_const_iterator<_Tp>::operator->() const {
    return static_cast<list_node<_Tp>*>(m_pNode);
  }

  template <class _Tp>
  bool list_const_iterator<_Tp>::operator==(
      const const_iterator& _position) const {
    return m_pNode == _position.m_pNode;
  }

  template <class _Tp>
  bool list_const_iterator<_Tp>::operator!=(
      const const_iterator& _position) const {
    return m_pNode != _position.m_pNode;
  }

}
