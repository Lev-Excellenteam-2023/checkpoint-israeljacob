#include "school.h"
#include <stdio.h>


int main()
{
    School* school = createSchool();
    char* firstName;
    char* lastName;
    char* phoneNmber;
    int numLevel;
    int numClass;
    int grades[10];
    FILE* fptr;
    fptr = fopen_s("file.txt", "r", 1000000000000);
    char str[50];
    int offset = 0;
    int charsRead;
    while (!feof(fptr))
    {
        sscanf_s(fptr + offset, " ", str, &charsRead);
        firstName = str;
        offset += charsRead;

        sscanf_s(fptr + offset, " ", str, &charsRead);
        lastName = str;
        offset += charsRead;

        sscanf_s(fptr + offset, " ", str, &charsRead);
        phoneNmber = str;
        offset += charsRead;

        sscanf_s(fptr + offset, " ", str, &charsRead);
        numLevel = str;
        offset += charsRead;

        sscanf_s(fptr + offset, " ", str, &charsRead);
        numClass = str;
        offset += charsRead;

        for (size_t i = 0; i < 10; i++)
        {
            sscanf_s(fptr + offset, " ", str, &charsRead);
            grades[i] = str;
            offset += charsRead;
        }

        addPupil(*school, firstName, lastName, phoneNmber, numLevel, numClass, grades);
    }

    printSchool(*school);
}