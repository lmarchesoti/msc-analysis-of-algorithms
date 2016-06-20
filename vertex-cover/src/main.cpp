#include <iostream>
#include <vector>
#include <list>
#include "graph.h"

using namespace std;

/* function prototypes */
sample vertex_cover_brute(graph&);

void vertex_cover_brute(graph&, sample&, sample&, unsigned);

vector<unsigned> to_vector(unsigned, unsigned);

vector<unsigned> vertex_cover_approx(graph&);

/* debug */

int main(){

  graph g(cin);

  /*
  // TEST BUILD REMOVE
  g.print(cout);
  cout << endl;

  //g.remove_edge(3, 6);
  //g.remove_edge(3, 6);
  //g.remove_adjacency(3);
  //g.remove_adjacency(3);

  for(int i = 0; i < 7; ++i)
    g.remove_adjacency(6-i);

  g.print(cout);
  cout << endl;
  */

  /*
  // TEST REMOVE 5ADJ REMOVE 6ADJ
  g.print(cout);
  cout << endl;

  g.remove_adjacency(5);
  g.remove_adjacency(6);

  g.print(cout);
  cout << endl;
  */

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

  return s;
}

void vertex_cover_brute(graph &g, sample &s, sample &opt, unsigned k){

  if(k == s.limit){

    if(s.size < opt.size && cover(s, g))
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

/* turns a number cover into a vector cover with up to vertex l */
vector<unsigned> to_vector(unsigned n, unsigned l){

  vector<unsigned> r;
  for(unsigned i = 0; i < l; ++i, n /= 2) 
    if(n%2) r.push_back(i);

  return r;
}

vector<unsigned> vertex_cover_approx(graph &g){

  vector<unsigned> c;

  // TODO

  return c;
}
