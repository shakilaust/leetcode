class MeetingSpot implements Comparator<MeetingSpot>{
    int time, flag;
    public MeetingSpot(int t, int f ) {
        this.time = t;
        this.flag = f;
    }
    
    public int compare(MeetingSpot a, MeetingSpot b) {
       if( a.time == b.time ) {
            return a.flag -  b.flag ;
        }
        return a.time - b.time;
    }
}

// class SortByTime implements Comparator<MeetingSpot> {
    
// }
class Solution {
    public int minMeetingRooms(int[][] intervals) {
        ArrayList<MeetingSpot> inp = new ArrayList<>();
        for( int[] interval: intervals) {
            inp.add( new MeetingSpot(interval[0], 2));
            inp.add( new MeetingSpot(interval[1], 1));
        }
        Collections.sort(inp, new MeetingSpot());
        int cnt = 0;
        int ans = 0;
        for( int i = 0 ; i < inp.size() ; i++ ) {
          
            if( inp.get(i).flag == 1 ) cnt--;
            else cnt++;
            ans = Math.max(ans, cnt);
        }
        return ans;
    }
}
