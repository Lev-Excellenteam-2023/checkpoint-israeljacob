#include "class.h"

typedef struct {
	int numLevel;
	MyClass classes[10];
}Level;

Level* createLevel(int numLevel);
void printLevel(const Level level);