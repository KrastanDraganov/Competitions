all: ruler_compass

ruler_compass: contestant_grader.cpp ruler_compass.cpp
	g++ -static -O2 -std=c++11 -o $@ $^

clean:
	rm ruler_compass
