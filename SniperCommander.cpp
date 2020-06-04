//
// Created by rotem levy on 27/05/2020.
//

#include "SniperCommander.hpp"
#include "Sniper.hpp"

using namespace std;

void SniperCommander::attack(vector<vector<Soldier*>> &b, pair<int,int> location)
{
    int row=location.first;
    int col=location.second;
    pair<pair<int,int>,Soldier*> temp=make_pair(make_pair(0,0),nullptr);
    int target=0;
    Soldier* enemy;
    for(int i= 0; i< b.size(); ++i)
    {
        for(int j=0; j< b[i].size(); ++j)
        {
           enemy =b[i][j];
            if(enemy!=nullptr)
            {
                if(enemy->getPlayer_Number()!=this->player_number) //if ememy
                {
                    if(enemy->getHp()>target)
                    {
                        target=enemy->getHp();
                        temp.first.first=i;ans.first.second=j;
                        temp.second=enemy;
                    }
                }
                else
                {
                    Sniper *sn = dynamic_cast<Sniper*>(enemy);
                    if(sn)
                    {
                        sn->attack(b,{i,j});
                    }
                }
            }
        }
    }
    temp.second->setHp(temp.second->getHp()+damage);
    if(temp.second->getHp()<=0)
    {
        b[temp.first.first][temp.first.second]=nullptr;
    }
}