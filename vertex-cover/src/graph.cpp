#include "graph.h"
#include <utility>

graph::graph(std::istream &in){

  in >> sz_v;
  adj.resize(sz_v);

  sz_e = 0;

  unsigned u, v;
  while(in >> u >> v)
    add_edge(u, v);
}

void graph::add_edge(unsigned u, unsigned v){

  adj[v].emplace_front(u);
  adj[u].emplace_front(v);

  adj[v].front().r = adj[u].begin();
  adj[u].front().r = adj[v].begin();

  ++sz_e;
}

std::list<edge>::iterator graph::remove_edge(std::list<edge>::iterator it){

  unsigned t(it->r->e);
  --sz_e;

  adj[it->e].erase(it->r);
  return adj[t].erase(it);
}

void graph::remove_adjacency(unsigned v)
{ for(auto i = adj[v].begin(); i != adj[v].end(); i = remove_edge(i)); }

bool cover(const sample &s, graph g){

  // FIXME
  // segfault
  for(unsigned i = 0; i < s.limit; ++i)
    if(s.v[i]) g.remove_adjacency(i);

  return g.size_e() == 0;
}

void graph::remove_edge(unsigned u, unsigned v){

  for(auto i = adj[u].begin(); i != adj[u].end();)
    if(i->e == v) i = remove_edge(i);
    else ++i;
}

void graph::print(std::ostream &os) const {

  for(unsigned u = 0; u < adj.size(); ++u)
    for(const auto &v : adj[u])
      os << u+1 << " " << v.e+1 << std::endl;
}

void graph::print() const {

  for(unsigned u = 0; u < adj.size(); ++u)
    for(const auto &v : adj[u])
      std::cout << u+1 << " " << v.e+1 << std::endl;
}

std::pair<unsigned, unsigned> graph::pick() const {

  unsigned u;
  for(u = 0; u < sz_v && adj[u].size() == 0; ++u);

  return {u, adj[u].front().e};
}
