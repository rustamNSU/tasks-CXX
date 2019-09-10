#include "WordCount.h"

/************************************************
 * Inserting key in "words".
 * 
 * If key matches the word in the container,
 * the function increase a number of this
 * word by 1.
 * 
 * If key does not match  the word in the
 * container, the function make a number of
 * this word by 1.
 * ********************************************** */
void WordCount::insert_word(const string key){

    words[key]++;
    numbersOfWords++;
}