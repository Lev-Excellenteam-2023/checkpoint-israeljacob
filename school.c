#include "school.h"

School createSchool()
{
    School school;
    for (size_t i = 0; i < 12; i++)
    {
        for (size_t j = 0; j < 10; j++) 
        {
            school.school[i][j] = createLinkedList();
        }
    } 
    return school;
}

void destroySchool(School school)
{
    for (size_t i = 0; i < 12; i++)
    {
        for (size_t j = 0; j < 10; j++)
        {
            destroyLinkdList(&school.school[i][j]);
        }
    }
}


void printSchool(School school)
{
    for (size_t i = 0; i < 12; i++)
    {
        for (size_t j = 0; j < 10; j++)
        {
            printList(school.school[i][j], i, j);
        }
    }
}

School addPupil(School school, char firstName[], char lastName[], char phoneNumber[], int numLevel, int numClass, int grades[])
{
    addFirst(&school.school[numLevel][numClass], firstName, lastName, phoneNumber, grades);
    return school;
}

Pupil* searchPupil(School school, char firstName[], char lastName[], int numLevel, int numClass)
{
  return nodeSearch(school.school[numLevel][numClass].head, firstName, lastName);
}

void deleteFromSchool(School school, char firstName[], char lastName[], int numLevel, int numClass)
{
  deletePupil(school.school[numLevel][numClass].head, firstName, lastName);
}

void addGrade(School school, char firstName[], char lastName[], int numLevel, int numClass, int input, int grade)
{
  addGradeToNode(school.school[numLevel][numClass].head, firstName, lastName, input, grade);
}

int getAverage(School school, int numLevel, int course)
{
  int sum = 0;
  for (size_t i = 0; i < 10; i++)
  {
      sum += getClassAverage(school.school[numLevel][i].head, course);
  }
  return sum/10;
} 

void saveSchoolToFile(School school, const char* fileName)
{
  FILE* file = fopen(fileName, "w");

  for (size_t i = 0; i < 12; i++) {
      for (size_t j = 0; j < 10; j++) {
          writeLinkedListToFile(school.school[i][j].head, file, i + 1, j + 1);
      }
  }

  fclose(file);
}