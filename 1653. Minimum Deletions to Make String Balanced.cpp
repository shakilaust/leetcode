class Solution {
public:
    int minimumDeletions(string s) {
        int sz = s.size();
        vector < int > leftA, leftB, rightA, rightB;
        for( int i = 0 ; i < sz ; i++ ) {
            leftA.push_back(0);
            leftB.push_back(0);
            rightA.push_back(0);
            rightB.push_back(0);
        }
        int a = 0, b = 0;
        for( int i = 0 ; i < sz ; i++ ) {
            leftA[i] = a;
            leftB[i] = b;
            if( s[i] == 'a' ) a++;
            else b++;
        }
        a = 0;
        b = 0;
        int firstBIdx = -1;
        for( int i = sz - 1 ; i >= 0 ; i-- ) {
            rightA[i] = a;
            rightB[i] = b;
            if( s[i] == 'a' ) a++;
            else {
                b++;
                firstBIdx = i;
            }
        }
        int ans = sz;
        int possibleAns = 0;
        for( int i = sz - 1 ; i >= 0 ; i-- ) {
            if( s[i] == 'a' ) {
                possibleAns = rightB[i] + leftB[i];
                ans = min( ans, possibleAns );
                possibleAns = rightA[i] + leftB[i];
                ans = min( ans, possibleAns );
            } else {
                possibleAns = rightA[i];
                if( i != firstBIdx ) {
                    possibleAns += ( rightA[firstBIdx] - rightA[i] );
                }
                ans = min( possibleAns, ans);
            }
        }
        return ans;
    }
};
