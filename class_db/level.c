#include "level.h"


Level* createLevel(int numLevel)
{
    Level* level = (Level*)malloc(sizeof(Level));
    level->numLevel = numLevel;
    for (size_t i = 0; i < 10; i++)
    {
        level->classes[i] = *(createMyClass(i));
    }

    return level;
}

void printLevel(const Level* level)
{
    for (size_t i = 0; i < 12; i++)
    {
        printClass(level->classes[i], level->numLevel);
    }
}