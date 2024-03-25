#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <ctime>
#include <string>
#include <conio.h>
#include <cmath>
#include <thread>
using namespace std;
HANDLE h0ut=GetStdHandle(STD_OUTPUT_HANDLE);
COORD coord;

void kolor(int c){
/*zwykly*/if(c==0) SetConsoleTextAttribute(h0ut,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
/*czerwony*/if(c==1) SetConsoleTextAttribute(h0ut,FOREGROUND_RED | FOREGROUND_INTENSITY);
/*zielony*/if(c==2) SetConsoleTextAttribute(h0ut,FOREGROUND_GREEN| FOREGROUND_INTENSITY);
/*pomaranczowy*/if(c==3) SetConsoleTextAttribute(h0ut,FOREGROUND_RED | FOREGROUND_INTENSITY);
}

void gotoXY(int x,int y){
coord.X=x;
coord.Y=y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
string carta[52]={
        "$A","$2","$3","$4","$5","$6","$7","$8","$9","$T","$J","$Q","$K",               //(char)5
        "#A","#2","#3","#4","#5","#6","#7","#8","#9","#T","#J","#Q","#K",               //(char)6
        "&A","&2","&3","&4","&5","&6","&7","&8","&9","&T","&J","&Q","&K",   //czerwone  //(char)3
        "%A","%2","%3","%4","%5","%6","%7","%8","%9","%T","%J","%Q","%K"    //czerwone  //(char)4
        };

//-------------------
string plansza[16][8];
string finish[4];
string transfer[4];
/////////////////////////////
class cursor{
int a;
    public:
int xPos,yPos;
bool selected;
int xcart,ycart;
bool running=true;
bool winning;
cursor(){
    winning=false;
    xPos=0;
    yPos=0;
    selected=false;
    xcart=ycart=-1;
}
void MoveLeft() {
    if(xPos>=0)
    xPos--;
    if(xPos==-1)
    xPos=7;
    }
void MoveRight(){
    if(xPos<8)
    xPos++;
    if(xPos==8)
    xPos=0;
    }
void MoveUp()   {
    if(yPos>-1)
    yPos--;
    }
void MoveDown() {
    if(yPos<15)
    yPos++;
    }
void zaznacz()  {
    /*dla transferu*/{
    if(xPos<4 && yPos==-1){
        if(!selected){
            xcart=xPos;
            ycart=yPos;
            selected=true;
        }
        else{
            if(ycart>=0 && transfer[xPos]==""){
                    swap(transfer[xPos],plansza[ycart][xcart]);
                    }
            selected=false;
            xcart=ycart=-1;
        }
    }
    }
    /*dla kart*/{
    if(yPos>=0  && plansza[yPos+1][xPos]==""){
        if(!selected){
            xcart=xPos;
            ycart=yPos;
            selected=true;
        }
        else {
            for(int i=0;i<1;i++){
            if(ycart==-1){//z transferu
                if(transfer[xcart][1]=='A' && plansza[yPos-1][xPos][1]=='2' && plansza[yPos][xPos]==""){
                if(( (transfer[xcart][0]=='#' || transfer[xcart][0]=='$' )
                   && (plansza[yPos-1][xPos][0]=='%' || plansza[yPos-1][xPos][0]=='&') )
                   ||
                   ( (transfer[xcart][0]=='%' || transfer[xcart][0]=='&' )
                   && (plansza[yPos-1][xPos][0]=='#' || plansza[yPos-1][xPos][0]=='$') )
                   ){
                plansza[yPos][xPos]=transfer[xcart];
                transfer[xcart]="";
                selected=false;
                break;
            }
            }
                if(transfer[xcart][1]=='2' && plansza[yPos-1][xPos][1]=='3' && plansza[yPos][xPos]==""){
                if(( (transfer[xcart][0]=='#' || transfer[xcart][0]=='$' )
                   && (plansza[yPos-1][xPos][0]=='%' || plansza[yPos-1][xPos][0]=='&') )
                   ||
                   ( (transfer[xcart][0]=='%' || transfer[xcart][0]=='&' )
                   && (plansza[yPos-1][xPos][0]=='#' || plansza[yPos-1][xPos][0]=='$') )
                   ){
                plansza[yPos][xPos]=transfer[xcart];
                transfer[xcart]="";
                selected=false;
                break;
            }}
                if((int)transfer[xcart][1]<=57 && (int)transfer[xcart][1]>50 && plansza[yPos][xPos]==""){
                if(plansza[yPos-1][xPos][1]==(char)((int)transfer[xcart][1]+1) ){
                if(( (transfer[xcart][0]=='#' || transfer[xcart][0]=='$' )
                   && (plansza[yPos-1][xPos][0]=='%' || plansza[yPos-1][xPos][0]=='&') )
                   ||
                   ( (transfer[xcart][0]=='%' || transfer[xcart][0]=='&' )
                   && (plansza[yPos-1][xPos][0]=='#' || plansza[yPos-1][xPos][0]=='$') )
                   ){
                plansza[yPos][xPos]=transfer[xcart];
                transfer[xcart]="";
                selected=false;
                break;
            }
            }
            }
                if(transfer[xcart][1]=='9' && plansza[yPos-1][xPos][1]=='T' && plansza[yPos][xPos]==""){
                if(( (transfer[xcart][0]=='#' || transfer[xcart][0]=='$' )
                   && (plansza[yPos-1][xPos][0]=='%' || plansza[yPos-1][xPos][0]=='&') )
                   ||
                   ( (transfer[xcart][0]=='%' || transfer[xcart][0]=='&' )
                   && (plansza[yPos-1][xPos][0]=='#' || plansza[yPos-1][xPos][0]=='$') )
                   ){
                plansza[yPos][xPos]=transfer[xcart];
                transfer[xcart]="";
                selected=false;
                break;
            }
            }
                if(transfer[xcart][1]=='T' && plansza[yPos-1][xPos][1]=='J' && plansza[yPos][xPos]==""){
                if(( (transfer[xcart][0]=='#' || transfer[xcart][0]=='$' )
                   && (plansza[yPos-1][xPos][0]=='%' || plansza[yPos-1][xPos][0]=='&') )
                   ||
                   ( (transfer[xcart][0]=='%' || transfer[xcart][0]=='&' )
                   && (plansza[yPos-1][xPos][0]=='#' || plansza[yPos-1][xPos][0]=='$') )
                   ){
                plansza[yPos][xPos]=transfer[xcart];
                transfer[xcart]="";
                selected=false;
                break;
            }
            }
                if(transfer[xcart][1]=='J' && plansza[yPos-1][xPos][1]=='Q' && plansza[yPos][xPos]==""){
                if(( (transfer[xcart][0]=='#' || transfer[xcart][0]=='$' )
                   && (plansza[yPos-1][xPos][0]=='%' || plansza[yPos-1][xPos][0]=='&') )
                   ||
                   ( (transfer[xcart][0]=='%' || transfer[xcart][0]=='&' )
                   && (plansza[yPos-1][xPos][0]=='#' || plansza[yPos-1][xPos][0]=='$') )
                   ){
                plansza[yPos][xPos]=transfer[xcart];
                transfer[xcart]="";
                selected=false;
                break;
            }
            }
                if(transfer[xcart][1]=='Q' && plansza[yPos-1][xPos][1]=='K' && plansza[yPos][xPos]==""){
                if(( (transfer[xcart][0]=='#' || transfer[xcart][0]=='$' )
                   && (plansza[yPos-1][xPos][0]=='%' || plansza[yPos-1][xPos][0]=='&') )
                   ||
                   ( (transfer[xcart][0]=='%' || transfer[xcart][0]=='&' )
                   && (plansza[yPos-1][xPos][0]=='#' || plansza[yPos-1][xPos][0]=='$') )
                   ){
                plansza[yPos][xPos]=transfer[xcart];
                transfer[xcart]="";
                selected=false;
                break;
            }
            }
            }
            if(ycart>=0){//z kart
                if(yPos==0 && plansza[yPos][xPos]==""){
                    swap(plansza[ycart][xcart],plansza[yPos][xPos]);
                        selected=false;
                        break;
                }
                if(plansza[ycart][xcart][1]=='Q' && yPos!=0 && plansza[yPos-1][xPos][1]=='K' && plansza[yPos][xPos]==""){
                if(
                ( (plansza[ycart][xcart][0]=='#' || plansza[ycart][xcart][0]=='$' )
                && (plansza[yPos-1][xPos][0]=='%' || plansza[yPos-1][xPos][0]=='&') )
                ||
                ( (plansza[ycart][xcart][0]=='%' || plansza[ycart][xcart][0]=='&' )
                && (plansza[yPos-1][xPos][0]=='#' || plansza[yPos-1][xPos][0]=='$') )
                ){
                swap(plansza[ycart][xcart],plansza[yPos][xPos]);
                selected=false;
                break;
            }}
                if(plansza[ycart][xcart][1]=='J' && yPos!=0 && plansza[yPos-1][xPos][1]=='Q' && plansza[yPos][xPos]==""){
                if(
                ( (plansza[ycart][xcart][0]=='#' || plansza[ycart][xcart][0]=='$' )
                && (plansza[yPos-1][xPos][0]=='%' || plansza[yPos-1][xPos][0]=='&') )
                ||
                ( (plansza[ycart][xcart][0]=='%' || plansza[ycart][xcart][0]=='&' )
                && (plansza[yPos-1][xPos][0]=='#' || plansza[yPos-1][xPos][0]=='$') )
                ){
                swap(plansza[ycart][xcart],plansza[yPos][xPos]);
                selected=false;
                break;
            }}
                if(plansza[ycart][xcart][1]=='T' && yPos!=0 && plansza[yPos-1][xPos][1]=='J' && plansza[yPos][xPos]==""){
                if(
                ( (plansza[ycart][xcart][0]=='#' || plansza[ycart][xcart][0]=='$' )
                && (plansza[yPos-1][xPos][0]=='%' || plansza[yPos-1][xPos][0]=='&') )
                ||
                ( (plansza[ycart][xcart][0]=='%' || plansza[ycart][xcart][0]=='&' )
                && (plansza[yPos-1][xPos][0]=='#' || plansza[yPos-1][xPos][0]=='$') )
                ){
                swap(plansza[ycart][xcart],plansza[yPos][xPos]);
                selected=false;
                break;
            }}
                if(plansza[ycart][xcart][1]=='9' && yPos!=0 && plansza[yPos-1][xPos][1]=='T' && plansza[yPos][xPos]==""){
                if(
                ( (plansza[ycart][xcart][0]=='#' || plansza[ycart][xcart][0]=='$' )
                && (plansza[yPos-1][xPos][0]=='%' || plansza[yPos-1][xPos][0]=='&') )
                ||
                ( (plansza[ycart][xcart][0]=='%' || plansza[ycart][xcart][0]=='&' )
                && (plansza[yPos-1][xPos][0]=='#' || plansza[yPos-1][xPos][0]=='$') )
                ){
                swap(plansza[ycart][xcart],plansza[yPos][xPos]);
                selected=false;
                break;
            }}
                if((int)plansza[ycart][xcart][1]>=50 && (int)plansza[ycart][xcart][1]<57 && yPos!=0 &&  plansza[yPos][xPos]==""){
                if(plansza[ycart][xcart][1]==(char)((int)plansza[yPos-1][xPos][1]-1)){
                    if(
                    ( (plansza[ycart][xcart][0]=='#' || plansza[ycart][xcart][0]=='$' )
                    && (plansza[yPos-1][xPos][0]=='%' || plansza[yPos-1][xPos][0]=='&') )
                    ||
                    ( (plansza[ycart][xcart][0]=='%' || plansza[ycart][xcart][0]=='&' )
                    && (plansza[yPos-1][xPos][0]=='#' || plansza[yPos-1][xPos][0]=='$') )
                    ){
                    swap(plansza[ycart][xcart],plansza[yPos][xPos]);
                    selected=false;
                    break;
                }}}
                if(plansza[ycart][xcart][1]=='A' && yPos!=0 && plansza[yPos-1][xPos][1]=='2' && plansza[yPos][xPos]==""){
                if(
                ( (plansza[ycart][xcart][0]=='#' || plansza[ycart][xcart][0]=='$' )
                && (plansza[yPos-1][xPos][0]=='%' || plansza[yPos-1][xPos][0]=='&') )
                ||
                ( (plansza[ycart][xcart][0]=='%' || plansza[ycart][xcart][0]=='&' )
                && (plansza[yPos-1][xPos][0]=='#' || plansza[yPos-1][xPos][0]=='$') )
                ){
                swap(plansza[ycart][xcart],plansza[yPos][xPos]);
                selected=false;
                break;
            }}

            }
        }
        selected=false;
        xcart=ycart=-1;
    }
    }
}
}
void enter(){
    if(yPos==-1){//transferu
        if(transfer[xPos]!="" && yPos==-1){
                for(int i=0;i<1;i++){
            if(transfer[xPos][1]=='A' && finish[(int)transfer[xPos][0]-35]==""){
                finish[(int)plansza[yPos][xPos][0]-35]=transfer[xPos];
                transfer[xPos]="";
                break;
            }
            if(transfer[xPos][1]=='2' && finish[(int)transfer[xPos][0]-35][1]=='A'){
                finish[(int)plansza[yPos][xPos][0]-35]=transfer[xPos];
                transfer[xPos]="";
                break;
            }
            if((int)finish[(int)transfer[xPos][0]-35][1]<57 &&
                       (int)finish[(int)transfer[xPos][0]-35][1]>=50){
                        if(transfer[xPos][1]==(char)((int)finish[(int)transfer[xPos][0]-35][1]+1)){
                            finish[(int)transfer[xPos][0]-35]=transfer[xPos];
                            transfer[xPos]="";
                            selected=false;
                        }
            }
            if(transfer[xPos][1]=='T' && finish[(int)transfer[xPos][0]-35][1]=='9'){
                finish[(int)plansza[yPos][xPos][0]-35]=transfer[xPos];
                transfer[xPos]="";
                break;
            }
            if(transfer[xPos][1]=='J' && finish[(int)transfer[xPos][0]-35][1]=='T'){
                finish[(int)plansza[yPos][xPos][0]-35]=transfer[xPos];
                transfer[xPos]="";
                break;
            }
            if(transfer[xPos][1]=='Q' && finish[(int)transfer[xPos][0]-35][1]=='J'){
                finish[(int)plansza[yPos][xPos][0]-35]=transfer[xPos];
                transfer[xPos]="";
                break;
            }
            if(transfer[xPos][1]=='K' && finish[(int)transfer[xPos][0]-35][1]=='Q'){
                finish[(int)plansza[yPos][xPos][0]-35]=transfer[xPos];
                transfer[xPos]="";
                break;
            }
        }}
    }
    if(yPos>=0 && plansza[yPos+1][xPos]==""){//z kart
        for(int i=0;i<1;i++){
            if(plansza[yPos][xPos][1]=='A' && finish[(int)plansza[yPos][xPos][0]-35]==""){
                finish[(int)plansza[yPos][xPos][0]-35]=plansza[yPos][xPos];
                plansza[yPos][xPos]="";
                break;
            }
            if(plansza[yPos][xPos][1]=='2' && finish[(int)plansza[yPos][xPos][0]-35][1]=='A'){
                finish[(int)plansza[yPos][xPos][0]-35]=plansza[yPos][xPos];
                plansza[yPos][xPos]="";
                break;
            }
            if((int)finish[(int)plansza[yPos][xPos][0]-35][1]<57 &&
               (int)finish[(int)plansza[yPos][xPos][0]-35][1]>=50){
                if(plansza[yPos][xPos][1]==(char)((int)finish[(int)plansza[yPos][xPos][0]-35][1]+1)){
                    finish[(int)plansza[yPos][xPos][0]-35]=plansza[yPos][xPos];
                    plansza[yPos][xPos]="";
                    selected=false;
                }
            }
            if(plansza[yPos][xPos][1]=='T' && finish[(int)plansza[yPos][xPos][0]-35][1]=='9'){
                finish[(int)plansza[yPos][xPos][0]-35]=plansza[yPos][xPos];
                plansza[yPos][xPos]="";
                break;
            }
            if(plansza[yPos][xPos][1]=='J' && finish[(int)plansza[yPos][xPos][0]-35][1]=='T'){
                finish[(int)plansza[yPos][xPos][0]-35]=plansza[yPos][xPos];
                plansza[yPos][xPos]="";
                break;
            }
            if(plansza[yPos][xPos][1]=='Q' && finish[(int)plansza[yPos][xPos][0]-35][1]=='J'){
                finish[(int)plansza[yPos][xPos][0]-35]=plansza[yPos][xPos];
                plansza[yPos][xPos]="";
                break;
            }
            if(plansza[yPos][xPos][1]=='K' && finish[(int)plansza[yPos][xPos][0]-35][1]=='Q'){
                finish[(int)plansza[yPos][xPos][0]-35]=plansza[yPos][xPos];
                plansza[yPos][xPos]="";
                break;
            }
        }

    }
}
void test() {
    a=0;
for (int i=0;i<4 ;i++ ){
    if(finish[i][1]=='K') a++;
}
if (a==4)
{
    winning=true;
    running=false;
}
}
};
//////////////////////////
class elements{
public:
    int win;
    elements(){
    win=0;
    for(int i=0;i<=100;i++){
swap(carta[rand()%52],carta[rand()%52]); //tasowanie
}
//umieszczanie na planszy
int i3=0;
for(int i=0;i<6;i++){
    for(int i2=0;i2<8;i2++){
        plansza[i][i2]=carta[i3];
        i3++;
    }}
for(int i=0;i<4;i++){
    plansza[6][i]=carta[i3+i];
}
}
void tell(cursor *EC){  //wyswietlanie planszy gry
    kolor(0);
    cout<<"   F r e e    C e l l"<<endl;
    /*transfer*/{
        for(int i=0;i<4;i++){
            if(transfer[i]==""){
                if((EC->xPos==i && EC->yPos==-1) || (EC->xcart==i && EC->ycart==-1)) kolor(2);
                else kolor(0);
                    cout<<(char)178<<(char)178<<" ";
            }
            else {
                if((EC->xPos==i && EC->yPos==-1) || (EC->xcart==i && EC->ycart==-1)) kolor(2);
                else if(transfer[i][0]=='%' || transfer[i][0]=='&') kolor(1);
                else kolor(0);
                if(transfer[i][0]=='$')cout<<(char)5<<transfer[i][1]<<" ";
                if(transfer[i][0]=='#')cout<<(char)6<<transfer[i][1]<<" ";
                if(transfer[i][0]=='&')cout<<(char)3<<transfer[i][1]<<" ";
                if(transfer[i][0]=='%')cout<<(char)4<<transfer[i][1]<<" ";
            }
        }
    }
    cout<<" ";
    /*meta*/{// $5  #6  &3  %4      4 i 3 czerwone
    for(int i=0;i<4;i++){
    if(EC->xPos==4+i && EC->yPos==-1) kolor(2);
    else {if(i==2 || i==3)kolor(1); else kolor(0);}
        if(finish[i]==""){
            if(i==0) cout<<(char)6<<"  ";
            if(i==1) cout<<(char)5<<"  ";
            if(i==2) cout<<(char)4<<"  ";
            if(i==3) cout<<(char)3<<"  ";
        }
        else
        {
            if(finish[i][0]=='$')cout<<(char)5<<finish[i][1]<<" ";
            if(finish[i][0]=='#')cout<<(char)6<<finish[i][1]<<" ";
            if(finish[i][0]=='&')cout<<(char)3<<finish[i][1]<<" ";
            if(finish[i][0]=='%')cout<<(char)4<<finish[i][1]<<" ";
        }
    }
    cout<<endl; kolor(0);
    for(int i=0;i<25;i++) cout<<"_";
    cout<<endl;
    }
    /*////////karty/////////*/{
    for(int i=0;i<16;i++){
            cout<<" ";
            for(int i2=0;i2<8;i2++){
    if(plansza[i][i2]==""){
        if(EC->xPos==i2 && EC->yPos==i){
        kolor(2);
        cout<<(char)219<<(char)219<<" ";
        }
        else cout<<"   ";
    }
    else{
        if((EC->xPos==i2 && EC->yPos==i) || (EC->xcart==i2 && EC->ycart==i && EC->selected)) kolor(2);
        else if(plansza[i][i2][0]=='&' || plansza[i][i2][0]=='%') kolor(1);
        else kolor(0);

            if(plansza[i][i2][0]=='#') cout<<(char)6<<plansza[i][i2][1]<<" ";
            if(plansza[i][i2][0]=='$') cout<<(char)5<<plansza[i][i2][1]<<" ";
            if(plansza[i][i2][0]=='%') cout<<(char)4<<plansza[i][i2][1]<<" ";
            if(plansza[i][i2][0]=='&') cout<<(char)3<<plansza[i][i2][1]<<" ";

    }
    }cout<<endl;}
}
gotoXY(0,0); //powrot do wspolrzednych (0,0)
}
};
  ////////////////////////
  //klawisze
  void myListener(cursor *c){
    while(true){
        if (GetAsyncKeyState(VK_LEFT) & (0x8000 != 0)){
            c->MoveLeft();
          }
        else if (GetAsyncKeyState(VK_RIGHT) & (0x8000 != 0)){
            c->MoveRight();
          }
        else if (GetAsyncKeyState(VK_UP) & (0x8000 != 0)){
            c->MoveUp();
          }
        else if (GetAsyncKeyState(VK_DOWN) & (0x8000 != 0)){
            c->MoveDown();
          }
        else if (GetAsyncKeyState(VK_SPACE) & (0x0001 != 0)){
            c->zaznacz();
        }
        else if (GetAsyncKeyState(VK_ESCAPE) & (0x8000 != 0)){
            c->running=false;
        }
        else if (GetAsyncKeyState(VK_RETURN) & (0x8000 != 0)){
            if(plansza[c->yPos][c->xPos]!="")
            c->enter();
        }
    Sleep(50);
    }
  }
  /////////////////////////////
void StartGame(){
elements myelement=elements();
cursor mycursor=cursor();
    thread mySecondThread(myListener, &mycursor);
//silnik
    while(mycursor.running){
            myelement.tell(&mycursor);
            mycursor.test();
        Sleep(80);
    }
    mySecondThread.detach();
    if(mycursor.winning){
        system("cls");
        gotoXY(3,3);
        cout<<"YOU WON";
        gotoXY(15,0);
        system("pause");
    }
}
//////////////////////////////////
int main()
{
    system("title Free Cell");
    srand(time(NULL));
    StartGame();
    return 0;
}
