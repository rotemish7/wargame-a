//
// Created by rotem levy on 27/05/2020.
//

#include "SniperCommander.hpp"
#include "Sniper.hpp"

using namespace std;

void SniperCommander::attack(vector<vector<Soldier*>> &b, pair<int,int> location)
{
    int x = location.first;
    int y = location.second;
    Soldier* s;
    Soldier* me = b[x][y];
    me->attack(b, location);
    for(int i = 0; i < b.size(); ++i)
    {
		for(int j = 0; j < b[i].size(); ++j)
        {
            s = b[i][j];
            if(s != nullptr && s->getPlayer_number() == me->getPlayer_number())
            {
		Sniper *sn=dynamic_cast<Sniper*>(tempSol); //if from my team and footSoldier
                if(sn)
		{
                	pair<int,int> index = make_pair(i ,j);
                	s->attack(b, index);
		}
            }
        }
    }
}
