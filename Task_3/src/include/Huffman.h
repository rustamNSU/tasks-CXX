///////////////////////////////////////////////////////////
// C++ course, Abdullin Rustam, task 3
// email: afaritovich@mail.ru
///////////////////////////////////////////////////////////

#pragma once
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#define Char_size 256


using std::map;
using std::string;
using std::vector;

struct HuffmanNode{

    vector<char> id;
    int weight;
};

struct huffman_node
{
    char id;
    int weight;
    huffman_node *left;
    huffman_node *right;
    huffman_node()
    {
        left = NULL;
        right = NULL;
    }
    huffman_node(
        char id_,
        huffman_node *l=NULL, 
        huffman_node *r=NULL)
    {
        left = l;
        right = r;
        id = id_;
    }
};

/**
 * Huffman coding
 */
class Huffman{

    private:

        // To use table for encode operation
        map< char, vector<char>> Table;                    ///< Table of huffman code for the character
        huffman_node * Tree = new huffman_node;            ///< Huffman tree
        int correct_byte;                                  ///< Number of rest bits
        int length_code;
    
    public:
    
        /* Constructors */
        Huffman() = default;

        /* Methods */
        /* To count all symbols in input file */
        map<char,int> fill_chars(std::ifstream& input);
        void fill_table(std::ifstream& input);

        vector<HuffmanNode> sort_symbols(map<char,int> symbols);

        void generate_table(huffman_node *root, vector<char>& char_code);
        void fill_table();
        
        /* Coding input file */
        void encode(std::ifstream& input, std::ofstream& out);
        void decode(std::ifstream& input, std::ofstream& out);

        void print_table(std::ofstream& out);

        void save_tree(std::ofstream& out);
        void save_tree(std::ofstream& out, huffman_node *root);

        void read_tree(std::ifstream& input);
        huffman_node* make_tree(std::ifstream& input);

        /* Destructor */
        ~Huffman() = default;

};