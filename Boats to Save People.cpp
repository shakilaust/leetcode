class Solution {
public:
    int weight[30005] = {0};
    int numRescueBoats(vector<int>& people, int limit) {
        int sz = people.size();
        for( int i = 0 ; i < sz ; i++ ) weight[people[i]]++;
        int ans = 0, low = 0, high = limit, need = sz;
        while( low <= high && need) {
            while(weight[high] == 0 && high > 0) high--;
            while(weight[low] == 0 && low < limit ) low++;
            if(weight[low] && weight[high] && low + high <= limit ) {
                int minValue = min(weight[low], weight[high]);
                weight[low] -= minValue;
                weight[high] -= minValue;
               
                if( low != high ) {
                     ans += minValue;
                     need -= ( minValue + minValue);
                }
                else {
                    ans += ( minValue/2) + ( minValue % 2 == 0 ? 0 : 1 );
                    need -= minValue;
                }

            }
            else if(weight[high] && low + high > limit ) {
                ans += weight[high];
                need -= weight[high];
                weight[high] = 0;
                high--;
            }
            else if(low == high ) {
                ans += weight[high];
                ans += weight[low];
                
                need -= (weight[low] + weight[high]);
                    
                weight[high] = 0;
                weight[low] = 0;
            }
        }
        return ans;
    }
};
