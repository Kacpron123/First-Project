#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
using namespace std;
char a[8][8],blok=219;          //[y] [x]
HANDLE h0ut = GetStdHandle(STD_OUTPUT_HANDLE);
int b[8],i,i2,c,d,g,w,k,kolor;
COORD coord;
void gotoXY(int x,int y){
coord.X=x;
coord.Y=y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void color(int b){
if(b==1)SetConsoleTextAttribute(h0ut , FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);//zolty
if(b==2)SetConsoleTextAttribute(h0ut , FOREGROUND_RED | FOREGROUND_INTENSITY);//czerwony
if(b==3)SetConsoleTextAttribute(h0ut , FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);//zwykly
}
void gwiazdka() {
for(i=0;i<8;i++)
{
    for(i2=0;i2<8;i2++)
    {a[i][i2]=' ';
    }}
}
void tablica(){

 for(i=1;i<=8;i++){
 for(i2=1;i2<=8;i2++){
 if(a[i-1][i2-1]=='z') color(2);
 else color(1);
 if(a[i-1][i2-1]==' ') continue;
 gotoXY(i2-1,i); cout<<blok;
 //cout<<a[i-1][i2-1];
  color(3);
 }
 cout<<endl;
 }
 //cout<<endl;
 color(3);
 for(i=1;i<=8;i++) cout<<i;
cout<<endl;}
void test(){
for(i=0;i<5;i++){
for(i2=0;i2<8;i2++){
if(a[i2][i]==a[i2][i+1] && a[i2][i+1]==a[i2][i+2] && a[i2][i+2]==a[i2][i+3] && a[i2][i]!=' ') k=1; //w poziomie
if(a[i][i2]==a[i+1][i2] && a[i+1][i2]==a[i+2][i2] && a[i+2][i2]==a[i+3][i2] && a[i][i2]!=' ') k=1; //w pionie
}}
for(i=0;i<5;i++){
for(i2=0;i2<5;i2++){
if(a[i][i2]==a[i+1][i2+1] && a[i+1][i2+1]==a[i+2][i2+2] && a[i+2][i2+2]==a[i+3][i2+3] && a[i][i2]!=' ') k=1;//lewoskosny
if(a[i][7-i2]==a[1+i][6-i2] && a[1+i][6-i2]==a[2+i][5-i2] && a[2+i][5-i2]==a[3+i][4-i2] && a[i][7-i2]!=' ')k=1;//prawoskoœny
}}
}
int main()
{
    gwiazdka();
    while(1!=2){
    if(w%2==0)   {cout<< "ruch "; color(2); cout<<blok<<endl;color(3);}
    else         {cout<< "ruch "; color(1); cout<<blok<<endl;color(3);}
    tablica();
    g=getch()-49;
    if(g==-2) return 0;
    if(g==8 || b[g]==8) {system("cls");continue;}
    b[g]+=1;
    if(w%2==0){a[8-b[g]][g]='z';}
    else {a[(8-b[g])][g]='c';}
    test();
    if(k==1){system("cls"); tablica(); if(w%2==0){cout<<"wygral z"; return 0;} else{cout<<"wygral c"; return 0;}}
    w++;system("cls");}
    return 0;
}
