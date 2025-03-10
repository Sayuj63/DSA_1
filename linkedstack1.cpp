#include<iosteam>
using namespace std;
 
 struct StackNode{
    int data;
    StackNode* next;
    StackNode(int x){
        data=x;
        next=NULL;
    }
 } 