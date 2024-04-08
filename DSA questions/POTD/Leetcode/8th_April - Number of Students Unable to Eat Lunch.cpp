// 1700. Number of Students Unable to Eat Lunch
// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/?envType=daily-question&envId=2024-04-08

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        queue<int> students_queue;
        stack<int> sandwich_stack;

        for(int i =0;i<n;i++){
            students_queue.push(students[i]);
            sandwich_stack.push(sandwiches[n-i-1]);
        }

        int lastServed = 0;
        while (!students_queue.empty() && lastServed < students_queue.size()) {
            if (sandwich_stack.top() == students_queue.front()) {
                sandwich_stack.pop(); // Serve sandwich
                students_queue.pop(); // Student leaves queue
                lastServed = 0;
            } else {
                // Student moves to back of queue
                students_queue.push(students_queue.front());
                students_queue.pop(); // Remove from front
                lastServed++;
            }
        }

        return students_queue.size();

    }
};
