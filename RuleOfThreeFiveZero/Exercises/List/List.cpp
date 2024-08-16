#include "List.h"
#include <sstream>
#include <climits>

// NODE

List::Node::Node(int value, Node *prev, Node *next) :
    value(value), prev(prev), next(next) {}

int List::Node::getValue() const {
    return value;
}

void List::Node::setValue(int value) {
    this->value = value;
}

List::Node *List::Node::getPrev() const {
    return prev;
}

void List::Node::setPrev(Node *prev) {
    this->prev = prev;
}

List::Node *List::Node::getNext() const {
    return next;
}

void List::Node::setNext(Node *next) {
    this->next = next;
}

// LIST

List::List() : size(0), head(nullptr), tail(nullptr) {}

int List::first() const {
    return head != nullptr ? head->getValue() : INT_MIN;
}

size_t List::getSize() const {
    return size;
}

bool List::isEmpty() const {
    return size == 0;
}

std::string List::toString() const {
    std::ostringstream ostr;
    List::Node * curr = head;
    bool bFirst = true;
    while(curr) {
        if (!bFirst)
            ostr << ' ';
        else
            bFirst = false;

        ostr << curr->getValue();
        curr = curr->getNext();
    }
    return ostr.str();
}

void List::add(int value) {
    Node * newNode = new Node(value, tail, nullptr);

    if (size == 0) {
        head = tail = newNode;
        size++;
    }
    else {
        tail->setNext(newNode);
        size++;
        tail = newNode;
    }
}

void List::addAll(const List &other) {
    const Node * curr = other.head;

    while(curr) {
        add(curr->getValue());
        curr = curr->getNext();
    }
}

void List::removeFirst() {
    if (size <= 1) {
        removeAll();
    } else {
        Node * currhead = head;
        head = head->getNext();
        head->setPrev(nullptr);
        delete currhead;
        size--;
    }
}

void List::removeAll() {
    Node * curr = head;
    while(curr) {
        Node * tmp = curr;
        curr = curr->getNext();
        delete tmp;
    }

    size = 0;
    head = nullptr;
    tail = nullptr;
}

List::~List() {
    removeAll();
}

List::List(const List &other) : List() {
    *this = other;
}

List &List::operator=(const List &other) {
    removeAll();
    addAll(other);
    return *this;
}

List &List::operator<<(const int &value) {
    add(value);
    return *this;
}

List &List::operator<<(const List &other) {
    addAll(other);
    return *this;
}

// List List::getReversed(List l) {
//
// }























