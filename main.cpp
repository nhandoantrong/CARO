#include <string.h>
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdio>
#include <string>
using namespace std;
char key,x,y;
string p1,p2;
char c[101][101];
void fil()
{
    int i,j;
    for (i=0; i<101; i++)
        for(j=0; j<101; j++)
            c[i][j]=0;
}
void point (int x, int y)
{
    COORD pos= {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void control()
{
    if (int(key==75)) x-=2;
    else if (int(key==77)) x+=2;
    else if (int(key==72)) y-=2;
    else if  (int(key==80)) y+=2;
    if (x<17) x=17;
    if (y<6) y=6;
    if (x>91) x=91;
    if (y>6+22) y=28;
    point(x,y);
}
void TextColor(int a)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
}
char turn(int i)
{
    if (i%2==0)
    {
        TextColor(11);
        return 'X';
    }
    else
    {
        TextColor(12);
        return 'O';
    }
}

bool check( bool n)
{
    return(n==1);
}
bool vert(int y)
{
    int i=y,j,dem=0;
    for (j=1; j<5; j++)
    {
        if (c[x][i+2*j]==c[x][i])
        {
            dem++;
        }
        else break;
    }
    if (dem<4)
    {
        for (j=1; j<5; j++)
        {
            if (c[x][i-2*j]==c[x][i])
            {
                dem++;
            }
            else break;
        }
    }
    return dem==4;
}

bool hor(int x)
{
    int i=x,j,dem=0;
    for (j=1; j<5; j++)
    {
        if (c[i][y]==c[i+2*j][y])
        {
            dem++;
        }
        else break;
    }
    if (dem<4)
    {
        for (j=1; j<5; j++)
        {
            if (c[i][y]==c[i-2*j][y])
            {
                dem++;
            }
            else break;
        }
    }
    return dem==4;
}
bool lrdiagonal (int x, int y)
{
    {
        int i=x,j,k=y,dem=0;
        for (j=1; j<5; j++)
        {
            if (c[i][k]==c[i+2*j][k+2*j])
            {
                dem++;
            }
            else break;
        }
        if (dem<4)
        {
            for (j=1; j<5; j++)
            {
                if (c[i][k]==c[i-2*j][k-2*j])
                {
                    dem++;
                }
                else break;
            }
        }
        return dem==4;
    }
}

bool rldiagonal(int x,int y)
{
    int i=x,j,k=y,dem=0;
    for (j=1; j<5; j++)
    {
        if (c[i][k]==c[i+2*j][k-2*j])
        {
            dem++;
        }
        else break;
    }
    if (dem<4)
    {
        for (j=1; j<5; j++)
        {
            if (c[i][k]==c[i-2*j][k+2*j])
            {
                dem++;
            }
            else break;
        }
    }
    return dem==4;
}

void player()
{
    cout<<"\t\t\t\tWELCOME TO CARO BATTLE FIELD"<<endl;
    cout<<"\t\t\t     YOU TWO HAVE TO PUT YOUR NAME HERE"<<endl;
    cout<<"PLAYER 1 : ";
    getline(cin,p1);
    cout<<"PLAYER 2 : ";
    getline(cin,p2);

}
void table()
{
    int i,j;
    char tt=218,ng=196,g=194,tp=191,d=179,ng1=195,th=197,ng2=180,dt=192,dg=193,dp=217;
    cout<<"\t\t";
    for (i=1; i<40; i++)
    {
        if (i==1) cout<<tt<<ng;
        else if (i==39) cout<<tp;
        else cout<<g<<ng;
    }
    cout<<endl<<"\t\t";
    for (j=1; j<12; j++)
    {
        for (i=1; i<79; i++)
        {
            if (i%2==1) cout <<d;
            else cout<<" ";
        }
        cout<<endl<<"\t\t";
        for (i=1; i<40; i++)
        {
            if (i==1) cout<<ng1;
            else if (i==39) cout<<ng<<ng2;
            else cout<<ng<<th;
        }
        cout<<endl<<"\t\t";
    }
    for (i=1; i<79; i++)
    {
        if (i%2==1) cout <<d;
        else cout<<" ";
    }
    cout<<endl<<"\t\t";
    for (i=1; i<40; i++)
    {
        if (i==1) cout<<dt<<ng;
        else if (i==39) cout<<dp;
        else cout<<dg<<ng;
    }
}
void inst()
{
    TextColor(7);
    point(0,8);
    cout<<"ARROWS : MOVE";
    point(0,9);
    cout<<"F : PLAY";
    point(0,10);
    cout<<"Q : ESCAPE";
}
void game(int i)
{
    system("cls");
    TextColor(13);
    cout<<"\t\t\t\t\tCARO BATTLE FIELD"<<endl;
    cout<<endl;
    cout<<"\t\t\t\t\t"<<p1<<" VS "<<p2<<endl<<endl;
    if (i%2==1)
    cout<<"\t\t\t\t\t"<<p1<<" go first"<<endl;
    else cout<<"\t\t\t\t\t"<<p2<<" go first"<<endl;
    TextColor(7);
    TextColor(10);
    table();
    inst();
}
int main()
{
//    ios_base::sync_with_stdio(0);
    player();
    int i,j;
    i=0;
    while (1)
    {
        fil();
        i++;
        game(i);
        x=17+15*2;
        y=6+4*2;
        point(x,y);
        while (key!='q'||key!='Q')
        {
            key=getch();
            control();
            if (key=='q'||key=='Q') break;
            else if ((key=='f')&&(!check(c[x][y]))||(key=='F'))
            {
                cout<<turn(i);
                c[x][y]=turn(i);
                i++;
                if ((vert(y))||(hor(x))||(lrdiagonal(x,y))||(rldiagonal(x,y)))
                {
                    point(0,20);
                    TextColor(14);
                    if (c[x][y]=='X')
                        {
                            cout<<" "<<p2<<" WIN";
                            Sleep(5000);
                            i=0;
                        }
                    else
                    {
                        cout<<" "<<p1<<" WIN";
                        Sleep(5000);
                        i=1;
                    }
                    break;
                }
            }
        }
    }
    point (0,29);
    return 0;
}
