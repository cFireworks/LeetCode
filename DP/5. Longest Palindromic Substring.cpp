class Solution {
public:
    string longestPalindrome(string s) {
        string result = "";
        if(s.size()<2) return s;
        // record table: store[s.size, s.size]
        vector<vector<bool>> store(s.size(),vector<bool>(s.size(),false));
        int start=0,maxlen=1;
        
        // third equaltion
        for(int i=s.size()-1;i>=0;i--){
            store[i][i] = true;
            if(i != 0 && s[i-1]==s[i]){
                store[i-1][i] = true;
                if(maxlen==1){
                    start = i-1;
                    maxlen = 2;
                }    
            }
            for(int j=i+2;j<s.size();j++){
                if(s[i]==s[j]){
                    if(store[i+1][j-1]){
                        store[i][j] = true;
                        if((j-i+1)>maxlen){
                            start = i;
                            maxlen = j-i+1;
                    }  
                    }
  
                }
            }
        }
        // collect the result
        return s.substr(start,maxlen);
    }
};

// Manacher Algorithm
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        if (s.size() == 1) return s;
        
        int L, R, pos = 0, len = -1, ss = s.size();
        char sr;

        for(int i = 0; i < ss; i++)
        {
            L = R = i;
            
            sr = s[R];
            
            while(R+1 <= ss && (sr == s[R+1]))
                R++;
         
            i = R;
        
            while(R+1 <= ss && L-1 >= 0 && (s[R+1] == s[L-1]))
            {
                R++;
                L--;
            } 
            
            if(len < R-L+1 )
            {
                len = R-L+1;
                pos = L;
            }
        }
        return s.substr(pos, len);
    }
};