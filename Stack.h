#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <limits>
#include <cmath>
#include "StackNode.h"
#include "StackException.h"
using namespace std;

class Stack {
private:
	StackNode* _Head;
    int _Size;
    static const int _MaxSize = 100;
    bool _IsEmpty() const;
    void _Annihilation();
public:

	Stack() : _Head(nullptr), _Size(0) {
        CommandCycle();
    }

    ~Stack() {
        _Annihilation();
    }

    void CommandCycle();

    StackNode* GetHead();

    void SetHead(StackNode* Node);

    int GetSize();

    void Push(const string& Value);

    void Pop();

    void Back();

    void Clear();

    void Size();

    void ShowCommands();

    bool IsNumber(const string& String);

};