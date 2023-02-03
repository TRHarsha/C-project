#include<iostream>
using namespace std;

float u1,u2,u3,u4,u5,u6,u7,u8,u9;
int i,j;
float matrix[5][5];
int x;

int main()
{
    cout<<"\n SQUARE MESH WITH BOUNDARY VALUES \n"<<endl;
    for(x=0;x<5;x++)
    {
    cout<<"ele(0,"<<x<<"): ";
    cin>>matrix[0][x];
    }
    for(x=1;x<5;x++)
    {
        cout<<"ele("<<x<<",0): ";
        cin>>matrix[x][0];
    }
    for(x=1;x<5;x++)
    {
        cout<<"ele("<<"4,"<<x<<"): ";
        cin>>matrix[4][x];
    }
    for(x=1;x<4;x++)
    {
        cout<<"ele("<<x<<",4): ";
        cin>>matrix[x][4];
    }
    u5=(0.25)*(matrix[2][0]+matrix[2][4]+matrix[0][2]+matrix[4][2]);
    cout<<"\n u5 = 1/4{"<<matrix[2][0]<<"+"<<matrix[2][4]<<"+"<<matrix[0][2]<<"+"<<matrix[4][2]<<"} ="<<u5<<endl;
    matrix[2][2]=u5;
    u1=(0.25)*(matrix[0][2]+matrix[2][0]+matrix[0][0]+matrix[2][2]);
    cout<<"\n u1 = 1/4{"<<matrix[0][2]<<"+"<<matrix[2][0]<<"+"<<matrix[0][0]<<"+"<<matrix[2][2]<<"} ="<<u1<<endl;
    matrix[1][1]=u1;
    u3=(0.25)*(matrix[0][4]+matrix[2][2]+matrix[0][2]+matrix[2][4]);
    cout<<"\n u3 = 1/4{"<<matrix[0][4]<<"+"<<matrix[2][2]<<"+"<<matrix[0][2]<<"+"<<matrix[2][4]<<"} ="<<u3<<endl;
    matrix[1][3]=u3;
    u7=(0.25)*(matrix[4][0]+matrix[2][2]+matrix[2][0]+matrix[4][2]);
    cout<<"\n u7 = 1/4{"<<matrix[4][0]<<"+"<<matrix[2][2]<<"+"<<matrix[2][0]<<"+"<<matrix[4][2]<<"} ="<<u7<<endl;
    matrix[3][1]=u7;
    u9=(0.25)*(matrix[4][2]+matrix[2][4]+matrix[2][2]+matrix[4][4]);
    cout<<"\n u9 = 1/4{"<<matrix[4][2]<<"+"<<matrix[2][4]<<"+"<<matrix[2][2]<<"+"<<matrix[4][4]<<"} ="<<u9<<endl;
    matrix[3][3]=u9;
    u2=(0.25)*(matrix[1][1]+matrix[1][3]+matrix[0][2]+matrix[2][2]);
    cout<<"\n u2 = 1/4{"<<matrix[1][1]<<"+"<<matrix[1][3]<<"+"<<matrix[0][2]<<"+"<<matrix[2][2]<<"} ="<<u2<<endl;
    matrix[1][2]=u2;
    u4=(0.25)*(matrix[2][0]+matrix[2][2]+matrix[1][1]+matrix[3][1]);
    cout<<"\n u4 = 1/4{"<<matrix[2][0]<<"+"<<matrix[2][2]<<"+"<<matrix[1][1]<<"+"<<matrix[3][1]<<"} ="<<u4<<endl;
    matrix[2][1]=u4;
    u6=(0.25)*(matrix[2][2]+matrix[2][4]+matrix[1][3]+matrix[3][3]);
    cout<<"\n u6 = 1/4{"<<matrix[2][2]<<"+"<<matrix[2][4]<<"+"<<matrix[1][3]<<"+"<<matrix[3][3]<<"} ="<<u6<<endl;
    matrix[2][3]=u6;
    u8=(0.25)*(matrix[3][1]+matrix[3][3]+matrix[2][2]+matrix[4][2]);
    cout<<"\n u8 = 1/4{"<<matrix[3][1]<<"+"<<matrix[3][3]<<"+"<<matrix[2][2]<<"+"<<matrix[4][2]<<"} ="<<u8<<endl;
    matrix[3][2]=u8;

    cout<<"\n\n DISPLAY MATRIX \n"<<endl;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            cout<<matrix[i][j]<<"\t\t";
        }
        cout<<endl;
    }
}

