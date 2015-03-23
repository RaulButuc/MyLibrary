/**
 *  forward_list_const_iterator.h
 *
 *  @author Raul Butuc.
 *  @version 1.1.1 23/03/2015
 */

#pragma once

#include <cassert>
#include <iterator>
#include "forward_list.h"
#include "forward_list_node.h"

namespace my_library {

  template <class _Tp> class forward_list;
  template <class _Tp> class forward_list_node;

  template <class _Tp>
  class forward_list_const_iterator {

    friend class forward_list<_Tp>;

  public:
    typedef forward_list_const_iterator<_Tp> const_iterator;
    typedef size_t size_type;
    typedef _Tp value_type;
    typedef _Tp& reference;
    typedef _Tp* pointer;
    typedef std::forward_iterator_tag iterator_category;
    typedef size_t difference_type;

    const const_iterator& operator++();
    const const_iterator& operator++(int);
    reference operator*() const;
    pointer operator->() const;
    bool operator==(const const_iterator&) const;
    bool operator!=(const const_iterator&) const;

  private:
    forward_list_node<_Tp>* m_pNode;

    forward_list_const_iterator(forward_list_node<_Tp>*);

  };

  template <class _Tp>
  forward_list_const_iterator<_Tp>::forward_list_const_iterator(forward_list_node<_Tp>* pNode) : m_pNode(pNode) {}

  template <class _Tp>
  const typename forward_list_const_iterator<_Tp>::const_iterator& forward_list_const_iterator<_Tp>::operator++() {
    assert(m_pNode != nullptr);
    m_pNode = m_pNode->m_pNext;
    return *this;
  }

  template <class _Tp>
  const typename forward_list_const_iterator<_Tp>::const_iterator& forward_list_const_iterator<_Tp>::operator++(int) {
    forward_list_const_iterator<_Tp>::const_iterator _tmp = *this;
    ++(*this);
    return _tmp;
  }

  template <class _Tp>
  typename forward_list_const_iterator<_Tp>::reference forward_list_const_iterator<_Tp>::operator*() const {
    return m_pNode->m_Data;
  }

  template <class _Tp>
  typename forward_list_const_iterator<_Tp>::pointer forward_list_const_iterator<_Tp>::operator->() const {
    return m_pNode;
  }

  template <class _Tp>
  bool forward_list_const_iterator<_Tp>::operator==(const typename forward_list_const_iterator<_Tp>::const_iterator& other) const {
    return m_pNode == other.m_pNode;
  }

  template <class _Tp>
  bool forward_list_const_iterator<_Tp>::operator!=(const typename forward_list_const_iterator<_Tp>::const_iterator& other) const {
    return m_pNode != other.m_pNode;
  }

}