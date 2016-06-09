/**
  *  graph.h
  *
  *  @author Raul Butuc.
  *  @version 1.0.1 09/06/2016
  */

#pragma once

#include "list.h"
#include "graph_node.h"
#include "graph_type.h"
#include <vector>

namespace my_library {

  template <class _Tp>
  class graph {

  public:
    graph();
    graph(GRAPH_TYPE);
    graph(bool);
    graph(GRAPH_TYPE, bool);
    GRAPH_TYPE getType();
    void setType(GRAPH_TYPE);
    bool isWeighted();
    void setWeighted(bool);
    bool isSparse();
    bool isDense();
    bool isHamiltonian();
    bool isEulerian();
    list<graph_node> shortestPath(graph_node, graph_node);
    ~graph();

  private:
    GRAPH_TYPE type;
    bool weighted;
    vector<graph_node> nodes;

  };

  template <class _Tp>
  graph::graph() { }

  template <class _Tp>
  graph::graph(GRAPH_TYPE _type) : type(_type) { }

  template <class _Tp>
  graph::graph(bool _weighted) : weighted(_weighted) { }

  template <class _Tp>
  graph::graph(GRAPH_TYPE _type, bool _weighted) : type(_type), weighted(_weighted) { }

  template <class _Tp>
  GRAPH_TYPE graph::getType() {
    return type;
  }

  template <class _Tp>
  void graph::setType(GRAPH_TYPE _type) {
    type = _type;
  }

  template <class _Tp>
  bool graph::isWeighted() {
    return weighted;
  }

  template <class _Tp>
  void graph::setWeighted(bool _weighted) {
    weighted = _weighted;
  }

  template <class _Tp>
  bool graph::isSparse() {
    // @TODO: Complete the sparse graph checks.
  }

  template <class _Tp>
  bool graph::isDense() {
    // @TODO: Complete the dense graph checks.
  }

  template <class _Tp>
  bool graph::isHamiltonian() {
    // @TODO: Complete the Hamiltonian graph checks (each vertex may be visited only once).
  }

  template <class _Tp>
  bool graph::isEulerian() {
    // @TODO: Complete the Eulerian graph checks (each edge may be visited only once).
  }

  template <class _Tp>
  list<graph_node> graph::shortestPath(graph_node start, graph_node end) {
    // @TODO: Implement Dijkstra, Bellman-Ford and Roy-Floyd-Warshall algorithms.
  }
  
  template <class _Tp>
  graph::~graph() { 
    // @TODO: Add pointers and memory leak prevention.
  }

}
