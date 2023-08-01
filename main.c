#include "school.h"
#include <stdio.h>
#include <stdlib.h>

School populateSchoolFromFile(School school, const char* fileName) {
    FILE* file = fopen(fileName, "r");

    char firstName[50];
    char lastName[50];
    char phoneNumber[11];
    int numLevel;
    int numClass;
    int grades[10];

    while (fscanf(file, "%s %s %s %d %d", firstName, lastName, phoneNumber, &numLevel, &numClass) == 5) {
        for (size_t i = 0; i < 10; i++) {
            fscanf(file, "%d", &grades[i]);
        }
        numLevel--;
        numClass--;
        school = addPupil(school, firstName, lastName, phoneNumber, numLevel, numClass, grades);
    }

    fclose(file);
    return school;
}

int main() {
     School school = createSchool();
    school = populateSchoolFromFile(school, "file.txt");
    printSchool(school);
    destroySchool(school);
    return 0;
}
