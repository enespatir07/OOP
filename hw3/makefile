all: compile2 run2 clean2 compile1 run1 clean1 

compile2: driver2.cpp tetris.cpp tetromino.cpp
	@echo "Compiling"
	@g++ -o test driver2.cpp tetris.cpp tetromino.cpp
run2:
	@echo "Runnnig"
	./test
clean2:
	@rm -f *.o
	@rm -f test

compile1: driver1.cpp tetris.cpp tetromino.cpp
	@echo "Compiling"
	@g++ -o test driver1.cpp tetris.cpp tetromino.cpp
run1:
	@echo "Runnnig"
	./test
clean1:
	@rm -f *.o
	@rm -f test