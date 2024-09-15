#include<iostream>
#include<limits.h>
using namespace std;

int divide(int dividend, int divisor) {

    if(dividend == divisor) return 1;

    if(dividend == INT_MIN && divisor == -1) return INT_MAX;
    if(dividend == INT_MIN && divisor == 1) return INT_MIN;
    if(dividend == INT_MIN && divisor == INT_MAX) return -1;
    if(dividend == INT_MAX && divisor == INT_MIN) return 0;

    int sign = true;
    if(dividend < 0 && divisor >= 0) sign = false;
    if(dividend >= 0 && divisor < 0) sign = false;

    dividend = abs(dividend);
    divisor = abs(divisor);

    long long quotient = 0;
    long long demoDiv = divisor;
    while(demoDiv <= dividend) {
        quotient++;
        demoDiv += divisor;
    }

    if(sign == false) {
        quotient *= (-1);
    }

    if(quotient > INT_MAX) {
        if(sign == false) {
            return INT_MIN;
        }
        else {
            return INT_MAX;
        }
    }

    return int(quotient);
}

int main()
{
    int divisor = 3;
    int dividend = 22;

    cout << divide(dividend, divisor);

    return 0;
}