#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;
class Solution {
public:
    string getDigits(string s,size_t &ptr){
        string ret="";
        while(isdigit(s[ptr])) ret.push_back(s[ptr++]);
        return ret;
    }//用于获取字符串中的数字。
    string getString(vector<string>& str){
        string ret="";
        for(const auto&s: str) ret+=s;
        return ret;
    }//合并字符串；
    string decodeString(string s) {
        
        vector<string>stack;
        size_t ptr=0;
        while(ptr<s.size()){
            char cur=s[ptr];
            if(isdigit(cur)){
                string digits=getDigits(s,ptr);
                stack.push_back(digits);
            }
            else if(isalpha(cur)||cur=='[')stack.push_back(string(1,s[ptr++]));
            else{
                ++ptr;
                vector<string> sub;
                while(stack.back()!="["){
                    sub.push_back(stack.back());
                    stack.pop_back();
                }
                stack.pop_back();
                reverse(sub.begin(),sub.end());
                int repTime=stoi(stack.back());
                stack.pop_back();
                string t="";
                string o=getString(sub);
                while(repTime--)t+=o;
                stack.push_back(t);
            }
        }
        return getString(stack);
    }
};
int main(){
    string str;
    cin>>str;//此类写法遇到空格或者换行会停止读取；
    /*getline(cin,str);*///此类写法则可以遇到空格也继续读取；
    Solution myobject;
    string ans=myobject.decodeString(str);
    cout<<ans<<endl;
    return 0;
}
