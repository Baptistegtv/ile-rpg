#ifndef ENEMY_H
#define ENEMY_H

#include <string>

enum EnemyType {
    SLIME_GREEN = 1,
    SLIME_BLUE = 2,
    SLIME_RED = 3,
    GOBLIN = 4,
    ORC = 5,
    DRAGON = 6,
    BOSS = 7
};

class Enemy {
private:
    std::string name;
    EnemyType type;
    int level;
    int hp;
    int max_hp;
    int attack;
    int defense;
    int experience_reward;
    int gold_reward;
    int x, y; // Position

public:
    Enemy(EnemyType t, int lvl);
    
    // Getters
    std::string getName() { return name; }
    int getHP() { return hp; }
    int getMaxHP() { return max_hp; }
    int getAttack() { return attack; }
    int getDefense() { return defense; }
    int getLevel() { return level; }
    int getExpReward() { return experience_reward; }
    int getGoldReward() { return gold_reward; }
    EnemyType getType() { return type; }
    
    // Combat
    void takeDamage(int damage);
    int calculateDamage();
    bool isAlive() { return hp > 0; }
    
    // Position
    void setPosition(int px, int py) { x = px; y = py; }
    int getX() { return x; }
    int getY() { return y; }
};

#endif
