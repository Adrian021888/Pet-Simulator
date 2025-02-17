#ifndef DOG_H
#define DOG_H
#include "genericpet.h"
#include <cstdlib>
#include <fstream>
#include <string>
#include <unistd.h>

class Dog : public Pet {
public:
Dog(string name);
void feed();
void play();
void sleep();
void displayStatus();
void save(string petType);
void nextHour();
void load();
};

#endif