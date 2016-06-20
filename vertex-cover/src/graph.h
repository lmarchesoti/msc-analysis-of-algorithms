#ifndef _GRAPH_H_
#define _GRAPH_H_
#include <list>
#include <vector>
#include <iostream>
#include "edge.h"
#include "sample.h"

class graph{

public:
  graph(std::istream&);
  std::list<edge>::iterator remove_edge(std::list<edge>::iterator);
  void remove_edge(unsigned, unsigned);
  void remove_adjacency(unsigned);
  unsigned size_v() const { return v; }
  unsigned size_e() const { return e; }
  void print(std::ostream&) const;
  void print() const;

private:
  unsigned v;
  unsigned e;
  std::vector<std::list<edge>> adj;
  void add_edge(unsigned, unsigned);
};

bool cover(const sample&, graph);
#endif
