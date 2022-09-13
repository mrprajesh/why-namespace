//~~~START:Tue, 13-Sep-2022, 17:15:38 IST
//~~~Author:Rajesh Pandian M | mrprajesh.co.in
#include <iostream>
#include <stdio.h> 
#include <unistd.h> 
#include <string.h> 

using namespace std;

#include "cuda/gen.cpp"           // we can change it .h of backend later
#include "omp/gen.cpp"            // we can change it .h of backend later


int main(int argc, char* argv[]) {
  if(argc<4){
    std::cout<< "Usage: " << argv[0] << " -f <dsl.sp>  -b [cuda|omp|mpi|acc]" << '\n';
    exit(-1);
  }

  int opt;
  char* fileName = NULL;
  char* backendTarget = NULL;
  bool staticGen = false;
  bool dynamicGen = false;
  bool optimize = false;

  while ((opt = getopt(argc, argv, "sdf:b:o")) != -1) {
    switch (opt) {
      case 'f':
        fileName = optarg;
        printf("option:%c value:%s\n", opt, optarg); 
        break;
      case 'b':
        backendTarget = optarg;
        printf("option:%c value:%s\n", opt, optarg); 
        break;
      case 's':
        staticGen = true;
        printf("option:%c\n",opt);
        break;
      case 'd':
        dynamicGen = true;
        printf("option:%c\n",opt);
        break;
      case 'o':
        optimize = true;
        printf("option:%c\n",opt);
        break;
      case '?':
        fprintf(stderr, "Unknown option: %c\n", opt);
        exit(-1);
        break;
      case ':':
        fprintf(stderr, "Missing arg for %c\n", opt);
        exit(-1);
        break;
    }
  }
     
  if(strcmp(backendTarget,"cuda")==0){
    std::cout<< "in cuda:" << fileName << '\n';
    cuda::Gen cppGen;
    cppGen.printMe();
  }
  else if(strcmp(backendTarget,"omp")==0) {
    std::cout<< "in omp:" << fileName << '\n';
    omp::Gen cppGen;
    cppGen.printMe();
  }
  else
    std::cout<< "invalid backend" << '\n';
  
  //printMe(); // should print AST
  
  return 0;
}
