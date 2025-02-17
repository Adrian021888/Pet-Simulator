#ifndef GENERICPET_H
#define GENERICPET_H

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class Pet {
private:
    string petType;
    string name;
    int hunger;
    int sleepiness;
    int boredom;
    int happiness;

public:
    Pet(string name, int hunger = 50, int sleepiness = 50, int boredom = 50, int happiness = 50);
    string getType();
    string getName();
    int getHunger();
    int getSleepiness();
    int getBoredom();
    int getHappiness();

    void setType(string type);
    void setName(string petName);
    void setHunger(int value);
    void setSleepiness(int value);
    void setBoredom(int value);
    void setHappiness(int value);

    virtual ~Pet();

    virtual void displayStatus()=0;
    virtual void feed()=0;
    virtual void play()=0;
    virtual void sleep()=0;
    virtual void load(Pet* mypet);
    virtual void save(string petType);
    virtual void nextHour();
};

#endif