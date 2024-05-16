

all: clean compile1 run1 clean compile2 run2

compile1: driver1.cpp tetromino.cpp tetromino.h tetris.h tetris.cpp
	@echo "-------------------------------------------"
	@echo "Compiling Driver 1"
	@g++ -o test driver1.cpp tetromino.cpp tetris.cpp
run1:
	@echo "Runnnig Driver 1"
	./test 

compile2: driver2.cpp tetromino.cpp tetromino.h tetris.h tetris.cpp
	@echo "-------------------------------------------"
	@echo "Compiling Driver 2"
	@g++ -o test driver2.cpp tetromino.cpp tetris.cpp

run2:
	@echo "Runnnig Driver 2"
	./test 
clean:
	@rm -f *.o
	@rm -f test