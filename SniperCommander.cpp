//
// Created by rotem levy on 27/05/2020.
//

#include "SniperCommander.hpp"
#include "Sniper.hpp"
#include "FootSoldier.hpp"
#include "Board.hpp"

using namespace std;

void SniperCommander::attack(vector<vector<Soldier*>> &b, pair<int,int> location)
{
    int row = location.first;
    int col = location.second;

    Soldier* s_enemy = nullptr;
    Soldier* temp = nullptr;
    int s_enemy_hp = 0;
    std::pair<int,int> s_enemy_loc;
    std::vector<Soldier*> company;
    std::vector<std::pair<int,int>> company_locs;

    for(int i = 0 ; i < b.size() ; i ++)
    {
        for(int j = 0 ; j < b[i].size(); j++)
        {
            temp = b[i][j];
            if(temp != nullptr)
            {
                if(temp->getPlayer_number() != player_number)
                {
                    uint temp_hp = temp->getHp();
                    if(temp_hp > s_enemy_hp)
                    {
                        s_enemy_hp = temp_hp;
                        s_enemy = temp;
                        s_enemy_loc = {i,j};
                    }
                }
                else
                {
                    if(temp->getType() == SniperType)
                    {
                        company.push_back(temp);
                        company_locs.push_back({i,j});
                    }
                }
            }
        }
    }

    if(s_enemy != nullptr)
    {
        int new_hp = s_enemy->getHp() +damage;
        s_enemy->setHp(new_hp);
        if(new_hp <= 0)
        {
            b[s_enemy_loc.first][s_enemy_loc.second] = nullptr;
        }
    }

    for(int i = 0 ; i < company.size() ; i++)
    {
        Soldier* teammate = company[i];
        std::pair<int,int> teammate_loc = company_locs[i];
        teammate->attack(b,teammate_loc);
    }
}
