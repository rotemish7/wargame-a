//
// Created by rotem levy on 27/05/2020.
//

#include "Board.hpp"

namespace WarGame
{

    Soldier*& Board::operator[](std::pair<int, int> location)
    {
        return board[location.first][location.second];
    }

    Soldier* Board::operator[](std::pair<int, int> location) const
    {
        return board[location.first][location.second];
    }

    void Board::move(uint player_number, std::pair<int, int> source, WarGame::Board::MoveDIR direction)
    {
        Soldier* soldier = (*this)[source];

        if(soldier==nullptr||soldier->getPlayer_number()!=player_number)
        {
            throw invalid_argument("No soldier available");

        }

        pair<int, int> move;
        switch(direction)
        {
            case Up:
            {
                move=make_pair(source.first+1,source.second);break;
            }
            case Down:
            {
                move=make_pair(source.first-1,source.second);break;
            }
            case Left:
            {
                move=make_pair(source.first,source.second-1);break;
            }
            case Right:
            {
                move=make_pair(source.first,source.second+1);break;
            }
            default:
            {
                throw invalid_argument("Not a valid move");
            }
        }

        if(move.first>board.size()-1||move.second>board.size()-1||move.first<0||move.second<0)
        {
            throw invalid_argument("Exited board limits ");
        }

        if((*this)[move] != nullptr)
        {
            throw runtime_error("place already taken by another player\n");
        }

        board[source.first][source.second]=nullptr;
        board[move.first][move.second]=soldier;
        soldier->attack(board,move);
    }

    bool Board::has_soldiers(uint player_number) const
    {
        for (int i=0;i<board.size();i++)
        {
            for(int j=0;i<board[0].size();j++)
            {
                if(board[i][j]->getPlayer_number()==player_number)
                {
                    return true;
                }
            }
        }
        return false;
    }
}
