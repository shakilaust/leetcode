class Solution {
public:
    vector<int> relativeSortArray(vector<int>& a, vector<int>& b) {
        vector < int > ans;
        int freq[1005] = {0};
        int sz = a.size();
        
        for( int x: a) { 
            freq[x]++;
        }
        
        for( int x: b ) { 
            while( freq[x]--) { 
                ans.push_back(x);
            }
        }
        
        for( int i = 0 ; i < 1005 ; i++ ) { 

            while( freq[i] > 0 && freq[i]-- ) { 
                ans.push_back(i);
              //  cout << " freq " << freq[i] << endl;
            }
          //  cout << i << " endl" << endl;
        }
        
        
        return ans;
    }
};
