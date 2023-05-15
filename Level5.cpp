/*
Name       : Avijit Mondal
Department : Masters of Computer Applications(MCA)
College    : Dr. B. C. Engineering College , Durgapur
Level      : 5
Questionn  : Assume that you are developing a game in which players can control different characters, such as warriors,
            archers, and mages. Each character has a set of abilities that they can use during gameplay. Write a C++
            program to model this game using object-oriented programming concepts. The program should have the
            following classes:
            A. Character: This class should have attributes such as name, health, and level, as well as a virtual function
            for using abilities.
            B. Warrior, Archer, and Mage: These classes should inherit from the Character class and have their own
            unique abilities.
            C. Ability: This class should have attributes such as name, damage, and mana cost, as well as a virtual
            function for executing the ability.
            The program should allow the player to create and control different characters, select and use abilities
            during gameplay, and display the current status of the game.
*/

#include <iostream>
#include <vector>
#include <string>

// Base class for all characters
class Character
{
protected:
    std::string name;
    int health;
    int level;
public:
    Character(const std::string& name, int health, int level)
        : name(name), health(health), level(level) {}

    virtual void useAbility() = 0; // Virtual function for using abilities

    std::string getName() const
    {
        return name;
    }
    int getHealth() const
    {
        return health;
    }
    int getLevel() const
    {
        return level;
    }
};

// Derived classes for specific character types
class Warrior : public Character
{
public:
    Warrior(const std::string& name, int health, int level)
        : Character(name, health, level) {}

    void useAbility() override
    {
        std::cout << getName() << " uses Cleave ability\n";
    }
};

class Archer : public Character
{
public:
    Archer(const std::string& name, int health, int level)
        : Character(name, health, level) {}

    void useAbility() override
    {
        std::cout << getName() << " uses Volley ability\n";
    }
};

class Mage : public Character
{
public:
    Mage(const std::string& name, int health, int level)
        : Character(name, health, level) {}

    void useAbility() override
    {
        std::cout << getName() << " uses Fireball ability\n";
    }
};

// Class to model abilities
class Ability
{
    std::string name;
    int damage;
    int manaCost;
public:
    Ability(const std::string& name, int damage, int manaCost)
        : name(name), damage(damage), manaCost(manaCost) {}

    virtual void execute() = 0; // Virtual function for executing ability

    std::string getName() const
    {
        return name;
    }
    int getDamage() const
    {
        return damage;
    }
    int getManaCost() const
    {
        return manaCost;
    }
};

// Derived classes for specific abilities
class Cleave : public Ability
{
public:
    Cleave() : Ability("Cleave", 50, 20) {}

    void execute() override
    {
        std::cout << "Cleave deals " << getDamage() << " damage and costs " << getManaCost() << " mana\n";
    }
};

class Volley : public Ability
{
public:
    Volley() : Ability("Volley", 40, 15) {}

    void execute() override
    {
        std::cout << "Volley deals " << getDamage() << " damage and costs " << getManaCost() << " mana\n";
    }
};

class Fireball : public Ability
{
public:
    Fireball() : Ability("Fireball", 60, 25) {}

    void execute() override
    {
        std::cout << "Fireball deals " << getDamage() << " damage and costs " << getManaCost() << " mana\n";
    }
};

int main()
{
    // Create some characters
    Warrior warrior("Garen", 100, 10);
    Archer archer("Ashe", 80, 12);
    Mage mage("Annie", 90, 15);

    // Create some abilities
    Cleave cleave;
    Volley volley;
    Fireball fireball;

    // Use some abilities
    std::cout << "Using some abilities:\n";
    cleave.execute();
    volley.execute();
    fireball.execute();

    // Store characters and abilities in vectors for easier management
    std::vector<Character*> characters{ &warrior, &archer, &mage };
    std::vector<Ability*> abilities{ &cleave, &volley, &fireball };

// Use abilities of each character
    for (auto character : characters) {
        std::cout << "Using abilities of " << character->getName() << ":\n";
        character->useAbility();
    }

// Execute abilities
    for (auto ability : abilities) {
        std::cout << "Executing " << ability->getName() << ":\n";
        ability->execute();
    }

    return 0;
}
