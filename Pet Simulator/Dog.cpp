#include "Dog.h"  
    
    Dog::Dog(string name) : Pet(name) {
        srand(time(NULL));
        setHunger(rand() % 101);
        setHappiness(rand() % 101);
        setBoredom(rand() % 101);
        setSleepiness(rand() % 101);
    }
    void Dog::feed() {
        setHappiness(getHappiness() + 20);
        setHunger(getHunger() - 15);
        cout << "You gave " << getName() << " dog food!" << endl;
        ifstream fin("dogeat.txt");
        string action;
        while (getline(fin,action)){

            cout<<action<<endl;

        }
        usleep(3000000);
        fin.close();
    }
    void Dog::play() {
        setHappiness(getHappiness() + 20);
        setHunger(getHunger() + 15);
        setSleepiness(getSleepiness()+5);
        setBoredom(getBoredom()-40);
        cout << "You played fetch with " << getName() << " what a good dog!" << endl;
        ifstream fin("dogplay.txt");
        string action;
        while (getline(fin,action)){

            cout<<action<<endl;

        }
        usleep(3000000);
        fin.close();
        
    }
    void Dog::sleep() {
        setHappiness(getHappiness() +5);
        setSleepiness(getSleepiness()-40);
        setBoredom(getBoredom()+20);
        setHunger(getHunger() + 15);
        cout << getName() << " took a nap!" << endl;
        ifstream fin("dognap.txt");
        string action;
        while (getline(fin,action)){

            cout<<action<<endl;

        }
        usleep(3000000);
        fin.close();
    }

    void Dog::displayStatus() {
        cout << "---------------------------------------------------------------------\n";
        cout << "|Name: " << getName()<< " |Hunger: " << getHunger()<< " |Sleepiness: " << getSleepiness() << " |Boredom: " << getBoredom()<< " |Happiness: " << getHappiness() << "\n";
        cout << "---------------------------------------------------------------------\n";
        
        if (getSleepiness()>70){

        ifstream fin("sleepdog.txt");
        string state;
        while (getline(fin,state)){

            cout<<state<<endl;

        }
        fin.close();
        }
        else if (getHappiness()<40){
        ifstream fin("saddog.txt");
        string state;
        while (getline(fin,state)){

            cout<<state<<endl;
        }
        fin.close(); 
        }
        else 
        {
        ifstream fin("normaldog.txt");
        string state;
        while (getline(fin,state)){

            cout<<state<<endl;
        }
        fin.close();
        }
        cout << "---------------------------------------------------------------------\n";
        cout << "What would you like to do?\n";
        cout << "---------------------------------------------------------------------\n";
        cout << "1. Feed"<< " |2. Play fetch"<< " |3. Sleep"<< " |4. Save"<< " |5. Save & Exit\n";
    }

        void Dog::nextHour() {
        setHunger(getHunger()+10);
        if (getHunger() > 100) {
            setHunger(100);
        }
        if (getHunger() < 0) {
            setHunger(0);
        }
        
        setSleepiness(getSleepiness()+5);
        if (getSleepiness() > 100) {
            setSleepiness(100);
        }
        if (getSleepiness() < 0) {
            setSleepiness(0);
        }
        
        setBoredom(getBoredom()+20);
        if (getBoredom() > 100) {
            setBoredom(100);
        }
        if (getBoredom() < 0) {
            setBoredom(0);
        }
        
        setHappiness(getHappiness()-20);
        if (getHappiness() > 100) {
            setHappiness(100);
        }
        if (getHappiness() < 0) {
            setHappiness(0);
        }
        
        if (getHunger() > 60) {
            cout <<"                     ||||||||"<< getName() << " wants a treat!|||||||\n";
        }
        else {
            cout <<"                     ||||||||"<< getName() << " ate too much!|||||||\n";
        }
        if (getSleepiness() > 70) {
            cout <<"                     ||||||||"<< getName() << " wants to take a nap!|||||||\n";
        }
        else {
            cout <<"                     ||||||||"<< getName() << " wants to go outside!|||||||\n";
        }
        if (getBoredom() > 40) {
            cout <<"                     ||||||||"<< getName() << " wants to play!||||||||\n";
        }
        else{
            cout <<"                     ||||||||"<< getName() << " is watching a fly!|||||||\n";
        }
        if (getHappiness() > 70) {
            cout <<"                     ||||||||"<< getName() << " is happy!||||||||\n";
        }
        else{
            cout <<"                     ||||||||"<< getName() << " is sad!|||||||\n";
        }
        
}


    void Dog::save(string petType) {
    ofstream fout("SaveFile.txt");
    fout << getType() << "\n";
    fout << getName() << "\n";
    fout << getHunger() << "\n";
    fout << getSleepiness() << "\n";
    fout << getBoredom() << "\n";
    fout << getHappiness() << "\n";
    fout.close();
    }

    void Dog::load() {
    ifstream fin("SaveFile.txt");
    if (fin.is_open()) {
        string petType, name;
        int hunger, sleepiness, boredom, happiness;
        fin >> petType >> name >> hunger >> sleepiness >> boredom >> happiness;

        setType(petType);
        setName(name);
        setHunger(hunger);
        setSleepiness(sleepiness);
        setBoredom(boredom);
        setHappiness(happiness);

        fin.close();
        cout << "Your pet has been loaded successfully!" << endl;
    }
    else {
        cout << "Unable to open the save file." << endl;
    }
}