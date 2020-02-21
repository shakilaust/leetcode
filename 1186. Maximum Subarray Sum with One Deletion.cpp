class Solution {
public:
    int maximumSum(vector<int>& a) {
        
        int ans = a[0];
        int suffixMxSum = a[0];
        int suffixMxSumDel = 0;
        int sz = a.size();
        for( int i = 1 ; i < sz ; i++ ){ 
            suffixMxSumDel = max(suffixMxSumDel + a[i] , suffixMxSum );
            suffixMxSum = max( suffixMxSum + a[i], a[i] );
            ans = max( ans, max( suffixMxSum, suffixMxSumDel));
        }
        return ans;
    }
};
