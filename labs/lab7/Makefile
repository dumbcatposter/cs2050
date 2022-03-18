lab_file = $(notdir $(shell pwd))
lab: 
	gcc -Wall -Werror -o $(lab_file).out $(lab_file).c main.c
	./$(lab_file).out
valgrind:
	gcc -Wall -Werror -o $(lab_file).out $(lab_file).c main.c
	valgrind ./$(lab_file).out
