#include "characters.h"
#include <iostream>
#include "list.h"
#include <vector>
#include <algorithm>
#include <string>
#include <functional>

// Базовый класс персонажа
class Play_Character {
    std::function<void()> heal;
protected:
//private:
    std::string name;
    int level;
    int health;
    int attack;

    
public:
    Play_Character(std::string region,std::string name, int level, int health, int attack )
        : name(name), level(level), health(health), attack(attack) {}

   void attackEnemy(Character& enemy) {
        std::cout << name << " атакует " << enemy.name << "!" << std::endl;
        // Логика атаки персонажа на врага
    }

   void usefly() {
        std::cout << name << " Использует полет" << std::endl;
        // Логика использования навыка персонажа
    }
   void skill() {
       std::cout << name << " Использует полет" << std::endl;
       // Логика использования навыка персонажа
   }
    friend std::ostream& operator<<(std::ostream& output, const Play_Character& character) {
        output << "Регион: " << character.region << std::endl;
        output << "Имя: " << character.name << std::endl;
        output << "Уровень: " << character.level << std::endl;
        output << "Здоровье: " << character.health << std::endl;
        output << "Атака: " << character.attack << std::endl;
        return output;
    }
    
    void setHeal(std::function<void()> healFunc) {
        heal = healFunc;
    }

    void performHeal() {
        if (heal) {
            heal();
        }
    }

};

class PlayerCharacter : public Play_Character {
private:
    int experience;
public:
    PlayerCharacter(const std::string& name, int health, int attack, int defense, int experience)
        : Play_Character(name, health, attack, defense), experience(experience) {}

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
    //Использование навыка усилеие
    void ULt() {
        attack += 100;
        health -= 25;
     }
    void specialAbility() {
        // Используем особый навык персонажа
я
    }
};





// Класс-декоратор для персонажей
class CharacterDecorator : public Play_Character {
protected:
    Play_Character& character;

public:
    CharacterDecorator(Play_Character& character)
        : Play_Character(character.name, character.level, character.health, character.attack), character(character) {}

    void attackEnemy(Play_Character& enemy) {
        character.attackEnemy(enemy);
    }

    void skill() override {
        character.usefly();
    }
};

// Класс-декоратор для усиления атаки персонажа
class AttackBoostDecorator : public CharacterDecorator {
private:
    int attackBoost;

public:
    AttackBoostDecorator(Play_Character& character, int attackBoost)
        : CharacterDecorator(character), attackBoost(attackBoost) {
        this->attack += attackBoost;
    }

    void attackEnemy(Play_Character& enemy) override {
        std::cout << name << " атакует " << enemy.name << " с усиленной атакой!" << std::endl;
        character.attackEnemy(enemy);
    }
};

// Класс-стратегия для выбора навыка персонажа
class SkillStrategy {
public:
    skill(Play_Character& character) {
        character = 0;
    }
};

// Конкретная стратегия для навыка "Огненный шар"
class FireballSkillStrategy : public SkillStrategy {
public:
    void skill(Play_Character& character)  {
        std::cout << character.name << " использует навык Огненный шар!" << std::endl;

    }
};

// Конкретная стратегия для навыка "Лечение"
class HealingSkillStrategy : public SkillStrategy {
public:
    void skill(Play_Character& character)  {
        std::cout << character.name << " использует навык Лечение!" << std::endl;
        // Логика использования навыка "Лечение"
    }
};

int main() {
    Play_Character player("Li UE","Сяо", 1, 100, 10);
    Play_Character enemy("Хиличурл", 1, 100, 10);

    std::cout << player << std::endl;
    std::cout << enemy << std::endl;

    player.attackEnemy(enemy);
    player.skill();

    AttackBoostDecorator boostedPlayer(player, 5);
    boostedPlayer.attackEnemy(enemy);

    FireballSkillStrategy fireballStrategy;
    HealingSkillStrategy healingStrategy;

    player.skill();
    fireballStrategy.skill(player);

    player.skill();
    healingStrategy.skill(player);

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


    Play_Character player("Mondsshtat","barbara", 100, 20, 10);
    player.setHeal([]() {
        std::cout << "Player heals themselves!" << std::endl;
        });

    player.performHeal(); // Выводит "Player heals themselves!"


}
