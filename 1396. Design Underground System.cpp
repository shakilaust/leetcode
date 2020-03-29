class UndergroundSystem {
   map < pair< string, string > , int > times, total; 
   unordered_map < int, string > checkInFrom;
   unordered_map < int, int > checkInTime;
public:
    UndergroundSystem() {
        times.clear();
        total.clear();
        checkInFrom.clear();
        checkInTime.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInFrom[id] = stationName;
        checkInTime[id] = t;
        
    }
    
    void checkOut(int id, string stationName, int t) {
        int needed = t - checkInTime[id];
        times[{checkInFrom[id], stationName}] += needed;
        total[{checkInFrom[id], stationName}] += 1;
        
    }
    
    double getAverageTime(string startStation, string endStation) {
        double ans = ( double ) times[{startStation, endStation}] / ( double ) total[{startStation, endStation}] ;
        return ans;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
