test: test.o
	g++ test.o -o test

test.o: test.cpp
	g++ test.cpp -c -o test.o

.PHONY : clean
clean:
	del *.o test.exe -rf