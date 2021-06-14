

class Solution {
public:
   
 
    int numSpecialEquivGroups(vector<string>& A) {
       
        set < string > has;
        for( string now: A ) {
            string even = "", odd = "";
            for( int i = 0 ; i < now.size() ; i++ ) {
                if( i % 2 ) odd += now[i];
                else even += now[i];
            }
            sort( even.begin(), even.end());
            sort( odd.begin(), odd.end());
            
            has.insert( odd + even );
        }
        
        return has.size();
       
       
    }
};
