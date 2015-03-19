/**
 *  list_const_iterator.h
 *
 *  @author Raul Butuc.
 *  @version 1.0.0 18/03/2015
 */

#pragma once

#include <cassert>
#include <iterator>
#include "list.h"
#include "list_node.h"

namespace my_library {

  template <class _Tp> class list;
  template <class _Tp> class list_node;

  template <class _Tp>
  class list_const_iterator {

    friend class list<_Tp>;

  public:
    typedef list_const_iterator<_Tp> const_iterator;
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
    list_node<_Tp>* m_pNode;

    list_const_iterator(list_node<_Tp>*);

  };

  template <class _Tp>
  list_const_iterator<_Tp>::list_const_iterator(list_node<_Tp>* pNode) : m_pNode(pNode) {}

  template <class _Tp>
  const typename list_const_iterator<_Tp>::const_iterator& list_const_iterator<_Tp>::operator++() {
    assert(m_pNode != nullptr);
    m_pNode = m_pNode->m_pNext;
    return *this;
  }

  template <class _Tp>
  const typename list_const_iterator<_Tp>::const_iterator& list_const_iterator<_Tp>::operator++(int) {
    list_const_iterator<_Tp>::const_iterator _tmp = *this;
    ++(*this);
    return _tmp;
  }

  template <class _Tp>
  typename list_const_iterator<_Tp>::reference list_const_iterator<_Tp>::operator*() const {
    return m_pNode->m_Node;
  }

  template <class _Tp>
  typename list_const_iterator<_Tp>::pointer list_const_iterator<_Tp>::operator->() const {
    return m_pNode;
  }

  template <class _Tp>
  bool list_const_iterator<_Tp>::operator==(const typename list_const_iterator<_Tp>::const_iterator& other) const {
    return m_pNode == other.m_pNode;
  }

  template <class _Tp>
  bool list_const_iterator<_Tp>::operator!=(const typename list_const_iterator<_Tp>::const_iterator& other) const {
    return m_pNode != other.m_pNode;
  }

}