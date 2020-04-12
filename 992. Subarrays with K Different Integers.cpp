class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        unordered_map < int, int > window1, window2;
        int left1 = 0, left2= 0;
        int unique1 = 0, unique2 = 0;
        int ans = 0;
        for( int right = 0 ; right < A.size() ; right++ ) { 

            window1[A[right]]++;
            window2[A[right]]++;
            if( window1[A[right]] == 1 ) unique1++;
            if( window2[A[right]] == 1 ) unique2++;
            while( unique1 > K ) { 
                window1[A[left1]]--;
                if( window1[A[left1]] == 0 ) unique1--;
                left1++;
            }
            
            while( unique2 >= K ) { 
                window2[A[left2]]--;
                if(window2[A[left2]] == 0 ) unique2--;
                left2++;
            }
            
            ans =  ans + (left2 - left1);
        }
        
        return ans;
    }
};
