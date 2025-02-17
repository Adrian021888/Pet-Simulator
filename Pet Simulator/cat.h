#ifndef CAT_H
#define CAT_H
#include "genericpet.h"
#include <cstdlib>
#include <fstream>
#include <string>
#include <unistd.h>

class Cat : public Pet {
public:
Cat(string name);
void feed();
void play();
void sleep();
void displayStatus();
void save(string petType);
void load();
};

#endif