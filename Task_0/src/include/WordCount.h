///////////////////////////////////////////////////////////
// C++ course, Abdullin Rustam, task 0
// email: afaritovich@mail.ru
//
// Lecturer: 
// Instructor: antsys_nsu@mail.ru
///////////////////////////////////////////////////////////

#pragma once
#include <string>
#include <map>
#include <vector>
#include <fstream>

using std::map;
using std::string;
using std::vector;


/**
 * 
 */
class WordCount{

    private:

        map<string,int> words;
        int numbersOfWords;
        vector<char> delimiters = vector<char>
        {' ', ',', '.', '?', '\n', '!', ';', ':', '-',
         '(', ')', '/', '=', '+', '\n', '`', '%', '"',
         '*', '^', '#', '@', '{', '}', '<', '>', '~', '[', ']'};

    public:
    
        /* Constructors */
        WordCount() = default;
        WordCount(const vector<char> user_delimiters);

        /* Methods */

        /**
         * Inserting key in "words".
         * 
         * If key matches the word in the container,
         * the function increase a number of this
         * word by 1.
         * 
         * If key does not match  the word in the
         * container, the function make a number of
         * this word by 1.
         */
        void InsertWord(const string key);

        /**
         * This function count words in text
         * and save them in associative container
         * < word -> numbers this word in text >
         * 
         * For define words is using special
         * symbols - delimiters
         */
        void FillWords(const std::ifstream& text);



        /* Destructor */
        ~WordCount() = default;

};

namespace Word