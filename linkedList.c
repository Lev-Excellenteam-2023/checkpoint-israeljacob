#include "linkedList.h"

LinkedList createLinkedList()
{
    LinkedList list ;
    list.head = 0;

    return list;
}

void destroyLinkdList(LinkedList* list)
{
    destroyNode(list->head);
}

Node* createNode(Pupil Pupil)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->myPupil = Pupil;
    node->next = NULL;

    return node;
}

void destroyNode(Node* node)
{
    if (node == NULL)
    {
        return;
    }
    if (node->next != NULL)
    {
      destroyNode(node->next);  
    }
    free(node);
    node = NULL;
}

void printList(LinkedList list, int numLevel, int numClass)
{
    Node* node = list.head;
    while (node != NULL)
    {
        printPupil(&node->myPupil, numLevel, numClass);
        node = node->next;
    }
}

void addFirst(LinkedList* list, char firstName[], char lastName[], char phoneNumber[], int grades[])
{
    Pupil pupil = createPupil(firstName, lastName, phoneNumber, grades);
    Node* node = createNode(pupil);
    if(list->head != NULL)
        node->next = list->head;
    list->head = node;
    //return &list;
} 
