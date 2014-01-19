#include<iostream>
#include<cstring>
#include"stog_polje.h"
//#include"stog_pokazivaci.h"
using namespace std;

void ukrcaj(automobili *stog){
     char izbor;
     automobil x;
     do{
        cout<<"Serijski broj: ";
        cin>>x.serial;
        cout<<"Proizvodac: ";
        cin.ignore();
        cin.getline(x.proizvodac, 20);
        cout<<"Model: ";
        cin.getline(x.model, 15);
        do{
           cout<<"Godina proizvodnje: ";
           cin>>x.godina;
           }while(x.godina<1995||x.godina>2010);
        PushS(x, stog);
        cout<<"Zelite li unijeti jos (d/n): ";
        cin>>izbor;
        }while(izbor=='d');
     cout<<endl;
     }

void prvi_iskrcaj(automobili *stog, automobili *stog2){
     automobil pom;
     cout<<"Iskrcaj automobila koji su proizvedeni nakon 2006. i nisu Audi!"<<endl;
     while(IsEmptyS(stog)!=1){
              pom=PopS(stog);
              if(pom.godina>2006&&(!(strcmp(pom.proizvodac, "Audi")==0)&&!(strcmp(pom.proizvodac, "audi")==0))){
                 cout<<"----------------------------------"<<endl;
                 cout<<"Serijski broj: "<<pom.serial<<endl;
                 cout<<"Proizvodac: "<<pom.proizvodac<<endl;
                 cout<<"Model: "<<pom.model<<endl;
                 cout<<"Godina proizvodnje: "<<pom.godina<<endl;
                 }
              else{
                  PushS(pom, stog2);
                  }
              }
     cout<<"----------------------------------"<<endl<<endl;
     while(IsEmptyS(stog2)!=1){
              pom=PopS(stog2);
              PushS(pom, stog);
              }
     cout<<"Ostali automobili: "<<endl;
     while(IsEmptyS(stog)!=1){
              pom=PopS(stog);
              cout<<"----------------------------------"<<endl;
              cout<<"Serijski broj: "<<pom.serial<<endl;
              cout<<"Proizvodac: "<<pom.proizvodac<<endl;
              cout<<"Model: "<<pom.model<<endl;
              cout<<"Godina proizvodnje: "<<pom.godina<<endl;
              PushS(pom, stog2);
              }
     cout<<"----------------------------------"<<endl<<endl;
     while(IsEmptyS(stog2)!=1){
              pom=PopS(stog2);
              PushS(pom, stog);
              }
     }
     
void drugi_iskrcaj(automobili *stog) {
	if (IsEmptyS(stog))
		return ;
	automobil pomm = PopS(stog);
	bool brisati = !strcmp(pomm.proizvodac, "Audi")||!strcmp(pomm.proizvodac, "audi");
	if (brisati){
        cout<<"----------------------------------"<<endl;
		cout<<"Serijski broj: "<<pomm.serial<<endl;
    	cout<<"Proizvodac: "<<pomm.proizvodac<<endl;
    	cout<<"Model: "<<pomm.model<<endl;
    	cout<<"Godina proizvodnje: "<<pomm.godina<<endl;
        }
	drugi_iskrcaj(stog);
	if (!brisati) {
		if (IsEmptyS(stog)){
                            cout<<"----------------------------------"<<endl<<endl;
                            cout<<"Ostali automobili: "<<endl;
                            }
		PushS(pomm, stog);
		cout<<"----------------------------------"<<endl;
    	cout << "Serijski broj: "<<pomm.serial<< endl;
    	cout << "Proizvodac: "<<pomm.proizvodac<< endl;
    	cout << "Model: "<<pomm.model<< endl;
    	cout << "Godina proizvodnje: "<<pomm.godina<< endl;
	}
}

int main() {
    int izbor;
    automobili *stog=new automobili;
    automobili *stog2=new automobili;
    InitS(stog);
    InitS(stog2);
    do {
        cout<<"=============================IZBOR==============================="<<endl;
        cout<<"1. Ukrcavanje novog automobila na skladiste! "<<endl;   
        cout<<"2. Iskrcaj automobila (2006+, te koji nisu Audi) u prvu autokucu!"<<endl;
        cout<<"3. Iskrcaj Audi automobila u drugoj auto kuci! "<<endl;
        cout<<"9. Izlaz"<<endl;
        cout<<"================================================================="<<endl;
        cin>>izbor;
        cout<<endl;
        switch(izbor) {
                      case 1: ukrcaj(stog);
                              break;
                      case 2: prvi_iskrcaj(stog, stog2);
                              break;
                      case 3: cout<<"Iskrcaj automobila marke Audi!"<<endl;
                              drugi_iskrcaj(stog);
                              cout<<"----------------------------------"<<endl<<endl;
                              break;
                      case 9: delete []stog;
                              delete []stog2;
                              break;
                      default: cout<<"Pogresam unos!"<<endl<<endl;
                               break;
                      
                      }
        }while(izbor!=9);
}
