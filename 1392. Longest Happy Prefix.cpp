const int NX = 1e5 + 5;

int T[ NX ];

int ComputePrefixFunction(string &B)
{      
    
      int lenB = B.size();
      int k=0,q;
       T[1]=0;
       for(q=2;q<=lenB;q++)
       {  while (k>0 && B[k]!=B[q-1]) k=T[k];
             if(B[k]==B[q-1]) k++;
             T[q]=k;
       }
    return T[lenB];
    
}


class Solution {
public:
    string longestPrefix(string s) {
        
        string ans = "";
        int len = ComputePrefixFunction(s);
        for( int i = 0 ; i < len ; i++ ) { 
            ans += s[i];
        }
        
      
        
        return ans;
    }
};
