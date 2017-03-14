/**
*  graph.h
*
*  @author Raul Butuc
*  @version 1.0.2 14/03/2017
*/

#pragma once

#include "list.h"
#include "graph_node.h"
#include "graph_type.h"
#include <vector>

#ifndef _MSC_VER
#define NOEXCEPT  noexcept
#else
#define NOEXCEPT 
#endif

namespace my_library {

  template <class _Tp>
  class graph {

  public:

    graph();
    graph(GRAPH_TYPE);
    graph(GRAPH_TYPE, bool);
    graph(GRAPH_TYPE, double);
    graph(GRAPH_TYPE, bool, double);
    auto getType() const -> GRAPH_TYPE;
    auto setType(GRAPH_TYPE const&) -> void;
    auto isWeighted() const -> bool;
    auto setWeighted(bool const&) -> void;
    auto isSparse() const -> bool;
    auto isDense() const -> bool;
    auto isHamiltonian() const -> bool;
    auto isEulerian() const -> bool;
    auto shortestPath(graph_node, graph_node) -> list<graph_node>;
    ~graph();

  private:

    GRAPH_TYPE type;
    bool weighted;
    double densityThreshold;
    std::vector<graph_node> nodes;

    auto computeDensity() const -> double;

  };

  template <class _Tp>
  graph<_Tp>::graph() : type(GRAPH_TYPE.Undirected), weighted(false), densityThreshold(0.5) { }

  template <class _Tp>
  graph<_Tp>::graph(GRAPH_TYPE _type) : type(_type), weighted(false), densityThreshold(0.5) { }

  template <class _Tp>
  graph<_Tp>::graph(GRAPH_TYPE _type, bool _weighted) : type(_type), weighted(_weighted),
      densityThreshold(0.5) { }

  template <class _Tp>
  graph<_Tp>::graph(GRAPH_TYPE _type, double _densityThreshold) : type(_type), weighted(false),
      densityThreshold(_densityThreshold) { }

  template <class _Tp>
  graph<_Tp>::graph(GRAPH_TYPE _type, bool _weighted, double _densityThreshold) : type(_type),
      weighted(_weighted), densityThreshold(_densityThreshold) { }

  template <class _Tp>
  auto graph<_Tp>::getType() const -> GRAPH_TYPE {
    return type;
  }

  template <class _Tp>
  auto graph<_Tp>::setType(GRAPH_TYPE const& _type) -> void {
    type = _type;
  }

  template <class _Tp>
  auto graph<_Tp>::isWeighted() const -> bool {
    return weighted;
  }

  template <class _Tp>
  auto graph<_Tp>::setWeighted(bool const& _weighted) -> void {
    weighted = _weighted;
  }

  template <class _Tp>
  auto graph<_Tp>::isSparse() const -> bool {
    double density = computeDensity();
    if (density < densityThreshold) {
      return true;
    }
    else {
      return false;
    }
  }

  template <class _Tp>
  auto graph<_Tp>::isDense() const -> bool {
    return !isSparse();
  }

  template <class _Tp>
  auto graph<_Tp>::isHamiltonian() const -> bool {
    // @TODO: Complete the Hamiltonian graph checks (each vertex may be visited only once).
  }

  template <class _Tp>
  auto graph<_Tp>::isEulerian() const -> bool {
    // @TODO: Complete the Eulerian graph checks (each edge may be visited only once).
  }

  template <class _Tp>
  auto graph<_Tp>::shortestPath(graph_node start, graph_node end) -> list<graph_node> {
    // @TODO: Implement Dijkstra, Bellman-Ford and Roy-Floyd-Warshall algorithms.
  }

  template <class _Tp>
  graph<_Tp>::~graph() { }

  template <class _Tp>
  auto graph<_Tp>::computeDensity() const -> double {
    int edges = 0; // to be updated
    int vertices = 0; // to be updated

    if (this.type == GRAPH_TYPE.Undirected) {
      return (2 * edges) / (vertices * (vectices - 1));
    }
    else {
      return edges / (vertices * (vectices - 1));
    }
  }

}
