class Solution {
public:

    // Encodes a URL to a shortened URL.
    unordered_map < string, string > ump;
    string alphanum = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    
    string uniqueStr() {
        string ans = "";
        int len = alphanum.size();
        bool unique = false;
        while( !unique ) {
            ans = "";
            for( int i = 0; i < 6 ; i++ ) {
                ans += alphanum[ rand() % len ];
            }
            if( ump.find(ans) == ump.end() ) {
                unique = true;
            }
        }
        return ans;
    }
    string encode(string longUrl) {
        string shortUrl = uniqueStr();
        ump[shortUrl] = longUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return ump[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
