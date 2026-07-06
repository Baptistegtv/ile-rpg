#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

struct Equipment {
    std::string name;
    int rarity; // 1-5 (Commun à Légendaire)
    int damage;
    int defense;
    int hp_bonus;
    int speed;
};

struct Skill {
    std::string name;
    int damage;
    int mana_cost;
    int cooldown;
};

struct Familiar {
    std::string name;
    int level;
    int damage_boost;
    int hp_boost;
};

class Player {
private:
    std::string name;
    int level;
    int experience;
    int max_experience;
    int hp;
    int max_hp;
    int mana;
    int max_mana;
    int gold;
    
    // Stats
    int attack;
    int defense;
    int speed;
    int critical_chance;
    
    // Equipment
    Equipment weapon;
    Equipment armor;
    Equipment accessory;
    
    // Skills & Familiars
    std::vector<Skill> skills;
    std::vector<Familiar> familiars;
    
    int current_island;
    int experience_to_next_level;

public:
    Player();
    
    // Getters
    int getLevel() { return level; }
    int getHP() { return hp; }
    int getMaxHP() { return max_hp; }
    int getExperience() { return experience; }
    int getGold() { return gold; }
    int getAttack() { return attack; }
    int getDefense() { return defense; }
    std::string getName() { return name; }
    
    // Setters
    void setName(std::string n) { name = n; }
    void addExperience(int xp);
    void levelUp();
    void addGold(int amount) { gold += amount; }
    void takeDamage(int damage);
    void heal(int amount);
    
    // Equipment
    void equipWeapon(Equipment e);
    void equipArmor(Equipment e);
    void equipAccessory(Equipment e);
    Equipment getWeapon() { return weapon; }
    
    // Skills
    void learnSkill(Skill s);
    std::vector<Skill> getSkills() { return skills; }
    
    // Familiars
    void addFamiliar(Familiar f);
    std::vector<Familiar> getFamiliars() { return familiars; }
    
    // Combat
    int calculateDamage();
    int calculateDefense();
    bool isCritical();
};

#endif
