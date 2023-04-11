#include "gtest/gtest.h"
#include "tictactoe.h"

class TicTacToeTest : public ::testing::Test
{
public:
    void SetUp()
    {
        // code here will execute just before the test ensues
        board = new TicTacToe();
    }
    void TearDown()
    {
        delete board;
    }

protected:
    TicTacToe *board;
};
