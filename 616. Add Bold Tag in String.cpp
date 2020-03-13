class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        int sSz = s.size();
        vector < int > tags( sSz + 2 , 0 );
        int dSz = dict.size();
        string ans = "";
        for( int i = 0 ; i < dSz ; i++) { 
            for( int j = 0 ; j < sSz ; j++ ) { 

             
                if( s.substr(j , dict[i].size() ) == dict[i] ) { 
                    
                    tags[j] += 1;
                    tags[j+dict[i].size()] -= 1;
                 
                }
            }
        }
        
        for( int i = 0 ; i < sSz ; i++ ) { 
            tags[i] += ( i ? tags[i-1] : 0 );
            if( i == 0 && tags[i] >= 1 ) { 
                ans += "<b>";
            } else if( tags[i] >= 1 && tags[i-1] == 0 ) { 
                ans += "<b>";
            } else if( i - 1 >= 0 && tags[i] == 0 && tags[i-1] >= 1 ) { 
                ans += "</b>";
            } 
            
            ans += s[i];
            
            if( i + 1 == sSz && tags[i] >= 1 ) { 
                ans += "</b>";
            }
        }
        
        return ans;
    }
};
