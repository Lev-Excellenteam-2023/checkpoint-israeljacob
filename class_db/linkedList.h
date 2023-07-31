#include "pupil.h"

typedef struct 
{
	Pupil myPupil;
	Node* next;
}Node;




typedef struct  {
	Node* head;
}LinkedList;



LinkedList* createLinkedList();
Node* createNode(Pupil* pupil);
void printList(LinkedList list, int numLevel, int numClasses);
LinkedList* addFirst(LinkedList list, char* firstName, char* lastName, char* phoneNumber, int* grades);
