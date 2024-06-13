// 2037. Minimum Number of Moves to Seat Everyone
// https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/description/?envType=daily-question&envId=2024-06-13

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int moves = 0;
        for (int i = 0; i < seats.size(); i++) {
            // Add the absolute value of the difference
            // between the position of the seat and the student
            moves += abs(seats[i] - students[i]);
        }
        return moves;
    }
};
