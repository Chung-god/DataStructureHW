#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <math.h>
using namespace std;

int map[130][130];
string str;
void divCon(int ns, int ms, int ne, int me)
{
   int check = map[ns][ms];

   for (int i = ns; i < ne; ++i) {
      for (int j = ms; j < me; ++j) {
         if (check == 0 && map[i][j] == 1) {
            check = 2;
         }
         else if (check == 1 && map[i][j] == 0) {
            check = 2;
         }
         if (check == 2) {
            cout << "(";
            divCon(ns, (ms + me) / 2, (ns + ne) / 2, me);//오른쪽 위
            divCon(ns, ms, (ns + ne) / 2, (ms + me) / 2);//왼쪽 위
            divCon((ns + ne) / 2, ms, ne, (ms + me) / 2);//왼쪽 아래
            divCon((ns + ne) / 2, (ms + me) / 2, ne, me);//오른쪽 아래
            cout << ")";
            return;
         }
      }
   }

   cout << check;

   return;
}

int getNextIndex(int index){
    while(1){
        if(str[index] =='(' || str[index]==')'){                
            index++;
        }else{
            return index;
        }
    }
}

void megCon(int x,int y,int size,int strIndex){
    if(str[strIndex] == '('){
        strIndex = getNextIndex(strIndex);
        megCon(x,y+size,size/2,strIndex);

        strIndex = getNextIndex(strIndex);
        megCon(x,y,size/2,strIndex);
        
        strIndex = getNextIndex(strIndex);
        megCon(x+size,y,size/2,strIndex);
        
        strIndex = getNextIndex(strIndex);
        megCon(x+size,y+size,size/2,strIndex+1);

    }
    else if(str[strIndex] == ')'){
        return;
    }else{
        for(int i = x; i < i + size(); i++){
            for(int j = y;j < j + size();j++ ){
                map[i][j] = str[strIndex];
            }
        }
    }

}
int main(int argc, char* argv[])
{
   int n;
   int squre;
   string op;
   string s;

   cin >> n>>op;
   squre = pow(2, n);
   memset(map, 0, sizeof(map));

    if(op  == "IMG"){
        for (int i = 0; i < n; ++i) {
            cin >> s;
            for (int j = 0; j < n; ++j) {
                map[i][j] = s[j] - '0';
            }
        }
        divCon(squre, 0, squre, squre);
    }else {
        cin>>str;
        megCon(0,0,n,0);
    }

   return 0;
}