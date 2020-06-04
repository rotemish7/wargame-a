//
// Created by rotem levy on 27/05/2020.
//

#include "FootSoldier.hpp"
#include <iostream>
#include <vector>
#include "Board.hpp"

using namespace std;

void FootSoldier::attack(vector<vector<Soldier*>> &b, pair<int,int> location)
{
    int row = location.first;
    int col = location.second;

    double dist = 0;
    double min = 0;
    Soldier* enemy;
    for(int i = 0; i < b.size(); ++i)
    {
        for(int j = 0; j < b[i].size(); ++j)
        {
            if (b[i][j] != nullptr && b[i][j]->getPlayer_number() != b[row][col]->getPlayer_number())
            {
                dist = distance(row, col, i, j);
            }

            if (dist < min)
            {
                min = dist;
                enemy = b[i][j];
            }
        }
    }
    int damage = b[row][col]->getDamage();
    int health = enemy->getHp();
    enemy->setHp(health-damage);
    if(!enemy->isAlive())
    {
        enemy = nullptr;
    }

}