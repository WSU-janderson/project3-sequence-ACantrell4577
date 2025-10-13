
#include "SequenceNode.h"

using namespace std;

//returns the stored data in the node
string SequenceNode::get_Item() const{
    return this->item;
}

//returns the pointer to the next node
SequenceNode* SequenceNode::get_Next() const{
    return this->next;
}

//returns the pointer to the previous node
SequenceNode* SequenceNode::get_Prev() const{
    return this->prev;
}

//sets the node's item as the passed variable
void SequenceNode::set_Item(string item) {
this->item = item;
}

//sets the pointer to the next node in the sequence
void SequenceNode::set_Next(SequenceNode* next) {
this->next = next;
}

//sets the pointer to the previous node in the sequence
void SequenceNode::set_Prev(SequenceNode* prev) {
    this->prev = prev;
}
