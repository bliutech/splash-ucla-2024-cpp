CPP=g++
CFLAGS=-Wall -O0

TARGET=pixel-panic

DEPS=$(TARGET).cpp graphics.cpp

default: $(TARGET)

$(TARGET): $(DEPS)
	$(CPP) $(CFLAGS) -o $@ *.cpp

.PHONY: default format valgrind clean

format:
	clang-format -i -style=Google *.cpp *.hpp

valgrind: $(TARGET)
	valgrind --leak-check=full ./$(TARGET) > /dev/null

clean:
	rm -f $(TARGET)