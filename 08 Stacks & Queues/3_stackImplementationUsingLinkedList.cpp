#include<iostream>
using namespace std;

class Node {

    public:
        int data;
        Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Stack {

    public:
        Node* top;
        int size;
    
    Stack() {
        top = NULL;
        size = 0;
    }

    void push(int ele) {
        Node* temp = new Node(ele);
        temp->next = top;
        top = temp;
        size++;
    }

    int pop() {
        if(top == NULL) return -1;
        int topData = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;

        return topData;
    }

    int peek() {
        if(top == NULL) return -1;
        return top->data;
    }

    int stackSize() {
        return size;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void printStack() {
        Node* temp = top;
        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main()
{

    Stack st;

    st.push(4);
    st.push(2);
    st.push(3);
    st.push(1);

    cout << "top ele: " << st.peek() << endl;
    cout << "popped element :" << st.pop() << endl;
    st.push(7);
    cout << "size : " << st.stackSize() << endl;

    st.printStack();    

    return 0;
}