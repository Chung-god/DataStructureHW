#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;

int main(){
    ifstream read;
    read.open("sapiens.txt");
    char str[sizeof(read)]={'\0'};

    list<char> genomeList;
    if(read.good()){
        bool isFirst = false;
        char strTemp[sizeof(read)] = {'\0'};
        while(!read.eof()){
            if(!isFirst){
                isFirst = true;
                read.getline(strTemp,sizeof(read));
                continue;
            }
            read.getline(str,sizeof(read));
            for(int i = 0; str[i]!='\0';i++){
                genomeList.push_back(str[i]);
            }
            // cout<<"\n";
        }
    }
    list<char>::iterator iter1;
    list<char>::iterator iter2;
    for(iter1 = genomeList.begin();iter1!=genomeList.end();iter1++){
        cout<<*iter1;
    } 
    read.close();

    int N;
    cin>>N;
    cout<<"\n";
    while(N--){
        string inst;
        int t1,t2;
        cin>>inst>>t1>>t2;
        iter1 = genomeList.begin();
        iter2 = genomeList.begin();

        for(int i = 0; i < t1; i++)
            iter1++;
        for(int i = 0; i < t2; i++ ) 
            iter2++;

        if(inst[0] == 'r'){
            while(iter1 != iter2){
                cout<<*iter1;
                iter1++;
            }
            continue;
        }else if(inst[0] == 'c'){
           genomeList.erase(iter1,iter2);
           continue;
        }

        list<char> tempList;
        list<char>::iterator tempIter1 = iter1;
        list<char>::iterator tempIter2 = iter2;
        while(tempIter1!=tempIter2){
            tempList.push_back(*tempIter1);
            tempIter1++;
        }
        tempIter1 = iter1;
        
        if(inst[0] == 'd'){
            for(int i = 0; i < tempList.size();i++){
                genomeList.insert(tempIter2,*tempIter2); 
                tempIter2++;
            }
        }else if(inst[0] == 'b'){
            genomeList.erase(iter1,iter2);
            for(int i = 0; i < tempList.size(); i++){
                genomeList.push_back(*tempIter1);
                tempIter1++;
            }
        }else if(inst[0] == 'f'){
            if(inst[1] == 'l'){
                genomeList.reverse();
                genomeList.erase(iter1,iter2);
                for(int i = 0; i < tempList.size(); i++){
                    genomeList.insert(iter1,*tempIter1);
                    tempIter1++;
                }
            }else if(inst[1] == 'r'){
                genomeList.erase(iter1,iter2);
                for(int i = 0; i < tempList.size(); i++){
                    genomeList.push_front(*tempIter1);
                    tempIter1++;
                }
            }
        }
    }

}