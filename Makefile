# Define the directories for source and include files
SRCDIR = src
INCDIR = include

# Update the find commands to search in the src and include directories
SRCS = $(shell find $(SRCDIR) -type f -name '*.cpp')
HEADERS = $(shell find $(INCDIR) -type f -name '*.h')

# Compiler and flags
CXX = clang++
override CXXFLAGS += -g -Wmost -Werror

# Targets
all: main

main: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o "$@"

main-debug: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -U_FORTIFY_SOURCE -O0 $(SRCS) -o "$@"

clean:
	rm -f main main-debug
