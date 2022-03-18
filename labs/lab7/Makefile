lab_file = $(notdir $(shell pwd))
lab: 
	gcc -Wall -Werror -o $(lab_file).out $(lab_file).c main.c
	./$(lab_file).out
check_leaks:
	/opt/homebrew/opt/llvm/bin/clang -fsanitize=address -o $(lab_file).out $(lab_file).c main.c
	ASAN_OPTIONS=detect_leaks=1 ./$(lab_file).out
