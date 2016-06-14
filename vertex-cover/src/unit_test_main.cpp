#include "../lib/unit.hpp"
#include "functions.cpp"

/* declare tests */
UNITTEST(test) {
    // your test here

}

/* test main */
int main() {
    if(!sweet::Unit::runTests()) {
        std::cerr<<"Some errors occoured"<<std::endl;
    }
    return 0;
}
