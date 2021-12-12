main:
	g++ main.cpp -o main -pthread -lcunit
clean:
	rm main
install:
	./install
run:
	./main
