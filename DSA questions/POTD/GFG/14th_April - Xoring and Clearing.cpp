// Xoring and Clearing
// https://www.geeksforgeeks.org/problems/xoring-and-clearing/1

class Solution {
  public:
    void printArr(int n, int arr[]) {
        for(int j=0;j<n;j++)
        {
            cout<<arr[j]<<" ";
        }
        cout<<endl;
    }

    void setToZero(int n, int arr[]) {
        for(int i=0;i<n;i++)
        {
           arr[i]&=0;
        }
    }

    void xor1ToN(int n, int arr[]) {
         int j=0;
        for(int i=0;i<n;i++)
        {
            arr[j]=arr[i]^i;
            j++;
        }
    }
};
