CXXFLAGS  = -g  -std=c++11 
CXX = g++ $(CXXFLAGS) -Wall -Wreturn-type #-fsanitize=address

all: starplat

starplat: bin main.o cuda.o omp.o ast.o
	$(CXX) bin/cgen.o bin/ogen.o bin/main.o -o StarPlat
	
main.o: main.cpp
	$(CXX) -c main.cpp -o bin/main.o  -I.

cuda.o: cuda/gen.cpp 
	$(CXX) -c cuda/gen.cpp -o bin/cgen.o -I.

omp.o: omp/gen.cpp 
	$(CXX) -c omp/gen.cpp -o bin/ogen.o -I.

ast.o: AST.cpp
	$(CXX) -c AST.cpp -o bin/ast.o

bin:
	mkdir -p bin
	
clean:
	rm bin/*.o StarPlat
	rmdir bin
	
	
	
