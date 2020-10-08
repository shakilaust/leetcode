class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        bool space = false;
        string ans = "";
        while( ss >> word ) {
            reverse(word.begin(), word.end());
        
            ans += ( space ? " " + word : word );
            space = true;
            
        }
        return ans;
    }
};
