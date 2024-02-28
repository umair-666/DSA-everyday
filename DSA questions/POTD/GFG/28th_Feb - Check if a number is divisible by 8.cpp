// Check if a number is divisible by 8
// https://www.geeksforgeeks.org/problems/check-if-a-number-is-divisible-by-83957/1

class Solution{
    public:
    int DivisibleByEight(string s){
        int n = s.size();
        int num = 0;
        if(n <= 4)   num = stoi(s);
        else
            num = (s[n-3] -'0')* 100 + (s[n-2] -'0')*10 + (s[n-1] - '0');
        
        return num % 8 == 0 ? 1 : -1;
            
    }
};
