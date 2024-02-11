/*
APPROACH 1 - LINEAR
TC - O(N)
SC - O(1)

APPROACH 2 - BINARY
TC - O(LOG N)
SC - O(1)
*/

#include<iostream>
using namespace std;

pair<int, int> floorCeil_1(int *arr, int n, int x) {

    int ans1 = -1;
	int ans2 = -1;

	for(int i=0; i<n; i++) {

		if(arr[i] == x) {
			return {arr[i], arr[i]};
		}

        // ceil
		if(arr[i] > x) {
			ans2 = arr[i];
			break;
		}

        //floor
		ans1 = arr[i];
	}
	return {ans1, ans2};
}

pair<int, int> floorCeil_2(int *arr, int n, int x) {

    int s = 0;
    int e = n - 1;
    int ans1 = -1;
    int ans2 = -1;

    while(s <= e) {

        int mid = s + (e - s) / 2;
 
        if(arr[mid] == x) {
            return {arr[mid], arr[mid]};
        }
        // floor
        else if(arr[mid] <= x) {
            ans1 = arr[mid];
            s = mid + 1;
        }
        else {
            ans2 = arr[mid];
            e = mid - 1;
        }
    }
    return {ans1, ans2};
}

int main() {

    int n = 6;
    int arr[] = {3, 4, 7, 8, 8, 10};   
    int x = 2;

    // pair<int, int> ans = floorCeil_1(arr, n, x);
    pair<int, int> ans = floorCeil_2(arr, n, x);

    cout << ans.first << " , " << ans.second;

    return 0;
}