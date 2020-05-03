class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int mx = 0, sum = 0;
        int sz = cardPoints.size();
        for( int i = 0 ; i < k ; i++ ) { 
            sum += cardPoints[i];
        }
        
        mx = max( mx, sum );
        
        for( int i = 0 ; i < k ; i++ ) { 
            sum -= cardPoints[k-i-1];
            sum += cardPoints[sz-i-1];
            mx = max(mx, sum);
        }
        
        return mx;
      
    }
};
