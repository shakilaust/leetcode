int divisiorSum( int num ) { 

    int ans = 0, cnt = 0;
    
    for( int i = 1 ; i <= num / i ; i++ ) { 

            if( num % i == 0 ) { 
                ans += i;
                cnt++;
                int y = num/i;
                if( i != y ) { 
                    ans += y;
                    cnt++;
                }

            }
    }
    
    return cnt == 4 ? ans : 0;
}


class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        
        int ans = 0;
        for( int i = 0 ; i < nums.size(); i++ ) ans += divisiorSum(nums[i]);
        return ans;
    }
};
