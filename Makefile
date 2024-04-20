CPP=g++
CFLAGS=-g -Wall -O0

TARGET=pixel-panic

DEPS=$(wildcard *.cpp) $(wildcard *.hpp)

default: $(TARGET)

$(TARGET): $(DEPS)
	$(CPP) $(CFLAGS) -o $@ *.cpp

.PHONY: default format valgrind clean

format:
	clang-format -i -style=Google *.cpp *.hpp

valgrind: $(TARGET)
	valgrind --leak-check=full ./$(TARGET)

clean:
	rm -f $(TARGET)