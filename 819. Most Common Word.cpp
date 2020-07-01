class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        
        
        unordered_map< string, bool > ban;
        unordered_map< string, int > freq;
        
        for( string word: banned) { 
            ban[word] = true;   
        }
        

        
        int most = 0;
        string ans = "";
        string word = "";
        
        for( int i = 0 ; i < paragraph.size() ; i++ ) {
            
            char ch = paragraph[i];
            if(isalpha(ch)) {
                word += tolower(ch);
            } else if( word.size() > 0 ){ 
                
                if( word.size() > 0 ) freq[word]++;
                
                if( ban.find(word) == ban.end() && freq[word] > most ) {
                    ans = word;
                    most = freq[word];
                }
                word = "";

            }

        }
        
        if( word.size() > 0 ) { 

            if( word.size() > 0 ) freq[word]++;
                
                if( freq[word] > most ) {
                    ans = word;
                   
                }
        }
        
        
        
        
        
        
        return ans;
        
    }
};
