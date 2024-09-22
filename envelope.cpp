#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    
    int onesort(vector<vector<int>>& envelopes,int start,int end){
        int key=envelopes[start][0];
        int i=0;
        int j=end;
        if(i==j)return i;
        while(true){
            if(i==j)break;
            if(envelopes[j][0]>key){
                swap(envelopes[i][0],envelopes[j][0]);
                break;
            }
            j--;
        }
        if(i==j)return i;
         while(true){
            if(i==j)break;
            if(envelopes[i][0]<key){
                swap(envelopes[i],envelopes[j]);
                break;
            }
            i++;
        }
        if(i==j)return i;
    }
    void quilksort(vector<vector<int>>& envelopes,int start,int end){
        if(start==end)return;
        int a=onesort(envelopes,start,end);
        quilksort(envelopes,start,a);
        quilksort(envelopes,a+1,end);
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.empty())return 0;//如果没有信封直接返回
        int length=envelopes.size();//得到信封数量；
        vector<int>f(length,1);//定义一个线性表记录每种组合方式得到的最大套娃数量；
        quilksort(envelopes,0,length);
        int i,j;
        for( i=0;i<length;i++);{
            for( j=0;j<length;j++){
                if(envelopes[i][0]>envelopes[j][0])f[i]=max(f[i],f[j]+1);
            }
        }
        return *max_element(f.begin(), f.end());
        
    }
};
