#include "Sequence.h"
#include <exception>
#include <iostream>

using namespace std;

//constructor
Sequence::Sequence(size_t sz) {
    element = new size_t[sz];
    this->sequenceSize = sz;
    this->head = nullptr;
    this->tail = nullptr;
}

//creates deep copy os sequence s
Sequence::Sequence(const Sequence &s) {

    //dynamically allocates memory
    this->element = new size_t;

    //copies the provided sequence
    this->head = s.head;
    this->tail = s.tail;
    *(this->element) = *(s.element);

}

//destructor
Sequence::~Sequence() {
    delete[] this->element;
}

//creates a deep copy and returns a reference
Sequence& Sequence:: operator=(const Sequence &s) {

    //if they arnt already euqal
    if (this !=  &s) {
        //destruct
        this->~Sequence();

        //create deep copy
        this->element = new size_t;
        this->head = s.head;
        this->tail = s.tail;
        *(this->element) = *(s.element);
    }

    //return the reference to sequence object
    return *this;
}

//returns the item inside the sequence's node at position
string &Sequence::operator[](size_t position) {

    //if position is in scope
    if (position < this->size() && position >= 0) {

        //creates a temp node to iterate through the sequence
        SequenceNode* currentNode = this->head;
        for (int i = 0; i < position; i++) {

            //currentNode is set to the next node
            currentNode=currentNode->get_Next();

        }

        //returns the item of the specified position node
        return currentNode->get_Item();

    }
    //if the position is out of bounds throw an exception
    else {
        throw exception();
    }

}

void Sequence::push_back(string item) {

    //end node represents the tail
    SequenceNode* endNode = this->tail;

    //Creates the new node
    SequenceNode* newNode = new SequenceNode(item);

    //sets the address of the new node to the next value of the previous tail
    endNode->set_Next(newNode);

    //Sets the prev value of the new tail to the previous node
    newNode->set_Prev(endNode);

    //sets the new tail
    this->tail = newNode;

    //increases the sequence size
    sequenceSize++;

}

void Sequence::pop_back() {

    //sets the tail as the temp node
    SequenceNode* endNode = this->tail;

    //sets another temp node to what will be the new tail
    SequenceNode* newTail = endNode->get_Prev();

    //sets the new tail for the sequence
    this->tail = newTail;
    newTail->set_Next(nullptr);

    //deallocates the old node
    delete endNode;

    //decrements the sequence size
    this->sequenceSize--;

}

void Sequence::insert(size_t position, string item) {


    //if position is in scope
    if (position < this->size() && position >= 0) {

        //creates a temp node to iterate through the sequence
        SequenceNode* currentNode = this->head;
        for (int i = 0; i < position; i++) {

            //currentNode is set to the next node
            currentNode=currentNode->get_Next();

        }

            //creates new node
            SequenceNode* newNode = new SequenceNode(item);

            //if the current node is the tail
            if (currentNode->get_Next() != nullptr) {

                //creates a temp reference node
                SequenceNode* pushedNode = currentNode->get_Next();

                //inserts the new node by changing old next and prev
                currentNode->set_Next(newNode);
                pushedNode->set_Prev(newNode);

                //news new next and prev
                newNode->set_Prev(currentNode);
                newNode->set_Next(pushedNode);
            }

    }
    //if the position is out of bounds throw an exception
    else {
        throw exception();
    }
}

string Sequence::front() const {

}

string Sequence::back() const {

}

bool Sequence::empty() const {

}

size_t Sequence::size() const {

    return sequenceSize;

}

void Sequence::clear() {

}

void Sequence::erase(size_t position) {

}

void Sequence::erase(size_t position, size_t count) {

}


