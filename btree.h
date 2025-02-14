//
// Created by ricardofachini on 11/02/25.
//

#ifndef BTREE_H
#define BTREE_H
#include <string>
#include <vector>

struct BTreePage;


typedef struct {
    BTreePage* left;
    float value;
    BTreePage* right;
} BTreeKey;

struct BTreePage {
    std::pmr::vector<BTreeKey>* elements;
    short int num_keys;
};



class BTree {
    public:
        std::string name;
        BTreePage* pages;
};

#endif //BTREE_H
