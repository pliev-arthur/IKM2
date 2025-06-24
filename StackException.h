#pragma once
#include <iostream>
#include <string>
using namespace std;

class StackException {
private:
    string _Message;
public:
    StackException(const string& Message) : _Message(Message) {}
    string what() const {
        return _Message;
    }
};