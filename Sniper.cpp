//
// Created by rotem levy on 27/05/2020.
//

#include "Sniper.hpp"

using namespace std;

Sniper::Sniper(uint player_number)
{
    player_number = player_number;
    hp = MAX_HP;
    damage = -50;
    type = Type::SniperType;
}

uint Sniper::getMaxHP()
{
    return MAX_HP;
}


void Sniper::attack(std::vector<std::vector<Soldier*>> &b, std::pair<int,int> location)
{
    int row = location.first;
    int col = location.second;

    Soldier* best_target = nullptr;
    uint best_target_hp = 0;
    std::pair<int,int> best_target_loc;

    for(int i = 0 ; i < b.size() ; i ++)
    {
        for(int j = 0 ; j < b[i].size(); j++)
        {
            Soldier* temp = b[i][j];
            if(temp != nullptr)
            {
                if(temp->getPlayer_number() != player_number)
                {
                    Soldier* temp = board[i][j];
                    uint temp_hp = temp->getHp();
                    if(temp_hp > best_target_hp)
                    {
                        best_target_hp = temp_hp;
                        best_target = temp;
                        best_target_loc = {i,j};
                    }
                }
            }
        }
    }

    if(best_target != nullptr)
    {
        int new_hp = strongest_enemy->getHP() + damage;
        strongest_enemy->setHp(new_hp);
        if(new_hp <= 0)
        {
            b[best_target_loc.first][best_target_loc.second] = nullptr;
        }
    }
}
