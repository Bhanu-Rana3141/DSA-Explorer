#include<iostream>
using namespace std;

class StackImplementation {

    public :
        int st[10];
        int top = -1;

        void push(int element) { 
            if(top >= 10) {
                cout << "Stack is full" << endl;
                return;
            }
            top++;
            st[top] = element;
        }

        void pop() {
            if(top == -1) {
                cout << "stack is empty" << endl;
                return;
            }
            top--;
        }

        int peek() {
            if(top == -1) {
                cout << "stack is empty" << endl;
                return -1;
            }
            return st[top];
        }

        int stackSize() {
            return top + 1;
        }
};

int main()
{
    
    StackImplementation st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);
    st.push(8);
    st.push(9);
    st.push(10);
    st.push(11);

    cout << "top : " << st.peek() << endl;
    cout << "size : " << st.stackSize() << endl;

    st.pop();

    cout << "top : " << st.peek() << endl;
    cout << "size : " << st.stackSize() << endl;

    return 0;
}