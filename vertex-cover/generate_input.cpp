#include <iostream>

using namespace std;

int main(){

  unsigned size;

  cin >> size;

  cout << size << endl;

  for(unsigned i = 0; i < size; ++i)
    for(unsigned j = i+1; j < size; ++j)
      cout << i << " " << j << endl;

  return 0;
}
