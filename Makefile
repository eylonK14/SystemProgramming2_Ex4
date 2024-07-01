CXX=clang++
CXXFLAGS=-std=c++2a -Werror -Wsign-conversion -g

# SFML integration
SFML_LIB_DIR := $(shell pkg-config --libs-only-L sfml-graphics)
SFML_LIBS := -lsfml-graphics -lsfml-window -lsfml-system

# Assuming Demo.cpp and Test.cpp are your main .cpp files
SOURCES=Test.cpp Complex.cpp
DEMO_SOURCES=Demo.cpp Complex.cpp
OBJECTS=$(SOURCES:.cpp=.o)
DEMO_OBJECTS=$(DEMO_SOURCES:.cpp=.o)

#tree: demo
#   ./$^

all: demo test

demo: $(DEMO_OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(SFML_LIB_DIR) $(SFML_LIBS)  # Link with SFML libraries

test: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

tidy:
	clang-tidy $(SOURCES) $(DEMO_SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

valgrind: demo test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

# Implicit rule for compiling source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@  # Use implicit rule

.PHONY: clean all

clean:
	rm -f *.o demo test
