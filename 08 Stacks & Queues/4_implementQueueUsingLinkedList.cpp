#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

    Node(int data) {
        this->data = data;
        this->next = next;
    }
};

class Queue {
    public:
        Node* front;
        Node* rare;
        int size;

    Queue() {
        front = rare = NULL;
        size = 0;
    }

    void enqueue(int ele) {
        Node* temp = new Node(ele);
        if(front == NULL) {
            front = rare = temp;
        }
        else {
            rare->next = temp;
            rare = temp;

        }
        size++;
    }

    void dequeue() {
        if(front == NULL) {
            cout << "Queue is empty" << endl;
        }
        if(front == rare) {
            front = rare = NULL;
        }
        else {
            Node* temp = front;
            cout << "removed val : " << front->data << endl;
            front = front->next;
            delete temp;
            size--;
        }
    }

    int queueSize() {
        return size;
    }

    int peek() {
        if(front == NULL) return -1;
        return front->data;
    }

    bool isEmpty() {
        return front == NULL;
    }
};

int main()
{
    
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.dequeue();
    cout << "The size of the Queue is " << q.queueSize() << endl;
    cout << "The Peek element of the Queue is "<<q.peek() << endl;

    return 0;
}