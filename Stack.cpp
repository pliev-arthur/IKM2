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
        throw StackException("������: ���� ���������� (�������� 100 ���������)!");
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
        throw StackException("������: ���� ����!");
    }
    StackNode* Temp = _Head;
    _Head = _Head->GetNext();
    delete Temp;
    _Size--;
    cout << "ok" << endl;
}

void Stack::Back() {
    if (_IsEmpty()) {
        throw StackException("������: ���� ����!");
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
    cout << "������ ������:" << endl;
    cout << endl;
    cout << "exit - ����� �� ���������" << endl;
    cout << endl;
    cout << "commands - �������� ������ ������" << endl;
    cout << endl;
    cout << "push n - �������� � ���� ������� n" << endl;
    cout << endl;
    cout << "pop - ������� ��������� �������" << endl;
    cout << endl;
    cout << "back - ������� ��������� �������" << endl;
    cout << endl;
    cout << "size - ������� ���������� ��������� �����" << endl;
    cout << endl;
    cout << "clear - ������� ��� �������� �����" << endl;
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
    cout << "������, ��� ��������� ��� ������ �� ������." << endl;
    cout << endl;
    ShowCommands();
    cout << "������� �������: " << endl;
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
                        cout << "��� ������� �� �������� ������, ����������? (Y/n)" << endl;
                        string Choise;
                        bool Flag = true;
                        while (Flag) {
                            getline(cin, Choise);
                            if (Choise == "Y") {
                                Push(Value);
                                Flag = false;
                            }
                            else if (Choise == "n") {
                                Flag = false;
                            }
                            else {
                                cout << "���������� ������� Y (��) ��� n (���)" << endl;
                            }
                        }
                    }
                }
                else {
                    throw StackException("������: �������� ������ ������� push!");
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
                throw StackException("����������� �������! ��������� �������: exit, commands, push, pop, back, size, clear");
            }
        }
        catch (const StackException& Exception) {
            cerr << Exception.what() << endl;
        }
        cout << endl;
        cout << "������� ��������� �������:" << endl;
    }
}