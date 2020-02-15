class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int sz = nums.size();
        set < int > uniqueNums;
        unordered_map < int, int > value;
        vector < int > answer(sz, 0);
        vector < int > hasCount( sz + 1, 0 );
        for( auto it: nums ) uniqueNums.insert(it);
        int idx = 1;
        for( auto item: uniqueNums ) { 
            value[item] = idx++;
        }
        for( int i = sz - 1 ; i >= 0 ; i-- ) { 

            int prevItemPosition = value[nums[i]] - 1;
            answer[i] = hasCount[prevItemPosition];
            int curItemPosition = prevItemPosition + 1;
            hasCount[curItemPosition]++;
            for( int j = curItemPosition + 1 ; j < idx ; j++ ) hasCount[j]++;
            
        }

        return answer;
    }
};
