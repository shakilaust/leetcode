class Solution {
public:
    void generateAll(int n, int open, int close, string inp, vector < string > &answer) { 
        if( open == n && close == n ) { 
            answer.push_back(inp);
            return;
        }
        if( open == n ) { 
                 generateAll( n , open , close + 1 , inp + ")" , answer );
         } else if( open == close ) { 
                 generateAll( n , open + 1 , close , inp + "(", answer );
        }  else  {
                 generateAll( n , open + 1 , close , inp + "(", answer);
                 generateAll( n , open , close + 1 , inp + ")" , answer );
        }
    }
    vector<string> generateParenthesis(int n) {
    vector < string > answer;
    generateAll(n, 0, 0, "", answer);
    return answer;
        
    }
};
