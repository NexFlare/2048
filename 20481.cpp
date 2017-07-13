#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

bool check (int a[][4],int b[][4])
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(a[i][j]!=b[i][j])
                return false;
        }
    }

    return true;
}
void shiftw(int a[][4],int s,int j){
    int c=3;
            for(int i=s;i<c;){
                if(a[i][j]==0){
                        int k=i;
                    while(k<3){
                        a[k][j]=a[k+1][j];
                        a[k+1][j]=0;
                        k++;
                    }
                     c--;
                }
                else
                    i++;
            }
    return;
}

void shifts(int a[][4],int s,int j){
    int c=0;
            for(int i=s;i>c;){
                if(a[i][j]==0){
                        int k=i;
                    while(k>0){
                        a[k][j]=a[k-1][j];
                        a[k-1][j]=0;
                        k--;
                    }
                     c++;
                }
                else
                    i--;
            }
    return;
}
void shifta(int a[][4], int s , int i)
{
    int c=3;
            for(int j=s;j<c;){
                if(a[i][j]==0){
                        int k=j;
                    while(k<3){
                        a[i][k]=a[i][k+1];
                        a[i][k+1]=0;
                        k++;
                    }
                     c--;
                }
                else
                    j++;
            }
    return;
}

void shiftd(int a[][4], int s , int i)
{
     int c=0;
            for(int j=s;j>c;){
                if(a[i][j]==0){
                        int k=j;
                    while(k>0){
                        a[i][k]=a[i][k-1];
                        a[i][k-1]=0;
                        k--;
                    }
                     c++;
                }
                else
                    j--;
            }
    return;
}
int main()
{
    srand (time(NULL));
    int a[4][4]={0};
    int score=0;
    int row=rand()%4;
    int col=rand()%2;
    a[row][col]=2;
    row=rand()%4;
    col=rand()%2+2;
    a[row][col]=2;
    char ch;
    int prev[4][4];
    cout<<"\t\t\t\tPress W for up.\n \t\t\t\tPress A for left.\n \t\t\t\tPress S for down.\n \t\t\t\tPress D for right.\n";
    while(1){
            cout<<endl<<endl<<endl<<endl;
            cout<<"\t\t\t\t"<<"SCORE : "<<score<<endl<<endl;
    cout<<endl<<"\t\t\t\t________________________________________________________"<<endl;
    cout<<endl<<"   ";
        for(int i=0;i<4;i++){
            cout<<"\t\t\t\t";
        for(int j=0;j<4;j++){
            if(a[i][j]==0){
            cout<<" "<<"\t|\t";
            }
            else{
                system("color C");
                cout<<a[i][j]<<"\t|\t";
            }
            prev[i][j] = a[i][j];
        }
        cout<<endl<<"\t\t\t\t\t|\t\t|\t\t|\t\t|"<<endl<<"\t\t\t\t________________________________________________________"<<endl<<endl;
    }
    cin>>ch;
    if(ch=='w'||ch=='W'){
        for(int j=0;j<4;j++)
        {
            shiftw(a,0,j);
            for(int i=0;i<3;){
                int x=a[i][j];
                int y=a[i+1][j];
                if(x==y){
                    a[i][j]=x+y;
                    score+=a[i][j];
                    a[i+1][j]=0;
                    shiftw(a,i+1,j);
                    i++;
                }
                else
                    i++;
            }
        }
        if(!check(a,prev))
         {
             srand (time(NULL));
        row = rand()%2 + 2;
        col = rand()%4;
        while(a[row][col]!=0)
        {
             srand (time(NULL));
            row = rand()%2 + 2;
            col = rand()%4;
        }
        a[row][col] = 2;
         }
    }
    else if(ch=='s'||ch=='S'){
        for(int j=0;j<4;j++)
        {
            shifts(a,3,j);
            for(int i=3;i>0;){
                int x=a[i][j];
                int y=a[i-1][j];
                if(x==y){
                    a[i][j]=x+y;
                    score+=a[i][j];
                    a[i-1][j]=0;
                    shifts(a,i-1,j);
                    i--;
                }
                else
                    i--;
            }
        }
        if(!check(a,prev))
         {
             srand (time(NULL));
        row = rand()%2 ;
        col = rand()%4;
        while(a[row][col]!=0)
        {
             srand (time(NULL));
            row = rand()%2;
            col = rand()%4;
        }
        a[row][col] = 2;
         }
    }
    else if(ch=='d'||ch=='D'){
        for(int i=0;i<4;i++)
        {
            shiftd(a,3,i);
            for(int j=3;j>0;){
                int x=a[i][j];
                int y=a[i][j-1];
                if(x==y){
                    a[i][j]=x+y;
                    score=score+a[i][j];
                    a[i][j-1]=0;
                    shiftd(a,i,j-1);
                    j--;
                }
                else
                    j--;
            }
        }
        if(!check(a,prev))
         {
         srand (time(NULL));
        col = rand()%2;
        row = rand()%4;
        while(a[row][col]!=0)
        {
             srand (time(NULL));
            col = rand()%2;
            row = rand()%4;
        }
        a[row][col] = 2;
         }
    }

   if(ch=='a'||ch=='A'){
        for(int i=0;i<4;i++)
        {
            shifta(a,0,i);
            for(int j=0;j<3;){
                int x=a[i][j];
                int y=a[i][j+1];
                if(x==y){
                    a[i][j]=x+y;
                    score=score+a[i][j];
                    a[i][j+1]=0;
                    shifta(a,i,j+1);
                    j++;
                }
                else
                    j++;
            }
        }
        if(!check(a,prev))
         {
             srand (time(NULL));
        col = rand()%2 + 2;
        row = rand()%4;
        while(a[row][col]!=0)
        {
             srand (time(NULL));
            col = rand()%2 + 2;
            row = rand()%4;
        }
        a[row][col] = 2;
         }
    }
   system("cls");

    }
    return 0;
}
