class Solution {
public:
    string intToRoman(int num) {
        unordered_map < int, string > numberToRoman;
        vector < int > digits{ 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
        numberToRoman[1000] = "M";
        numberToRoman[900] = "CM";
        numberToRoman[500] = "D";
        numberToRoman[400] = "CD";
        numberToRoman[100] = "C";
        numberToRoman[90] = "XC";
        numberToRoman[50] = "L";
        numberToRoman[40] = "XL";
        numberToRoman[10] = "X";
        numberToRoman[9] = "IX";
        numberToRoman[5] = "V";
        numberToRoman[4] = "IV";
        numberToRoman[1] = "I";
        
        string ans = "";
        for( int i = 0 ; i < digits.size(); i++ ) {
            while( num >= digits[i] ) {
                ans += numberToRoman[digits[i]];
                num -= digits[i];
            }
        }
        return ans;
        
        
    }
};
