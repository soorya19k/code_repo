#include <iostream>
#include<string>
#include <string.h>

using namespace std;
string searchIn [11] = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
    };
string table[10] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

void search(char*ans,string searchIn[],int j){

    for(int x=0;x<11;x++){
        int ptr=j-1;
        char test[j+1];
        while(searchIn[x][ptr]!='\0'){
                for(int y=ptr-j+1;y<=ptr;y++){
                    test[y-ptr+j-1]=searchIn[x][y];
                }
                test[j]='\0';
                 if(strcmp(ans,test)==0){
                     cout<<searchIn[x]<<endl;
                     break;
                 }
                 ptr++;

        }
    }
}

void dialpad(int no[],char *ans,int i,int j){
    //base case
    if(i<0){
        ans[j]='\0';
        search(ans,searchIn,j);
        return;
    }

    //recursive case
    int k=0;
    while(table[no[i]][k]!='\0'){
        ans[j]=table[no[i]][k];
        dialpad(no,ans,i-1,j+1);
        k++;
    }
    return;
}
int main() {
     long long n;
    cin>>n;
    int no[10]={0};
    int i=0;
    while(n>0){
        no[i]=n%10;
        n=n/10;
        i++;
    }
    char ans[i];
    dialpad(no,ans,i-1,0);
   return 0;
}
