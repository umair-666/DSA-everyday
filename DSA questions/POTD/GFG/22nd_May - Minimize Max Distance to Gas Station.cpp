//Minimize Max Distance to Gas Station
//https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1

class Solution {
  public:
    double findSmallestMaxDist(vector<int> &stations, int k) {
        int n = stations.size();
        double l = 0, r = 1e8;
        double ans;
        auto check = [&](double mid) -> bool {
            int cnt = 0;
            for (int i = 0; i < n - 1; i++) {
                double dist = stations[i + 1] - stations[i];
                cnt += ceil(dist / mid)-1;
            }
            return cnt <= k;
        };
        while(r-l > 1e-6){
            double mid = (l+r)/2;
            if(check(mid)){
                ans = mid;
                r = mid;
            }
            else
                l = mid;
            
        }
        return ans;
    }
};
