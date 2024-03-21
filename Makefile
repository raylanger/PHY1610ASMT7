CXX=g++
CXXFLAGS=-O3 -march=native

all: ASMT7

ASMT7: main.o read_file.o FFT.o power.o corr.o
	$(CXX) $(LDFLAGS) -o $@ $^ -lnetcdf -lnetcdf_c++4 -lfftw3

main.o: main.cpp read_file.h FFT.h power.h corr.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $< 

read_file.o: read_file.cpp read_file.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

FFT.o: FFT.cpp FFT.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $< 

power.o: power.cpp power.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $< 

corr.o: corr.cpp corr.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $< 

.PHONY: all clean

clean:
	$(RM) ASMT6 main.o read_file.o FFT.o power.o