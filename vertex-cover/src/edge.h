#ifndef _EDGE_H_
#define _EDGE_H_
#include <list>

class edge {

public:
  unsigned e;
  std::list<edge>::iterator r;
  edge(unsigned d) : e(d), r(nullptr) { }
  edge() { }
};
#endif
