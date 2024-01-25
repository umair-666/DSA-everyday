//Shortest Prime Path
//https://www.geeksforgeeks.org/problems/shortest-prime-path--141631/1

class Solution{   
public:
    bool isPrime(int n) {
        if(n == 1)
            return 0;
        
        for(int i = 2; i <= sqrt(n); i++)
            if(n % i == 0)
                return 0;
                
        return 1;
    }

    int solve(int num1,int num2){   
        string s1 = to_string(num1);
        string s2 = to_string(num2);
        
        queue<pair<string, int>> q;
        q.push({s1, 0});
        
        vector<int> vis(1e5, 0);
        
        while(!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            vis[stoi(word)] = 1;
            if(word == s2)
                return steps;
                
            for(int i = 0; i < word.size(); i++) {
                char ch = word[i];
                
                for(int j = 0; j < 10; j++) {
                    if(i == 0 and j == 0)   //if num is becoming a number with leading zeroes
                        continue;
                        
                    word[i] = char(j + '0');
                    int n = stoi(word);
                    
                    if(isPrime(n) and !vis[n]) {
                        vis[n] = 1;
                        q.push({word, steps + 1});
                    }
                }
                
                word[i] = ch;
            }
        }
        
        return -1;
    }
};
