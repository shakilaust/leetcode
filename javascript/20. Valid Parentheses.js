/**
 * @param {string} s
 * @return {boolean}
 */

var isOpening = function(ch) {
    if( ch == '(' || ch == '[' || ch == '{') {
       return true;
    }
    return false;

}

var isMatching = function( a, b) {
    if( a == '(' && b == ')') {
        return true;
    } else if( a == '[' && b == ']') {
        return true;
    } else if( a == '{' && b == '}') {
        return true;
    } else {
        return false

    }
}
var isValid = function(s) {
    var stack = [];
    
    for( let i = 0 ; i < s.length ; i++ ) {
        if(isOpening(s[i]) ) {
            stack.push(s[i]);
        } else {
            if(stack.length ) {
                if(isMatching(stack[stack.length - 1], s[i] ) ) {
                    stack.pop();
                } else return false;
            } else return false;
        }
    }
    return stack.length == 0;
};
