class Solution {
public:
    void printVec(vector< int> &inp) {
        for( int i = 0 ; i < inp.size() ; i++ ) {
            if( i ) cout << " ";
            cout << inp[i];
        }
        cout << endl;
    }
    vector<int> pancakeSort(vector<int>& arr) {
        vector < int > ans;
        int n = arr.size();
        int high = n - 1;
        while( high >= 0 ) {
            int mxIndx = 0;
            for( int i = 1 ; i <= high ; i++ ) {
               
                if( arr[i] >= arr[mxIndx] ) {
                    mxIndx = i;
                }
                
            }
            
            if( high != mxIndx ) {
               
                ans.push_back(mxIndx + 1);
                reverse( arr.begin(), arr.begin() + mxIndx + 1 );
               // printVec(arr);
                ans.push_back( high + 1 );
                reverse( arr.begin(), arr.begin() + high + 1 );
              //  printVec(arr);
            }
            high--;
           // cout << " HIGH " << high << endl;
        }
        
        return ans;
    }
};
