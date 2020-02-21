const int NX = ( 1 << 17 );
const int MX = 65;
const int INF = 100;
map < pair< int, int >, bool > memo;
map < string, int > skillPos;
vector < vector < string > > peoples;
int dp[ MX ][ NX ], requiredSkill, totalPerson;


int DP( int pos, int mask ) { 

    if( mask == ( 1 << requiredSkill ) - 1 ) { 
        return 0;
    } else if( pos >= totalPerson ) {
        return INF;
    }
    if( memo.find( make_pair( pos , mask ) ) != memo.end() ) { 
        return dp[pos][mask];
    }   
    
    memo[ make_pair( pos , mask ) ] = true;
    int &ret = dp[pos][mask];
    ret = DP( pos + 1 , mask );
    int sz = peoples[pos].size();
    int curMask = mask;
    for(int i = 0 ; i < sz ; i++ ) { 
    
        if(skillPos.find(peoples[pos][i]) == skillPos.end() ) continue;
        int idx = skillPos[peoples[pos][i]];
        curMask |= ( 1 << idx );
    }
    ret = min( ret, DP( pos + 1 , curMask ) + 1 );
    return ret;

}

void generateAnswer( int pos, int mask, vector < int > & ans, int mx) { 

    if( mx == 0 ) { 
        return;
    } else if( pos >= totalPerson ) {
        return;
    }
    
    int sz = peoples[pos].size();
    int newMask = mask;
     for(int i = 0 ; i < sz ; i++ ) { 
    
        if(skillPos.find(peoples[pos][i]) == skillPos.end() ) continue;
        int idx = skillPos[peoples[pos][i]];
        newMask |= ( 1 << idx );
    }
    int tmpRes = DP( pos + 1 , newMask ) + 1;
   // cout << " pos  " << pos << " res  " << tmpRes << " mx " << mx << endl;
    if( tmpRes == mx ) { 
        ans.push_back( pos );
        generateAnswer( pos + 1 , newMask , ans , mx - 1 );
    } else {
        generateAnswer( pos + 1 , mask , ans , mx );
    }

}



class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        peoples = people;
        skillPos.clear();
        int item = 0;
        for( int i = 0 ; i < req_skills.size() ; i++ ) { 
            skillPos[req_skills[i]] = item++;
        }
        
        memo.clear();
        requiredSkill = req_skills.size();
        totalPerson = people.size();
        int res = DP( 0 , 0 );
        vector < int > ans;
        generateAnswer( 0, 0, ans, res);
        return ans;
        
    }
};
