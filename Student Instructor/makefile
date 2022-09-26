CC = g++
DEBUG = -g
CFLAGS = -Wall -std=c++14 $(DEBUG) -O0 -pedantic-errors
LFLAGS = -Wall $(DEBUG)

main: Student.h Instructor.h main.cpp Student.cpp Instructor.cpp
	$(CC) $(CFLAGS) -o main main.cpp Student.cpp Instructor.cpp

student: Student.h Student.cpp
	$(CC) $(CFLAGS) -o Student Student.h Student.cpp

instructor: Instructor.h Instructor.cpp
	$(CC) $(CFLAGS) -o Instructor Instructor.h Instructor.cpp

clean:
	rm -rf main
	rm -rf Instructor
	rm -rf Student
	rm -rf *.o
