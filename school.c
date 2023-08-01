#include "school.h"

School* createSchool()
{
    School* school = (School*)malloc(sizeof(School));
    for (size_t i = 0; i < 12; i++)
    {
        for (size_t j = 0; j < 10; j++) 
        {
            school->school[i][j] = *createLinkedList();
        }
    } 
    return school;
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

School addPupil(School school, char* firstName, char* lastName, char* phoneNumber, int numLevel, int numClass, int* grades)
{
    school.school[numLevel][numClass].head = addFirst(school.school[numLevel][numClass], firstName, lastName, phoneNumber, grades);
    return school;
}

