/**
 *  forward_list_iterator.h
 *
 *  @author Raul Butuc
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

      auto operator++() -> iterator const&;
      auto operator++(int) -> iterator const&;
      auto operator+=(int) -> iterator const&;
      auto operator*() const -> reference;
      auto operator->() const -> pointer;
      auto operator==(iterator const&) const -> bool;
      auto operator!=(iterator const&) const -> bool;

    private:

      forward_list_node_base* m_pNode;

      forward_list_iterator(forward_list_node_base*);

  };
  
  template <class _Tp>
  forward_list_iterator<_Tp>::forward_list_iterator(
      forward_list_node_base* _node)
      : m_pNode(_node) {}

  template <class _Tp>
  auto forward_list_iterator<_Tp>::operator++() 
      -> typename forward_list_iterator<_Tp>::iterator const& {
    if (m_pNode == nullptr) return static_cast<const iterator&>(nullptr);
    m_pNode = m_pNode->m_pNext;
    return *this;
  }

  template <class _Tp>
  auto forward_list_iterator<_Tp>::operator++(int)
      -> typename forward_list_iterator<_Tp>::iterator const& {
    forward_list_iterator<_Tp> _temp(*this);
    ++(*this);
    return _temp;
  }

  template <class _Tp>
  auto forward_list_iterator<_Tp>::operator+=(int _num)
      -> typename forward_list_iterator<_Tp>::iterator const& {
    for (int i = 0; i < _num; ++i, ++(*this));
    return *this;
  }

  template <class _Tp>
  auto forward_list_iterator<_Tp>::operator*() const
      -> typename forward_list_iterator<_Tp>::reference {
    return static_cast<forward_list_node<_Tp>*>(m_pNode)->m_Value;
  }

  template <class _Tp>
  auto forward_list_iterator<_Tp>::operator->() const
      -> typename forward_list_iterator<_Tp>::pointer {
    return static_cast<forward_list_node<_Tp>*>(m_pNode);
  }

  template <class _Tp>
  auto forward_list_iterator<_Tp>::operator==(
      const iterator& _position) const -> bool {
    return m_pNode == _position.m_pNode;
  }

  template <class _Tp>
  auto forward_list_iterator<_Tp>::operator!=(
      const iterator& _position) const -> bool {
    return m_pNode != _position.m_pNode;
  }

}
