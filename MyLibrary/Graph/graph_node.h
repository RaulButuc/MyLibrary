/**
 *  graph_node.h
 *
 *  @author Raul Butuc.
 *  @version 1.0.0 04/06/2016
 */

#pragma once

#include "list.h"

namespace my_library {

  template <class _Tp>
  class graph_node {

    public:
      graph_node();
      graph_node(const _Tp&);
      graph_node(const graph_node&);
      graph_node(const _Tp&, const list<_Tp>&);
      graph_node(const graph_node&, const list<_Tp>&);
      graph_node(const _Tp&, const list<graph_node>&);
      graph_node(const graph_node&, const list<graph_node>&);
      void setValue(const _Tp&);
      _Tp getValue(); 
      void addNeighbour(const _Tp&);
      void addNeighbour(const graph_node&);
      void addNeighbours(const list<_Tp>&);
      void addNeighbours(const list<graph_node>&);
      void removeNeighbour(const _Tp&);
      void removeNeighbour(const graph_node&);
      void removeNeighbours(const list<_Tp>&);
      void removeNeighbours(const list<graph_node>&);
      void removeAllNeighbours();
      list<graph_node> getNeighbours();

    private:
      _Tp value;
      list<graph_node> neighbours;

  };

  template <class _Tp>
  graph_node<_Tp>::graph_node() { }

  template <class _Tp>
  graph_node<_Tp>::graph_node(const _Tp& _value) : value(_value) { }

  template <class _Tp>
  graph_node<_Tp>::graph_node(const graph_node& _node) : value(_node.getValue()) { }

  template <class _Tp>
  graph_node<_Tp>::graph_node(const _Tp& _value, const list<_Tp>& _neighbours)
      : value(_value) {
    for (auto it = _neighbours.begin(); it != _neighbours.end(); ++it) {
      graph_node newNeighbour = graph_node(*it);
      neighbours.push_back(newNeighbour);
    }
  }

  template <class _Tp>
  graph_node<_Tp>::graph_node(const graph_node& _node, const list<_Tp>& _neighbours)
      : value(_node.getValue()) {
    for (auto it = _neighbours.begin(); it != _neighbours.end(); ++it) {
      graph_node newNeighbour = graph_node(*it);
      neighbours.push_back(newNeighbour);
    }
  }

  template <class _Tp>
  graph_node<_Tp>::graph_node(const _Tp& _value, const list<graph_node>& _neighbours)
      : value(_value) {
    for (auto it = _neighbours.begin(); it != _neighbours.end(); ++it) {
      graph_node newNeighbour = graph_node(*it);
      neighbours.push_back(newNeighbour);
    }
  }

  template <class _Tp>
  graph_node<_Tp>::graph_node(const graph_node& _node, const list<graph_node>& _neighbours)
      : value(_node.getValue()) {
    for (auto it = _neighbours.begin(); it != _neighbours.end(); ++it) {
      graph_node newNeighbour = graph_node(*it);
      neighbours.push_back(newNeighbour);
    }
  }

  template <class _Tp>
  void graph_node<_Tp>::setValue(const _Tp& _value) {
    value = _value;
  }

  template <class _Tp>
  _Tp graph_node<_Tp>::getValue() {
    return value;
  }

  template <class _Tp>
  void graph_node<_Tp>::addNeighbour(const _Tp& _value) {
    graph_node newNeighbour = graph_node(_value);
    neighbours.push_back(newNeighbour);
  }

  template <class _Tp>
  void graph_node<_Tp>::addNeighbour(const graph_node& _node) {
    neighbours.push_back(_node);
  }

  template <class _Tp>
  void graph_node<_Tp>::addNeighbours(const list<_Tp>& _neighbours) {
    for (auto it = _neighbours.begin(); it != _neighbours.end(); ++it) {
      graph_node newNeighbour = graph_node(*it);
      neighbours.push_back(newNeighbour);
    }
  }

  template <class _Tp>
  void graph_node<_Tp>::addNeighbours(const list<graph_node>& _neighbours) {
    for (auto it = _neighbours.begin(); it != _neighbours.end(); ++it) {
      graph_node newNeighbour = graph_node(*it);
      neighbours.push_back(newNeighbour);
    }
  }

  template <class _Tp>
  void graph_node<_Tp>::removeNeighbour(const _Tp& _value) {
    neighbours.remove(graph_node(_value));
  }

  template <class _Tp>
  void graph_node<_Tp>::removeNeighbour(const graph_node& _node) {
    neighbours.remove(_node);
  }

  template <class _Tp>
  void graph_node<_Tp>::removeNeighbours(const list<_Tp>& _neighbours) {
    for (auto it = _neighbours.begin(); it != _neighbours.end(); ++it) {
      neighbours.remove(graph_node(*it));
    }
  }

  template <class _Tp>
  void graph_node<_Tp>::removeNeighbours(const list<graph_node>& _neighbours) {
    for (auto it = _neighbours.begin(); it != _neighbours.end(); ++it) {
      neighbours.remove(*it);
    }
  }

  template <class _Tp>
  void graph_node<_Tp>::removeAllNeighbours() {
    neighbours.clear();
  }

  template <class _Tp>
  list<graph_node> graph_node<_Tp>::getNeighbours() {
    return neighbours;
  }

}
