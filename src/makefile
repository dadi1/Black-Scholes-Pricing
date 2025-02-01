CXX = g++
CXXFLAGS = -Wall -std=c++17 -fPIC
LDFLAGS = -shared
SRCDIR = .
OBJDIR = build
INCDIR = include

# Sources and object files
SRC = $(wildcard bsm/*.cpp normals/*.cpp main.cpp)
OBJS = $(SRC:%.cpp=$(OBJDIR)/%.o)
TARGET = libproject.so

# Default rule
all: $(TARGET)

# Compile shared library
$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

# Compile object files
$(OBJDIR)/%.o: %.cpp
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

# Clean build files
clean:
	rm -rf $(OBJDIR) $(TARGET)