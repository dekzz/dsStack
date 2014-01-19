#include<iostream>

struct automobil {
       int serial, godina;
       char proizvodac[20], model [15];
       };
       
struct automobili {
       automobil polje[20];
       int kursor;
       };

void InitS(automobili *stog) {
     stog->kursor=19;
     }
     
void PushS(automobil x, automobili *stog) {
     stog->polje[stog->kursor]=x;
     stog->kursor--;
     }
     
automobil PopS(automobili *stog) {
     automobil vrh=stog->polje[stog->kursor+1];
     stog->kursor++;
     return vrh;
     }
     
automobil TopS(automobili *stog) {
     automobil vrh=stog->polje[stog->kursor+1];
     return vrh;
     }
     
bool IsEmptyS(automobili *stog) {
     if(stog->kursor==19)
         return true;
     return false;
     }
