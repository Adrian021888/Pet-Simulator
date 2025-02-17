#include <iostream>
#include <fstream>
#include "genericpet.h"
#include "cat.h"
#include "Dog.h"
#include "Duck.h"
#include "cat.cpp"
#include "genericpet.cpp"
#include "Dog.cpp"
#include "Duck.cpp"
using namespace std;


//gameloop takes the pet and runs until 5 is pressed
void gameloop(Pet* mypet){
    int option,actions=0;

    while (option !=5){
        mypet->displayStatus();
        cin>>option;
        switch(option){
            case 1:
            mypet->feed();
            actions++;
            break;

            case 2:
            mypet->play();
            actions++;
            break;

            case 3:
            mypet->sleep();
            actions++;
            break;

            case 4:
            mypet->save(mypet->getType());
            cout<<"Your game has been saved correctly!!!"<<endl;
            continue;

            case 5:
            cout<<"See you later!!"<<endl;
            mypet->save(mypet->getType());
            break;

            default:
            cout<<"Please choose a valid option!!!"<<endl;
            continue;
        }
        if (actions==3){
            mypet->nextHour();
            actions=0;
        }

    }
    
}

void title(){
    
ifstream title("Title.txt");
string show;
while(getline(title,show)){ //show menu
    cout<<show<<endl;
     }
    title.close();
}


int main() {
    int choose;
    int choice;
    string petname, petType, menu;
    bool exitGame = false;
    
    while (!exitGame) {
        
        title(); //shows title screen

        cin >> choice;
        ifstream fin("menu.txt");
        ifstream savefile("Savefile.txt");
        

        switch (choice) {

            case 1: // create a new pet and start the game loop
                while(getline(fin,menu)){ //show menu
                    cout<<menu<<endl;
                }
                fin.close();
                cin >> choose;
                
                // create a new pet of the chosen type and sets its type
                Pet* mypet;
                switch (choose) {
                    case 1:
                        mypet = new Cat("Cat");
                        mypet->setType("Cat");
                        break;
                    case 2:
                        mypet = new Dog("Dog");
                        mypet->setType("Dog");
                        break;
                    case 3:
                        mypet = new Duck("Duck");
                        mypet->setType("Duck");
                        break;
                    default:
                        cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
                        break;
                }

                // ask the player to name the pet
                cout << "Enter a name for your pet: ";
                cin.ignore();
                getline (cin,petname);
                mypet->setName(petname);
                
                //start game loop
                gameloop(mypet);
                break;

            case 2: // load an existing pet and start the game loop
                delete mypet;
                savefile>>petType; // read pettype

                if (petType == "Cat") {
                    mypet = new Cat("Cat");
                }
                else if (petType == "Dog") {
                    mypet = new Dog("Dog");
                }
                else if (petType == "Duck") {
                    mypet = new Duck("Duck");
                }
                
                mypet->setType(petType);
                mypet->load(mypet);
                savefile.close();
                gameloop(mypet);
                break;
            case 3: // exit the game
                exitGame = true;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
                break;
        }
    }

    return 0;
}