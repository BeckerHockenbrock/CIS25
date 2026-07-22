#include <cstddef>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Pokemon{
public:
    string id;
    string name;
    string type1;
    string type2;
    string total;
    string hp;
    string attack;
    string defense;
    string specialAttack;
    string specialDefense;
    string speed;

    void displayPokemon() {
        cout << "Name: " << name << endl;
        cout << "Type: " << type1 << endl;
        if(!type2.empty()){
            cout << "Second Type: " << type2 << endl;
        }
        cout << "HP: " << hp << endl;
        cout << "Attack: " << attack << endl;
        cout << "Defense: " << defense << endl;
        cout << "Special Attack: " << specialAttack << endl;
        cout << "Special Defense: " << specialDefense << endl;
        cout << "Speed: " << speed << endl;
    }



};


vector<Pokemon> loadPokemon() {
    vector<Pokemon> pokemonList;

    ifstream file("pokemon.csv");

    if (!file) {
        cout << "Could not open pokemon.csv" << endl;
        return pokemonList;
    }

    string line;
    getline(file, line);

      while (getline(file, line)) {
        stringstream ss(line);

        string number;
        string name;
        string type1;
        string type2;
        string total;
        string hp;
        string attack;
        string defense;
        string specialAttack;
        string specialDefense;
        string speed;

        getline(ss, number, ',');
        getline(ss, name, ',');
        getline(ss, type1, ',');
        getline(ss, type2, ',');
        getline(ss, total, ',');
        getline(ss, hp, ',');
        getline(ss, attack, ',');
        getline(ss, defense, ',');
        getline(ss, specialAttack, ',');
        getline(ss, specialDefense, ',');
        getline(ss, speed, ',');

        Pokemon currentPokemon;

        currentPokemon.name = name;
        currentPokemon.type1 = type1;
        currentPokemon.type2 = type2;
        currentPokemon.hp = stoi(hp);
        currentPokemon.attack = stoi(attack);
        currentPokemon.defense = stoi(defense);
        currentPokemon.specialAttack = stoi(specialAttack);
        currentPokemon.specialDefense = stoi(specialDefense);
        currentPokemon.speed = stoi(speed);

        pokemonList.push_back(currentPokemon);
    }

    file.close();

    return pokemonList;

}