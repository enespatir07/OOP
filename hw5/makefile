all: compile1 run1 compile2 run2 clean
 
compile1: driver1.cpp tetris.cpp tetromino.cpp
	@echo "Compiling Driver code"
	@g++ -o test driver1.cpp tetris.cpp tetromino.cpp
run1:
	@echo "Runnnig Driver code"
	./test 

compile2: driver2.cpp tetris.cpp tetromino.cpp
	@echo "Compiling Driver code"
	@g++ -o test driver2.cpp tetris.cpp tetromino.cpp
run2:
	@echo "Runnnig Driver code"
	./test 



clean:
	@rm -f *.o
	@rm -f test