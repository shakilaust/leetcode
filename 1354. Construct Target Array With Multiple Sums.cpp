class Solution {
public:
    bool isPossible(vector<int>& target) {
        
        int sz = target.size();
        if( sz == 1 ) {
            return target[0] == 1;
        }
        priority_queue <  long long int > pq;
        long long int sum = 0;
        for( int x: target ) {
            sum += x;
            pq.push(x);
        }
        
        
        while( pq.top() > 1 ) {
             long long int top=pq.top();pq.pop();
            if(top==0)continue;
            if(top==1)
            {
                sum-=1;
                continue;
            }
            long long int sumRem=sum-top;
            if(sumRem<=1)return sumRem;
            if(top-sumRem<=0)return false;
            sum-=top;
            pq.push(top%(sumRem));
            sum+=top%sumRem;
        }
        
        
        
        return true;
    }
};
