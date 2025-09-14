#include <iostream>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
#include <chrono>
#include <ctime>

const int LOWEST = 65;
const int RANGE = 25;

char get_a_char(){
    return static_cast<char>(LOWEST + std::rand() % RANGE);
}


int main(){
    std::srand(time(0));
    size_t digit[11][8]; // row[digit][row]

    digit[0][0] = 0b11111100;
    digit[0][1] = 0b11001100;
    digit[0][2] = 0b11001100;
    digit[0][3] = 0b11001100;
    digit[0][4] = 0b11111100;

    digit[1][0] = 0b00001100;
    digit[1][1] = 0b00001100;
    digit[1][2] = 0b00001100;
    digit[1][3] = 0b00001100;
    digit[1][4] = 0b00001100;

    digit[2][0] = 0b11111100;
    digit[2][1] = 0b00001100;
    digit[2][2] = 0b11111100;
    digit[2][3] = 0b11000000;
    digit[2][4] = 0b11111100;

    digit[3][0] = 0b11111100;
    digit[3][1] = 0b00001100;
    digit[3][2] = 0b11111100;
    digit[3][3] = 0b00001100;
    digit[3][4] = 0b11111100;

    digit[4][0] = 0b11001100;
    digit[4][1] = 0b11001100;
    digit[4][2] = 0b11111100;
    digit[4][3] = 0b00001100;
    digit[4][4] = 0b00001100;

    digit[5][0] = 0b11111100;
    digit[5][1] = 0b11000000;
    digit[5][2] = 0b11111100;
    digit[5][3] = 0b00001100;
    digit[5][4] = 0b11111100;

    digit[6][0] = 0b11111100;
    digit[6][1] = 0b11000000;
    digit[6][2] = 0b11111100;
    digit[6][3] = 0b11001100;
    digit[6][4] = 0b11111100;

    digit[7][0] = 0b11111100;
    digit[7][1] = 0b00001100;
    digit[7][2] = 0b00110000;
    digit[7][3] = 0b00110000;
    digit[7][4] = 0b00110000;

    digit[8][0] = 0b11111100;
    digit[8][1] = 0b11001100;
    digit[8][2] = 0b11111100;
    digit[8][3] = 0b11001100;
    digit[8][4] = 0b11111100;

    digit[9][0] = 0b11111100;
    digit[9][1] = 0b11001100;
    digit[9][2] = 0b11111100;
    digit[9][3] = 0b00001100;
    digit[9][4] = 0b11111100;

    digit[10][0] = 0b00000000;
    digit[10][1] = 0b00000000;
    digit[10][2] = 0b00110000;
    digit[10][3] = 0b00000000;
    digit[10][4] = 0b00000000;

    
    size_t hour1,hour2,minute1,minute2,second1,second2; 
    
    for(size_t c=0;c<10;c++){
        auto now = std::chrono::system_clock::now();
        auto timer = std::chrono::system_clock::to_time_t(now);
        std::tm bt = *std::localtime(&timer);
        hour1   = static_cast<size_t>(bt.tm_hour/10) ;
        hour2   = bt.tm_hour%10;

        minute1 = static_cast<size_t>(bt.tm_min/10);
        minute2 = bt.tm_min%10;

        second1 = static_cast<size_t>(bt.tm_sec/10);
        second2 = bt.tm_sec%10;
        size_t current_time[8] = {hour1,hour2,10,minute1,minute2,10,second1, second2};
        for(size_t row=0;row<5;row++)
        {
            for(size_t const &d: current_time){
                for(size_t i=8; i>0; i--)
                {
                    if ( (   static_cast<size_t>(std::pow(2,i-1)) & digit[d][row]  ) != 0)
                    {
                        std::cout<<get_a_char();
                    }
                    else std::cout<<' ';
                }
            }
            std::cout<<'\n';
        }
        std::cout << "\033[1A\033[2K\033[1A\033[2K\033[1A\033[2K\033[1A\033[2K\033[1A\033[2K";
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    return 0;
}