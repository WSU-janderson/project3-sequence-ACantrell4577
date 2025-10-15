#include "Sequence.h"
#include <exception>
#include <iostream>
#include <ranges>

using namespace std;

//constructor
Sequence::Sequence(size_t sz) {
    this->sequenceSize = 0;
    this->head = nullptr;
    this->tail = nullptr;

    //populates the sequence equal to the provided size
    for (int i = 0; i < sz; i++) {
        //fills the sequence with i
        this->push_back(std::to_string(i));
    }
}

//creates deep copy of sequence s
Sequence::Sequence(const Sequence &s) {


    //if they arnt already equal
    if (this !=  &s) {
        //destruct
        this->~Sequence();

        //creates dummy nodes
        SequenceNode* currentNode = s.head;

        //itterates through the other sequence copying the data
        for (int i = 0; i < s.sequenceSize; i++) {

            push_back(currentNode->item);
            currentNode = currentNode->next;


        }
    }
}

//destructor
Sequence::~Sequence() {
    this->clear();
}

//creates a deep copy and returns a reference
Sequence& Sequence:: operator=(const Sequence &s) {

    //if they arnt already equal
    if (this !=  &s) {
        //destruct
        this->~Sequence();

        //creates dummy nodes
        SequenceNode* currentNode = s.head;

        //itterates through the other sequence copying the data
        for (int i = 0; i < s.sequenceSize; i++) {

            push_back(currentNode->item);
            currentNode = currentNode->next;


        }
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
        if (position != 0) {
            for (int i = 0; i < position; i++) {

                //currentNode is set to the next node
                currentNode = currentNode->next;
            }
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


    //if no head create head
    if (this->empty()) {
        this->head = this->tail = new SequenceNode(item);
    }

    //if head append to the end of the sequence
    else {
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
    }
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

        //if position is head
        else if (position == 0) {

            //declare sequence nodes
            SequenceNode* newNode = new SequenceNode(item);
            SequenceNode* currentNode = this->head;

            //position new head node
            newNode->next = currentNode;
            currentNode->prev = newNode;
            this->head = newNode;

        }

        //if not empty
        else {
            //creates a temp node to iterate through the sequence
            SequenceNode* currentNode = this->head;

            //creates new node
            SequenceNode* newNode = new SequenceNode(item);

            for (int i = 0; i < position-1; i++) {

                //dont move forward if at tail
                if (currentNode->next != nullptr) {
                    //currentNode is set to the next node
                    currentNode=currentNode->next;
                }
            }
                //if the current node is not the tail
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

                //if the node is inserted at the tail
                else if (currentNode->next == nullptr) {

                    //adds link to the current tail
                    currentNode->next = newNode;

                    //make newNode tail
                    this->tail = newNode;

                }
                //if inserted at head
                else {
                    this->head = newNode;
                    //creates a temp reference node
                    SequenceNode* pushedNode = currentNode->next;
                    newNode->next = pushedNode;
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
        this->head = this->tail = nullptr;
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

        //if head set new head and delete the old
        if (currentNode == this->head) {

            //sets head to the second node and sets prev to null
            this->head = currentNode->next;
            this->head->next = nullptr;

            //removes old node
            delete currentNode;
        }

        //if tail is set for deletion set new tail before deletion
        else if (currentNode == this->tail) {
            this->tail = currentNode->prev;
            this->tail->next = nullptr;
            delete currentNode;
        }
        else {
            //when found remove from sequence
            currentNode->prev->next = currentNode->next;
            currentNode->next->prev = currentNode->prev;

            //delete node
            delete currentNode;
        }
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
        SequenceNode* delNode = nullptr;

        //itterates through sequence
        for (size_t i = 0; i < (position + count); i++) {


            //if start of removal is found set starting node to be saved for later
            if ((i+1) == position) {
                startNode = currentNode;
                currentNode = currentNode->next;
            }
            //if itterating past position and before the end of the count move forward and delete the current node
            else if (((i+1) <= (position + count) && ((i+1) > position) )) {

                //sets node for deletion
                delNode = currentNode;

                if (currentNode->next == nullptr) {
                    this->tail = startNode;
                }
                else {
                    //itterates to the next node deleting the node prior
                    currentNode = currentNode->next;
                }
                delete delNode;
                sequenceSize--;
            }
            //if neither move forward
            else {
                currentNode = currentNode->next;
            }
        }

        //sets mends the sequence by making the startNode's next equal to the current node
        startNode->next = currentNode;
        currentNode->prev = startNode;
    }

}

//ostream overload
ostream& operator<<(ostream& os, const Sequence& s){

    //declares node pointer
    SequenceNode* node = s.head;

    //formatting
    os << "< ";

    //while not at the end of the sequence print the data
    while (node != nullptr) {
        os << node->item << ", ";
        node = node->next;
    }
    //formatting
    os << ">" << endl;

    //return ostream
    return os;

};