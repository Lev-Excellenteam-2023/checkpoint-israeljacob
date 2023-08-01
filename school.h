#include "linkedList.h"


typedef struct {
	LinkedList school[12][10];
}School;

School createSchool();
void destroySchool(School school);
void printSchool(School);
School addPupil(School, char*, char*, char* phoneNumber, int numLevel, int numClass, int* grades);
Pupil* searchPupil(School school, char[], char [], int, int);
void deleteFromSchool(School school, char[], char [], int, int);
void addGrade(School school, char[], char [], int, int, int, int);
int getAverage(School, int, int);
void saveSchoolToFile(School school, const char* fileName);
void printUnderperformed(School, int);