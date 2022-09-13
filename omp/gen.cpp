#include "heads.h"
namespace omp {
  class Gen{
    public:
    Gen(){}
    ~Gen(){}
    
    void printMe(){
      std::cout<< "I am OMP" << '\n';
    }
  };
}
