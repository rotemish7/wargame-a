//
// Created by rotem levy on 27/05/2020.
//

#include "FootCommander.hpp"
#include "FootSoldier.hpp"

using namespace std;

void FootCommander::attack(vector<vector<Soldier*>> &b, pair<int,int> location)
{
    int row = location.first;
    int col = location.second;
    Soldier* temp;

    b[row][col]->attack(b, location);
    for(int i = 0; i < b.size(); ++i)
    {
        for(int j = 0; j < b[i].size(); ++j)
        {
            temp = b[i][j];
            if(temp != nullptr && temp->getPlayer_number() == b[row][col]->getPlayer_number())
            {
                FootSoldier *fs=dynamic_cast<FootSoldier*>(temp);
                if(fs)
                {
                    pair<int,int> index = make_pair(i ,j);
                    temp->attack(b, index);
                }
            }
        }
    }
}