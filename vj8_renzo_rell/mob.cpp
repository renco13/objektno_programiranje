#include <iostream>
#include "mob.h"

Enemy::Enemy(const std::string& name, int health, int damage) : n(name), h(health), d(damage) {
    if (health < 0 || damage < 0) {
        throw std::invalid_argument("Health and damage must be positive numbers.\n");
    }
}

Enemy::~Enemy() {}

Boss::Boss(const std::string& name, int health, int damage, const std::string& weapon) : Enemy(name, health, damage), w(weapon) {
    if (weapon.empty()) {
        throw std::invalid_argument("Boss must have a weapon!\n");
    }
}

void Boss::attack() const {
    std::cout << "Boss attacks with -> " << w << ", and deals -> " << d << " damage." << std::endl;
}

void Boss::display_info() const {
    std::cout << "Boss: " << n << std::endl << "Health: " << h << std::endl << "Damage: " << d << std::endl << "Weapon: " << w << std::endl;
}

Monster::Monster(const std::string& name, int health, int damage, const std::string& ability) : Enemy(name, health, damage), a(ability) {
    if (ability.empty()) {
        throw std::invalid_argument("Monster must have an ability!\n");
    }
}

void Monster::attack() const {
    std::cout << "Monster attacks with -> " << a << ",and deals -> " << d << " damage." << std::endl;
}
    
void Monster::display_info() const {
    std::cout << "Monster: " << n << std::endl << "Health: " << h << std::endl << "Damage: " << d << std::endl << "Ability: " << a << std::endl;
}
