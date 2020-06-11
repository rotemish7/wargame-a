//
// Created by rotem levy on 27/05/2020.
//

#include "SniperCommander.hpp"

using namespace std;

SniperCommander::SniperCommander(uint player_number)
{
    player_num = player_number;
    hp = MAX_HP;
    damage = -100;
    type = Type::SniperCommanderType;
}

uint SniperCommander::getMaxHP()
{
    return MAX_HP;
}

void SniperCommander::attack(std::vector<std::vector<Soldier*>> &b, std::pair<int,int> location)
{
    int row = location.first;
    int col = location.second;

    Soldier* best_target = nullptr;
    uint best_target_hp = 0;
    pair<int,int> best_target_loc;

    std::vector<Soldier*> teammates;
    std::vector<std::pair<int,int>> teammates_locations;

    for(int i = 0 ; i < b.size() ; i ++)
    {
        for(int j = 0 ; j < b[i].size(); j++)
        {
            Soldier* temp = b[i][j];
            if(temp != nullptr)
            {
                if(temp->getPlayer_number() != player_num)
                {
                    Soldier* temp = b[i][j];
                    uint temp_hp = temp->getHp();
                    if(temp_hp > best_target_hp)
                    {
                        best_target_hp = temp_hp;
                        best_target = temp;
                        best_target_loc = {i,j};
                    }
                } else {
                    if(temp->getType() == Type::SniperType)
                    {
                        teammates.push_back(temp);
                        teammates_locations.push_back({i,j});
                    }
                }
            }
        }
    }

    if(best_target != nullptr)
    {
        int new_hp = strongest_enemy->getHp() + damage;
        best_target->setHp(new_hp);
        if(new_hp <= 0)
        {
            b[best_target_loc.first][best_target_loc.second] = nullptr;
        }
    }

    for(int i = 0 ; i < teammates.size() ; i++)
    {
        Soldier* curr_teammate = teammates[i];
        std::pair<int,int> curr_location = teammates_locations[i];
        curr_teammate->attack(b,curr_location);
    }
}