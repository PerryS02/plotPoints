plotPoints: plotPoints.o main.o
	g++ -o plotPoints plotPoints.o main.o -l glui -l glut -l GLU -l GL -l Xi -l Xmu -l Xext -l X11 -l m

plotPoints.o: plotPoints.cpp plotPoints.h
	g++ -c plotPoints.cpp

main.o: main.cpp plotPoints.h
	g++ -c main.cpp

clean:
	rm *.o plotPoints
