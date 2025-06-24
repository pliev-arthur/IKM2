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
        throw StackException("Ошибка: стек переполнен (максимум 100 элементов)!");
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
        throw StackException("Ошибка: стэк пуст!");
    }
    StackNode* Temp = _Head;
    _Head = _Head->GetNext();
    delete Temp;
    _Size--;
    cout << "ok" << endl;
}

void Stack::Back() {
    if (_IsEmpty()) {
        throw StackException("Ошибка: стэк пуст!");
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
    cout << "Список команд:" << endl;
    cout << endl;
    cout << "exit - выход из программы" << endl;
    cout << endl;
    cout << "commands - показать список команд" << endl;
    cout << endl;
    cout << "push n - добавить в стэк элемент n" << endl;
    cout << endl;
    cout << "pop - удалить последний элемент" << endl;
    cout << endl;
    cout << "back - вывести последний элемент" << endl;
    cout << endl;
    cout << "size - вывести количество элементов стэка" << endl;
    cout << endl;
    cout << "clear - удалить все элементы стэка" << endl;
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
    cout << "Привет, это программа для работы со стэком." << endl;
    cout << endl;
    ShowCommands();
    cout << "Введите команду: " << endl;
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
                        cout << "Ваш элемент не является числом, продолжить? (Y/n)" << endl;
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
                                cout << "Пожалуйста введите Y (да) или n (нет)" << endl;
                            }
                        }
                    }
                }
                else {
                    throw StackException("Ошибка: неверный формат команды push!");
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
                throw StackException("Неизвестная команда! Доступные команды: exit, commands, push, pop, back, size, clear");
            }
        }
        catch (const StackException& Exception) {
            cerr << Exception.what() << endl;
        }
        cout << endl;
        cout << "Введите следующую команду:" << endl;
    }
}