#include "school.h"
#include <stdio.h>


int main()
{
    School* school = createSchool();
    char firstName[50];
    char lastName[50];
    char phoneNumber[11];
    int numLevel;
    int numClass;
    int grades[10];
    FILE* fptr;
    fopen_s(&fptr, "file.txt", "r");
    char str[50];
    int offset = 0;
    int charsRead;
    while (fscanf_s(fptr, "%s", str) == 1)
    {
        strcpy(firstName, str);
        fscanf_s(fptr, "%s", str);
        strcpy_s(lastName, str);
        fscanf_s(fptr, "%s", phoneNumber);
        fscanf_s(fptr, "%d", &numLevel);
        fscanf_s(fptr, "%d", &numClass);
        for (size_t i = 0; i < 10; i++)
        {
            fscanf_s(fptr, "%d", &grades[i]);
        }

        addPupil(*school, firstName, lastName, phoneNumber, numLevel, numClass, grades);
    }

    printSchool(*school);

    return 0;
}
