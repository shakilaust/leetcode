class MyCalendarTwo {
    TreeMap < Integer, Integer > myMap;

    public MyCalendarTwo() {
        myMap = new TreeMap();
    }
    
    public boolean book(int start, int end) {
        myMap.put( start, myMap.getOrDefault(start, 0 ) + 1 );
        myMap.put(end, myMap.getOrDefault(end, 0 ) - 1 );
        
        int cnt = 0;
        for( int v: myMap.values()) {
            cnt += v;
            if( cnt >= 3 ) {
                myMap.put(start, myMap.get(start) - 1 );
                myMap.put(end, myMap.get(end) + 1 );
                if( myMap.get(start) == 0 ) {
                    myMap.remove(start);
                }
                return false;
            }
        }
        return true;
    }
}

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * boolean param_1 = obj.book(start,end);
 */
