#include <iostream>
using namespace std;

// Class for the Animal
class Animal {
    public:
        // Constructor
        Animal(string name, int age, string species, string sex, string season, string color, int weight, string origin) {
            this->name = name;
            this->age = age;
            this->species = species;
            this-> sex = sex;
            this->season = season;
            this->color = color;
            this->weight = weight;
            this->origin = origin;
        }
        // Default constructor
        Animal() {
            name = "";
            age = 0;
            species = "";
            sex = "";
            season = "";
            color = "";
            weight = 0;
            origin = "";
        }

        // Getters
        string getName() {
            return name;
        }

        int getAge() {
            return age;
        }

        string getSpecies() {
            return species;
        }

        string getSex() {
            return sex;
        }

        string getSeason() {
            return season;
        }

        string getColor() {
            return color;
        }

        int getWeight() {
            return weight;
        }

        string getOrigin() {
            return origin;
        }

        // Setters

        void setName(string name) {
            this->name = name;
        }

        void setAge(int age) {
            this->age = age;
        }

        void setSpecies(string species) {
            this->species = species;
        }

        void setSex(string sex) {
            this->sex = sex;
        }

        void setSeason(string season) {
            this->season = season;
        }

        void setColor(string color) {
            this->color = color;
        }

        void setWeight(int weight) {
            this->weight = weight;
        }

        void setOrigin(string origin) {
            this->origin = origin;
        }

    protected:
        string name;
        int age;
        string species;
        string sex;
        string season;
        string color;
        int weight;
        string origin;

};

class Hyena : public Animal {
    public:
        Hyena(string name, int age, string species, string sex, string season, string color, int weight, string origin) : Animal(name, age, species,
        sex, season, color, weight, origin) {
            this->name = name;
            this->age = age;
            this->species = "Hyena";
            this->sex = sex;
            this->season = season;
            this->color = color;
            this->weight = weight;
            this->origin = origin;
        }
};

class Lion : public Animal {
    public:
        Lion(string name, int age, string species, string sex, string season, string color, int weight, string origin) : Animal(name, age, species,
        sex, season, color, weight, origin) {
            this->name = name;
            this->age = age;
            this->species = "Lion";
            this->sex = sex;
            this->season = season;
            this->color = color;
            this->weight = weight;
            this->origin = origin;
        }
};

class Tiger : public Animal {
    public:
        Tiger(string name, int age, string species, string sex, string season, string color, int weight, string origin) : Animal(name, age, species,
        sex, season, color, weight, origin) {
            this->name = name;
            this->age = age;
            this->species = "Tiger";
            this->sex = sex;
            this->season = season;
            this->color = color;
            this->weight = weight;
            this->origin = origin;
        }
};

class Bear : public  Animal {
    public:
        Bear(string name, int age, string species, string sex, string season, string color, int weight, string origin) : Animal(name, age, species,
        sex, season, color, weight, origin) {
            this->name = name;
            this->age = age;
            this->species = "Bear";
            this->sex = sex;
            this->season = season;
            this->color = color;
            this->weight = weight;
            this->origin = origin;
        }
};