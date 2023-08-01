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
} 

Pupil* nodeSearch(Node* node, char firstName[], char lastName[])
{
  if(node == NULL)
    return NULL;
  
  do
  {
    if(!strcmp(node->myPupil.firstName, firstName) && !strcmp(node->myPupil.lastName, lastName))
      return &node->myPupil;
    node = node->next;
  }while(node != NULL);
}

void deletePupil(Node* node, char firstName[], char lastName[])
{
    if (node == NULL)
        return;

    Node* preNode = node;
    while (node != NULL)
    {
        if (!strcmp(node->myPupil.firstName, firstName) && !strcmp((node)->myPupil.lastName, lastName))
        {
            if (preNode == node) // If the first node is the one to delete
            {
                node = node->next; // Update the head pointer
            }
            else
            {
                preNode->next = node->next;
            }
            free (node);
            node = NULL;
            return;
        }
        preNode = node;
        node = preNode->next;
    }
}

void addGradeToNode(Node* node, char firstName[], char lastName[], int input, int grade)
{
  if (node == NULL)
        return;
  do
  {
    if(!strcmp(node->myPupil.firstName, firstName) && !strcmp(node->myPupil.lastName, lastName))
      break;
    node = node->next;
  }while(node != NULL);
  if(node != NULL)
    node->myPupil.grades[input] = grade;
}

int getClassAverage(Node* node, int course)
{
  int sum = 0;
  if (node == NULL)
        return sum;
  int counter = 0;
  do
  {
    sum += node->myPupil.grades[course];
    counter++;
    node = node->next;
  }while(node != NULL);
  return sum/counter;
}

void writeLinkedListToFile(Node* node, FILE* file, int level, int class)
{
   while (node != NULL) {
        fprintf(file, "%s %s %s %d %d ", node->myPupil.firstName, node->myPupil.lastName,
                node->myPupil.phoneNumber, level, class);
        for (int i = 0; i < 10; i++) {
            fprintf(file, "%d ", node->myPupil.grades[i]);
        }
        fprintf(file, "\n");
        node = node->next;
    }
}