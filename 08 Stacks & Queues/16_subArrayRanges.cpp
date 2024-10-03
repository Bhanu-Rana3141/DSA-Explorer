/*
class Solution {
public:

    vector<int> findPSE(vector<int>& nums) {

        int n = nums.size();
        vector<int> pse(n);
        stack<int> st;

        for(int i = 0; i<n; i++) {
            while(!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return pse;
    }

    vector<int> findNSE(vector<int>& nums) {

        int n = nums.size();
        vector<int> nse(n);
        stack<int> st;

        for(int i = n-1; i>=0; i--) {
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return nse;
    }

    vector<int> findPGE(vector<int>& nums) {

        int n = nums.size();
        vector<int> pge(n);
        stack<int> st;

        for(int i = 0; i<n; i++) {
            while(!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return pge;
    }

    vector<int> findNGE(vector<int>& nums) {

        int n = nums.size();
        vector<int> nge(n);
        stack<int> st;

        for(int i = n-1; i>=0; i--) {
            while(!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return nge;
    }

    long long subArrRange(vector<int>& nums) {

        int n = nums.size();
        vector<int> pse = findPSE(nums);
        vector<int> nse = findNSE(nums);
        vector<int> pge = findPGE(nums);
        vector<int> nge = findNGE(nums);
        long long minSum = 0;
        long long maxSum = 0;

        for(int i = 0; i<n; i++) {
            long long leftMin = i - pse[i];
            long long rightMin = nse[i] - i;
            long long leftMax = i - pge[i];
            long long rightMax = nge[i] - i;

            minSum = minSum + (leftMin * rightMin * nums[i]);
            maxSum = maxSum + (leftMax * rightMax * nums[i]);
        }
        long long ans = abs(maxSum - minSum);
        return ans;
    }

    long long subArrayRanges(vector<int>& nums) {
        
        return subArrRange(nums);
    }
};
*/