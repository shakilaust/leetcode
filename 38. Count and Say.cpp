class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        while( --n ) { 
            string now = "";
            int cnt = 1;
            char prv = ans[0];
            for( int i = 1 ; i < ans.size() ; i++ ) { 
                if( prv != ans[i] ) { 
                    now += to_string(cnt);
                    now += prv;
                    prv = ans[i];
                    cnt = 1;
                } else cnt++;
            }
            
            now += to_string(cnt);
            now += prv;
            
            ans = now;
            
        }
        
        return ans;
    }
};
