class Solution {
public:
    
    string making;
    void dfs( int pos, int newStart, int value, int partition, string &inp, vector < string >&ans) {
        
        if( value > 255 || ( newStart == 0 && value == 0 && pos != inp.size() ) ) return;
        if( pos == inp.size() ) {
            if( partition == 4 ) {
                if( value >= 0 && value <= 255 ) {
                    ans.push_back(making);
                }
            }
            return;
        }
        
        int now = inp[pos] - '0';
        int partitionValue = ( value * 10 ) + now;
        making += inp[pos];
        if( partition < 4 && pos + 1 != inp.size() ) { // check we can make a partition or not
           
            if ( partitionValue >= 0 && partitionValue <= 255 ) {
                making += ".";
                dfs( pos + 1 , 1, 0 , partition + 1 , inp, ans );
                making.pop_back();
            }
            
        }
       
        dfs( pos + 1 , 0,  partitionValue ,  partition , inp , ans  );
         
        making.pop_back();
        
    }
    vector<string> restoreIpAddresses(string s) {
        vector < string > ans;
        making = "";
        dfs( 0 , 1, 0 , 1 , s , ans );
        return ans;
        
    }
};
