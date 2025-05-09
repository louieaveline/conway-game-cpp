#include "src/GameOfLife.hpp"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>

void printHelp()
{
    std::cout << "\nUsage:\n";
    std::cout << "  <rows> <cols> <pattern>\n";
    std::cout << "\nPatterns:\n";
    std::cout << "  glider, lwss, blinker, toad, beacon, pulsar, pentadecathlon, block, boat, tub\n";
    std::cout << "\n\n";
    std::cout << "";
    std::cout << "\nExamples:\n";
    std::cout << "  20 40 glider\n";
    std::cout << "  30 60 lwss\n";
    std::cout << "\n";
}

int main()
{
    std::string inputLine, patternName;
    int rows = 0, cols = 0;

    while (true)
    {
        std::cout << "Enter: <rows> <cols> <pattern> or 'help': ";
        std::getline(std::cin, inputLine);

        if (inputLine == "help")
        {
            printHelp();
            continue;
        }

        std::istringstream iss(inputLine);
        iss >> rows >> cols >> patternName;
        if (rows <= 0 || cols <= 0)
        {
            std::cout << "Invalid dimensions. Try again.\n";
            continue;
        }
        break;
    }

    GameOfLife game(rows, cols);

    std::map<std::string, std::vector<std::string>> patterns = {
        {"glider", {"010", "001", "111"}},
        {"lwss", {"00110", "10001", "00001", "10010"}},
        {"blinker", {"111"}},
        {"toad", {"000", "111", "111", "000"}},
        {"beacon", {"11", "11", "00", "11"}},
        {"pulsar", {"000000000000000", "000001110000000", "000000000000000", "000011101110000", "000010000010000", "000011101110000", "000000000000000", "000001110000000", "000000000000000"}},
        {"pentadecathlon", {"00100", "00100", "11111", "00100", "00100", "00100", "11111", "00100", "00100"}},
        {"block", {"11", "11"}},
        {"boat", {"11", "10", "01"}},
        {"tub", {"010", "101", "010"}}};

    if (patterns.count(patternName))
    {
        game.initializeFromPattern(patterns[patternName]);
    }
    else
    {
        game.initializeRandom();
    }

    int generation = 0;
    while (true)
    {
        game.printBoard(generation++);
        game.nextGeneration();
    }

    return 0;
}
