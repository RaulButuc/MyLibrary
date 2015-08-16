/**
 *  list_iterator.h
 *
 *  @author Raul Butuc.
 *  @version 1.0.0 16/08/2015
 */

#pragma once

#include <cassert>
#include <iterator>
#include "list_node.h"

namespace my_library {
  
  template <class _Tp> class list_node;

  template <class _Tp>
  class list_iterator {
    
    public:
      typedef list_iterator<_Tp> iterator;
      typedef size_t size_type;
      typedef _Tp value_type;
      typedef _Tp& reference;
      typedef _Tp* pointer;
      typedef std::forward_iterator_tag iterator_category;
      typedef size_t difference_type;

      const iterator& operator++();
      const iterator& operator++(int);
      const iterator& operator+=(int);
      const iterator& operator--();
      const iterator& operator--(int);
      const iterator& operator-=(int);
      reference operator*() const;
      pointer operator->() const;
      bool operator==(const iterator&) const;
      bool operator!=(const iterator&) const;

      private:
        list_node_base* m_pNode;

        list_iterator(list_node_base*);

  };

  template <class _Tp>
  list_iterator<_Tp>::list_iterator(list_node_base* _node)
    : m_pNode(_node) {}

  template <class _Tp>
  const typename list_iterator<_Tp>::iterator&
  list_iterator<_Tp>::operator++() {
    assert(m_pNode != nullptr);
    m_pNode = m_pNode->m_pNext;
    return *this;
  }

  template <class _Tp>
  const typename list_iterator<_Tp>::iterator&
  list_iterator<_Tp>::operator++(int) {
    list_iterator<_Tp> _temp(*this);
    ++(*this);
    return _temp;
  }

  template <class _Tp>
  const typename list_iterator<_Tp>::iterator&
  list_iterator<_Tp>::operator+=(int _num) {
    for (int i = 0; i < _num; ++i, ++(*this));
    return *this;
  }

  template <class _Tp>
  const typename list_iterator<_Tp>::iterator&
  list_iterator<_Tp>::operator--() {
    assert(m_pNode != nullptr);
    m_pNode = m_pNode->m_pPrev;
    return *this;
  }

  template <class _Tp>
  const typename list_iterator<_Tp>::iterator&
  list_iterator<_Tp>::operator--(int) {
    list_iterator<_Tp> _temp(*this);
    --(*this);
    return _temp;
  }

  template <class _Tp>
  const typename list_iterator<_Tp>::iterator&
  list_iterator<_Tp>::operator-=(int _num) {
    for (int i = 0; i < _num; ++i, --(*this));
    return *this;
  }

  template <class _Tp>
  typename list_iterator<_Tp>::reference
  list_iterator<_Tp>::operator*() const {
    return static_cast<list_node<_Tp>*>(m_pNode)->m_Value;
  }

  template <class _Tp>
  typename list_iterator<_Tp>::pointer
  list_iterator<_Tp>::operator->() const {
    return static_case<list_node<_Tp>*>(m_pNode);
  }

  template <class _Tp>
  bool list_iterator<_Tp>::operator==(
      const iterator& _position) const {
    return m_pNode == _position.m_pNode;
  }

  template <class _Tp>
  bool list_iterator<_Tp>::operator!=(
      const iterator& _position) const {
    return m_pNode != _position.m_pNode;
  }

}
