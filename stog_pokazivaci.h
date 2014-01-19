#include<iostream>

struct automobil {
       int serial, godina;
       char proizvodac[20], model [15];
       };
       
struct automobili {
       automobil podaci;
       automobili *sljedeci;
       };
       
void InitS(automobili *stog) {
     stog->sljedeci=NULL;
     }

void PushS(automobil x, automobili *stog) {
     automobili *novi=new automobili;
     novi->podaci=x;
     novi->sljedeci=stog->sljedeci;
     stog->sljedeci=novi;
     }
     
automobil PopS(automobili *stog) {
     automobili *pom=new automobili;  
     pom=stog->sljedeci;
     automobil vrh=pom->podaci;
     stog->sljedeci=pom->sljedeci;
     return vrh;
     }
     
automobil TopS(automobili *stog) {
     automobili *pom=new automobili;  
     pom=stog->sljedeci;
     automobil vrh=pom->podaci;
     return vrh;
     }
     
bool IsEmptyS(automobili *stog) {
     if(stog->sljedeci==NULL)
        return true;
     else
         return false;
     }
