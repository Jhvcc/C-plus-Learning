#include "../Headers/queue.h"
#include <cstdlib>

Queue::Queue(int qs) : qsize(0) {
    front = rear = NULL;
    items = 0;
}

Queue::~Queue() {
    Node * temp;
    while (front != NULL) {
        temp = front;
        front = front->next;
        delete temp;
    }
}

bool Queue::isEmpty() const {
    return items == 0;
}

bool Queue::isFull() const {
    return items == qsize;
}

int Queue::queueCount() const {
    return items;
}

bool Queue::enqueue(const Item & item) {
    if (isFull())
        return false;
    Node * add = new Node;
    add->item = item;
    add->next = NULL;
    items++;
    if (front == NULL) 
        front = add;
    else
        rear->next = add;
    rear = add;
    return true;
}

bool Queue::dequeue(Item & item) {
    if (front == NULL) 
        return false;
    item = front->item;
    items--;
    Node * tmp = front;
    front = front->next;
    delete tmp;
    if (items == 0)
        rear = NULL;
    return true;
}

void Customer::set(long when) {
    processtime = std::rand() % 3 + 1;
    arrive = when;
}