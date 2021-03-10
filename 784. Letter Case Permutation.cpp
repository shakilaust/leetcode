class Solution {
public:
    vector <string > answer;
    string inp;
    string cur;
    int len;
    void generateAll(int pos) {
        if( pos == len ) {
            answer.push_back(cur);
            return;
        }
        if( isalpha(inp[pos])) {
            cur += tolower(inp[pos]);
            generateAll(pos+1);
            cur.pop_back();
            cur += toupper(inp[pos]);
            generateAll(pos + 1 );
            cur.pop_back();
        } else {
            cur += inp[pos];
            generateAll(pos + 1 );
            cur.pop_back();
        }
    }
    vector<string> letterCasePermutation(string S) {
        answer.clear();
        inp = S;
        cur = "";
        len = S.size();
        generateAll(0);
        return answer;
    }
};
