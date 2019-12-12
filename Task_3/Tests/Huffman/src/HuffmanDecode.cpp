#include "Huffman.h"
#include <ctime>

int main(int argc, char** argv){

    std::ifstream input(argv[1]);
    std::ofstream output(argv[2]);
    std::ifstream tree(argv[3]);

    Huffman huffman;
    huffman.read_tree(tree);
    huffman.decode(input, output);
    return 0;

}