CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
TARGET = cinema_db_cpp
SOURCES = main.cpp Film.cpp FilmArray.cpp file_operations.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp Film.h FilmArray.h FileOperations.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET) cinema_database.bin

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
