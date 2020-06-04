#include "SniperCommander.hpp"

void SniperCommander::action(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> location)
{
    int x1 = location.first;
    int x2 = location.second;

    Soldier* strongest_enemy = nullptr;
    uint strongest_enemy_hp = 0;
    std::pair<int,int> strongest_enemy_location;

    std::vector<Soldier*> teammates;
    std::vector<std::pair<int,int>> teammates_locations;

    for(int i = 0 ; i < board.size() ; i ++)
    {
        for(int j = 0 ; j < board[i].size(); j++)
        {
            Soldier* curr = board[i][j];
            if(curr != nullptr)
            {
                if(curr->getPlayer_number() != player_number)
                {
                    Soldier* curr = board[i][j];
                    uint curr_hp = curr->getHp();
                    if(curr_hp > strongest_enemy_hp)
                    {
                        strongest_enemy_hp = curr_hp;
                        strongest_enemy = curr;
                        strongest_enemy_location = {i,j};
                    }
                } else {
                    if(curr->getType() == Type::SniperType)
                    {
                        teammates.push_back(curr);
                        teammates_locations.push_back({i,j});
                    }
                }
            }
        }
    }

    if(strongest_enemy != nullptr)
    {
        int new_hp = strongest_enemy->getHp() +damage;
        strongest_enemy->setHp(new_hp);
        if(new_hp <= 0)
        {
            board[strongest_enemy_location.first][strongest_enemy_location.second] = nullptr;
        }
    }

    for(int i = 0 ; i < teammates.size() ; i++)
    {
        Soldier* curr_teammate = teammates[i];
        std::pair<int,int> curr_location = teammates_locations[i];
        curr_teammate->attack(board,curr_location);
    }
}
