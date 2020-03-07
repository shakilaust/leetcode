class Solution {
public:
    bool isPossible( double dis, vector<int> &stations, int K) { 
        int used = 0;
        for( int i = 1; i < stations.size(); i++ ) { 
            used += (int) (stations[i] - stations[i-1])/dis;
            if( used > K ) return false;
            
        }
        
        return true;
    }
    double minmaxGasDist(vector<int>& stations, int K) {
        double eps = 1e-6;
        double low = 0;
        double high = 1e8;
        while( high - low >= eps ) {

            double mid = ( low + high ) / 2.0;
            if( isPossible( mid, stations, K) ) { 
                high = mid;
            } else { 
                low = mid;
            }   
        }
        
        return low;
    }
};
