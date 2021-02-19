class Solution {
    public String removeDuplicateLetters(String s) {
        Stack<Character> stack = new Stack<>();
        HashSet<Character> seen = new HashSet<>();
        HashMap<Character, Integer> lastOccurance = new HashMap<>();
        
        for( int i = 0 ; i < s.length(); i++ ) {
            lastOccurance.put(s.charAt(i), i);
        }
        
        for( int i = 0 ; i < s.length(); i++ ) {
            char ch = s.charAt(i);
            
            if(!seen.contains(ch)) {
                while(!stack.isEmpty() && ch < stack.peek() && lastOccurance.get(stack.peek()) > i ) {
                    seen.remove(stack.pop());
                }
                seen.add(ch);
                stack.push(ch);
            }
        }
        
        StringBuilder sb = new StringBuilder(stack.size());
        
        for(Character c: stack) {
            sb.append(c.charValue());
        }
        
        return sb.toString();
        
        
        
        
        
        
    }
}
