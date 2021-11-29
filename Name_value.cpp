#include "Name_value.h"
#include <iostream>
#include <string.h>

using namespace std;

Name_value::Name_value(char name[20], int score)
{
    strcpy(this->name, name);
    this->score = score;
}
char* Name_value::getName()
{
    return name;
}

int Name_value::getScore()
{
    return score;
}

