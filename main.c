#include <stdio.h>
#include <stdlib.h>

typedef struct _Student{
	int bodovi;
	char ime[20];
	char prezime[30];
} student;

int main() {
	char buffer[100] = {0};
	int br = 0;
	FILE* fp = fopen("popis.txt", "r");
	if(!fp) {
		printf("Greska pri otvaranju datoteke!\n");
		return -1;
	}

	while (!feof(fp)) {
		fgets(buffer, 100, fp);
		br++;
	}

	student* studenti = (student*)malloc(br * sizeof(student));
	if( !studenti ) {
		printf("Greska pri alokaciji memorije!\n");
		fclose(fp);
		return -1;
	}
	
	
	br = 0;
	while( !feof(fp)) {
		fscanf(fp, "%d %s %s", &studenti[br].bodovi, studenti[br].ime, studenti[br].prezime);
		br++;
	}

	fclose(fp);
	free(studenti);

	return 0;
}