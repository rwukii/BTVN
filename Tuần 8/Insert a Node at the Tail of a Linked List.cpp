#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


struct Node{
    int data;
    Node* next;
};
typedef Node* node;
node taonode(int data){
    node tmp=new Node();
    tmp->data=data;
    tmp->next=NULL;
    return tmp;
}
void chencuoi(node &head,int data){
    node moi=taonode( data);
    if(head==NULL) head=moi;
    else {
        node tmp=head;
        while(tmp->next!=NULL){
            tmp=tmp->next;
        }
        tmp->next=moi;
    }
}
void in(node head){
    while(head!=NULL){
        cout<<head->data<<endl;
        head=head->next;
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;cin>>n;
    node head=NULL;
    while(n--){
        int x;cin>>x;
        chencuoi(head,x);
    }
    in(head);
    return 0;
}
