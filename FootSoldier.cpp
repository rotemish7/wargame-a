//
// Created by rotem levy on 27/05/2020.
//

#include "FootSoldier.hpp"
#include <iostream>
#include <vector>
#include "Board.hpp"

using namespace std;

double distance(int x1, int y1, int x2, int y2) // d = sqrt((x1-x2)^2 + (y1-y2)^2)
{
    double dis1 = pow(x1-x2, 2);
    double dis2 = pow(y1-y2, 2);
    double ans = sqrt(dis1+dis2);
    return ans;
}

void FootSoldier::attack(vector<vector<Soldier*>> &b, pair<int,int> location)
{
    int row = location.first;
    int col = location.second;

    double dist = 0;
    double min = b.size()*b.size();
    Soldier* near_enemy;
    Soldier* temp;
    pair<int,int> near_enemy_loc;

    for(int i = 0; i < b.size(); ++i)
    {
        for(int j = 0; j < b[i].size(); ++j)
        {
            temp = b[i][j];
            if ( temp != nullptr)
            {
                if(temp->getPlayer_number() != b[row][col]->getPlayer_number())
                {
                    dist = distance(row, col, i, j);
                    if (dist < min)
                    {
                        min = dist;
                        near_enemy = temp;
                        near_enemy_loc = {i,j};
                    }
                }

            }

        }
    }
    
    int new_Hp = 0;
    if(near_enemy != nullptr)
    {
        int damage = b[row][col]->getDamage();
        int health = near_enemy->getHp();
        new_Hp = damage+health;
        near_enemy->setHp(new_Hp);
    }

    if(new_Hp <=0)
    {
        near_enemy = nullptr;
    }
}
