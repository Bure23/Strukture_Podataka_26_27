#include <stdio.h>
#include <stdlib.h>


typedef struct _Person* Position;
typedef struct _Person {
	char name[20];
	char surname[20];
	int age;
	Position next;
} Person;

int insertBegin( char* name, char* surname, int age, Position P) {
		Person* p = (Person*)malloc(sizeof(Person));
	if (p == NULL) {
		printf("Memory allocation failed!\n");
		return -1;
	}
	
	strcpy(p->name, name);
	strcpy(p->surname, surname);
	p->age = age;
	p->next = NULL;
	insertAfter(p, P);
	return 0;
}
int insertAfter(Position newP, Position P) {
	newP->next = P->next;
	P->next = newP;
}

int printList(Position P) {
	while(P != NULL) {
		printf("%s %s %d\n", P->name, P->surname, P->age);
		P = P->next;
	}

	return 0;
}

int insertEnd(char* name, char* surname, int age, Position P) {
	Person* p = (Person*)malloc(sizeof(Person));
	if (p == NULL) {
		printf("Memory allocation failed!\n");
		return -1;
	}

	strcpy(p->name, name);
	strcpy(p->surname, surname);
	p->age = age;
	p->next = NULL;

	while (P->next != NULL)
	{
		P = P->next;
	}
	insertAfter(p, P);
	return 0;
}

Position findLastname(char* surname, Position P) {
	
	for (P = P->next; P != NULL; P = P->next)
	{
		if (strcmp(P->surname, surname) == 0)
		{
			return P;
		}
	}
	
	return NULL;
}

int deletePerson(char* surname, Position head) {
	Position prev = head;
	Position current = head->next;
	current = findLastname(surname, prev);
	while(prev -> next != current) {
		prev = prev->next;
	} 
	
	prev->next = current->next;
	free(current);
	return 0;
}

int main() {
	Person Head={.name={0}, .surname={0}, .age=0, .next = NULL};
	Position P = &Head;
	printList(P->next);
	insertBegin("Mate", "Matic", 30, P);

	return 0;
}