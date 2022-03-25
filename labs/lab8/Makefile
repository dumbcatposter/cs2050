lab_file = $(notdir $(shell pwd))
CFLAGS = -Wall -Werror 
lab: 
	gcc-11 $(CFLAGS) -o $(lab_file).out $(lab_file).c main.c
	./$(lab_file).out
valgrind:
	gcc -Wall -Werror -g -o $(lab_file).out $(lab_file).c main.c
	valgrind ./$(lab_file).out
check_leaks:
	/opt/homebrew/opt/llvm/bin/clang -fsanitize=address -o $(lab_file).out $(lab_file).c main.c
	ASAN_OPTIONS=detect_leaks=1 ./$(lab_file).out
check_version:
	gcc-11 --version