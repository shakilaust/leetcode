class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector < int > ans;
        
        bool subdivided = false;
        for( int i = 0 ; i < input.size() ; i++ ) { 
    
            if( ispunct(input[i])) { 
                subdivided = true;
                for( int a: diffWaysToCompute( input.substr(0, i))) {
                    
                    for( int b: diffWaysToCompute( input.substr(i + 1 ) ) ) { 
                        
                        if( input[i] == '+' ) ans.push_back( a + b );
                        else if( input[i] == '-' ) ans.push_back( a - b );
                        else ans.push_back( a * b );
                    }
                }
            }
        }
        
        if( subdivided == false ) { 
            ans.push_back( stoi(input));
        }
        
        return ans;
        
       
    }
};
