#include<iostream>
#include<map>
#include<ctime>
using namespace std;
int t=time(0);
void drawmesh(char *arr){
    //function that draws the board after each move
    cout<<"     |     |      "<<"\n";
    cout<<"  "<<arr[0]<<"  |  "<<arr[1]<<"  |  "<<arr[2]<<"  "<<"\n";
    cout<<" ____|_____|_____ "<<"\n";
    cout<<"     |     |      "<<"\n";
    cout<<"  "<<arr[3]<<"  |  "<<arr[4]<<"  |  "<<arr[5]<<"  "<<"\n";
    cout<<" ____|_____|_____ "<<"\n";
    cout<<"     |     |      "<<"\n";
    cout<<"  "<<arr[6]<<"  |  "<<arr[7]<<"  |  "<<arr[8]<<"  "<<"\n";
    cout<<"     |     | "<<"\n";

}
void playermove(char *arr,char player){
    int move;
         do{
            cout<<"Choose only form 1,2,...8,9 and do not play the same move again for your move :";
            cin>>move;
            }while((move<1 || move>9)||(arr[move-1]!=' '));//do while loop so that player does not make any illegal move
           arr[move-1]=player;
           cout<<"player move over"<<"\n";
           }
        
void compmove(char *arr,char computer){
    int t=time(0);
    srand(t);
    int move;
    do{move=rand()%9;
    }while(arr[move]!=' ');//do while so that computer does not make any illegal move
    arr[move]=computer;
    cout<<"comp move over"<<"\n";
}
bool decideTIE(char *arr){
    //if there is any blank spaces left means there is a tie
for(int i=0;i<8;i++){
    if(arr[i]==' '){
        return false;
    }
}
cout<<"It is a tie"<<"\n";
return 1;

}
bool whoW0N(char *arr,char player,char computer){
    if((arr[0]!=' ') &&(arr[0]==arr[1])&&(arr[0]==arr[2])){//row 1
        arr[0]==player ?cout<<"Player won":cout<<"Comp won";
        return 1;
    }
    else if ( arr[3]!=' ' &&(arr[3]==arr[4])&&(arr[3]==arr[5]))//row 2
    {
        arr[3]==player ?cout<<"Player won":cout<<"Comp won";
        return 1;
    }
    else if ( arr[6]!=' ' && (arr[6]==arr[7])&&(arr[6]==arr[8]))//row 3
    { 
        arr[6]==player ?cout<<"Player won":cout<<"Comp won";
        return 1;
    }
    else if (arr[0]!=' ' &&(arr[0]==arr[3])&&(arr[0]==arr[6]))//column 1
    {
        arr[0]==player ?cout<<"Player won":cout<<"Comp won";
        return 1;
    }
    else if (arr[1]!=' ' &&(arr[1]==arr[4])&&(arr[1]==arr[7]))//column 2
    {
        arr[1]==player ?cout<<"Player won":cout<<"Comp won";
        return 1;

    }
    else if (arr[2]!=' ' &&(arr[2]==arr[5])&&(arr[2]==arr[8]))//column 3
    {
       arr[2]==player ?cout<<"Player won":cout<<"Comp won";
        return 1;
    }
    else if ( arr[0]!=' ' &&(arr[0]==arr[4])&&(arr[0]==arr[8]))//diagonal left to right
    {
        arr[0]==player ? cout<<"Player won":cout<<"Comp won";
        return 1; 
    }
    else if (arr[2]!=' ' &&(arr[2]==arr[4])&&(arr[2]==arr[6]))//diagonal right to left
    {
        arr[2]==player ? cout<<"Player won":cout<<"Comp won";
        return 1;
    }
    else{//means the game continues
        return 0;
    }

    return 1;
      
}
char toss(char HorT){
    char hd='H';
    char ts='T';
    srand(t);
    int result=rand()%2;
    if(result==0){
        return hd;
    }
    else{
        return ts;
    }
 }
int main(){
    char player,computer;//symbols of player and computer
    bool running=true;//variable to check the game is over / draw
    bool flag=true;//variable to keep player playing new games.
    while(flag){
    char arr[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
    drawmesh(arr);
    do{cout<<"Select your Symbol X/0 :";
    cin>>player;}while(player!='X' && player!='0');//do while loop so that user does not select any other characters
    computer = (player=='X') ? '0' : 'X';
    char HorT;
    do{cout<<"Select your toss coin H/T :";//another do while so that user does not selects any other character
    cin>>HorT;}while(HorT!='H'&&HorT!='T');//user selects there Heads or tails
    char result=toss(HorT);
    cout<< result <<" it is !"<<"\n";
    if(result==HorT){
        //player won toss therefore makes the first move
        while(running){
        playermove(arr,player);
        drawmesh(arr);
        if(whoW0N(arr,player,computer)==true){//if player wona at this step
            running=false;
            break;
        }
        else if (decideTIE(arr)==true)//or is it a tie
        {
            running=false;
            break;
        }
        
        compmove(arr,computer);//if computer won or is it a tie at this step
        drawmesh(arr);
        if(whoW0N(arr,player,computer)==true){
            running=false;
            break;
        }
        else if (decideTIE(arr)==true)
        {
            running=false;
            break;
        }
        }
        
    }
    else{
        //computer won toss now computer makes the first moves
        while(running){
        compmove(arr,computer);
        drawmesh(arr);
        if(whoW0N(arr,player,computer)==true){
            running=false;
            break;
        }
        else if (decideTIE(arr)==true)
        {
            running=false;
            break;
        }
        playermove(arr,player);
        drawmesh(arr);
        if(whoW0N(arr,player,computer)==true){
            running=false;
            break;
        }
        else if (decideTIE(arr)==true)
        {
            running=false;
            break;
        }
        
        
        }
 
    }
    cout<<"\n"<<"Press 1 to play once more or 0 to quit and exit : ";
    cin>>flag;
    running=true;//loop to check whether player want to play more or not
    if(!flag){
        cout<<"thank you";
        break;
    }
}

}