// 948. Bag of Tokens
// https://leetcode.com/problems/bag-of-tokens/description/?envType=daily-question&envId=2024-03-04

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0; //maximise
        int low = 0;
        int high = tokens.size() - 1;
        sort(tokens.begin(), tokens.end());

        while(low<=high){
            if(power >= tokens[low]){ // play face up when enough power
                power -=tokens[low];
                ++score;
                ++low;
            }
            else if(low < high && score >= 1){ // play highest token face down when enough score and atleast one toekn remaining
                    power +=tokens[high];
                    --score;
                    --high;
            }
            else return score; // not enough tokens,score or power to play further
        }

        return score;
    }
};


