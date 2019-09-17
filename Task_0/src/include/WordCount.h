///////////////////////////////////////////////////////////
// C++ course, Abdullin Rustam, task 0
// email: afaritovich@mail.ru
///////////////////////////////////////////////////////////

#pragma once
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ostream>
#include <sstream>
#include <iostream>
#include <algorithm>

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
        // vector<char> delimiters = vector<char>
        // {',', '.', '?', '!', ';', ':', '-',
        //  '(', ')', '/', '=', '+', '`', '%', '"',
        //  '*', '^', '#', '@', '{', '}', '<', '>', '~', '[', ']'};

    public:
    
        /* Constructors */
        WordCount() = default;

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
         * and saves them in associative container
         * < word -> numbers this word in text >
         * 
         * For defines words is using special
         * symbols - delimiters
         */
        void FillWords(std::ifstream& text);

        /**
         * This function transform string to word:
         * 
         * - drops all special symbols (delimiters)
         * - replaces large letters with small
         * 
         * ex. "abCDeFg`h" -> abcdefgh
         */
        string TransformString(const string str);

        /**
         * This function order words by frequency
         * of occurrence in the text
         * 
         * Returns a collection of index vectors
         * for any of the previous syntaxes
         */
        vector<std::pair<int,string>> SortByValues();

        /**
         * This function generate csv format files
         * by map of words
         */
        void GenerateCSV(std::ofstream& out, char delimiter = ',');

        /* Destructor */
        ~WordCount() = default;

};