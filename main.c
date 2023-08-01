#include "school.h"
#include <stdio.h>
#include <stdlib.h>

School* populateSchoolFromFile(School* school, const char* fileName) {
    FILE* file;
    fopen_s(&file, fileName, "r");

    char firstName[50];
    char lastName[50];
    char phoneNumber[11];
    int numLevel;
    int numClass;
    int grades[10];

    while (fscanf_s(file, "%49s %49s %10s %d %d", firstName, 50, lastName, 50, phoneNumber, 11, &numLevel, &numClass) == 5) {
        for (size_t i = 0; i < 10; i++) {
            fscanf_s(file, "%d", &grades[i]);
        }
        numLevel--;
        numClass--;
        *school = addPupil(*school, firstName, lastName, phoneNumber, numLevel, numClass, grades);
    }

    fclose(file);
    return school;
}

int main() {
    School* school = createSchool();
    school = populateSchoolFromFile(school, "file.txt");
    printSchool(*school);

    return 0;
}
