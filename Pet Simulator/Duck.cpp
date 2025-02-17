#include "Duck.h"

Duck::Duck(string name) : Pet(name) {
        srand(time(NULL));
        setHunger(rand() % 101);
        setHappiness(rand() % 101);
        setBoredom(rand() % 101);
        setSleepiness(rand() % 101);
    }
    void Duck::feed() {
        setHappiness(getHappiness() + 10);
        setHunger(getHunger() - 30);
        setBoredom(getBoredom() + 5);
        cout << getName() << " loves bread. Yum!" << endl;
        ifstream fin("duckeat.txt");
        string action;
        while (getline(fin,action)){

            cout<<action<<endl;

        }
        usleep(3000000);
        fin.close();
    }
    void Duck::play() {
        setHappiness(getHappiness() + 15);
        setHunger(getHunger() + 5);
        setSleepiness(getSleepiness()+15);
        setBoredom(getBoredom()-15);
        cout << getName()<<" is playing with other ducks!"<<endl;
        ifstream fin("duckplay.txt");
        string action;
        while (getline(fin,action)){

            cout<<action<<endl;

        }
        usleep(3000000);
        fin.close();
        
    }
    void Duck::sleep() {
        setHappiness(getHappiness() +10 );
        setSleepiness(getSleepiness()-70);
        setBoredom(getBoredom()+5);
        setHunger(getHunger() + 10);
        cout << getName() << " took a nap!" << endl;
        ifstream fin("ducknap.txt");
        string action;
        while (getline(fin,action)){

            cout<<action<<endl;

        }
        usleep(3000000);
        fin.close();
    }

    void Duck::displayStatus() {
        cout << "---------------------------------------------------------------------\n";
        cout << "|Name: " << getName()<< " |Hunger: " << getHunger()<< " |Sleepiness: " << getSleepiness() << " |Boredom: " << getBoredom()<< " |Happiness: " << getHappiness() << "\n";
        cout << "---------------------------------------------------------------------\n";
        
        if (getSleepiness()>70){

        ifstream fin("sleepduck.txt");
        string state;
        while (getline(fin,state)){

            cout<<state<<endl;

        }
        fin.close();
        }
        else if (getHappiness()<40){
        ifstream fin("sadduck.txt");
        string state;
        while (getline(fin,state)){

            cout<<state<<endl;
        }
        fin.close(); 
        }
        else 
        {
        ifstream fin("normalduck.txt");
        string state;
        while (getline(fin,state)){

            cout<<state<<endl;
        }
        fin.close();
        }
        cout << "---------------------------------------------------------------------\n";
        cout << "What would you like to do?\n";
        cout << "---------------------------------------------------------------------\n";
        cout << "1. Feed"<< " |2. Go swimming"<< " |3. Sleep"<< " |4. Save"<< " |5. Save & Exit\n";
    }

    void Duck::nextHour() {
        setHunger(getHunger()+5);
        if (getHunger() > 100) {
            setHunger(100);
        }
        if (getHunger() < 0) {
            setHunger(0);
        }
        
        setSleepiness(getSleepiness()+10);
        if (getSleepiness() > 100) {
            setSleepiness(100);
        }
        if (getSleepiness() < 0) {
            setSleepiness(0);
        }
        
        setBoredom(getBoredom()+5);
        if (getBoredom() > 100) {
            setBoredom(100);
        }
        if (getBoredom() < 0) {
            setBoredom(0);
        }
        
        setHappiness(getHappiness()-2);
        if (getHappiness() > 100) {
            setHappiness(100);
        }
        if (getHappiness() < 0) {
            setHappiness(0);
        }
        
        if (getHunger() > 70) {
            cout <<"                     ||||||||"<< getName() << " demands bread!|||||||\n";
        }
        else {
            cout <<"                     ||||||||"<< getName() << " is feeling fat!|||||||\n";
        }
        if (getSleepiness() > 80) {
            cout <<"                     ||||||||"<< getName() << " wants to rest!|||||||\n";
        }
        else {
            cout <<"                     ||||||||"<< getName() << " wants to swim!|||||||\n";
        }
        if (getBoredom() > 60) {
            cout <<"                     ||||||||"<< getName() << " needs to annoy someone!||||||||\n";
        }
        else{
            cout <<"                     ||||||||"<< getName() << " loves watching you!|||||||\n";
        }
        if (getHappiness() > 60) {
            cout <<"                     ||||||||"<< getName() << " moves its tail!||||||||\n";
        }
        else{
            cout <<"                     ||||||||"<< getName() << " wants your attention!|||||||\n";
        }
    }

    void Duck::save(string petType) {
        ofstream fout("SaveFile.txt");
        fout << getType() << "\n";
        fout << getName() << "\n";
        fout << getHunger() << "\n";
        fout << getSleepiness() << "\n";
        fout << getBoredom() << "\n";
        fout << getHappiness() << "\n";
        fout.close();
    }

    void Duck::load() {
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

    


