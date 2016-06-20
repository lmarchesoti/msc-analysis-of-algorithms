#ifndef _SAMPLE_H_
#define _SAMPLE_H_
#include <vector>

class sample {

public:
  std::vector<unsigned> v;
  unsigned size = 0;
  unsigned limit;
  sample(unsigned s) : v(std::vector<unsigned>(s, 0)), size(0), limit(s) { }
  void fill();
};
#endif
