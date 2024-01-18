// Water the Plants
// https://www.geeksforgeeks.org/problems/water-the-plants--170646/1

class Solution{
    public:
    int min_sprinklers(int gallery[], int n){
      int min_sprinklers(int gallery[], int n) {
    vector<pair<int, int>> arr;

    // Step 1: Construct a vector 'arr' of pairs representing sprinkler ranges
    for (int i = 0; i < n; i++) {
        if (gallery[i] == -1) continue;
        arr.push_back({max(0, i - gallery[i]), min(n-1, i + gallery[i])});
    }

    // Step 2: Sort the 'arr' vector based on the starting positions of sprinkler ranges
    sort(arr.begin(), arr.end()); 

    int i = 0, cnt = 0, j = 0, sz = arr.size();

    // Step 3: Iterate through the sorted sprinkler ranges to determine the minimum number of sprinklers needed
    while (i < n) {
        // If there is a gap before the current position, return -1 (impossible to cover)
        if (arr[j].first > i) return -1;

        int prev_i = i;

        // Step 4: Find the rightmost position a sprinkler can cover
        while (j < sz && arr[j].first <= prev_i) {
            i = max(i, arr[j].second + 1); // Update the current position
            j++;
        }

        // Increment the count of sprinklers turned on
        cnt++;
    }

    // Step 5: Return the minimum number of sprinklers needed
    return cnt;
}
