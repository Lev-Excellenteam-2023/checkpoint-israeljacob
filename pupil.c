#include "pupil.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Pupil createPupil(const char firstName[], const char lastName[], const char phoneNumber[], int grades[])
{
    Pupil newPupil;// = (Pupil*)malloc(sizeof(Pupil));
    size_t i;
    for (i = 0; i < sizeof(firstName); i++)
    {
        newPupil.firstName[i] = firstName[i];
    }
    newPupil.firstName[i] = 0;

    for (i = 0; i < sizeof(lastName); i++)
    {
        newPupil.lastName[i] = lastName[i];
    }
    newPupil.lastName[i] = 0;

    for (i = 0; i < 10; i++)
    {
        newPupil.phoneNumber[i] = phoneNumber[i];
    }
    newPupil.phoneNumber[10] = 0;

    for (i = 0; i < 10; i++)
    {
        newPupil.grades[i] = grades[i];
    }

    return newPupil;
}


void printPupil(const Pupil* pupil, int numLevel, int numClass)
{
    printf("%s %s %s ", pupil->firstName, pupil->lastName, pupil->phoneNumber);
    printf("%d %d ", numLevel + 1, numClass + 1);
    for (int i = 0; i < 10; i++) {
        printf("%d ", pupil->grades[i]);
    }
    printf("\n");
}
