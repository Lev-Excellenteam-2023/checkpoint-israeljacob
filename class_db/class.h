#include "linkedList.h"

typedef struct 
{
	int numClass;
	LinkedList pupils;
}MyClass;


MyClass* createMyClass(int numClass);

void printClass(MyClass myClass, int numLevel);
