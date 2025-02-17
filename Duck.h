#ifndef DUCK_H
#define DUCK_H
#include "genericpet.h"
#include <cstdlib>
#include <fstream>
#include <string>
#include <unistd.h>

class Duck : public Pet {
public:
Duck(string name);
void feed();
void play();
void sleep();
void displayStatus();
void save(string petType);
void load();
void nextHour();
};





#endif