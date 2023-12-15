#include <iostream>
#include <vector>
#include "mob.h"

int main() {
    std::vector<Enemy*> enemies;
    try {
        enemies.push_back(new Monster("Roko", 20, 2, "Fart of Doom"));
        enemies.push_back(new Boss("Meowster III", 100, 40, "Claw Spear"));
    } 
    catch (const std::invalid_argument& er) {
        std::cerr << "Error: " << er.what() << std::endl;
    }

    for (const auto& enemy : enemies) {
        enemy->attack();
        enemy->display_info();
        std::cout << std::endl << std::endl << std::endl;
    }

    for (const auto& enemy : enemies) {
        delete enemy;
    }
}
