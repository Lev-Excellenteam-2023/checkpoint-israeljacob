#include <malloc.h>

typedef struct {
	char* firstName;
	char* lastName;
	char* phoneNumber;
	int* grades;
}Pupil;

Pupil* createPupil(const char* pupilFirstName, const char* lastName, char* phoneNumber, int* grades);
void printPupil(const Pupil pupil, int numLevel, int numClass);