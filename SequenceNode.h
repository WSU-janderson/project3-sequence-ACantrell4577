//
// Created by avery on 10/13/2025.
//

#ifndef SEQUENCE_SEQUENCENODE_H
#define SEQUENCE_SEQUENCENODE_H

#include <string>

using namespace std;

class SequenceNode {

    //variable declaration
private:


public:
    SequenceNode* next;
    SequenceNode* prev;
    string item;
    //default constructor
    SequenceNode() : next(nullptr), prev(nullptr), item(""){};

    //overloaded constructor
    SequenceNode(string item) :next(nullptr), prev(nullptr), item(item){};

};


#endif //SEQUENCE_SEQUENCENODE_H