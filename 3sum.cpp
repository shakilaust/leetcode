set < vector < int > > alreadyFound;
vector < vector < int > > answer;
vector < int > tmp;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        alreadyFound.clear();
        answer.clear();
        int sz = nums.size();

       
        for( int i = 0 ; i < sz ; i++ ) {
            tmp.clear();
            for( int j = i + 1 ; j < sz ; j++ ) {
                if( nums[i] + nums[j] > 0 ) break;
                int need = 0 - ( nums[i] + nums[j]);
                int low = lower_bound(nums.begin() + j + 1 , nums.end(), need) - nums.begin();
                int high = upper_bound(nums.begin() + j + 1 , nums.end(), need) - nums.begin();
                if( high > low ) { 
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(need);
                    if(alreadyFound.find(tmp) == alreadyFound.end()){ 
                        alreadyFound.insert(tmp);
                        answer.push_back(tmp);
                        
                    }
                    tmp.clear();
                }
              
                
            }
        }
        
        
        return answer;
        
    }
};
