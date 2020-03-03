#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <cstdlib>
using namespace std;
void teren(char t[][10],char &x,char &te,int &pi, int &pj)
{
    cout<<"Dati forma terenului:";cin>>te;
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
        t[i][j]=te;
    cout<<"Alege-ti caracterul:";cin>>x;
    pi=rand()%10;
    pj=rand()%10;
    t[pi][pj]='*';
}
void afisare_teren(char t[][10], int points)
{
    for(int i=0;i<10;i++)
    {
        cout<<endl;
        for(int j=0;j<10;j++)
        cout<<t[i][j]<<" ";
    }
    cout<<endl<<"Points:"<<points;

}
void plasare_caracter(char t[][10],char x,int &ci, int &cj, int points)
{
    cout<<"Dati coordonatele plasarii caracterului(ex: 0 0):";cin>>ci>>cj;
    t[ci][cj]=x;

    afisare_teren(t,points);
}
void mutare_caracter(char t[][10],char x, int &ci, int &cj,char te,int points,int pi,int pj)
   {char mo;
   cout<<"Dati q pentru stop"<<endl;

   do{
   mo=_getch();
   switch(mo)
    {
        case 'w':
            if(ci!=0)
            {t[ci-1][cj]=x;
            t[ci][cj]=te;
            ci--;}
            break;
        case 'a':
            if(cj!=0)
            {t[ci][cj-1]=x;
            t[ci][cj]=te;
            cj--;}
            break;
        case 's':
            if(ci!=9)
            {t[ci+1][cj]=x;
            t[ci][cj]=te;
            ci++;}
            break;
        case 'd':
            if(cj!=9)
            {t[ci][cj+1]=x;
            t[ci][cj]=te;
            cj++;}
            break;
    }
    if(ci==pi&&cj==pj)
    {
        points++;
        pi=rand()%10;
        pj=rand()%10;
        t[pi][pj]='*';
    }
    system("cls");
    afisare_teren(t,points);
}while(mo!='q');
}
int main()
{
    char t[10][10],x,te;// t- este matricea; x- este caracterul controlat; te- caracterul tren
int ci,cj,points=0,pi,pj; // ci si cj- coordonatere lui x; pi si pj- coordonatele punctulu (programul il va pune aleatoriu)
teren(t,x,te,pi,pj);
plasare_caracter(t,x,ci,cj,points);
mutare_caracter(t,x,ci,cj,te,points,pi,pj);





    return 0;
}
