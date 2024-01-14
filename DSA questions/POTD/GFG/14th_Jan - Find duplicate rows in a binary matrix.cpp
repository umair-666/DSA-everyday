// Find duplicate rows in a binary matrix
 // https://www.geeksforgeeks.org/problems/find-duplicate-rows-in-a-binary-matrix/1

class Solution{   
    public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N) { 
        
        set<vector<int>> s;
        vector<int> res;
        for(int i=0;i<M;i++){
            // if the row is not found then insert into the set
            if(s.find(matrix[i])==s.end()){
                s.insert(matrix[i]);
            }
            // if the row is found push the index into ans array
            else{
                res.push_back(i);
            }
        }
        return res;    
    } 
};
