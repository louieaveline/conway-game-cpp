#ifndef GAMEOFLIFE_HPP
#define GAMEOFLIFE_HPP
#include <vector>
#include <string>

class GameOfLife
{
public:
    GameOfLife(int rows, int cols);
    ~GameOfLife();

    void initializeRandom();
    void initializeFromPattern(const std::vector<std::string> &pattern);
    void nextGeneration();
    void printBoard(int generation) const;

    void clearBoard();

private:
    int rows, cols;
    int **board;

    int countNeighbors(int x, int y) const;
    void allocateBoard();
    void deallocateBoard();
    void copyBoard(int **src, int **dest);
};

#endif
