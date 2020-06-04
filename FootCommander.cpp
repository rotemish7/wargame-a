//
// Created by rotem levy on 27/05/2020.
//
#include <iostream>
#include "FootCommander.hpp"
#include "FootSoldier.hpp"
#include "Board.hpp"

using namespace std;

double distance2(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

void FootCommander::attack(vector<vector<Soldier*>> &b, pair<int,int> location)
{
    int row = location.first;
    int col = location.second;
    Soldier* near_enemy = nullptr;
    Soldier* temp = nullptr;
    double min = b.size()*b.size();
    double dist = 0;
    std::vector<Soldier*> company;
    std::vector<std::pair<int,int>> company_locs;
    //b[row][col]->attack(b, location);
    for(int i = 0; i < b.size(); ++i)
    {
        for(int j = 0; j < b[i].size(); ++j)
        {
            temp = b[i][j];
            if(temp != nullptr)
            {
                if(temp->getPlayer_number() != b[row][col]->getPlayer_number())
                {
                    dist = distance(row,col,i,j);
                    if(dist<min)
                    {
                        min = dist;
                        near_enemy = temp;
                    }
                    else
                    {
                        if(temp->getType() == FootCommanderType)
                        {
                            company.push_back(temp);
                            company_locs.push_back({i,j});
                        }
                    }
                }
            }
        }
    }

    if(near_enemy != nullptr)
    {
        int new_Hp = near_enemy->getHp()+damage;
        near_enemy->setHp(new_Hp);
        if(new_Hp <= 0)
        {
            near_enemy = nullptr;
        }
    }

    for (int k = 0; k < company_locs.size(); ++k)
    {
        Soldier* current = company[k];
        pair<int,int> curr_locs = company_locs[k];
        current->attack(b,curr_locs);
    }
}
