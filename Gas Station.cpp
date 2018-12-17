class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int sz = gas.size();
        int low = 0, high = 0, sumUpToLow = 0, rangeSum = 0;
        while( high < sz ) {
            
            rangeSum += ( gas[high] - cost[high] );
            while( rangeSum < 0 ) {
                int change = ( gas[low] - cost[low]);
                rangeSum -= change;
                sumUpToLow += change;
                low++;
            }
            high++;
        }
        
        if( sumUpToLow + rangeSum < 0 ) return -1;
        return low;
        
    }
};
