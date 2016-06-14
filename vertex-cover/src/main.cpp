#include <iostream>
#include <vector>

using namespace std;

/* data structures */
class graph{
public:
  graph(istream&);
  void remove_edge(unsigned, unsigned);
  void remove_adjacency(unsigned);
  unsigned size_v() { return 0; }

private:

  // TODO
  /* decide which representation works best for removing adjacency */

};

graph::graph(istream &in){

  // TODO
}

/* global variables */

/* function prototypes */
vector<unsigned> vertex_cover_brute(graph&);

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

  unsigned opt = g.size_v();

  /* check if sample is a cover			   *
   * if so, save it if it is less than the optimum *
   * optional: early stop when first opt found	   */
  for(unsigned sample = 0; sample <= g.size_v(); ++sample){

    // TODO

  }

  return to_vector(opt, g.size_v());
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
