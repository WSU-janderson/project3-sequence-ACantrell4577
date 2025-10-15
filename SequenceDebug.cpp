/**
 * SequenceDebug.cpp
 * Project 3
 * CS 3100
 *
 * In this file, you will write your tests as you implement Sequence. If you are using CLion, you need to select
 * SequenceDebug from the drop-down menu next to the Build (hammer icon) if it is on SequenceTestHarness
 */
#include <iostream>
#include <string>
#include "Sequence.h"

using namespace std;

int main() {
    Sequence s(5);
    s.insert(0, to_string(99));
    cout << s;

    s.clear();

    return 0;
}