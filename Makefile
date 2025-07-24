CXX = g++
CXXFLAGS = -Wall -std=c++11
TARGET = student_manager
SRCS = main.cpp StudentLib.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = StudentLib.h

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run