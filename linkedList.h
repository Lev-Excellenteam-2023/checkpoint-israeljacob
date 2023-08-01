#pragma once
#include "pupil.h"

typedef struct
{
	Pupil myPupil;
	struct Node* next;
}Node;




typedef struct {
	Node* head;
}LinkedList;



LinkedList createLinkedList();
void destroyLinkdList(LinkedList* list);
void destroyNode(Node* node);
Node* createNode(Pupil pupil);
void printList(LinkedList list, int numLevel, int numClasses);
void addFirst(LinkedList* list, char firstName[], char lastName[], char phoneNumber[], int grades[]);
Pupil* nodeSearch(Node* node, char firstName[], char lastName[]);

