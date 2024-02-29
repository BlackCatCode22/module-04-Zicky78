#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <vector>
#include "Animal.h"
using namespace std;

// Functions that create new animal subclasses
Animal* createHyena(string name, int age, string species, string sex, string season, string color, int weight, string origin);
Animal* createLion(string name, int age, string species, string sex, string season, string color, int weight, string origin);
Animal* createTiger(string name, int age, string species, string sex, string season, string color, int weight, string origin);
Animal* createBear(string name, int age, string species, string sex, string season, string color, int weight, string origin);

// Functions for extracting data from the lines of the file
int extractAge(string line);
string extractSpecies(string line);
string extractSex(string line);
string extractSeason(string line);
string extractColor(string line);
int extractWeight(string line);
string extractOrigin(string line);

// Function that generates the report
void generateReport(vector<Animal*> animals);

// Main function
int main() {

    // Variables
    string line = "";
    vector<Animal*> animals;

    // Map of functions that create new animal subclasses
    map<string, function<Animal*(string, int, string, string, string, string, int, string)>> createAnimal;
    createAnimal["hyena"] = createHyena;
    createAnimal["lion"] = createLion;
    createAnimal["tiger"] = createTiger;
    createAnimal["bear"] = createBear;

    // Open arrivingAnimals.txt
    ifstream file("C:/Users/zacha/Desktop/Coding Stuff/CIT66/module-04-Zicky78/arrivingAnimals.txt");

    // Read the file line by line
    while(getline(file, line)) {
        
        // Create a new animal and add it to the vector
        // The type of animal is determined by the species
        animals.push_back(createAnimal[extractSpecies(line)](
            " ",
            extractAge(line),
            extractSpecies(line),
            extractSex(line),
            extractSeason(line),
            extractColor(line),
            extractWeight(line),
            extractOrigin(line)
        ));

    }

    // Close the file
    file.close();

    // Generate the report
    generateReport(animals);

    return 0;   
}

// Function that returns new Bear subclass
Animal* createBear(string name, int age, string species, string sex, string season, string color, int weight, string origin) {
    return new Bear(name, age, species, sex, season, color, weight, origin);
}

// Function that returns new Hyena subclass
Animal* createHyena(string name, int age, string species, string sex, string season, string color, int weight, string origin) {
    return new Hyena(name, age, species, sex, season, color, weight, origin);
}

// Function that returns new Lion subclass
Animal* createLion(string name, int age, string species, string sex, string season, string color, int weight, string origin) {
    return new Lion(name, age, species, sex, season, color, weight, origin);
}

// Function that returns new Tiger subclass
Animal* createTiger(string name, int age, string species, string sex, string season, string color, int weight, string origin) {
    return new Tiger(name, age, species, sex, season, color, weight, origin);
}

// Function that extracts the age from a line
int extractAge(string line) {
    // From start of string to first space
    return stoi(line.substr(0, line.find(" ")));
}

// Function that extracts the species from a line
string extractSpecies(string line) {
    // From start of string to first comma/space
    line = line.substr(0, line.find(", "));
    // From last space to end of string
    return line.substr(line.find_last_of(" ") + 1);
    
}

// Function that extracts the sex from a line
string extractSex(string line) {
    // From start of string to first comma
    line = line.substr(0, line.find(","));
    // From start of string to last space
    line = line.substr(0, line.find_last_of(" "));
    // From last space to end of string
    return line.substr(line.find_last_of(" ") + 1, line.length() - 1);
}

// Function that extracts the season from a line
string extractSeason(string line) {
    // From first comma/space to end of string
    line = line.substr(line.find(", ") + 2);
    // From start of string to first comma/space
    line = line.substr(0, line.find(", "));
    // From last space to end of string
    return line.substr(line.find_last_of(" ") + 1, line.length() - 1); 
}

// Function that extracts the color from a line
string extractColor(string line) {
    // From first comma/space to end of string
    line = line.substr(line.find(", ") + 2);
    // From first comma/space to end of string
    line = line.substr(line.find(", ") + 2);
    // From start of string to color,
    return line.substr(0, line.find(" color, "));
}

// Function that extracts the weight from a line
int extractWeight(string line) {
    // From color, to end of string
    line = line.substr(line.find("color,") + 7);
    // From start of string to pounds
    return stoi(line.substr(0, line.find("pounds") - 1));
}

// Function that extracts the origin from a line
string extractOrigin(string line) {
    // From from to end of string
    return line.substr(line.find("from") + 5, line.length() - 1);
}

// Function that generates the report
void generateReport(vector<Animal*> animals) {
    // Creat report.txt file
    ofstream report("C:/Users/zacha/Desktop/Coding Stuff/CIT66/module-04-Zicky78/report.txt");

    // Write to report.txt looping through animals vector
    for(int i = 0; i < animals.size(); i++) {
        report << "Animal " << i + 1 << ": " << endl;
        report << "Age: " << animals[i]->getAge() << endl;
        report << "Species: " << animals[i]->getSpecies() << endl;
        report << "Sex: " << animals[i]->getSex() << endl;
        report << "Season: " << animals[i]->getSeason() << endl;
        report << "Color: " << animals[i]->getColor() << endl;
        report << "Weight: " << animals[i]->getWeight() << endl;
        report << "Origin: " << animals[i]->getOrigin() << endl;
        report << endl;
    }

    // Close the file
    report.close();
}
    


