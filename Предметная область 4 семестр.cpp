//﻿#include "characters.h"
#include <iostream>
#include "list.h"
#include <vector>
#include <algorithm>
#include <string>

// Базовый класс персонажа
class Character {
protected:
    std::string name;
    int level;
    int health;
    int attack;

public:
    Character(std::string name, int level, int health, int attack)
        : name(name), level(level), health(health), attack(attack) {}

    virtual void attackEnemy(Character& enemy) {
        std::cout << name << " атакует " << enemy.name << "!" << std::endl;
        // Логика атаки персонажа на врага
    }

    virtual void useSkill() {
        std::cout << name << " использует навык!" << std::endl;
        // Логика использования навыка персонажа
    }

    friend std::ostream& operator<<(std::ostream& os, const Character& character) {
        os << "Имя: " << character.name << std::endl;
        os << "Уровень: " << character.level << std::endl;
        os << "Здоровье: " << character.health << std::endl;
        os << "Атака: " << character.attack << std::endl;
        return os;
    }
};

class PlayerCharacter : public Character {
private:
    int experience;
public:
    PlayerCharacter(const std::string& name, int health, int attack, int defense, int experience)
        : Character(name, health, attack, defense), experience(experience) {}

    int getExperience() const {
        return experience;
    }

    void setExperience(int exp) {
        experience = exp;
    }

    void levelUp() {
        // Увеличиваем его характеристики (например, атаку и защиту)
        attack += 10;
        //defense += 5;
        health += 20;
        experience = 0; // Обнуляем опыт после повышения уровня
    }

    void specialAbility() {
        // Используем особый навык персонажа
        // Например, наносим урон всем врагам на поле боя
    }
};





// Класс-декоратор для персонажей
class CharacterDecorator : public Character {
protected:
    Character& character;

public:
    CharacterDecorator(Character& character)
        : Character(character.name, character.level, character.health, character.attack), character(character) {}

    void attackEnemy(Character& enemy) override {
        character.attackEnemy(enemy);
    }

    void useSkill() override {
        character.useSkill();
    }
};

// Класс-декоратор для усиления атаки персонажа
class AttackBoostDecorator : public CharacterDecorator {
private:
    int attackBoost;

public:
    AttackBoostDecorator(Character& character, int attackBoost)
        : CharacterDecorator(character), attackBoost(attackBoost) {
        this->attack += attackBoost;
    }

    void attackEnemy(Character& enemy) override {
        std::cout << name << " атакует " << enemy.name << " с усиленной атакой!" << std::endl;
        character.attackEnemy(enemy);
    }
};

// Класс-стратегия для выбора навыка персонажа
class SkillStrategy {
public:
    virtual void useSkill(Character& character) = 0;
};

// Конкретная стратегия для навыка "Огненный шар"
class FireballSkillStrategy : public SkillStrategy {
public:
    void useSkill(Character& character) override {
        std::cout << character.name << " использует навык Огненный шар!" << std::endl;
        // Логика использования навыка "Огненный шар"
    }
};

// Конкретная стратегия для навыка "Лечение"
class HealingSkillStrategy : public SkillStrategy {
public:
    void useSkill(Character& character) override {
        std::cout << character.name << " использует навык Лечение!" << std::endl;
        // Логика использования навыка "Лечение"
    }
};

int main() {
    Character player("Сяо", 1, 100, 10);
    Character enemy("Хиличурл", 1, 100, 10);

    std::cout << player << std::endl;
    std::cout << enemy << std::endl;

    player.attackEnemy(enemy);
    player.useSkill();

    AttackBoostDecorator boostedPlayer(player, 5);
    boostedPlayer.attackEnemy(enemy);

    FireballSkillStrategy fireballStrategy;
    HealingSkillStrategy healingStrategy;

    player.useSkill();
    fireballStrategy.useSkill(player);

    player.useSkill();
    healingStrategy.useSkill(player);

    return 0;


    Container::forward_list<std::string> invite;
    invite.push_back("Взаимодействуйте с таинственной деревянной доской в определённом месте, чтобы поучаствовать в испытании в Королевствах лжи и раздора");
    invite.push_back("Вы должны беспрерывно побеждать противников в Королевствах лжи и раздора. Пройдите 3 испытания, чтобы закончить 1 боевой раунд. После окончания каждого раунда ваш прогресс будет автоматически сохранён.");
    invite.push_back("После каждого раунда из трёх пройденных испытаний вы должны изменить состав отряда.Продолжить сражаться сможет только один персонаж из текущего отряда");
    invite.push_back("Вы можете экипировать максимум 3 стратагемы за раунд. Стратагемы дают улучшения в бою.В конце каждого раунда вы сможете вытянуть 5 случайных стратагем для следующего раунд");
    invite.push_back("Вы можете использовать осколки стратагем, чтобы получить новые стратагемы или выбрать ранее экипированную стратагему для дальнейшего использования");
    std::cout << "Обучение для события 'Опасная тропа' " << std::endl;
    for (auto i : invite)
        std::cout << i << std::endl;


}
