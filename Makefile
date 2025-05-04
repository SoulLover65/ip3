CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Files and Targets
SRC = FishingRod.cpp FishingNet.cpp FishingSpear.cpp demo.cpp test.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = demo
testEXEC = test
DELEXEC = demo.exe test.exe

# Default target (build everything)
all: build

# Build targets
build: $(EXEC)

$(EXEC): FishingRod.o FishingNet.o FishingSpear.o demo.o
	$(CXX) $(CXXFLAGS) $^ -o $@

test_build: $(testEXEC)

$(testEXEC): FishingRod.o FishingNet.o FishingSpear.o test.o
	$(CXX) $(CXXFLAGS) $^ -o $@

# Run targets
run: build
	./$(EXEC)

test_run: test_build
	./$(testEXEC)

# Combined build and run
build_run: build run

test_build_run: test_build test_run

# Object files
%.o: %.cpp FishingRod.h FishingNet.h FishingTool.h FishingBoat.h FishingSpear.hn bbbbbbb nbbbbbbbbbbbb
	$(CXX) $(CXXFLAGS) -c $<

# Clean
clean:
	del -f $(OBJ) $(DELEXEC)