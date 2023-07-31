#include "class.h"

MyClass* createMyClass(int numClass)
{
    MyClass* myClass = (MyClass*)malloc(sizeof(MyClass));

    myClass->numClass = numClass;
    myClass->pupils = *(createLinkedList());

    return myClass;
}

void printClass(MyClass myClass, int numLevel)
{
    Node* node = myClass.pupils.head;
    while (node != NULL)
    {
       printPupil(node->myPupil, numLevel, myClass.numClass);
    }
    
}