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

using std::map;
using std::string;


/************************************************ *//**
 * 
 * ********************************************** */
class WordCount{

  private:

    map<string,int> words;
    int numbersOfWords;
    char* delimiters = new char[20]{' ', ',', '.', ';', ':', '-', '?', '!', '(', ')', '/', '=', '+', '\n', '`', '%'};

  public:
    
    /* Constructors */
    WordCount() = default;

    /* Methods */

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
    void insert_word(const string key);

    /* Destructor */
    ~WordCount() = default;

};