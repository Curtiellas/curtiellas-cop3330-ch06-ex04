/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 luis curtiellas
 */
#ifndef NAME_VALUE_H
#define NAME_VALUE_H

class Name_value
{
    char name[20];
    int score;

public:
    /* constructor */
    Name_value(char name[20], int score);
    /* getter */
    char* getName();
    int getScore();

};
#endif