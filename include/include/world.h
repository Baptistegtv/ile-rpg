#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "island.h"

class World {
private:
    std::vector<Island> islands;
    int current_island;
    
public:
    World();
    
    void initializeIslands();
    Island& getCurrentIsland() { return islands[current_island]; }
    Island& getIsland(int id) { return islands[id]; }
    int getCurrentIslandId() { return current_island; }
    void travelToIsland(int id) { current_island = id; }
    int getTotalIslands() { return islands.size(); }
};

#endif
