/* 
BRUTE - count frequency of each element
* TC - O(N^2)
* SC - O(1)


INBUILT SORT
* TC - O(N log N)
* SC - O(1)


BETTER - USING MAP 
* STORING FREQUENCY OF EACH ELEMENT
* TC - O(N) - FOR TRAVERSING AND O(LOG N) -> FOR USING MAP
* OVERALL TC - O(N*LOG N)
* SC - O(N)


OPTIMAL - Moore's Voting Algorithm
* TC - O(N)
* SC - O(1)

* Take a variable count and a variable majorityElement, count = 0, majorityElement = arr[i]
* Initially count is 0, and element at 0th index will be considered as majorityElement, and it will be searched in further part of array
* If element is found count++, else count--
* Therefore if count becomes 0 , means noe element has to be searched in new part of array
* After the end of array some frequency count of majorityElement will be present in count variable

SECOND TRAVERSAL
* Now initialise another count variable let say it cnt1, and traverse in array, if(arr[i] == majorityElement) cnt1++
* If cnt1 > arr/2, then it's the majority element, else not

IF ARRAY ALWAYS CONSISTS OF MAJORITY ELEMENT - only 1 traversal
* In that case the element stored in majorityElement after traversing array will be the majority element

*/

#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

// APPROACH 1
int majorityElement1(int arr[], int n) {
    for(int i=0; i<n; i++) {
        if(arr[i] == '#') {
            continue;
        }
        int count = 1;
        for(int j=i+1; j<n; j++) {
            if(arr[i] == arr[j]) {
                count++;
                arr[j] = '#';
            }
        }
        if(count > (n/2)) {
            return arr[i];        
        }
    }
}

// APPROACH 2
int majorityElement2(int arr[], int n) {  
    sort(arr, arr+n);
    return arr[n/2];
}

// APPROACH 3
int majorityElement3(int arr[], int n) {
    map<int, int> mpp;
    for(int i=0; i<n; i++) {
        mpp[arr[i]]++;
    }
    // it.first -> points to element(key)
    // it.second -> points to frequency(value)
    for(auto it : mpp) {
        if(it.second > (n / 2)) {
            return it.first;
        }
    }
    return -1;
}

// APPROACH 4
int majorityElement4(int arr[], int n) {
    int count = 0;
    int element = 0;

    for(int i=0; i<n; i++) {
        if(count == 0) {
            count = 1;
            element = arr[i];
        }
        else if(element == arr[i]) {
            count++;
        }
        else {
            count--;
        }
    }

    int cnt = 0;
    for(int i=0; i<n; i++) {
        if(element == arr[i]) {
            cnt++;
        }
    }

    if(count > (n/2)) {
        return element;
    }
    return -1;
}

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    int arr[n];
    
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    // int ans = majorityElement1(arr, n);
    // int ans = majorityElement2(arr, n);
    // int ans = majorityElement3(arr, n);
    int ans = majorityElement4(arr, n);

    cout << "ans: " << ans;
    
    return 0;
}