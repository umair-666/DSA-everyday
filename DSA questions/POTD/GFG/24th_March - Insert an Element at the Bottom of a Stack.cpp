// Insert an Element at the Bottom of a Stack
// https://www.geeksforgeeks.org/problems/insert-an-element-at-the-bottom-of-a-stack/1

class Solution{
public:
    stack<int> insertAtBottom(stack<int> st,int x){
        stack<int> s, z;
        s.push(x);
        while(!st.empty()){
            z.push(st.top());
            st.pop();
        }
        while(!z.empty()){
            s.push(z.top());
            z.pop();
        }
        
        return s;
    }
};
