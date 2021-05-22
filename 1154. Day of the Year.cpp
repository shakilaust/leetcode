class Solution {
public:
    
    bool isLeapYear( int year ) {
        if( year % 400 == 0 || ( year % 4 == 0 && year % 100 != 0 ) ) {
            return true;
        }
        return false;
    }
    
    int monthToDays( int month, int year ) {
        if( month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12 ) {
            return 31;
        } else if( month == 2 ) {
            if( isLeapYear(year) ) {
                return 29;
            }
            return 28;
        }
        return 30;
    }
    
    int dayOfYear(string date) {
       int month = ( date[5] - '0') * 10 + ( date[6] - '0');
       int day = ( date[8] - '0' )  * 10 + ( date[9] - '0' );
       int year = ( date[0] - '0' ) * 1000 + ( date[1] - '0' ) * 100 + ( date[2] - '0' ) * 10 + ( date[3] - '0' );   
        int days = day;
        for( int i = 1 ; i < month ; i++ ) {
          
            days += monthToDays(i, year);
        }
        
        return days;
        
    }
};
