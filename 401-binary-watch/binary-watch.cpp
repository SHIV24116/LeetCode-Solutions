class Solution {
public:
    string compute(string s){
        int H=0;
        int M=0;
        for(int i=0;i<4;i++){
            if(s[i]=='1') H=H+pow(2,3-i);
        }
        if(H>11) return "";
        for(int i=4;i<10;i++){
            if(s[i]=='1') M=M+pow(2,9-i);
        }
        if(M>59) return "";
        string x=to_string(H);
        string y;
        if(M<=9) y="0"+to_string(M);
        else y=to_string(M);
        return  x+":"+y;
    }
    void helper(int turnedOn,vector<string>&ans,string s){
        if(s.size()==10){
            if(turnedOn==0  && compute(s)!="") ans.push_back(compute(s));
            return;
        }
        s.push_back('0');
        helper(turnedOn,ans,s);
        s.pop_back();
        s.push_back('1');
        helper(turnedOn-1,ans,s);
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string>ans;
        string s="";
        helper(turnedOn,ans,s);
        return ans;
    }
};