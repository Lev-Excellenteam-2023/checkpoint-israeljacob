#include "linkedList.h"


typedef struct {
	LinkedList school[12][10];
}School;

School createSchool();
void destroySchool(School school);
void printSchool(School);
School addPupil(School, char*, char*, char* phoneNumber, int numLevel, int numClass, int* grades);
Pupil* searchPupil(School school, char[], char [], int, int);