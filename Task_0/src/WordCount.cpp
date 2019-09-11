#include "WordCount.h"

WordCount::WordCount(const vector<char> user_delimiters){

    delimiters = user_delimiters;

}

/*
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
void WordCount::InsertWord(const string key){

    words[key]++;
    numbersOfWords++;

}

/**
 * This function count words in text
 * and save them in associative container
 * < word -> numbers this word in text >
 * 
 * For define words is using special
 * symbols - delimiters
 */
void WordCount::FillWords(const std::ifstream& text){

    
}