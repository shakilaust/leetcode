const int NX = 50000 + 10;

int mainArray[ NX ];
vector < pair< int, int> > snapShots[ NX ];


class SnapshotArray {
    int snapNumber = 0;
public:
    SnapshotArray(int length) {
      
      
        for( int i = 0 ; i < length ; i++ ) { 
            snapShots[i].clear();
            mainArray[i] = 0;
        }
        snapNumber = 0;
    }
    
    void set(int index, int val) {
        mainArray[index] = val;
        snapShots[index].push_back(make_pair(snapNumber, val));
    }
    
    int snap() {
        snapNumber++;
        return snapNumber - 1;
    }
    
    int get(int index, int snap_id) {
        if(snapShots[index].size() == 0 ) // no entry
        {   
            return 0;
        } else if( snap_id >= snapShots[index][snapShots[index].size()-1].first) { 
            return mainArray[index];
         } else { 

            int ans = 0;
            for( int i = 0 ; i < snapShots[index].size() ; i++ ) { 
                if( snap_id < snapShots[index][i].first ) break;
                ans = snapShots[index][i].second;
            }
            return ans;
        }
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
