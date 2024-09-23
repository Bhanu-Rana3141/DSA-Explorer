#include<iostream>
#include<stack>
using namespace std;

class MinStack {

    public:
        stack<pair<int,int>> st;

    void push(int ele) {
        if(st.empty()) {
            st.push({ele, ele});
        }
        else {
            st.push({ele, min(ele, st.top().second)});
        }
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};

int main()
{
    MinStack st;

    st.push(-2);
    st.push(0);
    st.push(-3);
    cout << "min: " << st.getMin() << endl;
    st.pop();
    cout << "top: " << st.top() << endl;
    cout << "min: " << st.getMin() << endl;

    return 0;
}