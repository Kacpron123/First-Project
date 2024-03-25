#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <ctime>
#include <string>
#include <conio.h>
#include <cmath>
#include <thread>
#include <vector>
using namespace std;
char blok=91;
char blok2=219;
bool look_schowek=false;
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
string plansza[38][7];
vector <string> schowek;
string finish[4];
int lock[7]={0,1,2,3,4,5,6};
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
    xPos=6;
    }
void MoveRight(){
    if(xPos<7)
    xPos++;
    if(xPos==7)
    xPos=0;
    }
void MoveUp()   {
    if(yPos>-1)
    yPos--;
    }
void MoveDown() {
    if(yPos<18)
    yPos++;
    }
void zaznacz(){
    /*dla schowka*/{
if(look_schowek==false && xPos==0 && yPos==-1 && schowek.size()>0)
    look_schowek=true;
if(xPos==0 && yPos==-1 && look_schowek==true && schowek.size()>0)
    schowek_tasowanie();
    }
    /*dla karty schowka*/{
if(look_schowek==true){
if(xPos==1 && yPos==-1){
    if(selected==false){
        selected=true;
        xcart=1;
        ycart=-1;
    }
    else{
        selected=false;
        xcart=ycart=-1;
    }
    }
    }}
    /*dla zwyklej karty*/{
    if(lock[xPos]<=yPos){
    if(selected==false){
            if(plansza[yPos][xPos]!=""){
        xcart=xPos;
        ycart=yPos;
        selected=true;
    }}
    else{   //jezeli zaznaczam karte gdy selected==true
    if(xPos==xcart && yPos==ycart){ //jezeli klikam w karte zaznczaczona
        selected=false;
        xcart=ycart=-1;
    }
    else{ //jezeli klikam w karte nie zaznaczona
            if(ycart==-1){
            for(int i=0;i<1;i++){
            /*z finisha*/if(xcart>=3 && xcart<7){
                        if(finish[xcart-3][1]=='A' && plansza[yPos-1][xPos][1]=='2' && plansza[yPos][xPos]==""){
                if(( (finish[xcart-3][0]=='#' || finish[xcart-3][0]=='$' )
                   && (plansza[yPos-1][xPos][0]=='%' || plansza[yPos-1][xPos][0]=='&') )
                   ||
                   ( (finish[xcart-3][0]=='%' || finish[xcart-3][0]=='&' )
                   && (plansza[yPos-1][xPos][0]=='#' || plansza[yPos-1][xPos][0]=='$') )
                   ){
                plansza[yPos][xPos]=finish[xcart-3];
                finish[xcart-3]="";
                selected=false;
                break;
            }
            }
                        if(finish[xcart-3][1]=='2' && plansza[yPos-1][xPos][1]=='3' && plansza[yPos][xPos]==""){
                if(( (finish[xcart-3][0]=='#' || finish[xcart-3][0]=='$' )
                   && (plansza[yPos-1][xPos][0]=='%' || plansza[yPos-1][xPos][0]=='&') )
                   ||
                   ( (finish[xcart-3][0]=='%' || finish[xcart-3][0]=='&' )
                   && (plansza[yPos-1][xPos][0]=='#' || plansza[yPos-1][xPos][0]=='$') )
                   ){
                plansza[yPos][xPos]=finish[xcart-3];
                finish[xcart-3][1]='A';
                selected=false;
                break;
            }
            }
                        if((int)finish[xcart-3][1]<=57 && (int)finish[xcart-3][1]>50 && plansza[yPos][xPos]==""){
                if(plansza[yPos-1][xPos][1]==(char)((int)finish[xcart-3][1]+1) ){
                if(( (finish[xcart-3][0]=='#' || finish[xcart-3][0]=='$' )
                   && (plansza[yPos-1][xPos][0]=='%' || plansza[yPos-1][xPos][0]=='&') )
                   ||
                   ( (finish[xcart-3][0]=='%' || finish[xcart-3][0]=='&' )
                   && (plansza[yPos-1][xPos][0]=='#' || plansza[yPos-1][xPos][0]=='$') )
                   ){
                plansza[yPos][xPos]=finish[xcart-3];
                finish[xcart-3][1]=(char)((int)finish[xcart-3][1]-1);
                selected=false;
                break;
            }
            }
            }
                        if(finish[xcart-3][1]=='T' && plansza[yPos-1][xPos][1]=='9' && plansza[yPos][xPos]==""){
                if(( (finish[xcart-3][0]=='#' || finish[xcart-3][0]=='$' )
                   && (plansza[yPos-1][xPos][0]=='%' || plansza[yPos-1][xPos][0]=='&') )
                   ||
                   ( (finish[xcart-3][0]=='%' || finish[xcart-3][0]=='&' )
                   && (plansza[yPos-1][xPos][0]=='#' || plansza[yPos-1][xPos][0]=='$') )
                   ){
                plansza[yPos][xPos]=finish[xcart-3];
                finish[xcart-3][1]='9';
                selected=false;
                break;
            }
            }
                        if(finish[xcart-3][1]=='J' && plansza[yPos-1][xPos][1]=='T' && plansza[yPos][xPos]==""){
                if(( (finish[xcart-3][0]=='#' || finish[xcart-3][0]=='$' )
                   && (plansza[yPos-1][xPos][0]=='%' || plansza[yPos-1][xPos][0]=='&') )
                   ||
                   ( (finish[xcart-3][0]=='%' || finish[xcart-3][0]=='&' )
                   && (plansza[yPos-1][xPos][0]=='#' || plansza[yPos-1][xPos][0]=='$') )
                   ){
                plansza[yPos][xPos]=finish[xcart-3];
                finish[xcart-3][1]='T';
                selected=false;
                break;
            }
            }
                        if(finish[xcart-3][1]=='Q' && plansza[yPos-1][xPos][1]=='J' && plansza[yPos][xPos]==""){
                if(( (finish[xcart-3][0]=='#' || finish[xcart-3][0]=='$' )
                   && (plansza[yPos-1][xPos][0]=='%' || plansza[yPos-1][xPos][0]=='&') )
                   ||
                   ( (finish[xcart-3][0]=='%' || finish[xcart-3][0]=='&' )
                   && (plansza[yPos-1][xPos][0]=='#' || plansza[yPos-1][xPos][0]=='$') )
                   ){
                plansza[yPos][xPos]=finish[xcart-3];
                finish[xcart-3][1]='J';
                selected=false;
                break;
            }
            }
                        if(finish[xcart-3][1]=='K' && plansza[yPos-1][xPos][1]=='Q' && plansza[yPos][xPos]==""){
                if(( (finish[xcart-3][0]=='#' || finish[xcart-3][0]=='$' )
                   && (plansza[yPos-1][xPos][0]=='%' || plansza[yPos-1][xPos][0]=='&') )
                   ||
                   ( (finish[xcart-3][0]=='%' || finish[xcart-3][0]=='&' )
                   && (plansza[yPos-1][xPos][0]=='#' || plansza[yPos-1][xPos][0]=='$') )
                   ){
                plansza[yPos][xPos]=finish[xcart-3];
                finish[xcart-3][1]='Q';
                selected=false;
                break;
            }
            }
        }
            /*ze schwoka*/if(xcart==1){
                    if(schowek.size()>0){
                if(schowek[schowek.size()-1][1]=='K' && yPos==0 && plansza[yPos][xPos]==""){
            plansza[yPos][xPos]=schowek[schowek.size()-1];
            if(schowek.size()>0)schowek.pop_back();
            selected=false;
            break;
            }
            if(schowek[schowek.size()-1][1]=='Q' && plansza[yPos-1][xPos][1]=='K' && plansza[yPos][xPos]==""){
                if(( (schowek[schowek.size()-1][0]=='#' || schowek[schowek.size()-1][0]=='$' )
                   && (plansza[yPos-1][xPos][0]=='%' || plansza[yPos-1][xPos][0]=='&') )
                   ||
                   ( (schowek[schowek.size()-1][0]=='%' || schowek[schowek.size()-1][0]=='&' )
                   && (plansza[yPos-1][xPos][0]=='#' || plansza[yPos-1][xPos][0]=='$') )
                   ){
                plansza[yPos][xPos]=schowek[schowek.size()-1];
                if(schowek.size()>0)schowek.pop_back();
                selected=false;
                break;
            }
            }
            if(schowek[schowek.size()-1][1]=='J' && plansza[yPos-1][xPos][1]=='Q' && plansza[yPos][xPos]==""){
                if(( (schowek[schowek.size()-1][0]=='#' || schowek[schowek.size()-1][0]=='$' )
                   && (plansza[yPos-1][xPos][0]=='%' || plansza[yPos-1][xPos][0]=='&') )
                   ||
                   ( (schowek[schowek.size()-1][0]=='%' || schowek[schowek.size()-1][0]=='&' )
                   && (plansza[yPos-1][xPos][0]=='#' || plansza[yPos-1][xPos][0]=='$') )
                   ){
                plansza[yPos][xPos]=schowek[schowek.size()-1];
                if(schowek.size()>0)schowek.pop_back();
                selected=false;
            }
            }
            if(schowek[schowek.size()-1][1]=='T' && plansza[yPos-1][xPos][1]=='J' && plansza[yPos][xPos]==""){
                if(( (schowek[schowek.size()-1][0]=='#' || schowek[schowek.size()-1][0]=='$' )
                   && (plansza[yPos-1][xPos][0]=='%' || plansza[yPos-1][xPos][0]=='&') )
                   ||
                   ( (schowek[schowek.size()-1][0]=='%' || schowek[schowek.size()-1][0]=='&' )
                   && (plansza[yPos-1][xPos][0]=='#' || plansza[yPos-1][xPos][0]=='$') )
                   ){
                plansza[yPos][xPos]=schowek[schowek.size()-1];
                if(schowek.size()>0)schowek.pop_back();
                selected=false;
                break;
            }
            }
            if(schowek[schowek.size()-1][1]=='9' && plansza[yPos-1][xPos][1]=='T' && plansza[yPos][xPos]==""){
                if(( (schowek[schowek.size()-1][0]=='#' || schowek[schowek.size()-1][0]=='$' )
                   && (plansza[yPos-1][xPos][0]=='%' || plansza[yPos-1][xPos][0]=='&') )
                   ||
                   ( (schowek[schowek.size()-1][0]=='%' || schowek[schowek.size()-1][0]=='&' )
                   && (plansza[yPos-1][xPos][0]=='#' || plansza[yPos-1][xPos][0]=='$') )
                   ){
                plansza[yPos][xPos]=schowek[schowek.size()-1];
                if(schowek.size()>0)schowek.pop_back();
                selected=false;
                break;
            }
            }
            if((int)schowek[schowek.size()-1][1]<=56 && (int)schowek[schowek.size()-1][1]>=50 && plansza[yPos][xPos]==""){
                if(plansza[yPos-1][xPos][1]==(char)((int)schowek[schowek.size()-1][1]+1) ){
                if(( (schowek[schowek.size()-1][0]=='#' || schowek[schowek.size()-1][0]=='$' )
                   && (plansza[yPos-1][xPos][0]=='%' || plansza[yPos-1][xPos][0]=='&') )
                   ||
                   ( (schowek[schowek.size()-1][0]=='%' || schowek[schowek.size()-1][0]=='&' )
                   && (plansza[yPos-1][xPos][0]=='#' || plansza[yPos-1][xPos][0]=='$') )
                   ){
                plansza[yPos][xPos]=schowek[schowek.size()-1];
                if(schowek.size()>0)schowek.pop_back();
                selected=false;
                break;
            }
            }
            }
            if(schowek[schowek.size()-1][1]=='A' && plansza[yPos-1][xPos][1]=='2' && plansza[yPos][xPos]==""){
                if(( (schowek[schowek.size()-1][0]=='#' || schowek[schowek.size()-1][0]=='$' )
                   && (plansza[yPos-1][xPos][0]=='%' || plansza[yPos-1][xPos][0]=='&') )
                   ||
                   ( (schowek[schowek.size()-1][0]=='%' || schowek[schowek.size()-1][0]=='&' )
                   && (plansza[yPos-1][xPos][0]=='#' || plansza[yPos-1][xPos][0]=='$') )
                   ){
                plansza[yPos][xPos]=schowek[schowek.size()-1];
                if(schowek.size()>0)schowek.pop_back();
                selected=false;
                break;
            }
            }
            }}}}
            /*z kart*/else{
            if(xcart!=xPos ){
            if(plansza[ycart][xcart][1]=='K' && yPos==0 && plansza[yPos][xPos]==""){
                    for(int i=ycart;i<19;i++){
                        swap(plansza[i][xcart],plansza[i-ycart][xPos]);
                    }
                    if(lock[xcart]>0) lock[xcart]--;
                    selected=false;
            }
            if(plansza[ycart][xcart][1]=='Q' && yPos!=0 && plansza[yPos-1][xPos][1]=='K' && plansza[yPos][xPos]==""){
                    if(
                   ( (plansza[ycart][xcart][0]=='#' || plansza[ycart][xcart][0]=='$' )
                   && (plansza[yPos-1][xPos][0]=='%' || plansza[yPos-1][xPos][0]=='&') )
                   ||
                   ( (plansza[ycart][xcart][0]=='%' || plansza[ycart][xcart][0]=='&' )
                   && (plansza[yPos-1][xPos][0]=='#' || plansza[yPos-1][xPos][0]=='$') )
                   ){
                    for(int i=ycart;i<19;i++){
                        swap(plansza[i][xcart],plansza[i-ycart+yPos][xPos]);
                    }
                    if(lock[xcart]>0 && lock[xcart]==ycart) lock[xcart]--;
                    selected=false;
        }}
            if(plansza[ycart][xcart][1]=='J' && yPos!=0 && plansza[yPos-1][xPos][1]=='Q' && plansza[yPos][xPos]==""){
                    if(
                   ( (plansza[ycart][xcart][0]=='#' || plansza[ycart][xcart][0]=='$' )
                   && (plansza[yPos-1][xPos][0]=='%' || plansza[yPos-1][xPos][0]=='&') )
                   ||
                   ( (plansza[ycart][xcart][0]=='%' || plansza[ycart][xcart][0]=='&' )
                   && (plansza[yPos-1][xPos][0]=='#' || plansza[yPos-1][xPos][0]=='$') )
                   ){
                    for(int i=ycart;i<19;i++){
                        swap(plansza[i][xcart],plansza[i-ycart+yPos][xPos]);
                    }
                    if(lock[xcart]>0 && lock[xcart]==ycart) lock[xcart]--;
                    selected=false;
        }}
            if(plansza[ycart][xcart][1]=='T' && yPos!=0 && plansza[yPos-1][xPos][1]=='J' && plansza[yPos][xPos]==""){
                    if(
                   ( (plansza[ycart][xcart][0]=='#' || plansza[ycart][xcart][0]=='$' )
                   && (plansza[yPos-1][xPos][0]=='%' || plansza[yPos-1][xPos][0]=='&') )
                   ||
                   ( (plansza[ycart][xcart][0]=='%' || plansza[ycart][xcart][0]=='&' )
                   && (plansza[yPos-1][xPos][0]=='#' || plansza[yPos-1][xPos][0]=='$') )
                   ){
                    for(int i=ycart;i<19;i++){
                        swap(plansza[i][xcart],plansza[i-ycart+yPos][xPos]);
                    }
                    if(lock[xcart]>0 && lock[xcart]==ycart) lock[xcart]--;
                    selected=false;
        }}
            if(plansza[ycart][xcart][1]=='9' && yPos!=0 && plansza[yPos-1][xPos][1]=='T' && plansza[yPos][xPos]==""){
                    if(
                   ( (plansza[ycart][xcart][0]=='#' || plansza[ycart][xcart][0]=='$' )
                   && (plansza[yPos-1][xPos][0]=='%' || plansza[yPos-1][xPos][0]=='&') )
                   ||
                   ( (plansza[ycart][xcart][0]=='%' || plansza[ycart][xcart][0]=='&' )
                   && (plansza[yPos-1][xPos][0]=='#' || plansza[yPos-1][xPos][0]=='$') )
                   ){
                    for(int i=ycart;i<19;i++){
                        swap(plansza[i][xcart],plansza[i-ycart+yPos][xPos]);
                    }
                    if(lock[xcart]>0 && lock[xcart]==ycart) lock[xcart]--;
                    selected=false;
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
                    for(int i=ycart;i<19;i++){
                        swap(plansza[i][xcart],plansza[i-ycart+yPos][xPos]);
                    }
                    if(lock[xcart]>0 && lock[xcart]==ycart) lock[xcart]--;
                    selected=false;
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
                    if(lock[xcart]>0 && lock[xcart]==ycart) lock[xcart]--;
                    selected=false;
        }}
    }
}
    }
    }
    }}
    /*dla finishow*/{               // #  $  %  &
    for(int i=0;i<4;i++){
        if(xPos==i+3 && yPos==-1 && finish[i]!=""){
                if(!selected){
                    selected=true;
                    xcart=xPos;
                    ycart=yPos;
                    break;
                    }
                if(selected && ycart==-1 && xcart>=3){
                    selected=false;
                    ycart=xcart=-1;
                }
        }
    }
}
if(schowek.size()==0) look_schowek=false;
}
void enter(){
    for (int i=0;i<1;i++){
        if(lock[xPos]<=yPos){//z kart
            if(yPos>=0 && plansza[yPos+1][xPos]==""){
                    if(plansza[yPos][xPos][1]=='A' && finish[(int)plansza[yPos][xPos][0]-35]==""){
                        finish[(int)plansza[yPos][xPos][0]-35]=plansza[yPos][xPos];
                        plansza[yPos][xPos]="";
                        if(lock[xcart]>0 && lock[xPos]==yPos) lock[xPos]--;
                        break;
                    }
                    if(plansza[yPos][xPos][1]=='2' && finish[(int)plansza[yPos][xPos][0]-35][1]=='A'){
                        finish[(int)plansza[yPos][xPos][0]-35]=plansza[yPos][xPos];
                        plansza[yPos][xPos]="";
                        if(lock[xcart]>0 && lock[xPos]==yPos) lock[xPos]--;
                        break;
                    }
                    if((int)finish[(int)plansza[yPos][xPos][0]-35][1]<57 &&
                       (int)finish[(int)plansza[yPos][xPos][0]-35][1]>=50){
                        if(plansza[yPos][xPos][1]==(char)((int)finish[(int)plansza[yPos][xPos][0]-35][1]+1)){
                            finish[(int)plansza[yPos][xPos][0]-35]=plansza[yPos][xPos];
                            plansza[yPos][xPos]="";
                            if(lock[xPos]>0 && lock[xPos]==yPos) lock[xPos]--;
                            selected=false;
                        }
                    }
                    if(plansza[yPos][xPos][1]=='T' && finish[(int)plansza[yPos][xPos][0]-35][1]=='9'){
                        finish[(int)plansza[yPos][xPos][0]-35]=plansza[yPos][xPos];
                        plansza[yPos][xPos]="";
                        if(lock[xcart]>0 && lock[xPos]==yPos) lock[xPos]--;
                        break;
                    }
                    if(plansza[yPos][xPos][1]=='J' && finish[(int)plansza[yPos][xPos][0]-35][1]=='T'){
                        finish[(int)plansza[yPos][xPos][0]-35]=plansza[yPos][xPos];
                        plansza[yPos][xPos]="";
                        if(lock[xcart]>0 && lock[xPos]==yPos) lock[xPos]--;
                        break;
                    }
                    if(plansza[yPos][xPos][1]=='Q' && finish[(int)plansza[yPos][xPos][0]-35][1]=='J'){
                        finish[(int)plansza[yPos][xPos][0]-35]=plansza[yPos][xPos];
                        plansza[yPos][xPos]="";
                        if(lock[xcart]>0 && lock[xPos]==yPos) lock[xPos]--;
                        break;
                    }
                    if(plansza[yPos][xPos][1]=='K' && finish[(int)plansza[yPos][xPos][0]-35][1]=='Q'){
                        finish[(int)plansza[yPos][xPos][0]-35]=plansza[yPos][xPos];
                        plansza[yPos][xPos]="";
                        if(lock[xcart]>0 && lock[xPos]==yPos) lock[xPos]--;
                        break;
                    }
            }}
            if(yPos==-1 && (xPos==1 || xPos==0)){ //ze schowka
                    if(schowek.size()>0){
                    if(finish[(int)schowek[schowek.size()-1][0]-35]=="" && schowek[schowek.size()-1][1]=='A'){
                            finish[(int)schowek[schowek.size()-1][0]-35]=schowek[schowek.size()-1];
                            schowek.pop_back();
                            break;
                        }
                    if(finish[(int)schowek[schowek.size()-1][0]-35][1]=='A' && schowek[schowek.size()-1][1]=='2'){
                            finish[(int)schowek[schowek.size()-1][0]-35]=schowek[schowek.size()-1];
                            schowek.pop_back();
                            break;
                            }
                    if((int)finish[ (int)schowek[schowek.size()-1][0]-35 ][1]<57 &&
                       (int)finish[ (int)schowek[schowek.size()-1][0]-35 ][1]>=50){
                        if(schowek[schowek.size()-1][1]==(char)((int)finish[(int)schowek[schowek.size()-1][0]-35][1]+1)){
                            finish[(int)schowek[schowek.size()-1][0]-35]=schowek[schowek.size()-1];
                            schowek.pop_back();
                            break;
                        }
                    }
                    if(finish[(int)schowek[schowek.size()-1][0]-35][1]=='9' && schowek[schowek.size()-1][1]=='T'){
                            finish[(int)schowek[schowek.size()-1][0]-35]=schowek[schowek.size()-1];
                            schowek.pop_back();
                            break;
                            }
                    if(finish[(int)schowek[schowek.size()-1][0]-35][1]=='T' && schowek[schowek.size()-1][1]=='J'){
                            finish[(int)schowek[schowek.size()-1][0]-35]=schowek[schowek.size()-1];
                            schowek.pop_back();
                            break;
                            }
                    if(finish[(int)schowek[schowek.size()-1][0]-35][1]=='J' && schowek[schowek.size()-1][1]=='Q'){
                            finish[i]=schowek[schowek.size()-1];
                            schowek.pop_back();
                            break;
                            }
                    if(finish[(int)schowek[schowek.size()-1][0]-35][1]=='Q' && schowek[schowek.size()-1][1]=='K'){
                            finish[i]=schowek[schowek.size()-1];
                            schowek.pop_back();
                            break;
                            }
            }}
            }
        if(schowek.size()==0) look_schowek=false;
    }
void schowek_tasowanie(){
    if(look_schowek)
for(int i=0;i<schowek.size()-1;i++){
swap(schowek[i],schowek[i+1]);
}
}
void test(){
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
//umieszczanie na planszy i w schowku
for(int i=0;i<24;i++){
    schowek.push_back(carta[i]);

}
int i3=24;
for(int i=7;i>=1;i--){
    for(int i2=0;i2<i;i2++){
        plansza[7-i][i2+7-i]=carta[i3];
        i3++;
    }
}
}
void tell(cursor *EC){  //wyswietlanie planszy gry
    kolor(0);
    cout<<"    P A S J A N S"<<endl;
    /*ikona schowka*/{
    if(EC->xPos==0 && EC->yPos==-1) kolor(2);
    cout<<blok<<blok2<<" ";
    }
    /*karta schowka*/{
    if(EC->xcart==1 && EC->ycart==-1 && EC->selected==true){
        kolor(2);
        if(schowek[schowek.size()-1][0]=='$')cout<<(char)5<<schowek[schowek.size()-1][1]<<" ";
        if(schowek[schowek.size()-1][0]=='#')cout<<(char)6<<schowek[schowek.size()-1][1]<<" ";
        if(schowek[schowek.size()-1][0]=='&')cout<<(char)3<<schowek[schowek.size()-1][1]<<" ";
        if(schowek[schowek.size()-1][0]=='%')cout<<(char)4<<schowek[schowek.size()-1][1]<<" ";
    }
    else{
    if(EC->xPos==1 && EC->yPos==-1) kolor(2);
    else{
        if(look_schowek && (schowek[schowek.size()-1][0]=='&' || schowek[schowek.size()-1][0]=='%')) kolor(1);
        else    kolor(0);}
    if(!look_schowek){
        if( EC->xPos==1 && EC->yPos==-1 )   cout<<blok2<<blok2<<" ";
        else cout<<"   ";
    //if((EC->xPos!=1 || EC->yPos!=-1) || schowek.size()==0 ) cout<<"   ";
    }
    if(look_schowek){
            if(schowek.size()>0){
                if(schowek[schowek.size()-1][0]=='$')cout<<(char)5<<schowek[schowek.size()-1][1]<<" ";
                if(schowek[schowek.size()-1][0]=='#')cout<<(char)6<<schowek[schowek.size()-1][1]<<" ";
                if(schowek[schowek.size()-1][0]=='&')cout<<(char)3<<schowek[schowek.size()-1][1]<<" ";
                if(schowek[schowek.size()-1][0]=='%')cout<<(char)4<<schowek[schowek.size()-1][1]<<" ";

            }}
    }
}
    /*przerwa*/{
    if(EC->xPos==2 && EC->yPos==-1){kolor(2); cout<<blok2<<blok2<<" ";}
    else cout<<"   ";
    }
    /*meta*/{
    for(int i=0;i<4;i++){
    if((EC->xPos==3+i && EC->yPos==-1) || (EC->ycart==-1 && EC->xcart==3+i && EC->selected)) kolor(2);
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
    for(int i=0;i<21;i++) cout<<"_";
    cout<<endl;
    }
    /*////////karty/////////*/{
    for(int i=0;i<19;i++){for(int i2=0;i2<7;i2++){
        if(plansza[i][i2]==""){             //czy jest to pustka
            if(i==EC->yPos && i2==EC->xPos){//jesli jest tam kursor kolor zaznaczenia i ikonka cursora
                kolor(2);
                cout<<blok2<<blok2<<" ";
            continue;
            }
            else {cout<<"   "; continue;}   //jesli go tam nie ma przerwa
        }
        //jesli jest karta
        if(i==EC->ycart && i2==EC->xcart && EC->selected==true){ //jesli karta jest zaznaczona
            kolor(2);
                if(plansza[i][i2][0]=='$')cout<<(char)5<<plansza[i][i2][1]<<" ";
                if(plansza[i][i2][0]=='#')cout<<(char)6<<plansza[i][i2][1]<<" ";
                if(plansza[i][i2][0]=='&')cout<<(char)3<<plansza[i][i2][1]<<" ";
                if(plansza[i][i2][0]=='%')cout<<(char)4<<plansza[i][i2][1]<<" ";
            continue;
        }
        if(i==EC->yPos && i2==EC->xPos) kolor(2);   //czy kursor jest na karcie jesli tak kolor zaznaczenia
            else{
        if(plansza[i][i2][0]=='&' || plansza[i][i2][0]=='%')    //czy to czerwona karta i kolor czerwony
            kolor(1); else kolor(0);}                           //jesli nie, powiec karta o kolorze bialym
        if(i<lock[i2]){ //czy karta jest zablokowana
        if(i==EC->yPos && i2==EC->xPos) kolor(2);
        else kolor(0);
        cout<<blok<<blok2<<" ";}
        else
        {
            if(plansza[i][i2][0]=='$')cout<<(char)5<<plansza[i][i2][1]<<" ";
            if(plansza[i][i2][0]=='#')cout<<(char)6<<plansza[i][i2][1]<<" ";
            if(plansza[i][i2][0]=='&')cout<<(char)3<<plansza[i][i2][1]<<" ";
            if(plansza[i][i2][0]=='%')cout<<(char)4<<plansza[i][i2][1]<<" ";
        }
    }cout<<endl;}
    gotoXY(0,0); //powrot do wspolrzednych (0,0)
}
gotoXY(21,1); cout<<"   ";
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
    look_schowek=true;
    while(mycursor.running){
            myelement.tell(&mycursor);
            mycursor.test();
            gotoXY(20,0); cout<<"  ";gotoXY(0,0);
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
    system("title PASJANS SOLITAIRE");
    srand(time(NULL));
    StartGame();
    return 0;
}
