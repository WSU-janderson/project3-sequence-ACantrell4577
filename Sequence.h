
#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <ostream>
#include <string>

#include "SequenceNode.h"

using namespace std;

class Sequence {

    //variable declaration
    private:
    SequenceNode *head;
    SequenceNode *tail;
    size_t *element;
    size_t sequenceSize;

    public:
    //constructor
    Sequence(size_t sz = 0);

    //deep copy
    Sequence(const Sequence& s);

    //destructor
    ~Sequence();

    //overloading operators
    Sequence& operator=(const Sequence& s);
    string& operator[](size_t position);

    //method declaration
    void push_back(string item);
    void pop_back();
    void insert(size_t position, string item);

    //getters
    string front() const;
    string back() const;

    //if empty
    bool empty() const;

    //sie getter
    size_t size() const;

    //called destructor
    void clear();

    //removed items from the sequence
    void erase(size_t position);
    void erase(size_t position, size_t count);

    friend ostream& operator<<(ostream& os, const Sequence& s);
};

ostream& operator<<(ostream& os, const Sequence& s) {

    os << s.element;
    return os;

};

#endif