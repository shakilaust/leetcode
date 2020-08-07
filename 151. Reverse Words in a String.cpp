class Solution {
public:
    string reverseWords(string s) {
        
        vector < string > words;
        stringstream ss(s);
        string word;
        while( ss >> word ) { 
            words.push_back(word);
        }
        
        string ans = "";
        for( int i = words.size() - 1 , sp = 0 ; i >= 0 ; i-- , sp = 1 ) {

            if( sp ) { 
                ans += " ";
            }
            
            ans += words[i];
        }
        
        return ans;
        
    }
};
