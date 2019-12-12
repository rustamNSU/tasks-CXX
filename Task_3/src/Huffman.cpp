#include "Huffman.h"

map<char,int> Huffman::fill_chars(std::ifstream& input)
{
    map<char,int> result;
    char id;
    input.get(id);
    while(!input.eof())
    {
        result[id]++;
        input.get(id);
    }
    input.clear();
    input.seekg(0);
    return result;
}


void Huffman::fill_table(std::ifstream& input)
{
    auto symbols = sort_symbols(fill_chars(input));
    vector<huffman_node*> road_to_tree(symbols.size());
    for(int i = 0; i<symbols.size(); ++i)
    {
        huffman_node* local = new huffman_node();
        local->id = symbols[i].id[0];
        local->weight = symbols[i].weight;
        road_to_tree[i] = local;
    }
    while(road_to_tree.size()>1)
    {

        huffman_node* local = new huffman_node();
        local->left = *(road_to_tree.end()-1);
        local->right= *(road_to_tree.end()-2);
        local->weight = (*(road_to_tree.end()-1))->weight + (*(road_to_tree.end()-2))->weight;
        road_to_tree.pop_back();
        road_to_tree.pop_back();
        road_to_tree.push_back(local);
        std::stable_sort(
            road_to_tree.begin(),
            road_to_tree.end(),
            [](const huffman_node* a, const huffman_node* b){
                return a->weight > b->weight;
            }
        );
    }
    Tree = *(road_to_tree.begin());
    fill_table(); 
}



vector<HuffmanNode> Huffman::sort_symbols(map<char,int> symbols)
{
    vector<HuffmanNode> result(symbols.size());
    {
        int i = 0;
        for(auto it = symbols.begin(); it != symbols.end(); ++it)
        {            
            result[i].id.push_back(it->first);
            result[i].weight = it->second;
            i++;
        }
    }
    std::stable_sort(
        result.begin(),
        result.end(),
        [](const HuffmanNode& a, const HuffmanNode& b){
            return a.weight > b.weight;
        }
    );   
    return result;
}

void Huffman::generate_table(huffman_node *root, vector<char>& char_code)
{
    if(root->left!=NULL)
    {
        char_code.push_back(0);
        generate_table(root->left, char_code);
    }
    if(root->right!=NULL)
    {
        char_code.push_back(1);
        generate_table(root->right, char_code);
    }
    if(root->id) Table[root->id] = char_code;

    char_code.pop_back();
}

void Huffman::fill_table()
{
    vector<char> char_code;
    generate_table(Tree, char_code);
}

void Huffman::print_table(std::ofstream& out)
{
    for(auto itr = Table.begin(); itr!= Table.end(); itr++)
    {
        if(itr->second.size()!=0)
        {
            out << itr->first << ",";
            for(auto it = itr->second.begin(); it != itr->second.end(); ++it)
            {            
                out << (int)(*it);
            }
            out << std::endl;
        }
    }
}

/* Coding input file */
void Huffman::encode(std::ifstream& input, std::ofstream& out)
{
    fill_table(input);

    char element;
    unsigned char buf = 0;           // Buffer
    int count_bit = 0;     // If count_bit = 8, then write buf in ofstream    

    int testIn = 0;
    int testOut = 0; 
    int bitOut = 0;   
    while(input.get(element))
    {
        vector<char> char_code = this->Table[element];
        for(int i = 0; i< char_code.size(); ++i)
        {
            buf = buf | char_code[i]<<(7-count_bit);
            count_bit++;
            bitOut++;
            if (count_bit == 8)
            {
                out << buf;
                count_bit = 0;
                buf = 0;
                testOut++;
            }
        }
        testIn++;
    }
    correct_byte = count_bit;
    length_code = testOut;
    std::cout << "***********************************" << std::endl 
              << "testIn = " << testIn << std::endl
              << "testOut = " << testOut << std::endl << std::endl
              << "bitIn = " << testIn*8 << std::endl
              << "bitOut = " << bitOut << std::endl
              << "***********************************" << std::endl;

    out << buf;
    out.close();
}

void Huffman::decode(std::ifstream& input, std::ofstream& out)
{
    huffman_node* ptr = Tree;
    int count_bit = 0;
    char byte;
    input.get(byte);
    int testIn = 0;
    while(!input.eof())
    {
        // get 1 bit from byte
        bool bit = byte & (1<<(7-count_bit));
        if(bit){
            ptr = ptr->right;
        }
        else{
            ptr = ptr->left;
        }

        // check end of Tree
        if(ptr->left==NULL && ptr->right==NULL){
            out << ptr->id;
            ptr = Tree;
        }

        count_bit++;
        if(count_bit == 8){
            count_bit = 0;
            input.get(byte);
            testIn++;
            if(testIn == length_code)
            {
                break;
            }
        }
    }
    for(int i = 0; i<correct_byte; i++)
    {
        bool bit = byte & (1<<(7-count_bit));
        if(bit){
            ptr = ptr->right;
        }
        else{
            ptr = ptr->left;
        }

        // check end of Tree
        if(ptr->left==NULL && ptr->right==NULL){
            out << ptr->id;
            ptr = Tree;
        }
        count_bit++;
    }
    input.close();
}

void Huffman::save_tree(std::ofstream& out)
{
    save_tree(out,Tree);
    out << correct_byte;
    out << ' ';
    out << length_code;
}

void Huffman::save_tree(
    std::ofstream& out, 
    huffman_node *root)
{
    // Leaf
    if( root->left==NULL && root->right==NULL)
    {
        out << '1' << root->id;
    }
    else{
        out << '0';
        save_tree(out, root->left);
        save_tree(out, root->right);
    }
}

void Huffman::read_tree(std::ifstream& input)
{
    Tree = make_tree(input);
    input >> correct_byte;
    input >> length_code;
}

huffman_node* Huffman::make_tree(std::ifstream& input)
{
    char id;
    input.get(id);
    if(id=='1')
    {
        input.get(id);
        return (new huffman_node(id));
    }
    else
    {
        huffman_node *left = make_tree(input);
        huffman_node *right = make_tree(input);
        return (new huffman_node(0,left, right));
    }    
}
