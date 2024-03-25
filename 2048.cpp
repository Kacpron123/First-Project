#include <iostream>
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <conio.h>
using namespace std;
int matrix[4][4],w,score;
bool running(){
for(int i=0;i<3;i++){
    for(int i2=0;i2<4;i2++){if(matrix[i][i2]==matrix[i+1][i2]) return true;}}
for(int i=0;i<4;i++){
    for(int i2=0;i2<3;i2++){if(matrix[i][i2]==matrix[i][i2+1]) return true;}}
return false;
}

bool winnig(){
for(int i=0;i<4;i++){
    for(int i2=0;i2<4;i2++){
        if(matrix[i][i2]==2048) return true;
    }
    return false;
}
}
void tablica(){
score=0;
for(int i=0;i<4;i++){ for(int i2=0;i2<4;i2++){score+=matrix[i][i2];}}
for(int i=0;i<4;i++){
    for(int i2=0;i2<4;i2++){
        cout<<matrix[i2][i]<<"\t";
    }
cout<<endl<<endl;}
cout<<"SCORE: "<<score;
}
void go(int b){ //sterowanie
int g,h;
if(b==72){  //UP
    for(int i=0;i<4;i++){
            g=0;h=0;
            for(int i2=0;i2<4;i2++){ //sprawdzam ile elementow jest w wierszu
                    if(matrix[i][i2]!=0) g++;
            }
            int point[g+1];
            for(int i2=0;i2<4;i2++){ //sprawdzam elementy wiersza
                    if(matrix[i][i2]!=0){
                        point[h]=matrix[i][i2];
                        h++;
                    }
            }
        switch(g){
        case 1:{
            for(int i2=0;i2<4;i2++){matrix[i][i2]=0;}//zerowanie
            matrix[i][0]=point[0];
            break;}
        case 2:{
            if(point[0]==point[1]){
                for(int i2=0;i2<4;i2++){matrix[i][i2]=0;}//zerowanie
                matrix[i][0]=point[0]*2;
            }
            else{
                for(int i2=0;i2<4;i2++){matrix[i][i2]=0;}//zerowanie
                matrix[i][0]=point[0];
                matrix[i][1]=point[1];
            }
            break;}
        case 3:{
            if(point[3]==point[2] && point[2]==point[1]){
                for(int i2=0;i2<4;i2++){matrix[i][i2]=0;}//zerowanie
                matrix[i][0]=point[1]*2;
                matrix[i][1]=point[1];
                continue;
            }
            if(point[2]==point[1]){
                for(int i2=0;i2<4;i2++){matrix[i][i2]=0;}//zerowanie
                matrix[i][1]=point[2]*2;
                matrix[i][0]=point[0];
                continue;
            }
            if(point[0]==point[1]){
                for(int i2=0;i2<4;i2++){matrix[i][i2]=0;}//zerowanie
                matrix[i][1]=point[2];
                matrix[i][0]=point[0]*2;
                continue;
            }
            if(point[0]!=point[1] && point[1]!=point[2]){
                for(int i2=0;i2<4;i2++){matrix[i][i2]=0;}//zerowanie
                matrix[i][0]=point[0];
                matrix[i][1]=point[1];
                matrix[i][2]=point[2];
                continue;
            }
            break;}
        case 4:{
            if(point[0]==point[1]){
                for(int i2=0;i2<4;i2++){matrix[i][i2]=0;}//zerowanie
                matrix[i][0]=point[1]*2;
                if(point[2]==point[3])
                    matrix[i][1]=point[2]*2;
                else{
                    matrix[i][1]=point[2];
                    matrix[i][2]=point[3];
                }
            continue;
            }
            if(point[1]==point[2]){
                for(int i2=0;i2<4;i2++){matrix[i][i2]=0;}//zerowanie
                matrix[i][0]=point[0];
                matrix[i][1]=point[1]*2;
                matrix[i][2]=point[3];
            continue;
            }
            if(point[2]==point[3]){
                for(int i2=0;i2<4;i2++){matrix[i2][i]=0;}//zerowanie
                matrix[i][0]=point[0];
                matrix[i][1]=point[1];
                matrix[i][2]=point[2]*2;
            continue;
            }
            break;}
}
}
}
if(b==80){  //DOWN
for(int i=0;i<4;i++){
            g=0;h=0;
            for(int i2=0;i2<4;i2++){ //sprawdzam ile elementow jest w wierszu
                    if(matrix[i][i2]!=0) g++;
            }
            int point[g+1];
            for(int i2=0;i2<4;i2++){ //sprawdzam elementy wiersza
                    if(matrix[i][i2]!=0){
                        point[h]=matrix[i][i2];
                        h++;
                    }
            }
        switch(g){
        case 1:{
            for(int i2=0;i2<4;i2++){matrix[i][i2]=0;}//zerowanie
            matrix[i][3]=point[0];
            break;}
        case 2:{
            if(point[0]==point[1]){
                for(int i2=0;i2<4;i2++){matrix[i][i2]=0;}//zerowanie
                matrix[i][3]=point[0]*2;
            }
            else{
                for(int i2=0;i2<4;i2++){matrix[i][i2]=0;}//zerowanie
                matrix[i][3]=point[1];
                matrix[i][2]=point[0];
            }
            break;}
        case 3:{
            if(point[0]==point[1] && point[1]==point[2]){
                for(int i2=0;i2<4;i2++){matrix[i][i2]=0;}//zerowanie
                matrix[i][3]=point[1]*2;
                matrix[i][2]=point[1];
                continue;
            }
            if(point[2]==point[1]){
                for(int i2=0;i2<4;i2++){matrix[i][i2]=0;}//zerowanie
                matrix[3][i]=point[2]*2;
                matrix[2][i]=point[0];
                continue;
            }
            if(point[0]==point[1]){
                for(int i2=0;i2<4;i2++){matrix[i][i2]=0;}//zerowanie
                matrix[i][3]=point[2];
                matrix[i][2]=point[0]*2;
                continue;
            }
            if(point[0]!=point[1] && point[1]!=point[2]){
                for(int i2=0;i2<4;i2++){matrix[i][i2]=0;}//zerowanie
                matrix[i][1]=point[0];
                matrix[i][2]=point[1];
                matrix[i][3]=point[2];
                continue;
            }
            break;}
        case 4:{
            if(point[3]==point[2]){
                for(int i2=0;i2<4;i2++){matrix[i][i2]=0;}//zerowanie
                matrix[i][3]=point[2]*2;
                if(point[0]==point[1]) matrix[i][2]=point[1]*2;
                else{
                matrix[i][1]=point[0];
                matrix[i][2]=point[1];
                }
            continue;
            }
            if(point[1]==point[2]){
                for(int i2=0;i2<4;i2++){matrix[i][i2]=0;}//zerowanie
                matrix[i][3]=point[3];
                matrix[i][2]=point[1]*2;
                matrix[i][1]=point[0];
            continue;
            }
            if(point[0]==point[1]){
                for(int i2=0;i2<4;i2++){matrix[i][i2]=0;}//zerowanie
                matrix[i][3]=point[3];
                matrix[i][2]=point[2];
                matrix[i][1]=point[0]*2;
            continue;
            }
            break;}
    }
    delete point;
}
}
if(b==75){  //LEFT
    for(int i=0;i<4;i++){
            g=0;h=0;
            for(int i2=0;i2<4;i2++){ //sprawdzam ile elementow jest w wierszu
                    if(matrix[i2][i]!=0) g++;
            }
            int point[g+1];
            for(int i2=0;i2<4;i2++){ //sprawdzam elementy wiersza
                    if(matrix[i2][i]!=0){
                        point[h]=matrix[i2][i];
                        h++;
                    }
            }
        switch(g){
        case 1:{
            for(int i2=0;i2<4;i2++){matrix[i2][i]=0;}//zerowanie
            matrix[0][i]=point[0];
            break;}
        case 2:{
            if(point[0]==point[1]){
                for(int i2=0;i2<4;i2++){matrix[i2][i]=0;}//zerowanie
                matrix[0][i]=point[0]*2;
            }
            else{
                for(int i2=0;i2<4;i2++){matrix[i2][i]=0;}//zerowanie
                matrix[0][i]=point[0];
                matrix[1][i]=point[1];
            }
            break;}
        case 3:{
            if(point[3]==point[2] && point[2]==point[1]){
                for(int i2=0;i2<4;i2++){matrix[i2][i]=0;}//zerowanie
                matrix[0][i]=point[1]*2;
                matrix[1][i]=point[1];
                continue;
            }
            if(point[2]==point[1]){
                for(int i2=0;i2<4;i2++){matrix[i2][i]=0;}//zerowanie
                matrix[1][i]=point[2]*2;
                matrix[0][i]=point[0];
                continue;
            }
            if(point[0]==point[1]){
                for(int i2=0;i2<4;i2++){matrix[i2][i]=0;}//zerowanie
                matrix[1][i]=point[2];
                matrix[0][i]=point[0]*2;
                continue;
            }
            if(point[0]!=point[1] && point[1]!=point[2]){
                for(int i2=0;i2<4;i2++){matrix[i2][i]=0;}//zerowanie
                matrix[0][i]=point[0];
                matrix[1][i]=point[1];
                matrix[2][i]=point[2];
                continue;
            }
            break;}
        case 4:{
            if(point[0]==point[1]){
                for(int i2=0;i2<4;i2++){matrix[i2][i]=0;}//zerowanie
                matrix[0][i]=point[1]*2;
                if(point[2]==point[3])
                    matrix[1][i]=point[2]*2;
                else{
                    matrix[1][i]=point[2];
                    matrix[2][i]=point[3];
                }
            continue;
            }
            if(point[1]==point[2]){
                for(int i2=0;i2<4;i2++){matrix[i2][i]=0;}//zerowanie
                matrix[0][i]=point[0];
                matrix[1][i]=point[1]*2;
                matrix[2][i]=point[3];
            continue;
            }
            if(point[2]==point[3]){
                for(int i2=0;i2<4;i2++){matrix[i2][i]=0;}//zerowanie
                matrix[0][i]=point[0];
                matrix[1][i]=point[1];
                matrix[2][i]=point[2]*2;
            continue;
            }
            break;}
    }
    delete point;
}
}
if(b==77){  //RIGHT
    for(int i=0;i<4;i++){
            g=0;h=0;
            for(int i2=0;i2<4;i2++){ //sprawdzam ile elementow jest w wierszu
                    if(matrix[i2][i]!=0) g++;
            }
            int point[g+1];
            for(int i2=0;i2<4;i2++){ //sprawdzam elementy wiersza
                    if(matrix[i2][i]!=0){
                        point[h]=matrix[i2][i];
                        h++;
                    }
            }
        switch(g){
        case 1:{
            for(int i2=0;i2<4;i2++){matrix[i2][i]=0;}//zerowanie
            matrix[3][i]=point[0];
            break;}
        case 2:{
            if(point[0]==point[1]){
                for(int i2=0;i2<4;i2++){matrix[i2][i]=0;}//zerowanie
                matrix[3][i]=point[0]*2;
            }
            else{
                for(int i2=0;i2<4;i2++){matrix[i2][i]=0;}//zerowanie
                matrix[3][i]=point[1];
                matrix[2][i]=point[0];
            }
            break;}
        case 3:{
            if(point[0]==point[1] && point[1]==point[2]){
                for(int i2=0;i2<4;i2++){matrix[i2][i]=0;}//zerowanie
                matrix[3][i]=point[1]*2;
                matrix[2][i]=point[1];
                continue;
            }
            if(point[2]==point[1]){
                for(int i2=0;i2<4;i2++){matrix[i2][i]=0;}//zerowanie
                matrix[3][i]=point[2]*2;
                matrix[2][i]=point[0];
                continue;
            }
            if(point[0]==point[1]){
                for(int i2=0;i2<4;i2++){matrix[i2][i]=0;}//zerowanie
                matrix[3][i]=point[2];
                matrix[2][i]=point[0]*2;
                continue;
            }
            if(point[0]!=point[1] && point[1]!=point[2]){
                for(int i2=0;i2<4;i2++){matrix[i2][i]=0;}//zerowanie
                matrix[1][i]=point[0];
                matrix[2][i]=point[1];
                matrix[3][i]=point[2];
                continue;
            }
            break;}
        case 4:{
            if(point[3]==point[2]){
                for(int i2=0;i2<4;i2++){matrix[i2][i]=0;}//zerowanie
                matrix[3][i]=point[2]*2;
                if(point[0]==point[1]) matrix[2][i]=point[1]*2;
                else{
                matrix[1][i]=point[0];matrix[2][i]=point[1];
                }
            continue;
            }
            if(point[1]==point[2]){
                for(int i2=0;i2<4;i2++){matrix[i2][i]=0;}//zerowanie
                matrix[3][i]=point[3];
                matrix[2][i]=point[1]*2;
                matrix[1][i]=point[0];
            continue;
            }
            if(point[0]==point[1]){
                for(int i2=0;i2<4;i2++){matrix[i2][i]=0;}//zerowanie
                matrix[3][i]=point[3];
                matrix[2][i]=point[2];
                matrix[1][i]=point[0]*2;
            continue;
            }
            break;}
    }
    delete point;
}
}
}
void newpoint(){
    int x,y;
    while(true) {
        x=rand()%4;
        y=rand()%4;
        if(matrix[x][y]==0){
            matrix[x][y]=2;
            break;
        }
    }
}
int main()
{
    system("title 2048");
    cout<<"******************\n       2048\n******************";
    Sleep(2000);
    system("cls");
    srand(time(NULL));
    matrix[rand()%1][rand()%1]=2;
    matrix[rand()%1+2][rand()%1+2]=2;
    while(running()){
        tablica();
    Sleep(900);
    go(   getch()  );
    system("cls");
    if(w%2==1) newpoint();
    w++;
    }
    cout<<endl;
    if(winnig())  cout<<"******************\n      !!WIN!!\n******************\n\n\tSCORE: "<<score;
     else cout<<"******************\n    GAME OVER\n******************\n\n\tSCORE: "<<score;
    return 0;
}
