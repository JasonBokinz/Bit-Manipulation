#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int GetBit(int num, int pos) {
	return (num >> pos) & 1;
}
int SetBit(int num, int pos) {
	return (1 << pos) | num;
}
int ClearBit(int num, int pos) {
	return num & ~(1 << pos);
}
int Reversbit(int num) {
	int reversed = 0;
    int size = sizeof(num) * 8;
    for (int i = 0; i < size; i++) {
        reversed = reversed << 1;
        reversed = reversed | (num & 1);
        num = num >> 1;
    }
    return reversed;
}
int CountBit(int num) {
	int counter = 0;
	for (int i = 0; i < 32; i++) {
		if ((num & 1) == 1) {
			counter++;
		}
		num = num >> 1;
	}
	return counter;
}
int PowerofTwo(unsigned int num) {
	if (num == 0) {
		return 0;
	}
	while (num > 1) {
		if (num % 2 == 1) {
			return 0;
		}
		num /= 2;
	}
	return 1;
}

int main(int argc, char* argv[]){    
	(void)argc;
	(void)argv;
	if (argc < 3) {
		printf("Error: argc value less than 2");
        return 1;
    }
	int function = atoi(argv[1]);
	switch(function) {
		case 1: 
			printf("%d", GetBit(atoi(argv[2]), atoi(argv[3])));
			break;
		case 2:
			printf("%d", SetBit(atoi(argv[2]), atoi(argv[3])));
			break;
		case 3:
			printf("%d", ClearBit(atoi(argv[2]), atoi(argv[3])));
			break;
		case 4:
			printf("%d", Reversbit(atoi(argv[2])));
			break;
		case 5:
			printf("%d", CountBit(atoi(argv[2])));
			break;
		case 6:
			printf("%d", PowerofTwo((unsigned int) atoi(argv[2])));
			break;
		default:
			printf("Invalid function number: %d\n", function);
			return 1;
	}
	return 0;
}