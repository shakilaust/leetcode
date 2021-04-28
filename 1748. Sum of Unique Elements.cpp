class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map < int, int > freq;
        int sum = 0;
        for( int x: nums ) {
            if( freq[x] == 0 ) {
                sum += x;
                freq[x]++;
            } else if( freq[x] > 0 ) {
                sum -= x;
                freq[x] = INT_MIN;
            }
        }
        return sum;
    }
};
