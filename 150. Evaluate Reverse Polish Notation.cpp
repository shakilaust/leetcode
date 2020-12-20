

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack < int > nums;
        string operatorStr = "/+*-";
        int ans = 0;
        for( string option: tokens ) {
            auto found = operatorStr.find(option);
            if( found != string::npos) {
                int one = nums.top();
                nums.pop();
                int two = nums.top();
                nums.pop();
                int value;
                if( option == "+" ) value = ( two + one );
                else if( option == "-" ) value = ( two - one );
                else if( option == "*" ) value = ( two * one );
                else if( option == "/" ) value = ( two / one );
                nums.push(value);
               
            } else {
                int value = stoi(option);
             
               nums.push(value);
            }
        }
        return nums.top();
    }
};
