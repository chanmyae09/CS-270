
all: caesar

test: caesartest
	LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:/cs/cs270/lib ./caesartest

caesar: caesar_main.o Caesar.o
	g++ $^ -o $@

caesartest: caesar_test.o Caesar.o
	g++ $^ -o $@ -lgtest -lpthread -L/cs/cs270/lib

%.o: %.cpp
	g++ -c $^ -o $@ -I/cs/cs270/include

clean:
	rm -f ./*.o caesar caesartest
