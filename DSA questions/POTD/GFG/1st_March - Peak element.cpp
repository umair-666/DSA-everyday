// Peak element
// https://www.geeksforgeeks.org/problems/peak-element/1

//Brute force:

class Solution{
    public:
    int peakElement(int arr[], int n){
        int flag = -1 ;
       for(int i=0;i<n;i++){
            if(i==0 && arr[i] >= arr[i+1]){
                flag = i;
                break;
            }
            else if(i==n-1 && arr[i] >= arr[i-1]){
                flag = i;
                break;
            }
            else if(arr[i] >= arr[i-1] && arr[i] >= arr[i+1]){
                flag = i;
                break;
            }
       }
       return flag;
    }
};

// Binary Search:

class Solution{
    public:
    int peakElement(int arr[], int n){
       // Your code here
       int s = 0 , e = n-1;
       
      while(s<e){
          int mid = s + (e-s) / 2;
          if(arr[mid] < arr[mid+1])
            s = mid + 1;
        else
            e = mid;
      }
      return s;
    }
};
