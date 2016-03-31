PARAMS=-std=c++0x -lm -ggdb
TARGET=prog
TEST=test

# targets with shortcuts
compile c: src/main.cpp
	g++ src/main.cpp -o $(TARGET) $(PARAMS)

run r:
	sh lib/run.sh

clean n:
	rm -f $(TARGET) output/* $(TEST) src/functions.cpp

.PHONY=all
all a: clean compile run
