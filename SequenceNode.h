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
    SequenceNode() : next(nullptr), prev(nullptr), item("") {};

    //overloaded constructor
    SequenceNode(string item) :next(nullptr), prev(nullptr), item(item){};

    //setters and getters
    SequenceNode* get_Next() const;
    SequenceNode* get_Prev() const;
    string &get_Item();
    void set_Next(SequenceNode* next);
    void set_Prev(SequenceNode* prev);
    void set_Item(string item);
};


#endif //SEQUENCE_SEQUENCENODE_H