// 232. Implement Queue using Stacks
// https://leetcode.com/problems/implement-queue-using-stacks/description/?envType=daily-question&envId=2024-01-29


// insertion is O(1)  deletion O(N)

class MyQueue {
   private :
        std::stack<int>  s1 , s2; //defining two stacks
public:
    MyQueue() {
        
    }
   
    //insert efficient-> O(1)
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        while(!s1.empty()){   //empty s1 and push to s2
            s2.push(s1.top());
            s1.pop();
        }
         int popped = s2.top(); //remove element
        s2.pop();
        while(!s2.empty()){   //push from s2 to s1
            s1.push(s2.top());
            s2.pop();
        }
        return popped;
    }

    int peek() {
         while(!s1.empty()){   //empty s1 and push to s2 for finding first element of queue
            s2.push(s1.top());
            s1.pop();
        }
         int peeked = s2.top(); // store peeked element
        while(!s2.empty()){   //push from s2 to s1 after peeking
            s1.push(s2.top());
            s2.pop();
        }
        return peeked;
    }
    
    bool empty() {
        return s1.empty();
    }
};
