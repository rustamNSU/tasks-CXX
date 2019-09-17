#include "WordCount.h"
#include "WordCountTest.hpp"

#include <ctime>

int main(int argc, char** argv){

    std::ifstream input(argv[1]);
    std::ofstream output(argv[2]);

    WordCount dic;
    dic.FillWords(input);
    dic.GenerateCSV(output);
    
    return 0;

}