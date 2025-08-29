CXX ?= g++
FLAGS +=  -Wall -Wextra -Wpedantic -std=c++23 -O0 -D_GLIBCXX_DEBUG -g 
TARGET = build/test
OBJECTS = build/test.o



$(TARGET) : $(OBJECTS)
	$(CXX) $(FLAGS) -o $(TARGET) $(OBJECTS) $(LIBS)

build/%.o:
	@if test ! -d 'build'; then mkdir 'build'; echo "created 'build'" ; fi
	$(CXX) $(FLAGS) $(INCLUDES) -c -o $@ $<

clean:
	rm build/*.o

all: $(TARGET)



build/test.o: src/test/test.cpp src/include/aliases.hpp src/include/core.hpp makefile

