
bool isPalindrome(string &a) { 

    int low = 0, high = a.size() - 1;
    while( low < high ) if( a[low++] != a[high--]) return false;
    return true;
}

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map < string, int > pos;
        for( int i = 0 ; i < words.size() ; i++ ) {
            string s = words[i];
            reverse(s.begin(), s.end());
            pos[s] = i + 1;
        }

        vector< vector< int > > ans;
        
        for( int i = 0 ; i < words.size() ; i++ ) { 

            for( int j = 0 ; j <= words[i].size(); j++ ) {

                string left = words[i].substr(0, j);
                string right = words[i].substr(j);
                if( pos[left] > 0 && pos[left] - 1 != i && isPalindrome(right) ) { 
                    ans.push_back({ i, pos[left] - 1 } );
                }
                
                if(  !left.empty() && isPalindrome(left) && pos[right] > 0 && pos[right] != i + 1 )  { 

                    ans.push_back({ pos[right] - 1, i } );
                }
                
            }
        }
        
        return ans;
    }
};
