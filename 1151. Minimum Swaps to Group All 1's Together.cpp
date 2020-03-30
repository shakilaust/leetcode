class Solution {
public:
    int minSwaps(vector<int>& data) {
       for( int i = 1 ; i < data.size() ; i++ ) {
            data[i] += data[i-1];
        }
        
        int K = data.back();
        if( K == 0 ) return 0;
        int mxOne = data[K-1];
        for( int i = K ; i < data.size() ; i++ ) {
            mxOne = max(mxOne, data[i] - data[i-K]);
        }
        
        return K - mxOne;
    }
};
