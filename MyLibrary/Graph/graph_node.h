/**
*  graph_node.h
*
*  @author Raul Butuc
*/

#pragma once

#include "forward_list.h"

#ifndef _MSC_VER
#define NOEXCEPT  noexcept
#else
#define NOEXCEPT 
#endif

namespace my_library {

  template <class _Tp>
  class graph_node {

    public:

      graph_node();
      graph_node(_Tp const&);
      graph_node(graph_node<_Tp> const&);
      graph_node(_Tp const&, forward_list<_Tp> const&);
      graph_node(graph_node<_Tp> const&, forward_list<_Tp> const&);
      graph_node(_Tp const&, forward_list<graph_node<_Tp>> const&);
      graph_node(graph_node<_Tp> const&, forward_list<graph_node<_Tp>> const&);
      auto setValue(_Tp const&) -> void;
      auto getValue() const->_Tp;
      auto addNeighbour(_Tp const&) -> void;
      auto addNeighbour(graph_node<_Tp> const&) -> void;
      auto addNeighbours(forward_list<_Tp> const&) -> void;
      auto addNeighbours(forward_list<graph_node<_Tp>> const&) -> void;
      auto removeNeighbour(_Tp const&) -> void;
      auto removeNeighbour(graph_node<_Tp> const&) -> void;
      auto removeNeighbours(forward_list<_Tp> const&) -> void;
      auto removeNeighbours(forward_list<graph_node<_Tp>> const&) -> void;
      auto removeAllNeighbours() -> void;
      auto getNeighbours() -> forward_list<graph_node<_Tp>>;

    private:

      _Tp value;
      forward_list<graph_node<_Tp>> neighbours;

  };

  template <class _Tp>
  graph_node<_Tp>::graph_node() { }

  template <class _Tp>
  graph_node<_Tp>::graph_node(_Tp const& _value) : value(_value) { }

  template <class _Tp>
  graph_node<_Tp>::graph_node(graph_node<_Tp> const& _node) : value(_node.getValue()) { }

  template <class _Tp>
  graph_node<_Tp>::graph_node(_Tp const& _value,
      forward_list<_Tp> const& _neighbours) : value(_value) {
    for (auto it = _neighbours.begin(); it != _neighbours.end(); ++it) {
      graph_node<_Tp> newNeighbour = graph_node<_Tp>(*it);
      neighbours.push_back(newNeighbour);
    }
  }

  template <class _Tp>
  graph_node<_Tp>::graph_node(graph_node<_Tp> const& _node,
      forward_list<_Tp> const& _neighbours) : value(_node.getValue()) {
    for (auto it = _neighbours.begin(); it != _neighbours.end(); ++it) {
      graph_node<_Tp> newNeighbour = graph_node<_Tp>(*it);
      neighbours.push_back(newNeighbour);
    }
  }

  template <class _Tp>
  graph_node<_Tp>::graph_node(_Tp const& _value,
      forward_list<graph_node<_Tp>> const& _neighbours) : value(_value) {
    for (auto it = _neighbours.begin(); it != _neighbours.end(); ++it) {
      graph_node<_Tp> newNeighbour = graph_node<_Tp>(*it);
      neighbours.push_back(newNeighbour);
    }
  }

  template <class _Tp>
  graph_node<_Tp>::graph_node(graph_node<_Tp> const& _node,
      forward_list<graph_node<_Tp>> const& _neighbours) : value(_node.getValue()) {
    for (auto it = _neighbours.begin(); it != _neighbours.end(); ++it) {
      graph_node<_Tp> newNeighbour = graph_node<_Tp>(*it);
      neighbours.push_back(newNeighbour);
    }
  }

  template <class _Tp>
  auto graph_node<_Tp>::setValue(_Tp const& _value) -> void {
    value = _value;
  }

  template <class _Tp>
  auto graph_node<_Tp>::getValue() const -> _Tp {
    return value;
  }

  template <class _Tp>
  auto graph_node<_Tp>::addNeighbour(_Tp const& _value) -> void {
    graph_node<_Tp> newNeighbour = graph_node<_Tp>(_value);
    neighbours.push_back(newNeighbour);
  }

  template <class _Tp>
  auto graph_node<_Tp>::addNeighbour(graph_node<_Tp> const& _node) -> void {
    neighbours.push_back(_node);
  }

  template <class _Tp>
  auto graph_node<_Tp>::addNeighbours(forward_list<_Tp> const& _neighbours)
       -> void {
    for (auto it = _neighbours.begin(); it != _neighbours.end(); ++it) {
      graph_node<_Tp> newNeighbour = graph_node<_Tp>(*it);
      neighbours.push_back(newNeighbour);
    }
  }

  template <class _Tp>
  auto graph_node<_Tp>::addNeighbours(forward_list<graph_node<_Tp>> const& _neighbours)
      -> void {
    for (auto it = _neighbours.begin(); it != _neighbours.end(); ++it) {
      graph_node<_Tp> newNeighbour = graph_node<_Tp>(*it);
      neighbours.push_back(newNeighbour);
    }
  }

  template <class _Tp>
  auto graph_node<_Tp>::removeNeighbour(_Tp const& _value) -> void {
    neighbours.remove(graph_node<_Tp>(_value));
  }

  template <class _Tp>
  auto graph_node<_Tp>::removeNeighbour(graph_node<_Tp> const& _node) -> void {
    neighbours.remove(_node);
  }

  template <class _Tp>
  auto graph_node<_Tp>::removeNeighbours(forward_list<_Tp> const& _neighbours)
      -> void {
    for (auto it = _neighbours.begin(); it != _neighbours.end(); ++it) {
      neighbours.remove(graph_node<_Tp>(*it));
    }
  }

  template <class _Tp>
  auto graph_node<_Tp>::removeNeighbours(forward_list<graph_node<_Tp>> const& _neighbours)
       -> void {
    for (auto it = _neighbours.begin(); it != _neighbours.end(); ++it) -> void {
      neighbours.remove(*it);
    }
  }

  template <class _Tp>
  auto graph_node<_Tp>::removeAllNeighbours() -> void {
    neighbours.clear();
  }

  template <class _Tp>
  auto graph_node<_Tp>::getNeighbours() -> forward_list<graph_node<_Tp>> {
    return neighbours;
  }

}
