// Recursive sequence
//  https://www.geeksforgeeks.org/problems/recursive-sequence1611/1

class Solution{
public:
    long long i=1;
long long sequence(int N){

        if(N==0) return 0; 
        long long ans=sequence(N-1);
        long long c=1,a=1;
        while(c<=N){
            a=a*i++;
            c++;
        }
        a+=ans;
       return a;
        
    }
};
