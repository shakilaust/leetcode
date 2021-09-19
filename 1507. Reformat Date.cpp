class Solution {
public:
    string reformatDate(string date) {
        map < string, string > month;
        month["Jan"] = "01";
        month["Feb"] = "02";
        month["Mar"] = "03";
        month["Apr"] = "04";
        month["May"] = "05";
        month["Jun"] = "06";
        month["Jul"] = "07";
        month["Aug"] = "08";
        month["Sep"] = "09";
        month["Oct"] = "10";
        month["Nov"] = "11";
        month["Dec"] = "12";
        int iter = 0; // 0: date, 1: month, 2: year;
        string year, mon, day = "";
        
       
        stringstream ss(date);
        string now;
        while( ss >> now ) {
            
            if( iter == 0 ) {
             //  cout << " now " << now[0] <<endl;
                if( now.size() == 3 ) {
                    day = "0";
                    day += now[0];
                } else {
                    day += now[0];
                    day += now[1];
                   // cout << " day " << day << endl;
                }
                
            } else if( iter == 1) {
                mon = month[now];
            } else {
                year = now;
            }
            iter++;
            
        }
        
         return year+"-"+mon+"-"+day;
    }
};
