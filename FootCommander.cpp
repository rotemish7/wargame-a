//
// Created by rotem levy on 27/05/2020.
//
#include <iostream>
#include "FootCommander.hpp"


FootCommander::FootCommander(uint player_number)
{
    player_number = player_number;
    hp = MAX_HP;
    damage = -20;
    type = Type::FootCommanderType;
}

uint FootCommander::getMaxHP()
{
    return MAX_HP;
}

void FootCommander::attack(std::vector<std::vector<Soldier*>> &b, std::pair<int,int> location)
{
    int row = location.first;
    int col = location.second;

    Soldier* near_enemy = nullptr;
    std::pair<int,int> near_enemy_location;
    double min = b.size()*b.size();

    std::vector<Soldier*> teammates;
    std::vector<std::pair<int,int>> teammates_locations;

    for(int i = 0 ; i < b.size() ; i ++)
    {
        for(int j = 0 ; j < b[i].size(); j++)
        {
            Soldier * temp = b[i][j];
            if(temp != nullptr)
            {
                if(temp->getPlayer_number() != player_number)
                {
                    double dist = Utils::distance(x1,x2,i,j);
                    if(dist < min)
                    {
                        min = dist;
                        near_enemy = temp;
                        near_enemy_location = {i,j};
                    }
                } else {
                    if(temp->getType() == Type::FootSoldierType)
                    {
                        teammates.push_back(temp);
                        teammates_locations.push_back({i,j});
                    }
                }
            }
        }
    }

    if(near_enemy != nullptr)
    {
        int new_hp = near_enemy->getHp() + damage;
        near_enemy->setHp(new_hp);
        if(new_hp <= 0)
        {
            b[near_enemy_location.first][near_enemy_location.second] = nullptr;
        }
    }

    for(int i = 0 ; i < teammates.size() ; i++)
    {
        Soldier* temp_teammate = teammates[i];
        std::pair<int,int> temp_location = teammates_locations[i];
        temp_teammate->attack(b,temp_location);
    }
}
