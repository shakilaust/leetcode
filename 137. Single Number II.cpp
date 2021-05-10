class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set < int > uniqueNum;
        long long int sum = 0;
        for( int x: nums ) {
            uniqueNum.insert( x );
            sum += x;
        }
        long long int uniqueSum = 0;
        for( int x: uniqueNum ) {
            uniqueSum += x;
        }
        int ans = (3 * ( uniqueSum ) - sum ) / 2;
        return ans;
    }
};
