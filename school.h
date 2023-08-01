#pragma once
#include "linkedList.h"


typedef struct {
	LinkedList school[12][10];
}School;

School* createSchool();
void printSchool(School);
School addPupil(School, char*, char*, char* phoneNumber, int numLevel, int numClass, int* grades);