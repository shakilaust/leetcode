class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_map< int, int > freq;
        for( int i = 0 ; i < nums.size() ; i++ ) { 
            freq[nums[i]]++;
        }   
        
        for( int i = 0 ; i < nums.size() ; i++ ) { 
            if(freq[nums[i]] == 0 ) continue;
            int mn = freq[nums[i]];
            int x = nums[i];
            for( int j = 0 ; j < k ; j++, x++ ) { 

                if( freq[x] < mn ) return false;
                freq[x] -= mn;
            }

        }
        
        return true;
    }
};
