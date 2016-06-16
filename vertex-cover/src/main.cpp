#include <iostream>
#include <vector>
#include <list>

using namespace std;

class edge {

public:
  unsigned e;
  list<edge>::iterator r;
  edge(unsigned d) : e(d), r(NULL) { }
  edge() { }
};

class graph{
public:
  graph(istream&);
  list<edge>::iterator remove_edge(list<edge>::iterator);
  void remove_adjacency(unsigned);
  unsigned size_v() { return v; }
  unsigned size_e() { return e; }

private:

  unsigned v;
  unsigned e;
  vector<list<edge>> adj;
  void add_edge(unsigned, unsigned);
};

graph::graph(istream &in){

  in >> v;
  adj.resize(v);

  unsigned u, v;
  while(in >> u >> v)
    add_edge(u, v);
}

void graph::add_edge(unsigned u, unsigned v){

  adj[v].emplace_front(u);
  adj[u].emplace_front(v);

  adj[v].front().r = adj[u].begin();
  adj[u].front().r = adj[v].begin();

  ++e;
}

list<edge>::iterator graph::remove_edge(list<edge>::iterator it){

  unsigned t(it->r->e);
  --e;

  adj[it->e].erase(it->r);
  return adj[t].erase(it);
}

void graph::remove_adjacency(unsigned v)
{ for(auto i = adj[v].begin(); i != adj[v].end(); i = remove_edge(i)); }

/* global variables */

/* function prototypes */
vector<unsigned> vertex_cover_brute(graph&);

vector<unsigned> vertex_cover_brute(graph&, vector<unsigned>&, unsigned);

vector<unsigned> to_vector(unsigned, unsigned);

vector<unsigned> vertex_cover_approx(graph&);

/* debug */

int main(){

  graph g(cin);

  //auto c = vertex_cover_brute(g);
  auto c = vertex_cover_approx(g);

  for(const auto &i : c)
    cout << i << " ";
  cout << endl;
  
  return 0;
}

/* functions */
vector<unsigned> vertex_cover_brute(graph &g){

  //vector<unsigned> sample(g.size_v(), 0);

  //return vertex_cover_brute(g, sample, 0);
}

vector<unsigned> vertex_cover_brute(graph &g, vector<unsigned> &sample, unsigned k){

/*
  if(k == sample.size()){

    // process sample

    return opt;
  }

  sample[k] = 0;
  // rec

  sample[k] = 1;
  // rec

*/
  // FIXME
  return sample; 
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
