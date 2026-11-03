#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Poly* Position;
typedef struct Poly{
	int coeff;
	int exp;
	Position next;

}polynom;

int insertBegin(Position q, Position newPoly) {
	newPoly->next = q->next;
	q->next = newPoly;	
	return 0;
}

int main() {
	
	if(q->next == NULL) {
		insertBegin(q, newPoly);
	}

	if(q->next != NULL && q->next->exp < newPoly->exp) {
		insertBegin(q, newPoly);
	}


	return 0;
}