SRC:=Observer.cpp

a: c.o
	g++ c.o -o a

c.o: $(SRC)
	g++ $(SRC) -c -o c.o

.PHONY: clean
clean:
	rm *.o *.exe -rf