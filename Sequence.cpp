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

//
string &Sequence::operator[](size_t position) {

    //if position is in scope
    if (position < this->size() && position >= 0) {

        //creates a temp node to iterate through the sequence
        SequenceNode* currentNode = this->head;
        for (int i = 0; i < this->size(); i++) {

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

}

void Sequence::pop_back() {

}

void Sequence::insert(size_t position, string item) {

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


