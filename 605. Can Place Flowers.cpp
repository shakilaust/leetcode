class Solution {
public:
    bool canPlaceFlowers(vector<int>& inp, int n) {
        
        bool lastIsFlower = false;
        for( int i = 0 ; i < inp.size() && n > 0 ; i++ ) {
            if( inp[i] == 0 ) {
                if( i + 1 == inp.size() ) {
                    if( lastIsFlower == false ) {
                        n--;
                        lastIsFlower = true;
                    } else lastIsFlower = false;
                } else {
                    if( lastIsFlower == false && inp[i + 1] == 0 ) {
                         lastIsFlower = true;
                        n--;
                    } else lastIsFlower = false;
                }
            } else lastIsFlower = true;
        }
        
        return n == 0;
    }
};
