#include "Sequence.h"
#include <exception>

using namespace std;

//constructor
Sequence::Sequence(size_t sz) {
    elements = new size_t[sz];
    this->head = nullptr;
    this->tail = nullptr;
}

//creates deep copy os sequence s
Sequence::Sequence(const Sequence &s) {

    //dynamically allocates memory
    this->elements = new size_t;

    //copies the provided sequence
    this->head = s.head;
    this->tail = s.tail;
    *(this->elements) = *(s.elements);

}

//destructor
Sequence::~Sequence() {
    delete[] this->elements;
}

//creaates a deep copy and returns a reference
Sequence& Sequence:: operator=(const Sequence &s) {

    //if they arnt already euqal
    if (this !=  &s) {
        //destruct
        this->~Sequence();

        //create deep copy
        this->elements = new size_t;
        this->head = s.head;
        this->tail = s.tail;
        *(this->elements) = *(s.elements);
    }

    //return the reference to sequence object
    return *this;
}

string &Sequence::operator[](size_t position) {



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

}

void Sequence::clear() {

}

void Sequence::erase(size_t position) {

}

void Sequence::erase(size_t position, size_t count) {

}


