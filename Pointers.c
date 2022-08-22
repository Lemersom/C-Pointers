// C Pointers         github.com/Lemersom

#include <stdio.h>

// Go to main and follow the Situations order

void S2(int n2, int *p2, int np2, int *x){    // Situation 2
	
	// n2 is local, so its address will be diferent, but p2 is a pointer and its address keeps the same
	printf("\n%d - %d - %d - %d - %d", p2, &n2, &np2, np2, x); // 6684164 - 6684000 - 6684016 - 2 - 6684164
	
	*p2 = 22; // will change n2 in main
	*x = 22;  // will change n2 in main
	n2 = 222; // will just change localy
	
}

struct person{    // 24 bytes     used in Situation 3
	char name[20];
	int age;
};

int main(){
	
	int n1 = 1, *p1 = &n1,
		n2 = 2, *p2 = &n2,
		n3[3] = {10, 20, 30}, *p3 = &n3[0];
	
	struct person someone[3];
	struct person *ptrSomeone = &someone[0];
		
	
	/* ---------- Situation 1 ---------- */
	printf("%d - %d - %d - %d - %d", p1, &p1, &n1, n1, *p1); // 6684180 - 6684168 - 6684180 - 1 - 1
	
	// %p for the hexadecimal address
	printf("\n%p - %p - %p", p1, &p1, &n1); //65FE14 - 65FE08 - 65FE14
	
	/* ---------- Situation 2 ---------- */
	printf("\n%d - %d", p2, &n2); // 6684164 - 6684164
	
	S2(n2, p2, *p2, &n2); // Go to function S2
	
	printf("\n%d", n2); // 22 *changed in S2 using pointer
	
	/* ---------- Situation 3 ---------- */
	printf("\n%d - %d - %d - %d - %d", &n3[0], &n3[1], &n3[2], p3, &p3); // 6684152 - 6684156 - 6684160 - 6684152 - 6684144
	
	// will work with structs too(Situation 4), no need to sum the bytes quantity
	printf("\n%d - %d - %d", p3, p3 + 1, p3 + 2); // 6684152 - 6684156 - 6684160
	
	/* ---------- Situation 4 ---------- */
	printf("\n%d - %d - %d - %d", &someone[0], &someone[1], &someone[2], &ptrSomeone); // 6684064 - 6684088 - 6684112 - 6684056
	printf("\n%d - %d - %d", ptrSomeone, ptrSomeone + 1, ptrSomeone + 2); // 6684064 - 6684088 - 6684112
	
	return 0;
}
