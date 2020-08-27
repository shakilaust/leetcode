class Solution {
public:
    
    void merge(vector< int >&nums, int low, int mid, int high) { 
       
        int side1 = low, side2 = mid + 1;
        int idx = low;
        vector < int > lft, rgt;
        
        while( side1 <= mid ) lft.push_back(nums[side1++]);
        while(side2 <= high ) rgt.push_back( nums[side2++]);
        
        int l = 0, r = 0;
        
        while( l < lft.size() && r < rgt.size() ) { 
           if( lft[l] <= rgt[r] ) { 
                nums[idx++] = lft[l++];
            } else nums[idx++] = rgt[r++];
        }
        
        while( l < lft.size() ) nums[idx++] = lft[l++];
        while( r < rgt.size() ) nums[idx++] = rgt[r++];
        
       
        
    }
    
    int mergeSort(vector< int> &nums, int low, int high ) { 
        
        if( low >= high) return 0;
        int cnt = 0;
        int mid = low + ( high - low ) / 2;
        cnt = mergeSort( nums, low, mid) + mergeSort( nums, mid + 1 , high );
        int j = mid + 1;
        for( int i = low ; i <= mid ; i++ ) { 
            while( j <= high && nums[i] > nums[j] * 2LL ) j++;
            cnt += ( j - ( mid + 1) );
        }
        merge( nums, low, mid, high );
        return cnt;

    }
    int reversePairs(vector<int>& nums) {
        return  mergeSort( nums, 0 , nums.size() - 1 );
    }
};
