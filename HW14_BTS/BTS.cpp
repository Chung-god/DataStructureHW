#include <iostream>
#include <string>
using namespace std;

int number;
int inputN;
string op[4] = {"+","-","depth","leaf"};

int get_type(string t){
    for(int i = 0; i < 4; i++){
        if(t == op[i]) return(i);
    }
    return(-1);
}
typedef struct node* treePtr;
typedef struct node{
    node* left;
    node* right;
    string data;
    
}node;

void add(string w){
    treePtr ptr = &nodes[0];
    if(ptr->data == NULL){
        ptr->data = w;
    }else{
        while(ptr->data != NULL){
            if(ptr->data < w)
                ptr = ptr->right;
            else
                ptr = ptr->left;
        }
        ptr->data = w;
    }
}




int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>inputN;
    node nodes[50];

    while(inputN--){
        string temp;
        cin>>temp;
        int result = get_type(temp);
        string w;
        int n;
        switch (result)
        {
        case 0:
            cin>>w;
            
            break;
        case 1:
            cin>>w;
            
            break;
        case 2:
            cin>>n;
           
            break;
        case 3:
            
            break;
        default:
            break;
        }
    }

}