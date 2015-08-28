/**
 *  forward_list_iterator.h
 *
 *  @author Raul Butuc.
 *  @version 1.2.1 28/08/2015
 */

#pragma once

#include "forward_list.h"
#include "forward_list_node.h"

namespace my_library {

  template <class _Tp> class forward_list;
  template <class _Tp> class forward_list_node;

  template <class _Tp>
  class forward_list_iterator {

    friend class forward_list<_Tp>;

    public:
      typedef forward_list_iterator<_Tp> iterator;
      typedef size_t size_type;
      typedef _Tp value_type;
      typedef _Tp& reference;
      typedef _Tp* pointer;
      typedef std::forward_iterator_tag iterator_category;
      typedef size_t difference_type;

      const iterator& operator++();
      const iterator& operator++(int);
      const iterator& operator+=(int);
      reference operator*() const;
      pointer operator->() const;
      bool operator==(const iterator&) const;
      bool operator!=(const iterator&) const;

    private:
      forward_list_node_base* m_pNode;

      forward_list_iterator(forward_list_node_base*);

  };
  
  template <class _Tp>
  forward_list_iterator<_Tp>::forward_list_iterator(
      forward_list_node_base* _node)
      : m_pNode(_node) {}

  template <class _Tp>
  const typename forward_list_iterator<_Tp>::iterator&
  forward_list_iterator<_Tp>::operator++() {
    if (m_pNode == nullptr) return static_cast<const iterator&>(nullptr);
    m_pNode = m_pNode->m_pNext;
    return *this;
  }

  template <class _Tp>
  const typename forward_list_iterator<_Tp>::iterator&
  forward_list_iterator<_Tp>::operator++(int) {
    forward_list_iterator<_Tp> _temp(*this);
    ++(*this);
    return _temp;
  }

  template <class _Tp>
  const typename forward_list_iterator<_Tp>::iterator&
  forward_list_iterator<_Tp>::operator+=(int _num) {
    for (int i = 0; i < _num; ++i, ++(*this));
    return *this;
  }

  template <class _Tp>
  typename forward_list_iterator<_Tp>::reference
  forward_list_iterator<_Tp>::operator*() const {
    return static_cast<forward_list_node<_Tp>*>(m_pNode)->m_Value;
  }

  template <class _Tp>
  typename forward_list_iterator<_Tp>::pointer
  forward_list_iterator<_Tp>::operator->() const {
    return static_cast<forward_list_node<_Tp>*>(m_pNode);
  }

  template <class _Tp>
  bool forward_list_iterator<_Tp>::operator==(
      const iterator& _position) const {
    return m_pNode == _position.m_pNode;
  }

  template <class _Tp>
  bool forward_list_iterator<_Tp>::operator!=(
      const iterator& _position) const {
    return m_pNode != _position.m_pNode;
  }

}