#ifndef mob_h
#define mob_h

#include <iostream>
#include <string>
#include <vector>

class Enemy
{
protected:
    std::string n;
    int h;
    int d;

public:
    Enemy(const std::string& name, int health, int damage);
    virtual ~Enemy();
    virtual void attack() const = 0;
    virtual void display_info() const = 0;
};

class Boss : public Enemy
{
protected:
    std::string w;

public:
    Boss(const std::string& name, int health, int damage, const std::string& weapon);
    void attack() const override;
    void display_info() const override;
};

class Monster : public Enemy
{
protected:
    std::string a;

public:
    Monster(const std::string& name, int health, int damage, const std::string& ability);
    void attack() const override;
    void display_info() const override;
};

#endif
