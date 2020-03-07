class Solution {
public:
    string nextClosestTime(string time) {
        string ans = time;
        
        int hr = (time[0] - '0') * 10 + ( time[1] - '0');
        int min = (time[3] - '0') * 10 + ( time[4] - '0');
        int startingMins = (hr * 60 ) + min;
        
        int digitPresent[10] = {0};
        digitPresent[time[0]-'0'] = 1;
        digitPresent[time[1]-'0'] = 1;
        digitPresent[time[3]-'0'] = 1;
        digitPresent[time[4]-'0'] = 1;
        
        int wholeMins = 60 * 24;
        int curMins = startingMins;
        curMins = ( curMins + 1 ) % wholeMins;
        
        int diffInMins = -1;
     //   cout << "curMins " << curMins << endl;
        bool notFound = true;
        while(notFound) { 
           // cout << " curMins " << curMins << endl;
            int hr = (curMins) / 60;
            int min = (curMins ) % 60;
            notFound = false;
            if( hr < 10 ) { 
                if(digitPresent[hr] == 0 ) notFound = true;
                if(digitPresent[0] == 0 ) notFound = true;
            } else {
                if(digitPresent[hr/10] == 0 ) notFound = true;
                if(digitPresent[hr%10] == 0 ) notFound = true;
           }
            
           if( min < 10 ) { 
                if(digitPresent[min] == 0 ) notFound = true;
                if(digitPresent[0] == 0 ) notFound = true;
            } else {
                if(digitPresent[min/10] == 0 ) notFound = true;
                if(digitPresent[min%10] == 0 ) notFound = true;
           }
            
           if(notFound == false) { 
               
                    if(hr < 10 ) {
                        ans[0] = '0';
                        ans[1] = hr + '0';
                    } else {
                        ans[0] = (hr / 10 ) + '0';
                        ans[1] = (hr % 10 ) + '0';
                    }

                     if(min < 10 ) {
                        ans[3] = '0';
                        ans[4] = min + '0';
                    } else {
                        ans[3] = (min / 10 ) + '0';
                        ans[4] = (min % 10 ) + '0';
                    }
               
               break;

            }
            curMins = ( curMins + 1 ) % wholeMins;
        }
        
        return ans;
    }
};
