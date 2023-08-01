#include "school.h"
#include <stdio.h>
#include <stdlib.h>


void insertNewStudent(School* school)
{
    char firstName[50];
    char lastName[50];
    char phoneNumber[11];
    int numLevel;
    int numClass;
    int grades[10];
    
    scanf("%s %s %s %d %d" , firstName, lastName, phoneNumber, &numLevel, &numClass);
    for (size_t i = 0; i < 10; i++) {
            scanf( "%d", &grades[i]);
    }
    *school = addPupil(*school, firstName, lastName, phoneNumber, numLevel, numClass, grades);
}

Pupil* helperSearch(School* school, int* numLevel, int* numClass)
{
  printf("Enter the first name\n");
  char firstName[50];
  char lastName[50];
  scanf("%s", firstName);
  printf("Enter the last name\n");
  scanf("%s", lastName);
  printf("Enter level number\n");
  scanf("%d", numLevel);
  printf("Enter class number\n");
  scanf("%d", numClass);
  return searchPupil(*school, firstName, lastName ,*numLevel - 1, *numClass - 1);
}
void searchStudent(School* school)
{
  int numLevel;
  int numClass;
  Pupil* pupil = helperSearch(school, &numLevel, &numClass);
  if(pupil == NULL)
    printf("there is not such a student");
  else
    printPupil(pupil, numLevel - 1, numClass - 1);
}

void printAllStudents(School* school)
{
  printSchool(*school);
}

enum menu_inputs {
    Insert = '0',
    Delete = '1',
    Edit = '2',
    Search = '3',
    Showall = '4',
    Top10 = '5',
    UnderperformedStudents = '6',
    Average = '7',
    Export = '8',
    Exit = '9'
};

void menu(School *school) {
    char input;
    // school.name = "schoolName";
    do {
        printf("\n|School Manager<::>Home|\n");
        printf("--------------------------------------------------------------------------------\n");
        //printf("Welcome to ( %s ) School!\nYou have inserted ( %zu ) students.\n\n", school.name, school.numOfStudents);
        printf("\t[0] |--> Insert\n");
        printf("\t[1] |--> Delete\n");
        printf("\t[2] |--> Edit\n");
        printf("\t[3] |--> Search\n");
        printf("\t[4] |--> Show All\n");
        printf("\t[5] |--> Top 10 students per course\n");
        printf("\t[6] |--> Underperformed students\n");
        printf("\t[7] |--> Average per course\n");
        printf("\t[8] |--> Export\n");
        printf("\t[9] |--> Exit\n");
        printf("\n\tPlease Enter Your Choice (0-9): ");
        input = getc(stdin);
        fflush(stdin);
        getc(stdin);
        switch (input) {
            case Insert:
                insertNewStudent(school);
                break;
            case Delete:
                //deleteStudent();
                break;
            case Edit:
                //editStudentGrade();
                break;
            case Search:
                searchStudent(school);
                break;
            case Showall:
                printAllStudents(school);
                break;
            case Top10:
                //printTopNStudentsPerCourse();
                break;
            case UnderperformedStudents:
                //printUnderperformedStudents();
                break;
            case Average:
                //printAverage();
                break;
            case Export:
                //exportDatabase();
                break;
            case Exit:
                //handleClosing();
                break;
            default:
                printf("\nThere is no item with symbol \"%c\".Please enter a number between 1-10!\nPress any key to continue...",
                       input);
                getc(stdin);
                getc(stdin);
                break;
        }
    } while (input != Exit);
}

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
    //printSchool(school);
    menu(&school);
    destroySchool(school);
    return 0;
  }