all: compile run clean
 
compile: driver.cpp pfarray.cpp
	@echo "Compiling"
	@g++ -o test driver.cpp pfarray.cpp
run:
	@echo "Runnnig Driver code"
	./test 
clean:
	@rm -f *.o
	@rm -f test