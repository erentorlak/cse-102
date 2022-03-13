all: compile run clean

compile: main.c utils.c utils.h
	@echo "-------------------------------------------"
	@echo "Compiling..."
	@gcc -o test main.c utils.c

run:
	@echo "-------------------------------------------"
	@echo "Running the tests...."
	@echo "================================================================================="
	./test
	@echo "================================================================================="
	@echo "Completed tests...."

clean:
	@echo "-------------------------------------------"
	@echo "Removing compiled files..."
	@rm -f *.o
	@rm -f *.txt
	@rm -f test
	
