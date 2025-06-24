#include "StackNode.h"

string StackNode::GetValue() {
	return _Value;
}
StackNode* StackNode::GetNext() {
	return _Next;
}
void StackNode::SetValue(const string& Value) {
	_Value = Value;
}
void StackNode::SetNext(StackNode* Node) {
	_Next = Node;
}