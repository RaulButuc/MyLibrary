/**
 *  list_const_interator.h
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
  class list_const_iterator {
    
    public:

      typedef list_const_iterator<_Tp> const_iterator;
      typedef size_t size_type;
      typedef _Tp value_type;
      typedef _Tp& reference;
      typedef _Tp* pointer;
      typedef std::bidirectional_iterator_tag iterator_category;
      typedef size_t difference_type;

      auto operator++() -> const_iterator const&;
      auto operator++(int) -> const_iterator const&;
      auto operator+=(int) -> const_iterator const&;
      auto operator--() -> const_iterator const&;
      auto operator--(int) -> const_iterator const&;
      auto operator-=(int) -> const_iterator const&;
      auto operator*() const -> reference;
      auto operator->() const -> pointer;
      auto operator==(const_iterator const&) const -> bool;
      auto operator!=(const_iterator const&) const -> bool;

    private:

      list_node_base* m_pNode;

      list_const_iterator(list_node_base*);

  };

  template <class _Tp>
  list_const_iterator<_Tp>::list_const_iterator(list_node_base* _node)
    : m_pNode(_node) {}

  template <class _Tp>
  auto list_const_iterator<_Tp>::operator++()
      -> typename list_const_iterator<_Tp>::const_iterator& {
    assert(m_pNode != nullptr);
    m_pNode = m_pNode->m_pNext;
    return *this;
  }

  template <class _Tp>
  auto list_const_iterator<_Tp>::operator++(int)
      -> typename list_const_iterator<_Tp>::const_iterator const& {
    list_const_iterator<_Tp> _temp(*this);
    ++(*this);
    return _temp;
  }

  template <class _Tp>
  auto list_const_iterator<_Tp>::operator+=(int _num)
      -> typename list_const_iterator<_Tp>::const_iterator const& {
    for (int i = 0; i < _num; ++i, ++(*this));
    return *this;
  }

  template <class _Tp>
  auto list_const_iterator<_Tp>::operator--()
      -> typename list_const_iterator<_Tp>::const_iterator const& {
    assert(m_pNode != nullptr);
    m_pNode = m_pNode->m_pPrev;
    return *this;
  }

  template <class _Tp>
  auto list_const_iterator<_Tp>::operator--(int)
      -> typename list_const_iterator<_Tp>::const_iterator const& {
    list_const_iterator<_Tp> _temp(*this);
    --(*this);
    return _temp;
  }

  template <class _Tp>
  auto list_const_iterator<_Tp>::operator-=(int _num)
      -> typename list_const_iterator<_Tp>::const_iterator const& {
    for (int i = 0; i < _num; ++i, --(*this));
    return *this;
  }

  template <class _Tp>
  auto list_const_iterator<_Tp>::operator*() const
      -> typename list_const_iterator<_Tp>::reference {
    return static_cast<list_node<_Tp>*>(m_pNode)->m_Value;
  }

  template <class _Tp>
  auto list_const_iterator<_Tp>::operator->() const
      -> typename list_const_iterator<_Tp>::pointer {
    return static_cast<list_node<_Tp>*>(m_pNode);
  }

  template <class _Tp>
  auto list_const_iterator<_Tp>::operator==(
      const_iterator const& _position) const -> bool {
    return m_pNode == _position.m_pNode;
  }

  template <class _Tp>
  auto list_const_iterator<_Tp>::operator!=(
      const_iterator const& _position) const -> bool {
    return m_pNode != _position.m_pNode;
  }

}
