#include "WordCount.h"
#include "WordCountTest.hpp"

#include <ctime>

int main(int argc, char** argv){

    std::ifstream input(argv[1]);
    std::ofstream output(argv[2]);

    WordCount dic;
    clock_t time_start = clock();
    dic.FillWords(input);
    dic.GenerateCSV(output);
    clock_t time = clock() - time_start;
    std::cout << "time = " << time / 1000000.0 << std::endl;
    
    return 0;

}