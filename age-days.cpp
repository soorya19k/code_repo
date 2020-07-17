#include <iostream>
#include<conio.h>
using namespace std;
bool leapyr(int n){
    if(n%4==0){
        if(n%100==0){
            if(n%400==0){
               return true;
            }
            else{
                return false;
            }
        }
        else{
           return true;
        }
    }
    else
    {
        return false;
    }
}
int leapyr_count(int yob,int py,int mob,int pm,int pd){
     int noly=0;
   if( mob <= 2){
        for(int i=yob;i<py;i++){
            bool check=leapyr(i);
            if(check){
                noly++;
            }
        }
   }
   else {
        for(int i=yob+1;i<py;i++){
            bool check=leapyr(i);
            if(check){
                noly++;
            }
        }
   }
   /*if(pm==2 && pd==29){
       bool check=leapyr(py);
        if(check){
                noly++;
            }
   }*/
   if(pm >2){
        bool check=leapyr(py);
            if(check){
                noly++;
            }
   }
   return noly;
}
int main() {
    //entering year of birth
    cout<<"INSTRUCTIONS \n The date format should be like yyyy/mm/dd \n Press ENTER KEY after each entry"<<endl;
    cout<<"for example : \n \t Enter year of -----. \n \t 2008 \n \t 3 \n \t 27 "<<endl;


   int yob;
   cout<<"Enter year of Birth."<<endl;
   cin>>yob;
   int mob;
   cin>>mob;
   int dob;
   cin>>dob;
   //entering present year
   int py;
   cout<<"Enter Present year."<<endl;
   cin>>py;

   int pm;
   cin>>pm;

   int pd;
   cin>>pd;
    //count of leap years
   int noly=0;
   noly=leapyr_count(yob,py,mob,pm,pd);
  // cout<<"demo\n"<<noly<<"\ndemo";
   // calculating days leaving boundary years
   int days=0;
   for(int i=yob+1;i<py;i++){
       days = days + 365;
   }
    //cout<<"demo\n"<<days<<"\ndemo";
   // adding pending days of leap years
    days = days + noly;
    // cout<<"demo\n"<<days<<"\ndemo";
   // cout<<"demo \n"<<days<<"\ndemo";


    // making array of month days
     int month[13]={0,31,59,90,120,151,181,212,243,273,304,334,365};
   //calculating days
    {
   days = days + month[12] - month[mob];
    //calculating days spend in the month of birth
    days = days + month[mob]-month[mob-1]-dob +1;
   days = days + month[pm-1];
   days = days + pd;

    }
    if(yob==py){
        days=days-365 -2;
    }

    cout<<endl<<"Age in the days is "<<days<<endl;
   return 0;
}
