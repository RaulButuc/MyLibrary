/**
 *  list_iterator.h
 *
 *  @author Raul Butuc
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

      auto operator++() -> iterator const&;
      auto operator++(int) -> iterator const&;
      auto operator+=(int) -> iterator const&;
      auto operator--() -> iterator const&;
      auto operator--(int) -> iterator const&;
      auto operator-=(int) -> iterator const&;
      auto operator*() const -> reference;
      auto operator->() const -> pointer;
      auto operator==(iterator const&) const -> bool;
      auto operator!=(iterator const&) const -> bool;

      private:

        list_node_base* m_pNode;

        list_iterator(list_node_base*);

  };

  template <class _Tp>
  list_iterator<_Tp>::list_iterator(list_node_base* _node)
    : m_pNode(_node) {}

  template <class _Tp>
  auto list_iterator<_Tp>::operator++()
      -> typename list_iterator<_Tp>::iterator const& {
    assert(m_pNode != nullptr);
    m_pNode = m_pNode->m_pNext;
    return *this;
  }

  template <class _Tp>
  auto list_iterator<_Tp>::operator++(int)
      -> typename list_iterator<_Tp>::iterator const& {
    list_iterator<_Tp> _temp(*this);
    ++(*this);
    return _temp;
  }

  template <class _Tp>
  auto list_iterator<_Tp>::operator+=(int _num)
      -> typename list_iterator<_Tp>::iterator const&{
    for (int i = 0; i < _num; ++i, ++(*this));
    return *this;
  }

  template <class _Tp>
  auto list_iterator<_Tp>::operator--()
      -> typename list_iterator<_Tp>::iterator const& {
    assert(m_pNode != nullptr);
    m_pNode = m_pNode->m_pPrev;
    return *this;
  }

  template <class _Tp>
  auto list_iterator<_Tp>::operator--(int)
      -> typename list_iterator<_Tp>::iterator const& {
    list_iterator<_Tp> _temp(*this);
    --(*this);
    return _temp;
  }

  template <class _Tp>
  auto list_iterator<_Tp>::operator-=(int _num)
      -> typename list_iterator<_Tp>::iterator const& {
    for (int i = 0; i < _num; ++i, --(*this));
    return *this;
  }

  template <class _Tp>
  auto list_iterator<_Tp>::operator*() const
      -> typename list_iterator<_Tp>::reference {
    return static_cast<list_node<_Tp>*>(m_pNode)->m_Value;
  }

  template <class _Tp>
  auto list_iterator<_Tp>::operator->() const
      -> typename list_iterator<_Tp>::pointer {
    return static_cast<list_node<_Tp>*>(m_pNode);
  }

  template <class _Tp>
  auto list_iterator<_Tp>::operator==(
      iterator const& _position) const -> bool {
    return m_pNode == _position.m_pNode;
  }

  template <class _Tp>
  auto list_iterator<_Tp>::operator!=(
      iterator const& _position) const -> bool {
    return m_pNode != _position.m_pNode;
  }

}
