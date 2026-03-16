main: main.o practic1.o
	gcc -Wall -Werror -Wextra main.o practic1.o -o main

main.o: main.c
	gcc -c -Wall -Werror -Wextra main.c -o main.o

practic1.o: practic1.c
	gcc -c -Wall -Werror -Wextra practic1.c -o practic1.o

clean:
	rm main *.o