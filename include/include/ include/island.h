#ifndef ISLAND_H
#define ISLAND_H

#include <string>
#include <vector>
#include "enemy.h"

struct NPC {
    std::string name;
    std::string dialogue;
    bool has_quest;
    std::string quest_description;
    int reward_xp;
    int reward_gold;
};

class Island {
private:
    std::string name;
    int id;
    std::string description;
    std::string environment; // "Plage tropicale", "Forêt", etc.
    int min_level_recommended;
    
    std::vector<Enemy> enemies;
    std::vector<NPC> npcs;
    
public:
    Island(int island_id, std::string n, std::string env);
    
    // Getters
    std::string getName() { return name; }
    std::string getEnvironment() { return environment; }
    std::string getDescription() { return description; }
    int getMinLevel() { return min_level_recommended; }
    std::vector<Enemy>& getEnemies() { return enemies; }
    std::vector<NPC>& getNPCs() { return npcs; }
    
    // Enemies
    void generateEnemies(int player_level);
    Enemy& getRandomEnemy();
    
    // NPCs
    void addNPC(NPC npc);
};

#endif
