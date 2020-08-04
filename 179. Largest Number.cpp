bool cmp(string a, string b) { 
    
    return a + b > b + a;

}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector < string > inp;
        for( int num: nums) { 
            inp.push_back(to_string(num));
        }
        sort(inp.begin(), inp.end(), cmp);
        string res = "";
        
        for( string now: inp) { 
            res += now;
        }
        
        while( res[0] == '0' && res.size() > 1 ) { 
            res.erase(res.begin());
        }
        
        return res;
    }
};
