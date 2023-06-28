#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <string>

class Character {
protected:
    std::string name;
    int level;
    int health;
    int attack;
    int defense;
public:
    Character(std::string name, int level, int health, int attack, int defense);
    virtual ~Character();
    virtual void attack(Character* target);
    virtual void takeDamage(int damage);
    virtual bool isAlive();
    virtual void printInfo();
};

class Player : public Character {
private:
    int experience;
    int gold;
public:
    Player(std::string name, int level, int health, int attack, int defense, int experience, int gold);
    virtual ~Player();
    virtual void attack(Character* target);
    virtual void takeDamage(int damage);
    virtual void gainExperience(int experience);
    virtual void gainGold(int gold);
    virtual void printInfo();
};

class Monster : public Character {
private:
    int experience;
    int gold;
public:
    Monster(std::string name, int level, int health, int attack, int defense, int experience, int gold);
    virtual ~Monster();
    virtual void attack(Character* target);
    virtual void takeDamage(int damage);
    virtual int getExperience();
    virtual int getGold();
    virtual void printInfo();
};

class FriendlyMonster : public Character {
private:
    int heal;
public:
    FriendlyMonster(std::string name, int level, int health, int attack, int defense, int heal);
    virtual ~FriendlyMonster();
    virtual void attack(Character* target);
    virtual void takeDamage(int damage);
    virtual void healCharacter(Character* target);
    virtual void printInfo();
};


class Strategy { //использование стратегии защиты или аттаки
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


//Паттерн для присвоения скилов
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
};



#endif