#pragma once
#include <iostream>
#include <string>
using namespace std;

class StackNode {
private:
    string _Value;
    StackNode* _Next;
public:
    StackNode(const string& Val) : _Value(Val), _Next(nullptr) {}
    string GetValue();
    StackNode* GetNext();
    void SetValue(const string& Value);
    void SetNext(StackNode* Node);
};