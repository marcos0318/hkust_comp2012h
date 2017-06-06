register: main.o course.o student.o courseSelection.o studentTable.o courseTable.o selectionTable.o 
	g++ -o register main.o course.o student.o courseSelection.o studentTable.o courseTable.o selectionTable.o

main.o: main.cpp course.h student.h courseSelection.h studentTable.h courseTable.h selectionTable.h 
	g++ -c main.cpp

selectionTable.o: selectionTable.cpp student.h course.h courseSelection.h selectionTable.h
	g++ -c selectionTable.cpp

courseTable.o: courseTable.cpp courseTable.h course.h
	g++ -c courseTable.cpp

studentTable.o: studentTable.cpp studentTable.h student.h
	g++ -c studentTable.cpp

student.o: student.cpp student.h
	g++ -c student.cpp

course.o: course.cpp course.h
	g++ -c course.cpp

courseSelection.o: courseSelection.cpp courseSelection.h
	g++ -c courseSelection.cpp

clean: 
	rm -f *.o register 
