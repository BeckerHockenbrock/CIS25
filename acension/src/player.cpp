#include <iostream>
#include <string>

using namespace std;

class Player {
protected:
    string name;

    // Primary Stats
    int strength = 5;
    int agility = 5;
    int perception = 5;
    int vitality = 5;
    int intelligence = 5;

    // Derived Stats & Level
    int level = 1;
    int experience = 0;
    
    int maxHealth = 50;
    int currentHealth = 50;
    
    int maxMana = 50;
    int currentMana = 50;

    int commandCapacity = 5;

public:

    Player(string n){

        name = n;

    }

    // Recalculate max health and max mana based on stats
    void updateStats() {
        maxHealth = vitality * 10;
        maxMana = intelligence * 10;
    }

    // Print all player stats to the screen
    void printStats() {
        cout << "=============================" << endl;
        cout << "Name: " << name << " (Level " << level << ")" << endl;
        cout << "Health: " << currentHealth << " / " << maxHealth << endl;
        cout << "Mana: " << currentMana << " / " << maxMana << endl;
        cout << "Command Capacity: " << commandCapacity << endl;
        cout << "-----------------------------" << endl;
        cout << "Strength: " << strength << endl;
        cout << "Agility: " << agility << endl;
        cout << "Perception: " << perception << endl;
        cout << "Vitality: " << vitality << endl;
        cout << "Intelligence: " << intelligence << endl;
        cout << "=============================" << endl;
    }
};