class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
      
        string one = "", two = "";
        for( string tmp: word1) {
            one += tmp;
        }
        for( string tmp: word2) {
            two += tmp;
        }
        return one == two;
    }
};
