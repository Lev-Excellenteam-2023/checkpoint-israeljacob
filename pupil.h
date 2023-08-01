#pragma once
#include <malloc.h>

typedef struct {
	char firstName[51];
	char lastName[51];
	char phoneNumber[11];
	int grades[10];
}Pupil;

Pupil* createPupil(const char* pupilFirstName, const char* lastName,const char* phoneNumber, int* grades);
void printPupil(const Pupil pupil, int numLevel, int numClass);