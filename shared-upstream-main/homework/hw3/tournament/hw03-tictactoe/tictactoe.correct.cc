#include "tictactoe.h"
#include <array>
#include <iostream>
#include <sstream>

std::string TicTacToe::GetIndex(int row, int col) const
{
    return this->board.at(row * 3 + col);
}

bool TicTacToe::MakeMove(std::string playerToMove, int row, int col)
{
    if ( ! (0 <= row && row < 3 && 0 <= col && col < 3))
    {
        return false; // out of bounds
    }

    if (nextPlayerToMove != playerToMove)
    {
        return false; // player is not allowed to move
    }

    // index into board
    int boardIdx = row * 3 + col;
    auto &boardSpot = this->board.at(boardIdx);
    if (boardSpot != "-")
    {
        return false; // someone is already in that spot on the board
    }

    boardSpot = playerToMove;

    // set up player for next turn
    if (playerToMove == "X")
    {
        nextPlayerToMove = "O";
    }
    else if (playerToMove == "O")
    {
        nextPlayerToMove = "X";
    }
    else
    {
        return false;
    }
    return true;
}

std::string TicTacToe::CheckWinner() const
{
    std::array<std::array<std::string, 3>, 8> winningArrangements = {
        // check rows (3)
        std::array<std::string, 3>{GetIndex(0, 0), GetIndex(1, 0), GetIndex(2, 0)},
        {GetIndex(0, 1), GetIndex(1, 1), GetIndex(2, 1)},
        {GetIndex(0, 2), GetIndex(1, 2), GetIndex(2, 2)},

        // check cols (3)
        {GetIndex(0, 0), GetIndex(0, 1), GetIndex(0, 2)},
        {GetIndex(1, 0), GetIndex(1, 1), GetIndex(1, 2)},
        {GetIndex(2, 0), GetIndex(2, 1), GetIndex(2, 2)},

        // check diagonals (2)
        {GetIndex(0, 0), GetIndex(1, 1), GetIndex(2, 2)},
        {GetIndex(0, 2), GetIndex(1, 1), GetIndex(2, 0)}};

    // if a player has 3 in a row, then return X or O appropriately
    for (const auto &arrangement : winningArrangements)
    {
        if (
            arrangement[0] != "-" // not empty
            && arrangement[0] == arrangement[1] && arrangement[1] == arrangement[2])
        {
            return arrangement[0];
        }
    }

    if (CountEmptySpaces() == 0)
    {
        // indicates tie
        return "-";
    }
    else
    {
        // indicates no winner yet
        return "";
    }
}

void TicTacToe::Restart()
{
    for (int i = 0; i < board.size(); i++)
    {
        board.at(i) = "-";
    }
    nextPlayerToMove = "X";
}

int TicTacToe::CountEmptySpaces() const
{
    int count = 0;

    for (int i = 0; i < board.size(); i++)
    {
        if (board.at(i) == "-")
        {
            count += 1;
        }
    }

    return count;
}

std::string TicTacToe::GetBoardAsString() const {
    std::stringstream ret;
    for (int row = 0; row <= 2; row++) {
        ret << GetIndex(row, 0) << " " << GetIndex(row, 1) << " " << GetIndex(row, 2) << std::endl;
    }

    return ret.str();
}

