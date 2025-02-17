    #include "cat.h"
    
    Cat::Cat(string name) : Pet(name) {
        srand(time(NULL));
        setHunger(rand() % 101); //the rand function will generate a random value
        setHappiness(rand() % 101);
        setBoredom(rand() % 101);
        setSleepiness(rand() % 101);
    }
    void Cat::feed() {
        setHappiness(getHappiness() + 40);
        setHunger(getHunger() - 10);
        cout << "You gave " << getName() << " a fish. Yum!" << endl;
        ifstream fin("cateat.txt");
        string action;
        while (getline(fin,action)){

            cout<<action<<endl;

        }
        usleep(3000000);
        fin.close();
    }
    void Cat::play() {
        setHappiness(getHappiness() + 5);
        setHunger(getHunger() + 20);
        setSleepiness(getSleepiness()+20);
        setBoredom(getBoredom()-20);
        cout << "You played with " << getName() << " the cat. So much fun!" << endl;
        ifstream fin("catplay.txt");
        string action;
        while (getline(fin,action)){

            cout<<action<<endl;

        }
        usleep(3000000);
        fin.close();
        
    }
    void Cat::sleep() {
        setHappiness(getHappiness() +20);
        setSleepiness(getSleepiness()-20);
        setBoredom(getBoredom()+10);
        setHunger(getHunger() + 20);
        cout << getName() << " took a nap!" << endl;
        ifstream fin("catnap.txt");
        string action;
        while (getline(fin,action)){

            cout<<action<<endl;

        }
        usleep(3000000);
        fin.close();
    }

    void Cat::displayStatus() {
        cout << "---------------------------------------------------------------------\n";
        cout << "|Name: " << getName()<< " |Hunger: " << getHunger()<< " |Sleepiness: " << getSleepiness() << " |Boredom: " << getBoredom()<< " |Happiness: " << getHappiness() << "\n";
        cout << "---------------------------------------------------------------------\n";
        
        if (getSleepiness()>70){

        ifstream fin("sleepcat.txt");
        string state;
        while (getline(fin,state)){

            cout<<state<<endl;

        }
        fin.close();
        }
        else if (getHappiness()<40){
        ifstream fin("sadcat.txt");
        string state;
        while (getline(fin,state)){

            cout<<state<<endl;
        }
        fin.close(); 
        }
        else 
        {
        ifstream fin("normalcat.txt");
        string state;
        while (getline(fin,state)){

            cout<<state<<endl;
        }
        fin.close();
        }
        cout << "---------------------------------------------------------------------\n";
        cout << "What would you like to do?\n";
        cout << "---------------------------------------------------------------------\n";
        cout << "1. Feed"<< " |2. Play w/ laser"<< " |3. Sleep"<< " |4. Save"<< " |5. Save & Exit\n";
    }

    void Cat::save(string petType) {
    ofstream fout("SaveFile.txt");
    fout << getType() << "\n";
    fout << getName() << "\n";
    fout << getHunger() << "\n";
    fout << getSleepiness() << "\n";
    fout << getBoredom() << "\n";
    fout << getHappiness() << "\n";
    fout.close();
    }

    void Cat::load() {
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