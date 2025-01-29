
all: ll_program

ll_program: ll_main.o ll.h ll.ipp
	g++ $< -o $@ -std=c++14

test: lltest
	LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:/cs/cs270/lib ./lltest

lltest: test.o
	g++ $^ -o $@ -lgtest -lpthread -L/cs/cs270/lib -std=c++14

%.o: %.cpp ll.h ll.ipp
	g++ -c $< -o $@ -I/cs/cs270/include -std=c++14

clean:
	rm -f ./*.o lltest ll_program
