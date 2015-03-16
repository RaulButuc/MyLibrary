/**
 *  list.h
 *
 *  @author Raul Butuc.
 *  @version 1.0.0 16/03/2015
 */

#pragma once

#include "list_node.h"
#include "list_iterator.h"

namespace my_library {

  template <class _Tp>
  class list {

    public:
      typedef list_iterator<_Tp> iterator;

      list();
      ~list();

      bool empty() const;
      void push_back(const _Tp&);

      iterator begin();
      iterator end();

    private:
      list_node<_Tp>* m_pHead;
      list_node<_Tp>* m_pTail;
  };
  
  template <class _Tp>
  list<_Tp>::list() : m_pHead(NULL), m_pTail(NULL) {}

  template <class _Tp>
  list<_Tp>::~list() {
    delete m_pHead;
  }

  template <class _Tp>
  bool list<_Tp>::empty() const {
    return m_pHead == NULL;
  }
  
  template <class _Tp>
  void list<_Tp>::push_back(const _Tp& node) {
    list_node<_Tp>* _node = new list_node<_Tp>(node, NULL);
    if (m_pHead == NULL) {
      m_pHead = _node;
    }
    else {
      m_pTail->m_pNext = _node;
    }
    m_pTail = _node;
  }

  template <class _Tp>
  list<_Tp>::iterator list<_Tp>::begin() {
    return list_iterator<_Tp>(m_pHead);
  }

  template <class _Tp>
  list<_Tp>::iterator list<_Tp>::end() {
    return list_iterator<_Tp>(NULL);
  }

}