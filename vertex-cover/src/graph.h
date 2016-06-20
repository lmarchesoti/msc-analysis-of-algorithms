#ifndef _GRAPH_H_
#define _GRAPH_H_
#include <list>
#include <vector>
#include <iostream>
#include "edge.h"
#include "sample.h"
#include <utility>

class graph{

public:
  graph(std::istream&);
  std::list<edge>::iterator remove_edge(std::list<edge>::iterator);
  void remove_edge(unsigned, unsigned);
  void remove_adjacency(unsigned);
  unsigned size_v() const { return sz_v; }
  unsigned size_e() const { return sz_e; }
  void print(std::ostream&) const;
  void print() const;
  std::pair<unsigned, unsigned> pick() const;

private:
  unsigned sz_v;
  unsigned sz_e;
  std::vector<std::list<edge>> adj;
  void add_edge(unsigned, unsigned);
};

bool cover(const sample&, graph);
#endif
