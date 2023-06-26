#include "characters.h"
#include <iostream>
/*class Strategy {
public:
    virtual void execute() = 0;
};

class AttackStrategy : public Strategy {
public:
    void execute() override {
        // выполнение алгоритма атаки
    }
};

class DefenseStrategy : public Strategy {
public:
    void execute() override {
        // выполнение алгоритма защиты
    }
};
class CharacterDecorator : public Character {
protected:
    Character* character;
public:
    CharacterDecorator(Character* character) : character(character) {}
};

class SpeedDecorator : public CharacterDecorator {
public:
    SpeedDecorator(Character* character) : CharacterDecorator(character) {}
    void increaseSpeed() {
        // увеличение скорости передвижения
    }
};

class MagicDefenseDecorator : public CharacterDecorator {
public:
    MagicDefenseDecorator(Character* character) : CharacterDecorator(character) {}
    void increaseMagicDefense() {
        // увеличение магической защиты
    }
};*/


Character::Character(std::string name, int level, int health, int attack, int defense) {
    this->name = name;
    this->level = level;
    this->health = health;
    this->attack = attack;
    this->defense = defense;
}

Character::~Character() {}

void Character::attack(Character* target) {
    int damage = attack - target->defense;
    if (damage < 0) {
        damage = 0;
    }
    target->takeDamage(damage);
}

void Character::takeDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0;
    }
}

bool Character::isAlive() {
    return health > 0;
}

void Character::printInfo() {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Level: " << level << std::endl;
    std::cout << "Health: " << health << std::endl;
    std::cout << "Attack: " << attack << std::endl;



}
    int main() {
        std::string name;
        int level, health, attack, defense, experience, gold;

        std::cout << "Enter player name: ";
        std::cin >> name;
        std::cout << "Enter player level: ";
        std::cin >> level;
        std::cout << "Enter player health: ";
        std::cin >> health;
        std::cout << "Enter player attack: ";
        std::cin >> attack;
        std::cout << "Enter player defense: ";
        std::cin >> defense;
        std::cout << "Enter player experience: ";
        std::cin >> experience;
        std::cout << "Enter player gold: ";
        std::cin >> gold;

        Player player(name, level, health, attack, defense, experience, gold);
        player.printInfo();

        return 0;
    }