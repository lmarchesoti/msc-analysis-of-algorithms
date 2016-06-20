#include <iostream>
#include <vector>
#include <list>
#include "graph.h"

using namespace std;

/* function prototypes */
sample vertex_cover_brute(graph&);

void vertex_cover_brute(graph&, sample&, sample&, unsigned);

sample vertex_cover_approx(graph&);

/* debug */

int main(){

  graph g(cin);

  auto c = vertex_cover_brute(g);
  //auto c = vertex_cover_approx(g);

  for(unsigned i = 1; i <= c.limit; ++i)
    if(c.v[i]) cout << i << " ";
  cout << endl;
  
  return 0;
}

/* functions */
sample vertex_cover_brute(graph &g){

  sample s(g.size_v());
  sample opt(g.size_v());
  opt.fill();

  vertex_cover_brute(g, s, opt, 0);

  return opt;
}

void vertex_cover_brute(graph &g, sample &s, sample &opt, unsigned k){

  if(k == s.limit){

    if(cover(s, g) && (s.size < opt.size))
      opt = s;

    return;
  }

  s.v[k] = 0;
  vertex_cover_brute(g, s, opt, k+1);

  ++s.size;
  s.v[k] = 1;
  vertex_cover_brute(g, s, opt, k+1);
  --s.size;
}

sample vertex_cover_approx(graph &g){

  sample c(g.size_v());

  while(g.size_e()){

    auto e = g.pick();

    c.v[e.first] = 1;
    c.v[e.second] = 1;

    g.remove_adjacency(e.first);
    g.remove_adjacency(e.second);
  }

  return c;
}
