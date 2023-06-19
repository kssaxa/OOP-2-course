// новая предметная область.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Iterator.h"

class Character {
public:
    std::string name;
    int level;
    int health;
    int attackDamage;

    // Конструктор класса
    Character(std::string charName, int charLevel, int charHealth, int charAttackDamage)
        : name(charName), level(charLevel), health(charHealth), attackDamage(charAttackDamage) {}

    // Функция для атаки персонажем
    virtual void Attack(Character& target) {
        target.health -= attackDamage;
        std::cout << name << " атакует " << target.name << " и наносит " << attackDamage << " урона!\n";
    }

    // Виртуальная функция для специального навыка персонажа
    virtual void SpecialSkill() {
        // Логика выполнения специального навыка персонажа
    }
};

class Friend : public Character {
public:
    int healAmount;

    // Конструктор класса Friend
    Friend(std::string charName, int charLevel, int charHealth, int charAttackDamage, int heal)
        : Character(charName, charLevel, charHealth, charAttackDamage), healAmount(heal) {}

    // Переопределенная функция атаки для дружественного персонажа
    void Attack(Character& target) override {
        target.health -= attackDamage;
        health += healAmount;  // Дружественный персонаж также может исцеляться при атаке
        std::cout << name << " атакует " << target.name << " и наносит " << attackDamage << " урона!\n";
        std::cout << name << " исцеляется на " << healAmount << " единиц здоровья!\n";
    }
};

class GameObject {
public:
    std::string name;
    Vector3 position;

    // Конструктор класса
    GameObject(std::string objName, Vector3 objPosition)
        : name(objName), position(objPosition) {}

    // Функция для обновления объекта
    void Update() {
        // Логика обновления объекта
    }

    // Функция для отрисовки объекта
    void Render() {
        // Логика отрисовки объекта
    }
};

void Battle(Character& player, Character& enemy) {
    while (player.health > 0 && enemy.health > 0) {
        player.Attack(enemy);
        if (enemy.health <= 0) {
            std::cout << "Враг побежден!\n";
            break;
        }

        enemy.Attack(player);
        if (player.health <= 0) {
            std::cout << "Игрок побежден!\n";
            break;
        }
    }
}







int main()
{
    std::cout << "Hello World!\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
