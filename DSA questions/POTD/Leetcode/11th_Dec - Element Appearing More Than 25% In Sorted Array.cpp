// 1287. Element Appearing More Than 25% In Sorted Array
// https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/description/?envType=daily-question&envId=2023-12-11

// Using Unordered Map:  TC = O(N),  SC = O(N)

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++)
            mp[arr[i]]++;
        
        int num = 0;
        for(auto it :mp){
            if(it.second > 0.25*n){
                num = it.first;
                    break;
            }
        }
        return num;
    }
};

// Using cnt variable: TC = O(N) SC = O(1)

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int qtr = n/4;
        int cnt = 1;
        int num = arr[0];
        for(int i=1;i<n;i++){
            if(num == arr[i])
                cnt++;
            else cnt = 1;

            if(cnt > qtr)   break;

            num = arr[i];
        }
        
        return num;
    }
};

// Using Binary Search: TC = (MlogN) , SC = O(1);     N is length of input array , M is number of candidates [M = (N - quarter) / quarter]   

class Solution {
private:
    int binarySearch(const vector<int>& arr, int target, bool isFirst) {
        int left = 0;
        int right = arr.size() - 1;
        int result = -1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (arr[mid] == target) {
                result = mid;
                if (isFirst) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }  

public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int quarter = n / 4;

        // Handle the case where quarter is zero
        if (quarter == 0) {
            return n > 0 ? arr[0] : -1;
        }

        // Check every possible candidate element
        for (int i = quarter; i < n; i += quarter) {
            // Use binary search to find the first and last occurrence of the candidate element
            int leftOccurrence = binarySearch(arr, arr[i], true);
            int rightOccurrence = binarySearch(arr, arr[i], false);

            // Check if the frequency is greater than 25%
            if (rightOccurrence - leftOccurrence + 1 > quarter) {
                return arr[i];
            }
        }

        return -1;       
    }
};
