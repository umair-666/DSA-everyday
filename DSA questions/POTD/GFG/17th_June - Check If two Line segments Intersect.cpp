// Check If two Line segments Intersect
// https://www.geeksforgeeks.org/problems/check-if-two-line-segments-intersect0017/1

class Solution {
    int direction(int p[], int q[], int r[]){
    long long val = (long long)(q[1] - p[1]) * (r[0] - q[0]) - (long long) (q[0] - p[0]) * (r[1] - q[1]);
    if (val == 0) {
        return 0;
    }
    if (val > 0){
        return 1;
    }
    else {
        return -1;
    }
}

int func(int p[], int q[], int r[]){
    if (q[0] <= max(p[0] , r[0]) && q[0] >= min (p[0] ,r[0]) && q[1] <= max(p[1] , r[1]) && q[1] >= min(p[1] , r[1])){
        return 1;
    }
    else{
        return 0;
    }
}
  public:
    string doIntersect(int p1[], int q1[], int p2[], int q2[]) {
       int d1 = direction(p1, q1, p2);
        int d2 = direction(p1, q1, q2);
        int d3 = direction(p2, q2, p1);
        int d4 = direction(p2, q2, q1);
        
        if (d1 != d2 && d3 != d4){
            return "true";
        }
        if(d1 == 0 && func(p1, q1, p2)) {
            return "true";
        }
        else if(d2 == 0 && func(p1 , q1, q2)) {
            return "true";
        }
        else if(d3 == 0 && func(p2 , q2, p1)) {
            return "true";
        }
        else if(d4 == 0 && func(p2 ,q2, q1)) {
            return "true";
        }
        return "false";
    }
};
