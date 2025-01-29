
all: test

test: stringtest
	LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:/cs/cs270/lib ./stringtest

stringtest: tests.o mystring.o
	g++ $^ -o $@ -lgtest -lpthread -L/cs/cs270/lib -std=c++14

%.o: %.cpp mystring.h
	g++ -c $< -o $@ -I/cs/cs270/include -std=c++14

clean:
	rm -f ./*.o stringtest
