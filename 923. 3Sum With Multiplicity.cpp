const int mod = 1e9 + 7;

class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        long long int count[105] = {0};
        for( int i = 0 ; i < A.size() ; i++ ) { 
            count[A[i]]++;
        }
        
        vector < int > values;
        for( int i = 0 ; i <= 100 ; i++ ) { 

            if(count[i] > 0 ) { 
                values.push_back(i);
            }
        }

        long long int ans = 0;
        for( int i = 0 ; i < values.size(); i++ )  {
            int a = values[i];
            int lookFor = target - a;
            int j = i, k = values.size() - 1;
            while( j <= k ) { 
                int b = values[j];
                int c = values[k];
                
                if( b + c > lookFor ) k--;
                else if( b + c < lookFor ) j++;
                else { 
                    if( i < j && j < k ) { 
                        ans += ( count[a] * count[b] * count[c] );
                    } else if( i == j && j < k ) { 
                        ans += ( count[a] * ( count[a] - 1 ) ) / 2 * count[c];
                    } else if( i < j && j == k ) { 
                        ans += ( count[b] * ( count[b] - 1 ) ) / 2 * count[a];
                     } else // i == j == k 
                        ans +=  count[a] * ( count[a] - 1 ) * ( count[a] - 2 )  / 6;
                    
                    ans %= mod;
                    j++;
                    k--;
            
                }

            }
        }
        
        return ans;
    }
};
