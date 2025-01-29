
all: test

test: tabletest
	LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:/cs/cs270/lib ./tabletest

testcompile: test.o

tabletest: tabletest2.o
	g++ $^ -o $@ -lgtest -lpthread -L/cs/cs270/lib

%.o: %.cpp hashtable.h
	g++ -c $< -I/cs/cs270/include -o $@

clean:
	rm -f ./*.o tabletest
