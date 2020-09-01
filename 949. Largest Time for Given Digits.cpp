class Solution {
public:
    

    string largestTimeFromDigits(vector<int>& A) {
        string ans = "";
        int mxTime = -1;
        sort( A.begin(), A.end() );
        do { 
            int hr = A[0] * 10 + A[1];
            int mn = A[2] * 10 + A[3];
            
            if( hr < 24 && mn < 60 ) { 
                
                int totalMin = hr * 60 + mn;
                if( mxTime == -1 || mxTime < totalMin ) { 
                    mxTime = totalMin;
                }
            }
        }while( next_permutation(A.begin(), A.end()));
        
        if( mxTime == -1 ) return ans;
        
        int hr = mxTime / 60;
        int mn = mxTime % 60;
        
        if( hr >= 10 ) { 
            ans += to_string( hr / 10 );
            ans += to_string( hr % 10 );
        }
        
        else { 
            ans += "0";
            ans += to_string(hr);
        }
        
        ans += ":";
        
        if( mn >= 10 ) { 
            ans += to_string( mn / 10 );
            ans += to_string( mn % 10 );
        } else { 
            ans += "0";
            ans += to_string(mn);
        }
        
        return ans;
        
        
        
    }
};
