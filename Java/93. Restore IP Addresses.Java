class Solution {
    
    public int[] segments;
    void dfs(String inp, List<String> ans, int idx, int segment) {
        if( idx == inp.length() && segment == 4) {
            String tmp = "";
            for( int i = 0 ; i < 4 ; i++ ) {
                if( i > 0 ) tmp += ".";
                tmp += segments[i];
            }
            ans.add(tmp);
            return;
            
        }
        if( idx == inp.length() || segment == 4 ) return ;
        for( int i = 1 ; i <= 3 && i + idx <= inp.length() ; i++ ) {
            int val = Integer.parseInt(inp.substring(idx, idx + i ) );
            if( i >= 2 && inp.charAt(idx) == '0' || val > 255 ) break;
            segments[segment] = val;
            dfs(inp, ans, idx + i, segment + 1 );
        }
    }
    public List<String> restoreIpAddresses(String s) {
        List<String> answer = new LinkedList<>();
        this.segments = new int[4];
        dfs(s, answer, 0, 0 );
        return answer;
        
        
    }
}
