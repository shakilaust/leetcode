
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
 vector<vector<string>>ans;
        unordered_set<string>s;
        for(auto a:wordList)
            s.insert(a);
        queue<vector<string>>q;
        q.push({beginWord});
        unordered_map<string,bool>use;
        int res=1;
        int flag=false,l=0;
        while(!q.empty())
        {
            int n=q.size();
            while(n--)
            {
                vector<string>v=q.front();
                string a=v.back();
                q.pop();
                use[a]=true;
                if(a==endWord)
                {
                    ans.push_back(v);
                    flag=true;
                }
                for(int i=0;i<a.size();i++)
                {
                    char ch=a[i];
                    for(char c='a';c<='z';c++)
                    {
                        if(c!=ch)
                        {
                            a[i]=c;
                            if(s.find(a)!=s.end() && use[a]==false)
                            {
                                v.push_back(a);
                                q.push(v);
                                v.pop_back();
                            }
                        }
                    }
                    a[i]=ch;
                }
            }
            if(flag==true)
                break;
            res++;
        }
        return ans;
    }
};
