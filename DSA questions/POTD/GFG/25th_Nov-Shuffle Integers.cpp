
// Shuflle Integers
// https://www.geeksforgeeks.org/problems/shuffle-integers2401/1

void shuffleArray(int arr[],int n)
	{
	    // Your code goes here
	   if(n==1 || n==2) return;
        vector<int>ans;
        for(int i=0;i<n;i++){
            ans.push_back(arr[i]);
        }
        int even=0,odd=1;
        
        for(int i=0;i<n/2;i++){
            arr[even]=ans[i];
            even=even+2;
        }
        int k=(n/2) ;
        for(;k<n;k++){
            arr[odd]=ans[k];
            odd=odd+2;
	}}
