#include <iostream>
#include <cstring>
using namespace std;
int main() {
    float no1,no2;
    int opt;
    bool running=true;
    cout<<"Welcome to simple claculator"<<"\n";
    while(running){
    cout<<"What do you want to perform press 1/2/3/4"<<"\n";
    do{
    cout<<"1.Addition:"<<"\n";
    cout<<"2.Subtraction:"<<"\n";
    cout<<"3.Multiplication:"<<"\n";
    cout<<"4.Division:"<<"\n";  
    cin>>opt;}while(opt>4&&opt<1);
    switch(opt){
        case 1:
            cout<<"Enter first number:";
            cin>>no1;
            cout<<"Enter second number:";
            cin>>no2;
            cout<<no1<<"+"<<no2<<":"<<no1+no2;
            break;
        case 2:
            cout<<"Enter first number:";
            cin>>no1;
            cout<<"Enter second number:";
            cin>>no2;
            cout<<no1<<"-"<<no2<<":"<<no1-no2;
            break;
        case 3:
            cout<<"Enter first number:";
            cin>>no1;
            cout<<"Enter second number:";
            cin>>no2;
            cout<<no1<<"x"<<no2<<":"<<no1*no2;
            break;
        case 4:
            cout<<"Enter first number:";
            cin>>no1;
            cout<<"Enter second number:";
            cin>>no2;
            cout<<no1<<"/"<<no2<<":"<<no1/no2; 
            break;   

    }
    cout<<endl<<"Want to perform more operations press 1/0 :";
    cin>>running;  
    }
}
