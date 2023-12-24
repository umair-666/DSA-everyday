// Buy Maximum Stocks if i stocks can be bought on i-th day
// https://www.geeksforgeeks.org/problems/buy-maximum-stocks-if-i-stocks-can-be-bought-on-i-th-day/1

class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
          vector<pair<int,int>> a;
        for(int i=0;i<n;i++){
            a.push_back({price[i],i+1});
        }
        sort(a.begin(),a.end());
        int count = 0;
        int p=0;
        int s;
        while(p < n && k >=a[p].first){
            s=floor(k/a[p].first);
            if(s>a[p].second){
                count+=a[p].second;
                k-=(a[p].first*a[p].second);
            }
            else{
                count+=s;
                k-=s*a[p].first;
            }
            p++;
          
        }
        return count;
    }
};
