int sFreq[26] = {0};
int pFreq[26] = {0};

bool isAnagram() { 

    for( int i = 0 ; i < 26 ; i++ ) if( sFreq[i] != pFreq[i] ) return false;
    return true;
}

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

       int psz = p.size();
       int ssz = s.size();
       for(int i = 0 ; i < 26 ; i++ ) {
            pFreq[i] = sFreq[i] = 0;
        }
       for( int i = 0 ; i < psz ; i++ ) { 
            pFreq[p[i] - 'a']++;
        }
        int low = 0, high = 0;
        vector < int > ans;
        
        while( high < ssz ) { 

            sFreq[s[high] - 'a']++;
            
            while( low <= high && sFreq[s[low] - 'a'] > pFreq[s[low] - 'a'] ) {
                sFreq[s[low]-'a']--;
                low++;
            }
          //  cout << " low " << low << " high " << high << endl;
            if(high - low + 1 == psz && isAnagram() ) { 
                ans.push_back(low);
                sFreq[s[low]-'a']--;
                low++;
            }
            
            high++;
            
        }
        
        return ans;
    }
};
