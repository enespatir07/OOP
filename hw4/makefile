all: compile run clean

compile: driver.cpp util.cpp
	@echo "Compiling Driver code"
	@g++ -o test driver.cpp util.cpp
run:
	@echo "Runnnig Driver code"
	./test 

clean:
	@rm -f *.o
	@rm -f test