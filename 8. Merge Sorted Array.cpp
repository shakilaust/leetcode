class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int sz = n + m - 1;
        m -= 1;
        n -= 1;
        while( sz >= 0 && n >= 0 && m >= 0 ) { 
            if( nums1[m] >= nums2[n] ) { 
                nums1[sz] = nums1[m--];
            } else { 
                nums1[sz] = nums2[n--];
            }
            sz--;
        }
        
        while( m >= 0 ) { 
            nums1[sz--] = nums1[m--];
        }
        
        while( n >= 0 ) { 
           nums1[sz--] = nums2[n--];
        }
        
       
    }
};
