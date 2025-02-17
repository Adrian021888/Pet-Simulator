#include "genericpet.h"
    
    
    Pet::Pet(string name, int hunger , int sleepiness , int boredom,  int happiness) : name(name), hunger(hunger), sleepiness(sleepiness), boredom(boredom), happiness(happiness) {}

    string Pet::getType() {
        return petType;
    }

    string Pet::getName() {
        return name;
    }

    int Pet::getHunger() {
        return hunger;
    }

    int Pet::getSleepiness() {
        return sleepiness;
    }

    int Pet::getBoredom() {
        return boredom;
    }

    int Pet::getHappiness() {
        return happiness;
    }

    void Pet::setType(string type) {
        petType = type;
    }

    void Pet::setName(string petName) {
        name = petName;
    }

    void Pet::setHunger(int value) {
    if (value < 0) {
        hunger = 0;
    } else if (value > 100) {
        hunger = 100;
    } else {
        hunger = value;
    }
    }

    void Pet::setSleepiness(int value) {
    if (value < 0) {
        sleepiness = 0;
    } else if (value > 100) {
        sleepiness = 100;
    } else {
        sleepiness = value;
    }
    }

    void Pet::setBoredom(int value) {
    if (value < 0) {
        boredom = 0;
    } else if (value > 100) {
        boredom = 100;
    } else {
        boredom = value;
    }
    }

    void Pet::setHappiness(int value) {
    if (value < 0) {
        happiness = 0;
    } else if (value > 100) {
        happiness = 100;
    } else {
        happiness = value;
    }
    }

    Pet::~Pet() {}

    void Pet::displayStatus() {
        cout << "----------------------------\n";
        cout << "Name: " << name << "\n";
        cout << "Hunger: " << hunger << "\n";
        cout << "Sleepiness: " << sleepiness << "\n";
        cout << "Boredom: " << boredom << "\n";
        cout << "Happiness: " << happiness << "\n";
        cout << "----------------------------\n";
        cout << "What would you like to do?\n";
        cout << "1. Feed\n";
        cout << "2. Play\n";
        cout << "3. Sleep\n";
        cout << "4. Save\n";
        cout << "5. Exit\n";
    }

    
    void Pet::feed() {
        hunger -= 10;
        happiness += 5;
        cout << name << " has been fed.\n";
        if (happiness >100){
            happiness=100;
        }
    }

    void Pet::play() {
        boredom -= 10;
        happiness += 10;
        hunger += 5;
        sleepiness += 5;
        cout << name << " is playing.\n";
        if (happiness >100){
            happiness=100;
        }
    }

    void Pet::sleep() {
        boredom += 5;
        happiness += 5;
        sleepiness += 10;
        cout << name << " took a nap.\n";
        if (happiness >100){
            happiness=100;
        }
    }

    
    void Pet::nextHour() {
        hunger += 10;
        if (hunger > 100) {
            hunger = 100;
        }
        if (hunger < 0) {
            hunger = 0;
        }
        
        sleepiness += 20;
        if (sleepiness > 100) {
            sleepiness = 100;
        }
        if (sleepiness < 0) {
            sleepiness = 0;
        }
        
        boredom += 5;
        if (boredom > 100) {
            boredom = 100;
        }
        if (boredom < 0) {
            boredom = 0;
        }
        
        happiness -= 5;
        if (happiness > 100) {
            happiness = 100;
        }
        if (happiness < 0) {
            happiness = 0;
        }
        
        if (hunger > 70) {
            cout <<"                     ||||||||"<< name << " is hungry!|||||||\n";
        }
        else {
            cout <<"                     ||||||||"<< name << " is Full!|||||||||\n";
        }
        if (sleepiness > 70) {
            cout <<"                     ||||||||"<< name << " is sleepy!|||||||\n";
        }
        else {
            cout <<"                     ||||||||"<< name << " is full of energy!|||||||\n";
        }
        if (boredom > 70) {
            cout <<"                     ||||||||"<< name << " is bored!||||||||\n";
        }
        else {
            cout <<"                     ||||||||"<< name << " is entertained!||||||||\n";
        }
        if (happiness > 50) {
            cout <<"                     ||||||||"<< name << " is happy!||||||||\n";
        }
        else {
            cout <<"                     ||||||||"<< name << " is sad!||||||||\n";
        }
}

void Pet::save(string petType) {
    ofstream fout("SaveFile.txt");
    fout << getType() << "\n";
    fout << getName() << "\n";
    fout << getHunger() << "\n";
    fout << getSleepiness() << "\n";
    fout << getBoredom() << "\n";
    fout << getHappiness() << "\n";
    fout.close();
    }

void Pet::load(Pet* mypet) {
    ifstream fin("SaveFile.txt");
    if (fin.is_open()) {
        string petType, name;
        int hunger, sleepiness, boredom, happiness;
        fin >> petType;
        fin.ignore();
        getline(fin, name);
        fin >> hunger >> sleepiness >> boredom >> happiness;

        mypet->setType(petType);
        mypet->setName(name);
        mypet->setHunger(hunger);
        mypet->setSleepiness(sleepiness);
        mypet->setBoredom(boredom);
        mypet->setHappiness(happiness);

        fin.close();
        cout << "Your pet has been loaded successfully!" << endl;
    }
    else {
        cout << "Unable to open the save file." << endl;
    }
}