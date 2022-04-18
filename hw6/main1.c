#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void printMap(char map[][30]){              // prints to terminal 

    int i,j;


for(i=0;i<15;i++){

    for(j=0;j<30;j++){




        if(map[i][j]==(char)49){            // for colors 
            printf("\033[0;33m");
        }
        else if(map[i][j]==(char)50){
            printf("\033[0;34m");
        }
        else if(map[i][j]=='X'){
            printf("\033[0;31m");
        }
        else if(map[i][j]=='_'){
            printf("\033[0;32m");
        }
        printf("%c",map[i][j]);                //printing
        printf("\033[0m");

    }
    printf("\n");
}   

}

int dice(){
    
    int num=1;
    
    do{
        num=rand()%7;           //returnig numbers between 1-6 
    }while(num==0);

    return num;
}

int startGame(int dice1,int dice2){

    if(dice1>dice2){
        return 1;                       //return which player gonna start 
    }

    else 
        return 2;

}






int main (){

    srand(time(NULL));

    int dice1,dice2,code=0,start,done1,done2,count1=0,count2=0;
    int i,j,k,x1,y1,x2,y2;
    char t,control;
    char map [15][30];

    int p1x=1;
    int p1y=1;
    int p2x=3;
    int p2y=3;

for(i=0;i<15;i++){          //these long code for filling array for first time 

    for(j=0;j<30;j++){      

        if(i==0||i==14){
            
           
            map[i][j]='.';
          
           
        }
        else if(p1x==j && p1y==i){
          
            map[i][j]=(char)49;
            x1=i;y1=j;
        }
        else if(p2x==j && p2y==i){
           
            map[i][j]=(char)50;
            x2=i;y2=j;
        }
        else if(14==j && 1==i){
          
            map[i][j]='X';
        }

        else if(28==j && 7==i){
          
            map[i][j]='X';
        }
        else if(14==j && 13==i){
           
            map[i][j]='X';
        }
        else if(10==j && 3==i){
           
            map[i][j]='X';
        }
        else if(18==j && 3==i){
          
            map[i][j]='X';
        }
        else if(26==j && 5==i){
          
            map[i][j]='X';
        }
        else if(26==j && 10==i){

           
            map[i][j]='X';
        }
        else if(10==j && 11==i){
           
            map[i][j]='X';
        }
        else if(18==j && 11==i){
           
            map[i][j]='X';
        }
        else if( (i==2 && j==1) ||  (i==4 && j==3) ){
            
            map[i][j]='_';
        }

        else if(i>0 && i<14 && (j==0||j==29) ){

           
            map[i][j]='|';
            if(j==29){
               
            }
          
        }

        else if(i>2 && i<12 && (j==2||j==27) ){
           
            map[i][j]='|';
        }
        else if(i==2||i==12){

                if(j==1||j==28){
                  
                    map[i][j]=' ';
                }
                else {
                   
                    map[i][j]='.';
                }
        }
            
        else if(i>4 && i<10 && (j==4||j==25) ){
        
            map[i][j]='|';
        }

        else if(i==4||i==10){

                if(j>3 && j<26){
                
                    map[i][j]='.';
                }
                else {
                 
                    map[i][j]=' ';
                }
        }




        else{
          
            map[i][j]=' ';
        }
 
        
    }
}




    printMap(map);
    printf("To start to game,players should dice and decide who is going to start first according to it...\n");


do{
    printf("\033[33m");
    printf("PLAYER 1... PLEASE ENTER TO DICE");             //selecting who is gonna start first 
    getchar();
    dice1=dice();
    printf("DICE : %d\n",dice1);
    printf("\033[0m");
    printf("\033[34m");
    printf("PLAYER 2... PLEASE ENTER TO DICE");
    getchar();
    dice2=dice();
    printf("DICE : %d\n",dice2);
    printf("\033[0m");

    if(dice1==dice2){
        printf("Same dice value..Please try again\n");
        continue;
    }
    
    start=startGame(dice1,dice2);

    if(start==1){
        printf("\033[33m");
        printf("\n*** PLAYER 1  will start the game....***\n\n");
        printf("\033[0m");
    }

    else{
        printf("\033[34m");
        printf("\n*** PLAYER 2  will start the game....***\n\n");
        printf("\033[0m");
    }
    break;

}while(1);



    do{
        done1=0;
        done2=0;

        if(start==1){                       //enter to dice 
            
            printf("\033[33m");
            printf("PLAYER 1... PLEASE ENTER TO DICE");
            getchar();
            dice1=dice();
            printf("DICE : %d\n",dice1);
            printf("\033[0m");
            printf("\033[34m");
            printf("PLAYER 2... PLEASE ENTER TO DICE");
            getchar();
            dice2=dice();
            printf("DICE : %d\n",dice2);
            printf("\033[0m");
        }


        if(start==2){                         //enter to dice 
            
            printf("\033[34m");
            printf("PLAYER 2... PLEASE ENTER TO DICE");
            getchar();
            dice2=dice();
            printf("DICE : %d\n",dice2);
            printf("\033[0m");
            printf("\033[33m");
            printf("PLAYER 1... PLEASE ENTER TO DICE");
            getchar();
            dice1=dice();
            printf("DICE : %d\n",dice1);
            printf("\033[0m");
        }





        for(i=0;i<dice1;i++){                   // going as many as dice number 
            count1++;
            if(p1x>0 && p1x<28 && p1y==1){
                t=map[p1y][p1x];
                map[p1y][p1x]=' ';
                p1x++;
                map[p1y][p1x]=t;
            }
            else if(p1y>0&&p1y<13&&p1x==28){
                t=map[p1y][p1x];
                map[p1y][p1x]=' ';
                p1y++;
                map[p1y][p1x]=t;
            }
            else if(p1x>1 && p1x<29 && p1y==13){
                t=map[p1y][p1x];
                map[p1y][p1x]=' ';
                p1x--;
                map[p1y][p1x]=t;
            }
            else if(p1y>0&&p1y<14&&p1x==1){
                t=map[p1y][p1x];
                map[p1y][p1x]=' ';
                p1y--;
                map[p1y][p1x]=t;
            }
           
           
        }
        if((p1x==1 && p1y==2)|| (p1x>0 && p1x<8 && p1y==1 && count1>30) ){  // winner 1 situation 
                done1=1;
        }
        
        




        for(i=0;i<dice2;i++){                           // going as many as dice number 
            count2++;   
            if(p2x>2 && p2x<26 && p2y==3){
                t=map[p2y][p2x];
                map[p2y][p2x]=' ';
                p2x++;
                map[p2y][p2x]=t;
            }
            else if(p2y>2&&p2y<11&&p2x==26){
                t=map[p2y][p2x];
                map[p2y][p2x]=' ';
                p2y++;
                map[p2y][p2x]=t;
            }
            else if(p2x>3 && p2x<27 && p2y==11){
                t=map[p2y][p2x];
                map[p2y][p2x]=' ';
                p2x--;
                map[p2y][p2x]=t;
            }
            else if(p2y>2&&p2y<12&&p2x==3){
                t=map[p2y][p2x];
                map[p2y][p2x]=' ';
                p2y--;
                map[p2y][p2x]=t;
            }
           
        }
        if(  (p2x==3 && p2y==4) || (p2x>2 && p2x<8 && p2y==3 && count2>20) ){           //winner 2 situation 
                done2=1;
        }

        if(map[1][14]!=(char)49&&map[7][28]!=(char)49&&map[13][14]!=(char)49){          // controls if racer on the X 

            map[1][14]='X';
            map[7][28]='X';
            map[13][14]='X';
        }
        else{                                                   //penalty situation

            printf("\033[33m");                                 //going two back
            printf("Penalty for player 1\n");
            printf("\033[0m");
            if(p1x>0 && p1x<28 && p1y==1){          
                t=map[p1y][p1x];
                map[p1y][p1x]=' ';
                p1x=p1x-2;
                map[p1y][p1x]=t;
            }
            else if(p1y>0&&p1y<13&&p1x==28){
                t=map[p1y][p1x];
                map[p1y][p1x]=' ';
                p1y=p1y-2;
                map[p1y][p1x]=t;
            }
            else if(p1x>1 && p1x<29 && p1y==13){
                t=map[p1y][p1x];
                map[p1y][p1x]=' ';
                p1x=p1x+2;
                map[p1y][p1x]=t;
            }
            else if(p1y>0&&p1y<14&&p1x==1){
                t=map[p1y][p1x];
                map[p1y][p1x]=' ';
                p1y=p1y+2;
                map[p1y][p1x]=t;
            }

        }
        if(map[3][10]!=(char)50&&map[3][18]!=(char)50&&map[5][26]!=(char)50&&map[10][26]!=(char)50&&map[11][10]!=(char)50&&map[11][18]!=(char)50){// controls if racer on the X 

            map[3][10]='X';
            map[3][18]='X'; 
            map[5][26]='X';
            map[10][26]='X';
            map[11][10]='X';
            map[11][18]='X';
        }
        else{                                                        //penalty situation
            printf("\033[34m");
            printf("Penalty for player 2\n");                           //going two back
            printf("\033[0m");
            if(p2x>2 && p2x<26 && p2y==3){                                      
                t=map[p2y][p2x];
                map[p2y][p2x]=' ';
                p2x=p2x-2;
                map[p2y][p2x]=t;
            }
            else if(p2y>2&&p2y<11&&p2x==26){
                t=map[p2y][p2x];
                map[p2y][p2x]=' ';
                p2y=p2y-2;
                map[p2y][p2x]=t;
            }
            else if(p2x>3 && p2x<27 && p2y==11){
                t=map[p2y][p2x];
                map[p2y][p2x]=' ';
                p2x=p2x+2;
                map[p2y][p2x]=t;
            }
            else if(p2y>2&&p2y<12&&p2x==3){
                t=map[p2y][p2x];
                map[p2y][p2x]=' ';
                p2y=p2y+2;
                map[p2y][p2x]=t;
            }
        }
        
        if(map[2][1]!=(char)49){                            

            map[2][1]='_';
        }   
        if(map[4][3]!=(char)50){

            map[4][3]='_';
        }   

        printMap(map);
        if(done1==1){
            printf("\033[0;33m");
            printf("\n*** PLAYER 1 WON THE GAME ***\n\n");              //if player 1 wins exit loop
            printMap(map);
            code=1;
            printf("\033[0m");
        }
        if(done2==1){
            printf("\033[34m");
            printf("\n*** PLAYER 2 WON THE GAME ***\n\n");                      //if player 2 wins exit loop
            printMap(map);
            code=1;
            printf("\033[0m");
        }

    }while(code==0);






    return 0;
}