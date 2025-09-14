#include <iostream>
#include <string>
#include <cmath>
#include <chrono>
#include <thread>
#include <cstdint>

const int LOWEST = 65;
const int RANGE = 25;

// char get_a_char(){ return static_cast<char>(LOWEST + std::rand() % RANGE); }

int main(int argc, char* argv[]){
    // std::srand(time(0));

    int loop_times = -1;
    if (argc == 1)
        loop_times = 10;
    else if (argc>2) {
        std::cerr << "It takes one or zero arguments!\n";
        return 1;
    }
    else
        loop_times = std::stoi(argv[1]);
    

    // bitmap of the numbers
    size_t digit[11][8] = {
        {0b11111100,0b11001100,0b11001100,0b11001100,0b11111100}, // 0
        {0b00001100,0b00001100,0b00001100,0b00001100,0b00001100}, // 1
        {0b11111100,0b00001100,0b11111100,0b11000000,0b11111100}, // 2
        {0b11111100,0b00001100,0b11111100,0b00001100,0b11111100}, // 3
        {0b11001100,0b11001100,0b11111100,0b00001100,0b00001100}, // 4
        {0b11111100,0b11000000,0b11111100,0b00001100,0b11111100}, // 5
        {0b11111100,0b11000000,0b11111100,0b11001100,0b11111100}, // 6
        {0b11111100,0b00001100,0b00110000,0b00110000,0b00110000}, // 7
        {0b11111100,0b11001100,0b11111100,0b11001100,0b11111100}, // 8
        {0b11111100,0b11001100,0b11111100,0b00001100,0b11111100}, // 9
        {0b00000000,0b00000000,0b00110000,0b00000000,0b00000000}  // -
    };

    
    size_t hour_digit_1,hour_digit_2,minute_digit_1,minute_digit_2,second_digit_1,second_digit_2;
    const size_t colon_index = 10;
    
    for(int c=0;c<loop_times;c++){
        auto now = std::chrono::system_clock::now();
        auto timer = std::chrono::system_clock::to_time_t(now);
        std::tm bt = *std::localtime(&timer);

        hour_digit_1   = static_cast<size_t>(bt.tm_hour/10);
        hour_digit_2   = bt.tm_hour%10;
        minute_digit_1 = static_cast<size_t>(bt.tm_min/10);
        minute_digit_2 = bt.tm_min%10;
        second_digit_1 = static_cast<size_t>(bt.tm_sec/10);
        second_digit_2 = bt.tm_sec%10;

        size_t current_time[8] = {
            hour_digit_1,hour_digit_2,
            colon_index,
            minute_digit_1,minute_digit_2,
            colon_index,
            second_digit_1, second_digit_2
        };

        for(int row=0;row<5;row++)
        {
            for(size_t const &d: current_time){
                for(size_t i=8; i>0; i--)
                {
                    if ( (digit[d][row] & (1 << (i-1))  ) != 0)
                        std::cout<<'&'; // alternativelly get_a_char()
                    else
                        std::cout<<' ';
                }
            }
            std::cout<<'\n';
        }

        // clear the screen, i.e., the 5 previous lines
        for(int8_t i=0; i<5; i++)
            std::cout << "\033[1A\033[2K";

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}