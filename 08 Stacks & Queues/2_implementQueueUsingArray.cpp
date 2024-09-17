#include<iostream>
using namespace std;

class QueueImplementation {

    public:
        int size;
        int *q;
        int start;
        int end;
        int currSize;

    QueueImplementation(int size) {
        this->size = size;
        q = new int[size];
        start = end = -1;
        currSize = 0;
    }

    void push(int ele) {
        if(currSize == size) {
            cout << "queue is full" << endl;
            return;
        }
        if(currSize == 0) {
            start = end = 0;
        }
        else {
            end = (end + 1) % size;
        }
        q[end] = ele;
        currSize++;
    }

    int pop() {
        if(currSize == 0) {
            cout << "queue is empty" << endl;
            return -1;
        }
        int ele = q[start];
        if(currSize == 1) {
            start = end = -1;
        }
        else {
            start = (start + 1) % size;
        }
        currSize--;
        return ele;
    }

    int front() {
        if(currSize == 0) {
            cout << "queue is empty" << endl;
            return -1;
        }
        return q[start];
    }

    int queueSize() {
        return currSize;
    }
};

int main()
{
    QueueImplementation q(4);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << "top ele:  " << q.front() << endl;

    q.pop();

    cout << "top ele:  " << q.front() << endl;

    return 0;
}