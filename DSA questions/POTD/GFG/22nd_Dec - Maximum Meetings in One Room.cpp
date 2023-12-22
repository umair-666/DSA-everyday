// Maximum Meetings in One Room
// https://www.geeksforgeeks.org/problems/maximum-meetings-in-one-room/1

class Solution{
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        vector<vector<int>>ans;
        for(int i=0;i<N;i++){
            ans.push_back({F[i], S[i], i+1});
        }
        sort(ans.begin(), ans.end()); // sort the ans vector with respect to finish time 
        vector<int>res;
        res.push_back(ans[0][2]);
        int end_time=ans[0][0];
        for(int i=1;i<N;i++){
            if(ans[i][1]>end_time){
                res.push_back(ans[i][2]);
                end_time=ans[i][0];
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
