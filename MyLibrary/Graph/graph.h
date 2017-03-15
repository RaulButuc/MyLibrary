/**
*  graph.h
*
*  @author Raul Butuc
*/

#pragma once

#include "forward_list.h"
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
    auto addNode(_Tp const&) -> void;
    auto addNode(graph_node<_Tp> const&) -> void;
    auto addNodes(std::vector<_Tp> const&) -> void;
    auto addNodes(std::vector<graph_node<_Tp>> const&) -> void;
    auto getType() const -> GRAPH_TYPE;
    auto setType(GRAPH_TYPE const&) -> void;
    auto isWeighted() const -> bool;
    auto setWeighted(bool const&) -> void;
    auto getNrNodes() const -> int;
    auto getNrEdges() const -> int;
    auto getNodeInnerDegree(graph_node<_Tp> const&) const -> int;
    auto getNodeOuterDegree(graph_node<_Tp> const&) const -> int;
    auto getNodeDegree(graph_node<_Tp> const&) const-> int;
    auto isComplete() const -> bool;
    auto isSimple() const -> bool;
    auto isMultigraph() const -> bool;
    auto isQuiver() const -> bool;
    auto isConnected() const -> bool;
    auto isStronglyConnected() const -> bool;
    auto isSparse() const -> bool;
    auto isDense() const -> bool;
    auto isPath() const -> bool;
    auto isPlanar() const -> bool;
    auto isCycle() const -> bool;
    auto isInterval() const -> bool;
    auto isBipartite() const -> bool;
    auto isHamiltonian() const -> bool;
    auto isEulerian() const -> bool;
    auto shortestPath(graph_node<_Tp>, graph_node<_Tp>) -> list<graph_node<_Tp>>;
    ~graph();

  private:

    GRAPH_TYPE type;
    bool weighted;
    double densityThreshold;
    std::vector<graph_node<_Tp>> nodes;

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
  auto my_library::graph<_Tp>::addNode(_Tp const& _value) -> void {
    graph_node<_Tp> node(_value);
    nodes.push_back(node);
  }

  template<class _Tp>
  auto my_library::graph<_Tp>::addNode(graph_node<_Tp> const& _node) -> void {
    nodes.push_back(_node);
  }

  template<class _Tp>
  inline auto graph<_Tp>::addNodes(std::vector<_Tp> const &) -> void
  {
  }

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
  auto my_library::graph<_Tp>::getNrNodes() const -> int {
    return nodes.size();
  }

  template <class _Tp>
  auto my_library::graph<_Tp>::getNrEdges() const -> int {
    for (auto node : nodes) {
      auto neighbours = node.getNeighbours();
      return neighbours.size();
    }
  }

  template<class _Tp>
  auto graph<_Tp>::getNodeInnerDegree(graph_node<_Tp> const& _node) const -> int {
    if (type == GRAPH_TYPE::Directed) {
      return 0; // The inner degree
    }

    return getNodeDegree(_node);
  }

  template<class _Tp>
  auto graph<_Tp>::getNodeOuterDegree(graph_node<_Tp> const& _node) const -> int {
    if (type == GRAPH_TYPE::Directed) {
      return 0; // The outer degree
    }      

    return getNodeDegree(_node);
  }

  template<class _Tp>
  auto graph<_Tp>::getNodeDegree(graph_node<_Tp> const& _node) const -> int {
    if (type == GRAPH_TYPE::Undirected) {
        return _node.getNeighbours().size();      
    }

    return -1;
  }

  template<class _Tp>
  inline auto graph<_Tp>::isComplete() const -> bool
  {
    return false;
  }

  template<class _Tp>
  inline auto graph<_Tp>::isSimple() const -> bool
  {
    return false;
  }

  template<class _Tp>
  inline auto graph<_Tp>::isMultigraph() const -> bool
  {
    return false;
  }

  template<class _Tp>
  inline auto graph<_Tp>::isQuiver() const -> bool
  {
    return false;
  }

  template<class _Tp>
  inline auto graph<_Tp>::isConnected() const -> bool
  {
    return false;
  }

  template<class _Tp>
  inline auto graph<_Tp>::isStronglyConnected() const -> bool
  {
    return false;
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

  template<class _Tp>
  inline auto graph<_Tp>::isPath() const -> bool
  {
    return false;
  }

  template<class _Tp>
  inline auto graph<_Tp>::isPlanar() const -> bool
  {
    return false;
  }

  template<class _Tp>
  inline auto graph<_Tp>::isCycle() const -> bool
  {
    return false;
  }

  template<class _Tp>
  inline auto graph<_Tp>::isInterval() const -> bool
  {
    return false;
  }

  template<class _Tp>
  inline auto graph<_Tp>::isBipartite() const -> bool
  {
    return false;
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
    int edges = getNrEdges();
    int nodes = getNrNodes();

    switch (this.type) {
      case GRAPH_TYPE::Undirected:
        return (2 * edges) / (nodes * (nodes - 1));
        break;

      case GRAPH_TYPE::Directed:
        return edges / (nodes * (nodes - 1));
        break;

      default:
        break;
    }
    
    return -1;
  }

}
