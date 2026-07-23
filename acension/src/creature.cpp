#include <iostream>
#include <string>

using namespace std;

class Creature {
protected:
    string name;
    string race;
    
    int level = 1;
    int maxHealth = 30;
    int currentHealth = 30;
    
    int attack = 5;
    int defense = 2;

public:
    Creature() {
        name = "Unknown Creature";
        race = "Monster";
    }

    Creature(string n, string r, int hp, int atk, int def, int lvl) {
        name = n;
        race = r;
        maxHealth = hp;
        currentHealth = hp;
        attack = atk;
        defense = def;
        level = lvl;
    }

    bool isAlive() {
        return currentHealth > 0;
    }

    void takeDamage(int dmg) {
        int damageTaken = dmg - defense;
        if (damageTaken < 1) {
            damageTaken = 1;
        }
        currentHealth -= damageTaken;
        if (currentHealth < 0) {
            currentHealth = 0;
        }
        cout << name << " took " << damageTaken << " damage! (Health: " << currentHealth << "/" << maxHealth << ")" << endl;
    }

    void printStats() {
        cout << "=============================" << endl;
        cout << "Name: " << name << " (" << race << ")" << endl;
        cout << "Level: " << level << endl;
        cout << "Health: " << currentHealth << " / " << maxHealth << endl;
        cout << "Attack: " << attack << endl;
        cout << "Defense: " << defense << endl;
        cout << "=============================" << endl;
    }
};
