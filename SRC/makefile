CC = g++
CFLAGS =  -O3  -DNDEBUG

OBJ  = inputData.o  iTest.o  fTest.o  simplex.o  reltab.o  mvc.o  main.o

all : demics

demics : $(OBJ)
	$(CC)  -o  demics  $(CFLAGS)  $(OBJ)  -lm

inputData.o : inputData.cpp
	$(CC)  $(CFLAGS)  -c  inputData.cpp

iTest.o : iTest.cpp
	$(CC)  $(CFLAGS)  -c  iTest.cpp

fTest.o : fTest.cpp
	$(CC)  $(CFLAGS)  -c  fTest.cpp

simplex.o : simplex.cpp
	$(CC)  $(CFLAGS)  -c  simplex.cpp

reltab.o : reltab.cpp
	$(CC)  $(CFLAGS)  -c  reltab.cpp

mvc.o : mvc.cpp
	$(CC)  $(CFLAGS)  -c  mvc.cpp

main.o : main.cpp
	$(CC)  $(CFLAGS)  -c  main.cpp

clean:
	/bin/rm -f *.o *~ core.*  demics
