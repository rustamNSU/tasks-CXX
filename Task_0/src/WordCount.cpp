#include "WordCount.h"

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
 * and saves them in associative container
 * < word -> numbers this word in text >
 * 
 * For defines words is using special
 * symbols - delimiters
 */
void WordCount::FillWords(std::ifstream& text){

    if (!text.good()){
        std::cout << "File can not be opened" << std::endl;
        return;
    }
    
    string str;
    while(getline(text, str)) 
    {
        
        std::istringstream iss(str);
        string word;
        while(iss >> word)
        {
            word = TransformString(word);
            if(word.size() > 0){
                this->InsertWord(word);
            }
        }

    }
}

/**
 * This function transform string to word:
 * 
 * - drops all special symbols (delimiters)
 * - replaces large letters with small
 * 
 * ex. "abCDeFg`h" -> abcdefgh
 */
inline string WordCount::TransformString(const string str){

    string word;
    for( std::string::const_iterator it = str.begin(); it!=str.end(); it++ ){
        
        if((*it >= 'a') && (*it <= 'z')){
            word.push_back(*it);
            continue;
        }

        // transform 'A' - 'Z' -> 'a' - 'z'
        else if((*it >= 'A') && (*it <= 'Z')){
            word.push_back(*it + (char)32);
            continue;
        }
        //

    }
    return word;
}

/**
 * This function order words by frequency
 * of occurrence in the text
 * 
 * Returns a collection of index vectors
 * for any of the previous syntaxes
 */
vector<std::pair<int,string>> WordCount::SortByValues(){

    vector<std::pair<int,string>> result( this->words.size());
    
    // Generating array of pair < value, index in map of words >
    {
        int i = 0;
        for(auto it = words.begin(); it != words.end(); ++it) {
            
            result[i].first  = it->second;
            result[i].second = it->first;
            i++;

        }
    }
    std::stable_sort(result.begin(), result.end(),
        [](const std::pair<int,string>& a, const std::pair<int,string>& b){
            return a.first > b.first;
        });
    
    return result;

}

/**
 * This function generate csv format files
 * by map of words
 */
void WordCount::GenerateCSV(std::ofstream& out, char delimiter){

    auto sorting_words = this->SortByValues();
    std::for_each(sorting_words.begin(), sorting_words.end(),
    [&](std::pair<int,string> &element) -> void{

        double frequency = element.first / (double)this->numbersOfWords * 100.0;
        out << element.second << delimiter << element.first << delimiter << frequency << '%' << std::endl;
        
    });
}