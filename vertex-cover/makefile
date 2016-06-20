PARAMS=-std=c++0x -lm -ggdb
TARGET=prog
TEST=test

# targets with shortcuts
compile c: src/main.cpp
	g++ src/* -o $(TARGET) $(PARAMS)

test t: src/test_main.cpp
	sh lib/extract_functions.sh 
	g++ src/test_main.cpp -o $(TEST) -I lib/ $(PARAMS)
	./test

run r:
	sh lib/run.sh

clean n:
	rm -f $(TARGET) output/* $(TEST) src/functions.cpp

generatec gc:
	g++ generate_input.cpp -o generate

.PHONY=all
all a: clean compile run
