#include "linkedList.h"

LinkedList* createLinkedList()
{
   LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
   list->head = NULL;

   return list;
}

Node* createNode(Pupil* Pupil)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->myPupil = *Pupil;
    node->next = NULL;

    return node;
}


void printList(LinkedList list, int numLevel, int numClass)
{
    Node* node = list.head;
    while (node != NULL)
    {
       printPupil(node->myPupil, numLevel, numClass);
    }
}

LinkedList* addFirst(LinkedList list, char* firstName, char* lastName, char* phoneNumber, int* grades)
{
    Pupil* pupil = createPupil(firstName, lastName, phoneNumber, grades);
    Node* node = createNode(pupil);
    node->next = list.head;
    list.head = node;
}