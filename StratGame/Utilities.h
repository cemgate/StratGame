#pragma once
#include <iostream>
#include <random>
#include <Windows.h>

class Utilities 
{
public:
    static int getRandomNumberFromRange(int minValue, int maxValue) 
    {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(minValue, maxValue);

        return distrib(gen);
    }

    static void printColoredMap(const std::vector<std::vector<char>>& map)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        for (const auto& row : map) {
            for (const auto& cell : row) 
            {
                if (cell == '.') {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN); // Br¹zowy kolor
                    std::cout << cell;
                }
                else if (cell == 'X') 
                {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Bia³y kolor
                    std::cout << cell;
                }
                else if (cell == 'O') 
                {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE); // Niebieski kolor
                    std::cout << cell;
                }
                else if (cell == 'W') {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); // Zielony kolor
                    std::cout << cell;
                }
                else if (cell == '1' || cell == '2') 
                {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE); // Ró¿owy kolor
                    std::cout << cell;
                }
                else if (cell == '#')
                {
                    SetConsoleTextAttribute(hConsole, 12);
                    std::cout << cell;
                }
            }
            std::cout << std::endl; // Nowa linia po ka¿dym wierszu
        }

        // Przywróæ domyœlny kolor
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
};

