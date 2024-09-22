#include<iostream>
using namespace std;
struct letter{
    char le;
    letter* next;
};
int main(){
    letter* head=new letter;
    letter*p;
    letter*s;
    int count=0;
    while(1){
        if(head==nullptr){
            s=new letter;
            cin>>s->le;
            if(s->le!=',')count++;
            head=s;
        }
        else{
            s=new letter;
            cin>>s->le;
            s->next=head;
            if(s->le!=',')count++;
            head=s;
        }
        if(count==5)break;
    }
    while(head!=nullptr){
        if(head->le==',')continue;
        cout<<head->le;
        head=head->next;
    }
    return 0;
}
        
        
            
    
    
    
    