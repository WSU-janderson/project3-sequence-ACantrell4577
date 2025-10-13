#include "Sequence.h"

using namespace std;

Sequence::Sequence(size_t sz) {
    elements = new size_t[sz];
    this->head = nullptr;
    this->tail = nullptr;
}

//creates deep copy
Sequence::Sequence(const Sequence &s) {

    this->elements = new size_t;

    this->head = s.head;
    this->tail = s.tail;
    this->elements = s.elements ;

}

Sequence::~Sequence() {
    delete[] this->elements;
}

Sequence& Sequence:: operator=(const Sequence &s) {

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

ostream& operator<<(ostream& os, const Sequence& s) {

}


