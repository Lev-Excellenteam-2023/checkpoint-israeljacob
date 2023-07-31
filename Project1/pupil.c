#include "Pupil.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Pupil* createPupil(const char* firstName, const char* lastName, const char* phoneNumber, int* grades)
{
    Pupil* newPupil = (Pupil*)malloc(sizeof(Pupil));
    strcpy_s(newPupil->firstName, firstName, 50);
    strcpy_s(newPupil->lastName, lastName, 50);
    strcpy_s(newPupil->phoneNumber, phoneNumber, 10);
    newPupil->phoneNumber[10] = '\0'; // Ensure null-termination
    for (size_t i = 0; i < 10; i++)
    {
        newPupil->grades[i] = grades[i];
    }

    return newPupil;
}

void printPupil(const Pupil pupil, int numLevel, int numClass)
{
    printf("%s %s %s", pupil.firstName, pupil.lastName, pupil.phoneNumber);
    printf("%d %d ", numLevel, numClass);
    for (int i = 0; i < 10; i++) {
        printf("%d ", pupil.grades[i]);
    }
}
