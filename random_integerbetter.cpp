#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
void random_number(int ll,int ul,int choice){
    int t=time(0);
    int rno;//rand number
    int guess;
    int counter=0;//variable to check how many times the usser guessed
    srand(t);
    cout<<"guess ";
    if(choice==1){
        do{
            rno=(rand()%ul)+1;//limit will be 1..ul

        }while(rno<ll);
        //after loop new limit will be ll..ul
         do {
        cin >> guess;
        if (guess < rno) {
            cout << "Guess Higher ";
            counter++;
        } else if (guess > rno) {
            cout << "Guess Lower ";
            counter++;
        }
    } while (guess != rno);
    cout << "Yay you guessed it after " << counter+1<< " wrong answers";
    }
    else {
            rno=(rand()%500)+1;//limit will be 1..500
            do{
            cin>>guess;
            
            if(guess<rno){
                cout<<"Guess Higher ";
                counter++;
            }
            else if (guess > rno){
            cout<<"Guess Lower ";
            counter++;
            }
            }while(guess!=rno);
        cout<<"Yay you guessed it after "<<counter+1<<" wrong answers";

        }
    
}
int main(){
    int a;
    do{
    cout<<"Press 1 if you want your own range to guess number"<<"\n";
    cout<<"Press 2  if you want to guess number in the range 1-500: ";
    cin>>a;
    if ((a!=1)&&(a!=2)){
        cout<<"enter only 1 or 2";
    }
    else{
        break;
    }
    }while((a!=1)&&(a!=2));
    
    if(a==1){
        int x1,x2;
        cout<<"Enter lower limit of range:";
        cin>>x1;
        cout<<"Enter upper limit of range:";
        cin>>x2;
        random_number(x1,x2,a);
    }
    else {
        random_number(1,500,a);//the limit will be 1..500

    }}
