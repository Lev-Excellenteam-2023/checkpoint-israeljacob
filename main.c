#include "school.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

size_t get_input(char* dst, size_t max_size) {
    char* input = NULL;
    size_t len = 0;
    size_t len_size = 0;
    len_size = getline(&input, &len, stdin);
    if (len_size == -1)
        return -1;
    if (len_size < max_size) {
        input[len_size - 1] = '\0';
        strncpy(dst, input, len_size);
    }
    else {
        input[max_size - 1] = '\0';
        strncpy(dst, input, max_size);
        len_size = max_size;
    }
    free(input);
    return len_size;
}

int getNumber(int min, int max)
{
  char *end;
  int number;
  int numOfDigits;
  bool flag;
  char dst[4];
  do
  {
    do
    {
      flag = true;
      printf("Enter a number\n");
      numOfDigits = get_input(dst, 4);
      flag = true;
      strtol(dst, &end, 10);
      if (*end != '\0')
      {
        flag = false;
        printf("You should input digits only\nEnter again:\n");
        break;
      }
    }while(!flag);
    number = atoi(dst);
    if(number > max || number < min)
      printf("Illegal number.Try again!\n");
  }while(number > max || number < min);
  return number;
}

void getPupilDetails(char* firstName[], char* lastName[], int* numLevel, int* numClass)
{
  printf("Enter the first name\n");
  get_input(firstName,50);
  printf("Enter the last name\n");
  get_input(lastName,50);
  printf("Enter level number\n");
  *numLevel = getNumber(1,12);
  printf("Enter class number\n");
  *numClass = getNumber(1,10);
}

enum professions {
    Math = 0,
    English = 1,
    Hebrew = 2,
    Computers = 3,
    Citizenship = 4,
    Tora = 5,
    Safrut = 6,
    History = 7,
    Religion = 8,
    Electric = 9
};

void insertNewStudent(School* school)
{
    char firstName[50];
    char lastName[50];
    char phoneNumber[11];
    int numLevel;
    int numClass;
    int grades[10];
    
    getPupilDetails(&firstName, &lastName, &numLevel, &numClass);
    printf("Enter the pupils phone number:\n");
    get_input(phoneNumber, 10);
    for (size_t i = 0; i < 10; i++) {
      grades[i] = getNumber(0, 100);
    }
    *school = addPupil(*school, firstName, lastName, phoneNumber, numLevel - 1 , numClass - 1, grades);
}


void searchStudent(School* school)
{
  int numLevel;
  int numClass;
  char firstName[50];
  char lastName[50];
  getPupilDetails(&firstName, &lastName, &numLevel, &numClass);
  Pupil* pupil = searchPupil(*school, firstName, lastName ,numLevel - 1, numClass - 1);
  if(pupil == NULL)
    printf("there is not such a student");
  else
    printPupil(pupil, numLevel - 1, numClass - 1);
}

void deleteStudent(School* school)
{
  char firstName[50];
  char lastName[50];
  int numLevel;
  int numClass;
  getPupilDetails(&firstName, &lastName, &numLevel, &numClass);
  deleteFromSchool(*school, firstName, lastName, numLevel - 1, numClass - 1);
}


void editStudentGrade(School* school)
{
  int input;
  char firstName[50];
  char lastName[50];
  int numLevel;
  int numClass;
  int grade;
  getPupilDetails(&firstName, &lastName, &numLevel, &numClass);
  printf("\t[0] |--> Math\n");
  printf("\t[1] |--> English\n");
  printf("\t[2] |--> Hebrew\n");
  printf("\t[3] |--> Computers\n");
  printf("\t[4] |--> Citizenship\n");
  printf("\t[5] |--> Tora\n");
  printf("\t[6] |--> Safrut\n");
  printf("\t[7] |--> History\n");
  printf("\t[8] |--> Religion\n");
  printf("\t[9] |--> Electric\n");
  printf("\n\tPlease Enter Your Choice (0-9): ");
  input = getNumber(0, 9);
  printf("Enter the updated grade\n");
  grade = getNumber(0, 100);
  addGrade(*school, firstName, lastName, numLevel - 1, numClass - 1, input, grade);
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
                deleteStudent(school);
                break;
            case Edit:
                editStudentGrade(school);
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
        school = addPupil(school, firstName, lastName, phoneNumber, numLevel-1, numClass-1, grades);
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