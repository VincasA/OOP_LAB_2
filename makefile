CXX = g++
CXXFLAGS = -std=c++17
SOURCES = Funkcijos.cpp
HEADERS = Funkcijos.h Funkcijos_impl.h Studentas.h
EXECUTABLES = main main_vector main_deque main_list

all: $(EXECUTABLES)

main_vector: main_vector.cpp $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $@ main_vector.cpp $(SOURCES)

main_deque: main_deque.cpp $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $@ main_deque.cpp $(SOURCES)

main_list: main_list.cpp $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $@ main_list.cpp $(SOURCES)

main: main.cpp $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $@ main.cpp $(SOURCES)

clean:
	rm -f $(EXECUTABLES)
