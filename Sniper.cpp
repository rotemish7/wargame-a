//
// Created by rotem levy on 27/05/2020.
//


#include "Sniper.hpp"

using namespace std;

void Sniper::attack(vector<vector<Soldier*>> &b, pair<int,int> location)
{
    int row=location.first;
    int col=location.second;
    int target=0;
    pair<pair<int,int>,Soldier*> temp=make_pair(make_pair(0,0),nullptr);

    for(int i= 0; i< b.size(); ++i)
    {
        for(int j=0; j< b[i].size(); ++j)
        {
            if(b[i][j]!=nullptr&&b[i][j]->getPlayerNumber()!=this->playerNumber&&b[i][j]->getHealth()>target)
            {
                target=b[i][j]->getHealth();
                temp.first.first=i;
                temp.first.second=j;
                temp.second=b[i][j];
            }
        }
    }

    temp.second->setHealth(temp.second->getHealth()+damage);
    if(temp.second->getHealth()<=0)
    {
        b[temp.first.first][temp.first.second]=nullptr;
    }
}