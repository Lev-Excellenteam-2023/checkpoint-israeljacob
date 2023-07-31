#include "linkedList.h"


typedef struct {
	LinkedList school[12][10];
}School;

School* createSchool();
void printSchool(School school);
School* addPupil(School school, char* firstName, char* lastName, char* phoneNumber, int numLevel, int numClass, int* grades);