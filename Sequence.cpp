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
    this->sequenceSize = s.sequenceSize;
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
            currentNode = currentNode->next;

        }

        //returns the item of the specified position node
        return currentNode->item;

    }
    //if the position is out of bounds throw an exception
    else {
        throw exception();
    }

}

//ads item to end of sequence
void Sequence::push_back(string item) {

    //end node represents the tail
    SequenceNode* endNode = this->tail;

    //Creates the new node
    SequenceNode* newNode = new SequenceNode(item);

    //sets the address of the new node to the next value of the previous tail
    endNode->next = newNode;

    //Sets the prev value of the new tail to the previous node
    newNode->prev = endNode;

    //sets the new tail
    this->tail = newNode;

    //increases the sequence size
    sequenceSize++;

}

//removes from end of sequence
void Sequence::pop_back() {

    //sets the tail as the temp node
    SequenceNode* endNode = this->tail;

    //sets another temp node to what will be the new tail
    SequenceNode* newTail = endNode->prev;

    //sets the new tail for the sequence
    this->tail = newTail;
    newTail->next = nullptr;

    //deallocates the old node
    delete endNode;

    //decrements the sequence size
    this->sequenceSize--;

}


//inserts item at position
void Sequence::insert(size_t position, string item) {


    //if position is in scope
    if (position < this->size() && position >= 0) {


        //if sequence is empty
        if (this->head == nullptr && this->tail == nullptr) {

            //head becomes the new node
            this->head = new SequenceNode(item);

        }

        //if not empty
        else {
            //creates a temp node to iterate through the sequence
            SequenceNode* currentNode = this->head;
            for (int i = 0; i < position; i++) {

                //currentNode is set to the next node
                currentNode=currentNode->next;

            }

            //creates new node
            SequenceNode* newNode = new SequenceNode(item);

            //if the current node is the tail
            if (currentNode->next != nullptr) {

                //creates a temp reference node
                SequenceNode* pushedNode = currentNode->next;

                //inserts the new node by changing old next and prev
                currentNode->next = newNode;
                pushedNode->prev = newNode;

                //news new next and prev
                newNode->prev = currentNode;
                newNode->next = pushedNode;
            }

            //if the node is inserted at the head
            else if (currentNode->prev == nullptr) {
                this->head = newNode;
                //creates a temp reference node
                SequenceNode* pushedNode = currentNode->next;
                newNode->next = pushedNode;
            }
            //if inserted at tail
            else {
                //make newNode tail
                this->tail = newNode;

                //adds link to the current tail
                currentNode->next = newNode;
            }
        }
        //increases sequence size
        sequenceSize++;


    }
    //if the position is out of bounds throw an exception
    else {
        throw exception();
    }
}

//returns head item
string Sequence::front() const {

    //if head isnt empty throw exception
    if (this->head == nullptr) {
        throw exception();
    }
    else {
        return this->head->item;
    }

}

//returns tail item
string Sequence::back() const {

    //if tail is empty throw exception
    if (this->tail == nullptr) {
        throw exception();
    }
    //if not empty returns tail element
    else {
        return this->tail->item;
    }

}

//returns true if sequence is empty
bool Sequence::empty() const {

    //if empty
    if (this->head == nullptr && this->tail == nullptr) {
        return 1;
    }
    //if not empty
    else {
        return 0;
    }

}

//returns sequence size
size_t Sequence::size() const {
    return sequenceSize;
}

void Sequence::clear() {

    if (!(this->empty())) {
        SequenceNode* currentNode = this->head;
        for (size_t i = 0; i < this->size(); i++) {

            //if current node is not tail
            if (currentNode->next != nullptr) {

                //move the current node forward deleteing previous node
                currentNode = currentNode->next;
                delete currentNode->prev;
                sequenceSize--;
            }
            //if tail delete currentNode
            else {
                delete currentNode;
                sequenceSize--;
            }
        }
    }

}

void Sequence::erase(size_t position) {

    //if removal is in scope
    if (position < this->size() && position >= 0) {

        SequenceNode* currentNode = this->head;

        //itterates throught the sequence until desired node is found
        for (size_t i = 0; i < position; i++) {
            currentNode=currentNode->next;
        }

        //when found delete node
        delete currentNode;
        sequenceSize--;
    }

    //else throw exception
    else {
        throw exception();
    }

}

void Sequence::erase(size_t position, size_t count) {

    //if the total desired elements to be removed are in scope
    if ((position + count - 1) < this->size() && position >= 0) {

        SequenceNode* startNode = this->head;
        SequenceNode* currentNode = this->head;

        //itterates through sequence
        for (size_t i = 0; i < (position + count - 1); i++) {

            //if start of removal is found set starting node to be saved for later
            if ((i+1) == position) {
                startNode = currentNode;
            }
            //if itterating past position and before the end of the count move forward and delete the current node
            else if (((i+1) <= (position + count - 1)) && ((i+1) > position) ) {
                currentNode = currentNode->next;
                delete currentNode->prev;
                sequenceSize--;
            }
            //if neither move forward
            else {
                currentNode = currentNode->next;
            }
        }

        //sets mends the sequence by making the startNode's next equal to the current node
        startNode->next = currentNode;
    }

}