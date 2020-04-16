const int mod = 1e9 + 7;
class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int n = A.size();
        vector < int > left(n, 0);
        int ans = 0;
        stack < pair< int, int >> st;
        for( int i = 0 ; i < n ; i++ ) { 
            int cnt = 1;
            while(!st.empty() && st.top().first > A[i] ) { 
                cnt += st.top().second;
                st.pop();
            }
            
            st.push({A[i], cnt});
            left[i] = cnt;

        }
        
        while(!st.empty()) st.pop();
        
         for( int i = n - 1 ; i >= 0 ; i-- ) { 
            int cnt = 1;
            while(!st.empty() && st.top().first >= A[i] ) { 
                cnt += st.top().second;
                st.pop();
            }
            
            st.push({A[i], cnt});
            int add = ( left[i] * A[i] * cnt ) % mod;
            ans = ( ans + add ) % mod;
        
        }
        return ans;
    }
};
