class Solution {
public:
    string removeDuplicateLetters(string s) {
        int freq[26] = {0};
        bool taken[26] = {false};
        string ans = "";
        for( char ch: s ) { 
            int cur = ch - 'a';
            freq[cur]++;

        }
        
        for( char ch: s ) { 
            int cur = ch - 'a';
            freq[cur]--;
            if( taken[cur] ) continue;
            while(!ans.empty() && ch < ans.back() && freq[ans.back() - 'a'] > 0 ) { 
                taken[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            
            ans += ch;
            taken[cur] = true;

        }
        
        return ans;
    
    }
};
