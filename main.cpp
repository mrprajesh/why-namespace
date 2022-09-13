//~~~START:Tue, 13-Sep-2022, 17:15:38 IST
//~~~Author:Rajesh Pandian M | mrprajesh.co.in
#include <bits/stdc++.h>
#include <stdio.h> 
#include <unistd.h> 
using namespace std;

#include "cuda/gen.cpp"
#include "omp/gen.cpp"

int main(int argc, char* argv[]) {

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
        printf("option:%c val:%s\n", opt, optarg); 
        break;
      case 'b':
        backendTarget = optarg;
        printf("option:%c val:%s\n", opt, optarg); 
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
     
    
  return 0;
}
