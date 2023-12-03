# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -g -Wall

# Source files
SOURCES = Avaliacao.cpp Cliente.cpp ListaMidia.cpp Main.cpp Midia.cpp Streaming.cpp

# Header files
HEADERS = Avaliacao.h Cliente.h ListaMidia.h Midia.h Streaming.h

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Executable
EXECUTABLE = Main

# Targets
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)
