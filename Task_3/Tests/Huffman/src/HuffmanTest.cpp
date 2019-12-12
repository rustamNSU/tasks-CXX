#include "Huffman.h"
#include "HuffmanTest.hpp"

int main(int argc, char** argv){

    std::ifstream input(argv[1]);
    std::ofstream output(argv[2]);
    std::ofstream tree(argv[3]);

    Huffman huffman;
    huffman.encode(input, output);
    huffman.save_tree(tree);
    
    return 0;

}