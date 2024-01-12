// Reverse First K elements of Queue
// https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1

class Solution{
    public:
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        stack<int> s;
        
        while(k--){
            s.push(q.front());
            q.pop();
        }
        
        queue<int> x;
        
        while(!s.empty()){
            x.push(s.top());
            s.pop();
        }
        
        while(!q.empty()){
            x.push(q.front());
            q.pop();
        }
        
        return x;
    }
};

// Python solution:

class Solution:
    def modifyQueue(self, q, k):
        return q[:k][::-1]+q[k:]



  
