#ifndef TICTACTOE_H__
#define TICTACTOE_H__

#include <vector>
#include <string>

/**
 * @brief Class that represents the state of a tic-tac-toe game.
 * 
 */
class TicTacToe
{
private:
    std::string nextPlayerToMove;
    std::vector<std::string> board;

    std::string GetIndex(int row, int col) const;

public:
    TicTacToe() : board(9, "-"), nextPlayerToMove("X") {}
    TicTacToe(std::string firstToMove) : board(9, "-"), nextPlayerToMove(std::move(firstToMove)) {}

    /**
     * @brief Have a player make a move
     * 
     * @param playerToMove The player that is moving
     * @param row The row on the board that they should play
     * @param col The col on the board that they should play
     * @return true if the move was successful, false if it was illegal
     */
    bool MakeMove(std::string playerToMove, int row, int col);

    /**
     * @brief Check if a player has won yet
     * 
     * @return std::string One of 4 values:
     *  - `"X"` if X player won
     *  - `"O"` if O player won
     *  - `"-"` if players tied
     *  - `""` if the game has not concluded yet
     */
    std::string CheckWinner() const;

    /**
     * @brief Count the number of empty spaces on the board
     * 
     * @return int 
     */
    int CountEmptySpaces() const;

    /**
     * @brief Reset the board to play a new game
     */
    void Restart();

    /**
     * @brief Get the board as human-understandable string
     * 
     * @return std::string 
     */
    std::string GetBoardAsString() const;
};

#endif
