class Solution {
    public int[] exclusiveTime(int n, List<String> logs) {
        Stack < Integer > st = new Stack<> ();
        int[] res = new int[n];
        String[] str = logs.get(0).split(":");
        int idx = 1;
        int prv = Integer.parseInt(str[2]);
        st.push(Integer.parseInt(str[0]));
        while( idx < logs.size() ) {
            str = logs.get(idx).split(":");
            if( str[1].equals("start")) {
                if( !st.empty()) {
                    res[st.peek()] += Integer.parseInt(str[2]) - prv;
                }
                st.push(Integer.parseInt(str[0]));
                prv = Integer.parseInt(str[2]);
            } else {
                res[st.peek()] += Integer.parseInt(str[2]) - prv + 1;
                st.pop();
                prv = Integer.parseInt(str[2]) + 1;
            }
            idx++;
        }
                
        return res;
    }
}
