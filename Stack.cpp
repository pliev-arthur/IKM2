#include "Stack.h"

StackNode* Stack::GetHead() {
    return _Head;
}

void Stack::SetHead(StackNode* Node) {
    _Head = Node;
}

int Stack::GetSize() {
    return _Size;
}

bool Stack::_IsEmpty() const {
    return _Head == nullptr;
}

void Stack::Push(const string& Value) {
    if (_Size >= _MaxSize) {
        throw StackException("Error: stack overflow (maximum 100 elements)!");
    }
    StackNode* NewNode = new StackNode(Value);
    if (_IsEmpty()) {
        _Head = NewNode;
        _Size++;
    }
    else {
        NewNode->SetNext(_Head);
        _Head = NewNode;
        _Size++;
    }
    cout << "ok" << endl;
}

void Stack::Pop() {
    if (_IsEmpty()) {
        throw StackException("Error: stack is empty!");
    }
    StackNode* Temp = _Head;
    _Head = _Head->GetNext();
    cout << Temp->GetValue() << endl;
    delete Temp;
    _Size--;
}

void Stack::Back() {
    if (_IsEmpty()) {
        throw StackException("Error: stack is empty!");
    }
    cout << _Head->GetValue() << endl;
}

void Stack::Size() {
    cout << _Size << endl;
}

void Stack::Clear() {
    if (_IsEmpty()) {
        cout << "ok" << endl;
        return;
    }
    else {
        while (_Head) {
            StackNode* Temp = _Head;
            _Head = _Head->GetNext();
            delete Temp;
            _Size--;
        }
    }
    cout << "ok" << endl;
}

void Stack::_Annihilation() {
    if (_IsEmpty()) {
        return;
    }
    else {
        while (_Head) {
            StackNode* Temp = _Head;
            _Head = _Head->GetNext();
            delete Temp;
            _Size--;
        }
    }
}

void Stack::ShowCommands() {
    cout << "Command list:" << endl;
    cout << endl;
    cout << "exit - exit the program" << endl;
    cout << endl;
    cout << "commands - show command list" << endl;
    cout << endl;
    cout << "push n - add element n to the stack" << endl;
    cout << endl;
    cout << "pop - remove the last element" << endl;
    cout << endl;
    cout << "back - show the last element" << endl;
    cout << endl;
    cout << "size - show the number of elements in the stack" << endl;
    cout << endl;
    cout << "clear - remove all elements from the stack" << endl;
    cout << endl;
}

bool Stack::IsNumber(const string& String) {
    if (String.empty()) {
        return false;
    }
    size_t StartPos = 0;
    if (String[0] == '-') {
        StartPos = 1;
        if (String.length() == 1) {
            return false;
        }
    }
    bool HasPoint = false;
    for (size_t i = StartPos; i < String.length(); ++i) {
        if (String[i] == '.') {
            if (HasPoint) {
                return false;
            }
            HasPoint = true;
        }
        else if (!isdigit(String[i])) {
            return false;
        }
    }
    return true;
}

void Stack::CommandCycle() {
    cout << "Hello, this is a stack program." << endl;
    cout << endl;
    ShowCommands();
    cout << "Enter a command: " << endl;
    string Input = "";
    while (true) {
        cout << endl;
        getline(cin, Input);
        if (Input.empty()) {
            continue;
        }
        stringstream Stream(Input);
        string Command;
        Stream >> Command;
        try {
            if (Command == "exit") {
                cout << "bye" << endl;
                break;
            }
            else if (Command == "commands") {
                ShowCommands();
            }
            else if (Command == "push") {
                string Value;
                if (Stream >> Value) {
                    if (IsNumber(Value)) {
                        Push(Value);
                    }
                    else {
                        cout << "Your element is not a number, continue? (Y/n)" << endl;
                        string Choice;
                        bool Flag = true;
                        while (Flag) {
                            getline(cin, Choice);
                            if (Choice == "Y") {
                                Push(Value);
                                Flag = false;
                            }
                            else if (Choice == "n") {
                                Flag = false;
                            }
                            else {
                                cout << "Please enter Y (yes) or n (no)" << endl;
                            }
                        }
                    }
                }
                else {
                    throw StackException("Error: invalid push command format!");
                }
            }
            else if (Command == "pop") {
                Pop();
            }
            else if (Command == "back") {
                Back();
            }
            else if (Command == "size") {
                Size();
            }
            else if (Command == "clear") {
                Clear();
            }
            else {
                throw StackException("Unknown command! Available commands: exit, commands, push, pop, back, size, clear");
            }
        }
        catch (const StackException& Exception) {
            cerr << Exception.what() << endl;
        }
        cout << endl;
        cout << "Enter next command:" << endl;
    }
}
