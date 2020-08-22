class Solution {
public:
    
    double getMinValue( int n, int m, int &idx0, int &idx1, vector<int>& nums1, vector<int>& nums2) {
        double ans;
        if( idx0 < n && idx1 < m ) { 
            if( nums1[idx0] <= nums2[idx1] ) { 
                ans = nums1[idx0];
                idx0++;
            } else {
                ans = nums2[idx1++];
            }
        } else if( idx0 < n ) { 
            ans = nums1[idx0++];
        } else { 
            ans = nums2[idx1++];
        }
        
        return ans;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector < int > medianIdx;
        int total = n + m;
        int minTarget = total / 2;
        if( total % 2 == 0 ) minTarget -= 1;
        
        int idx0 = 0, idx1 = 0;
        while( minTarget > 0 ) { 
            if( idx0 < n && idx1 < m ) { 
                if( nums1[idx0] <= nums2[idx1] ) { 
                    idx0++;
                } else { 
                    idx1++;
                }
            } else if( idx0 < n ) { 
                idx0++;
            } else idx1++;
            
            minTarget--;
        }
        
        double ans = getMinValue( n , m , idx0, idx1 , nums1, nums2 );
        if( total % 2 == 0 ) { 
            ans = ans + getMinValue( n , m , idx0, idx1 , nums1, nums2 );
            ans = ans / 2.0;
        }
        
        return ans;

        
        
        
    }
};
