class Solution {
public:
    string removeKdigits(string num, int k) {
        
        int sz = num.size();
        vector < bool > notTaken( sz + 1 , false );
        string answer = "";
        bool already = false;
        for( int i = 0 ; i < sz  ; i++ ) { 

            for( int j = i + k ; j > i && k > 0; j-- ) { 

                if( num[i] > num[j] ) { 
                    notTaken[i] = true;
                    k--;
                    break;
                    
                }
            }
            if( num[i] == '0' && already == false ) {
                continue;
            }
            else if( notTaken[i] == false ) {
                
                answer += num[i];
                already = true;

            }
        }
        
        if( answer == "" ) answer = "0";
        return answer;

        
        
        
    }
};
