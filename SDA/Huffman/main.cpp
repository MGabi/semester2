#include <fstream>
#include <string>
#include <queue>
#include <iostream>
#include <cassert>
#include <algorithm>
#include "headers/BinaryTree.h"
#include "headers/PriorityQueue.h"

#define MAX_CHAR 256
#define IN_FILE "../input_file.txt"
#define OUT_FILE "../output_huffman.txt"

using std::string;
using std::vector;

void testPQ();
void testBT();

void readFile(string &fileC);
void makeFrequencies(const string &str, int *freq);
void generateHuffmanCodes(TNode *root, const string &str);
TNode * generateHuffmanTree(const string &str, PriorityQueue *pq);
void printEncoded(const string &str, BinaryTree * bt);
void decodeFromTree(string encodedMessage, BinaryTree *bt);
void iterateOverTree(BinaryTree *bt);

std::ifstream fin(IN_FILE);
std::ofstream fout(OUT_FILE);

string encodings[MAX_CHAR];
string fileContent;
int freq[MAX_CHAR];

void readFile(string &fileC){
    string read;
    if(fin.is_open()){
        while(!fin.eof()){
            std::getline(fin, read);
            fileC += read;
        }
    }
}

TNode * generateHuffmanTree(const string &str, PriorityQueue *pq){
    makeFrequencies(str, freq);
    BinaryTree *bt;
    for(int i = 0; i<256; i++){
        if(freq[i] != 0){
            bt = new BinaryTree();
            bt->initLeaf(new TInfo(char(i), freq[i]));
            pq->push(bt);
        }
    }
    auto newBt = new BinaryTree();
    while(pq->size() != 1){
        auto left = pq->top();
        pq->pop();
        auto right = pq->top();
        pq->pop();
        newBt = new BinaryTree();

        newBt->initTree(new TInfo('$', left->root()->freq + right->root()->freq),
                        left,
                        right);
        pq->push(newBt);
    }
    generateHuffmanCodes(pq->top()->rootNode, "");
    return pq->top()->rootNode;
}

void makeFrequencies(const string &str, int *freq){
    for(int i=0; i<256; i++){
        encodings[i] = "";
        freq[i] = 0;
    }
    for(const auto& chr : str){
        freq[int(chr)] ++;
    }
}

void generateHuffmanCodes(TNode *root, const string &str){
    if(!root)
        return;

    if(root->info->data != '$'){
        encodings[root->info->data] = str;
    }

    generateHuffmanCodes(root->left, str + '0');
    generateHuffmanCodes(root->right, str + '1');
}

void printEncoded(const string &str, BinaryTree * bt) {
    fout << ">>> Letter encoding of '" << str << '\'' << std::endl;
    for(int i=0; i<MAX_CHAR; i++){
        if(!encodings[i].empty()){
            fout << (char)i << ": " << encodings[i] << std::endl;
        }
    }

    fout << "\n>>> Original message:\n" << str << std::endl;

    fout << "\n>>> Encoded message:\n";

    string encoded = "";
    for(const auto& ch : str){
        encoded += encodings[(int)ch];
        fout << encodings[(int)ch];
    }
    decodeFromTree(encoded, bt);
}

void decodeFromTree(string encodedMessage, BinaryTree *bt) {
    fout << "\n\n>>> Decoded message:\n";
    TNode* node = bt->rootNode;
    for (char ch : encodedMessage) {
        if(ch == '0')
            node = node->left;
        else
            node = node->right;
        if (node->info->data != '$') {
            fout << node->info->data;
            node = bt->rootNode;
        }
    }
}

void iterateOverTree(BinaryTree *bt) {
    PreorderIterator iterator = bt->iterator();
    while(iterator.valid()){
        printf("char: %c freq: %d\n", iterator.getCurrent()->data, iterator.getCurrent()->freq);
        iterator.next();
    }
}

int main(){
    testBT();
    testPQ();

    auto *p_queue = new PriorityQueue();
    readFile(fileContent);
    auto * bt = new BinaryTree();
    bt->rootNode = generateHuffmanTree(fileContent, p_queue);
    //iterateOverTree(bt);
    printEncoded(fileContent, bt);
    free(p_queue);
    free(bt);
    std::cout << "\nEncoding / decoding was successful!\n";
    return 0;
}

void testBT() {
    auto *bt = new BinaryTree();

    assert(bt->isEmpty());

    bt->initLeaf(new TInfo('!', 3));
    assert(bt->root()->data == '!' && bt->root()->freq == 3);
    assert(!bt->isEmpty());
    free(bt);

    bt = new BinaryTree(new TNode(new TInfo('$', 2)));
    assert(bt->root()->freq == 2 && bt->root()->data == '$');

    bt->insertLeftSubtree(new BinaryTree(new TNode(new TInfo('#', 5))));
    assert(bt->left()->info->freq == 5 && bt->left()->info->data == '#');

    bt->insertRightSubtree(new BinaryTree(new TNode(new TInfo('#', 5))));
    assert(bt->right()->info->freq == 5 && bt->right()->info->data == '#');

    delete(bt);

    bt = new BinaryTree();
    bt->initTree(new TInfo('@', 3), new BinaryTree(), new BinaryTree());
    assert(bt->left() != nullptr);
    assert(bt->right() != nullptr);

    bt->insertLeftSubtree(new BinaryTree(new TNode(new TInfo('#', 5))));

    bt->insertRightSubtree(new BinaryTree(new TNode(new TInfo('^', 7))));

    PreorderIterator iterator = bt->iterator();
    assert(iterator.getCurrent()->data == '@');
    iterator.next();
    assert(iterator.getCurrent()->data == '#');
    iterator.next();
    assert(iterator.getCurrent()->data == '^');

    delete(bt);
    std::cout << "ALL TESTS PASSED FOR PQ !" << std::endl;
}

void testPQ() {
    auto *pq = new PriorityQueue();
    srand((unsigned int)time(nullptr));
    assert(pq->isEmpty());

    pq->push(new BinaryTree(new TNode(new TInfo((char)('a'), 5))));
    assert(pq->top()->root()->data == 'a');
    assert(pq->top()->root()->freq == 5);

    assert(!pq->isEmpty());

    pq->push(new BinaryTree(new TNode(new TInfo((char)('b'), 4))));
    assert(pq->top()->root()->data == 'b');
    assert(pq->top()->root()->freq == 4);

    pq->pop();

    assert(pq->top()->root()->data == 'a');
    assert(pq->top()->root()->freq == 5);

    for(int i=0; i<20; i++){
        pq->push(new BinaryTree(new TNode(new TInfo('c'+i, i))));
    }

    assert(pq->top()->root()->data == 'c');
    assert(pq->top()->root()->freq == 0);

    delete(pq);
    std::cout << "ALL TESTS PASSED FOR PQ !" << std::endl;
}
