#include "GameOfLife.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#ifdef _WIN32
#include <windows.h>
#define CLEAR "cls"
#define SLEEP(ms) Sleep(ms)
#else
#include <unistd.h>
#define CLEAR "clear"
#define SLEEP(ms) usleep((ms) * 1000)
#endif

GameOfLife::GameOfLife(int rows, int cols) : rows(rows), cols(cols)
{
    allocateBoard();
    initializeRandom();
}

GameOfLife::~GameOfLife()
{
    deallocateBoard();
}

void GameOfLife::allocateBoard()
{
    board = new int *[rows];
    for (int i = 0; i < rows; ++i)
        board[i] = new int[cols]();
}

void GameOfLife::deallocateBoard()
{
    for (int i = 0; i < rows; ++i)
        delete[] board[i];
    delete[] board;
}

void GameOfLife::initializeRandom()
{
    srand(time(0));
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            board[i][j] = rand() % 2;
}

void GameOfLife::initializeFromPattern(const std::vector<std::string> &pattern)
{
    clearBoard();
    int startRow = rows / 2 - pattern.size() / 2;
    for (size_t i = 0; i < pattern.size(); ++i)
    {
        for (size_t j = 0; j < pattern[i].size(); ++j)
        {
            if (pattern[i][j] == '1')
                board[startRow + i][cols / 2 - pattern[i].size() / 2 + j] = 1;
        }
    }
}

int GameOfLife::countNeighbors(int x, int y) const
{
    int count = 0;
    for (int i = -1; i <= 1; ++i)
    {
        for (int j = -1; j <= 1; ++j)
        {
            if (i == 0 && j == 0)
                continue;
            int ni = (x + i + rows) % rows;
            int nj = (y + j + cols) % cols;
            count += board[ni][nj];
        }
    }
    return count;
}

void GameOfLife::copyBoard(int **src, int **dest)
{
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            dest[i][j] = src[i][j];
}

void GameOfLife::nextGeneration()
{
    int **newBoard = new int *[rows];
    for (int i = 0; i < rows; ++i)
        newBoard[i] = new int[cols]();

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            int neighbors = countNeighbors(i, j);
            if (board[i][j] == 1)
            {
                newBoard[i][j] = (neighbors == 2 || neighbors == 3) ? 1 : 0;
            }
            else
            {
                newBoard[i][j] = (neighbors == 3) ? 1 : 0;
            }
        }
    }

    copyBoard(newBoard, board);
    for (int i = 0; i < rows; ++i)
        delete[] newBoard[i];
    delete[] newBoard;
}

void GameOfLife::printBoard(int generation) const
{
    system(CLEAR);
    std::cout << "\033[1;36mGeneration: " << generation << "\033[0m" << std::endl;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (board[i][j])
            {
                std::cout << "#";
            }
            else
            {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    SLEEP(150);
}

void GameOfLife::clearBoard()
{
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            board[i][j] = 0;
}
