/**
*  graph_node.h
*
*  @author Raul Butuc
*  @version 1.0.1 14/03/2017
*/

#pragma once

#include "list.h"

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
      graph_node(graph_node const&);
      graph_node(_Tp const&, list<_Tp> const&);
      graph_node(graph_node const&, list<_Tp> const&);
      graph_node(_Tp const&, list<graph_node> const&);
      graph_node(graph_node const&, list<graph_node> const&);
      auto setValue(_Tp const&) -> void;
      auto getValue() const->_Tp;
      auto addNeighbour(_Tp const&) -> void;
      auto addNeighbour(graph_node const&) -> void;
      auto addNeighbours(list<_Tp> const&) -> void;
      auto addNeighbours(list<graph_node> const&) -> void;
      auto removeNeighbour(_Tp const&) -> void;
      auto removeNeighbour(graph_node const&) -> void;
      auto removeNeighbours(list<_Tp> const&) -> void;
      auto removeNeighbours(list<graph_node> const&) -> void;
      auto removeAllNeighbours() -> void;
      auto getNeighbours()->list<graph_node>;

    private:

      _Tp value;
      list<graph_node> neighbours;

  };

  template <class _Tp>
  graph_node<_Tp>::graph_node() { }

  template <class _Tp>
  graph_node<_Tp>::graph_node(_Tp const& _value) : value(_value) { }

  template <class _Tp>
  graph_node<_Tp>::graph_node(graph_node const& _node) : value(_node.getValue()) { }

  template <class _Tp>
  graph_node<_Tp>::graph_node(_Tp const& _value, list<_Tp> const& _neighbours)
      : value(_value) {
    for (auto it = _neighbours.begin(); it != _neighbours.end(); ++it) {
      graph_node newNeighbour = graph_node(*it);
      neighbours.push_back(newNeighbour);
    }
  }

  template <class _Tp>
  graph_node<_Tp>::graph_node(graph_node const& _node, list<_Tp> const& _neighbours)
      : value(_node.getValue()) {
    for (auto it = _neighbours.begin(); it != _neighbours.end(); ++it) {
      graph_node newNeighbour = graph_node(*it);
      neighbours.push_back(newNeighbour);
    }
  }

  template <class _Tp>
  graph_node<_Tp>::graph_node(_Tp const& _value, list<graph_node> const& _neighbours)
      : value(_value) {
    for (auto it = _neighbours.begin(); it != _neighbours.end(); ++it) {
      graph_node newNeighbour = graph_node(*it);
      neighbours.push_back(newNeighbour);
    }
  }

  template <class _Tp>
  graph_node<_Tp>::graph_node(graph_node const& _node, list<graph_node> const& _neighbours)
      : value(_node.getValue()) {
    for (auto it = _neighbours.begin(); it != _neighbours.end(); ++it) {
      graph_node newNeighbour = graph_node(*it);
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
    graph_node newNeighbour = graph_node(_value);
    neighbours.push_back(newNeighbour);
  }

  template <class _Tp>
  auto graph_node<_Tp>::addNeighbour(graph_node const& _node) -> void {
    neighbours.push_back(_node);
  }

  template <class _Tp>
  auto graph_node<_Tp>::addNeighbours(list<_Tp> const& _neighbours) -> void {
    for (auto it = _neighbours.begin(); it != _neighbours.end(); ++it) {
      graph_node newNeighbour = graph_node(*it);
      neighbours.push_back(newNeighbour);
    }
  }

  template <class _Tp>
  auto graph_node<_Tp>::addNeighbours(list<graph_node> const& _neighbours) -> void {
    for (auto it = _neighbours.begin(); it != _neighbours.end(); ++it) {
      graph_node newNeighbour = graph_node(*it);
      neighbours.push_back(newNeighbour);
    }
  }

  template <class _Tp>
  auto graph_node<_Tp>::removeNeighbour(_Tp const& _value) -> void {
    neighbours.remove(graph_node(_value));
  }

  template <class _Tp>
  auto graph_node<_Tp>::removeNeighbour(graph_node const& _node) -> void {
    neighbours.remove(_node);
  }

  template <class _Tp>
  auto graph_node<_Tp>::removeNeighbours(list<_Tp> const& _neighbours) -> void {
    for (auto it = _neighbours.begin(); it != _neighbours.end(); ++it) {
      neighbours.remove(graph_node(*it));
    }
  }

  template <class _Tp>
  auto graph_node<_Tp>::removeNeighbours(list<graph_node> const& _neighbours) {
    for (auto it = _neighbours.begin(); it != _neighbours.end(); ++it) -> void {
      neighbours.remove(*it);
    }
  }

  template <class _Tp>
  auto graph_node<_Tp>::removeAllNeighbours() -> void {
    neighbours.clear();
  }

  template <class _Tp>
  auto graph_node<_Tp>::getNeighbours() -> list<graph_node> {
    return neighbours;
  }

}
