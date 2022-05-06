#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define MAPSIZE 15


void printmap(char map[][16]){                                      //prints puzzle map 
    for(int i=0;i<MAPSIZE;i++){

        for(int j=0;j<MAPSIZE;j++){
            printf("%c ",map[i][j]);
        }
        printf("\n");
    }
}


void select_direction(int direction_num[]){                         // which direction ? horizontally, vertically, or diagonally (8 directions)
    int i,j;
    int num ;
    for(i=0;i<7;i++){
        num =rand()%8+1;

        if(num==1){
            direction_num[i]=num;
        }
        else if(num==2){
            direction_num[i]=num;
        }
        else if(num==3){
            direction_num[i]=num;
        }
        else if(num==4){
            direction_num[i]=num;
        }
        else if(num==5){
            direction_num[i]=num;
        }
        else if(num==6){
            direction_num[i]=num;
        }
        else if(num==7){
            direction_num[i]=num;
        }
        else if(num==8){
            direction_num[i]=num;
        }
        else {
            i--;
        }
    }
}
char *strrev(char *str)	//strrev not available in linux gcc
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

int main(){

    int random_w;
    int k,i,j;
    srand(time(NULL));

    char map[MAPSIZE][MAPSIZE+1];
    int direction_num[8];
    int word_begin[2][7];

    for(i=0;i<MAPSIZE;i++){                             //filling array with '.' 

        for(j=0;j<MAPSIZE;j++){
            map[i][j]='.';
        }
    }

    FILE* inp; 
    inp = fopen("wordlist.txt","r");		
    char words[51][10];		
    i = 0; 
    while(1){ 
        char r = (char)fgetc(inp); 
        int m = 0; 
        while(r!='\n' && !feof(inp)){	//read till '\n' or EOF 
            words[i][m++] = r;			//store in words
            r = (char)fgetc(inp); 
        } 
        words[i][m]='\0';		//make last character of string null  
        if(feof(inp)){		//check again for EOF 
            break; 
        } 
        i++; 
    } 
    fclose(inp);

    int con=0;
    char word7[7][10];                                                          
    int lenght_7 [7];
    int notsame [7]={-1,-1,-1,-1,-1,-1,-1};

    for(k=0;k<7;k++){                                       //getting info about 7 word

        random_w = rand()%50 ;
        for(i=0;i<7;i++){
            if(random_w==notsame[i]){
                con=1;                  //continue, dont use same word
            }
        }
        if(con==1)
            k--;
        else{
            notsame[k]=random_w;                        //used words goes to notsame array 
            strcpy(word7[k],words[random_w]);            
               lenght_7[k]=strlen(word7[k]);            //words7 and lenght_7 gets filled 
        }
        con=0;
    }

    int rand_x,rand_y,bad=0;                  //choosing word starting coordinates
    

    select_direction(direction_num);           



    for(k=0;k<7;k++){
       
        bad=0;                                  //unwanted situation if bad == 1 

        if(1==direction_num[k]){
            do{
                bad=0;

            
                rand_x=rand()%15;
                rand_y=rand()%15;
            
                if(rand_x+ lenght_7[k]<15){

                    for(j=0;j<lenght_7[k];j++){
                        if(map[rand_y][rand_x+j]!='.'){                     // controls if the places for word is not used
                            bad=1;
                            break;
                        }
                    }
                    if(bad==0){
                        for(j=0;j<lenght_7[k];j++){
                            map[rand_y][rand_x+j]=word7[k][j];
                            if(j==lenght_7[k]-1){
                                word_begin[0][k]=rand_x;                       //keeping start points of words 
                                word_begin[1][k]=rand_y;

                            }
                        }
                    }


                }
                else{
                    bad=1;
                }
            
            }while(bad==1);
        }
        bad=0;
        if(2==direction_num[k]){
            strrev(word7[k]);
            do{
                bad=0;
            
                rand_x=rand()%15;
                rand_y=rand()%15;
            
                if(rand_x+ lenght_7[k]<15){

                    for(j=0;j<lenght_7[k];j++){
                        if(map[rand_y][rand_x+j]!='.'){                         // controls if the places for word is not used
                            bad=1;
                            break;
                        }
                    }
                    if(bad==0){
                        for(j=0;j<lenght_7[k];j++){
                            map[rand_y][rand_x+j]=word7[k][j];
                            if(j==lenght_7[k]-1){
                                word_begin[0][k]=rand_x+j;                       //keeping start points of words 
                                word_begin[1][k]=rand_y;

                            }
                        }
                    }


                }
                else{
                    bad=1;
                }
            }while(bad==1);
            strrev(word7[k]);
        }
        bad=0;
        if(3==direction_num[k]){
            do{
                bad=0;
            
                rand_x=rand()%15;
                rand_y=rand()%13;
            
                if(rand_y+ lenght_7[k]<15){

                    for(j=0;j<lenght_7[k];j++){
                        if(map[rand_y+j][rand_x]!='.'){                                 // controls if the places for word is not used
                            bad=1;
                            break;
                        }
                    }
                    if(bad==0){
                        for(j=0;j<lenght_7[k];j++){
                            map[rand_y+j][rand_x]=word7[k][j];
                            if(j==lenght_7[k]-1){
                                word_begin[0][k]=rand_x;                      //keeping start points of words 
                                word_begin[1][k]=rand_y;

                            }
                        }
                    }


                }
                else{
                    bad=1;
                }
            }while(bad==1);
        }



        bad=0;
        if(4==direction_num[k]){
            strrev(word7[k]);
            do{
                bad=0;
                rand_x=rand()%15;
                rand_y=rand()%13;
            
                if(rand_y+ lenght_7[k]<15){

                    for(j=0;j<lenght_7[k];j++){
                        if(map[rand_y+j][rand_x]!='.'){                                 // controls if the places for word is not used
                            bad=1;
                            break;
                        }
                    }
                    if(bad==0){
                        for(j=0;j<lenght_7[k];j++){
                            map[rand_y+j][rand_x]=word7[k][j];
                            if(j==lenght_7[k]-1){
                                word_begin[0][k]=rand_x;                       //keeping start points of words 
                                word_begin[1][k]=rand_y+j;

                            }
                        }
                    }

                }
                else{
                    bad=1;
                }
            
            }while(bad==1);
            strrev(word7[k]);
        }
        bad=0;
        if(5==direction_num[k]){
            do{
                bad=0;
                rand_x=rand()%15;
                rand_y=rand()%15;
            
                if(rand_x+ lenght_7[k]<15 && rand_y+ lenght_7[k]<15){

                    for(j=0;j<lenght_7[k];j++){
                        if(map[rand_y+j][rand_x+j]!='.'){                           // controls if the places for word is not used
                            bad=1;
                            break;
                        }
                    }
                    if(bad==0){
                        for(j=0;j<lenght_7[k];j++){
                            map[rand_y+j][rand_x+j]=word7[k][j];
                            if(j==lenght_7[k]-1){
                                word_begin[0][k]=rand_x;                       //keeping start points of words 
                                word_begin[1][k]=rand_y;

                            }
                        }
                    }
                }
                else{
                    bad=1;
                }
            }while(bad==1);
        }
        bad=0;
        if(6==direction_num[k]){
            strrev(word7[k]);
            do{
                bad=0;
                rand_x=rand()%15;
                rand_y=rand()%15;
            
                if(rand_x+ lenght_7[k]<15 && rand_y+ lenght_7[k]<15){

                    for(j=0;j<lenght_7[k];j++){
                        if(map[rand_y+j][rand_x+j]!='.'){                                   // controls if the places for word is not used
                            bad=1;
                            break;
                        }
                    }
                    if(bad==0){
                        for(j=0;j<lenght_7[k];j++){
                            map[rand_y+j][rand_x+j]=word7[k][j];
                            if(j==lenght_7[k]-1){
                                word_begin[0][k]=rand_x+j;                       //keeping start points of words 
                                word_begin[1][k]=rand_y+j;

                            }
                        }
                    }
                }
                else{
                    bad=1;
                }
            }while(bad==1);
            strrev(word7[k]);
        }
        bad=0;
        if(7==direction_num[k]){
            do{
                bad=0;
                rand_x=rand()%13;
                rand_y=rand()%13;
            
                if(rand_x- lenght_7[k]>=0 && rand_x+ lenght_7[k]<15 && rand_y+ lenght_7[k]<15){

                    for(j=0;j<lenght_7[k];j++){
                        if(map[rand_y+j][rand_x-j]!='.'){                                           // controls if the places for word is not used
                            bad=1;
                            break;
                        }
                    }
                    if(bad==0){
                        for(j=0;j<lenght_7[k];j++){
                            map[rand_y+j][rand_x-j]=word7[k][j];
                            if(j==lenght_7[k]-1){
                                word_begin[0][k]=rand_x;                       //keeping start points of words 
                                word_begin[1][k]=rand_y;

                            }
                        }
                    }
                }
                else{
                    bad=1;
                }
            }while(bad==1);
        }
        bad=0;
        if(8==direction_num[k]){
            strrev(word7[k]);
            do{
                bad=0;
                rand_x=rand()%13;
                rand_y=rand()%13;
            
                if(rand_x- lenght_7[k]>=0 && rand_x+ lenght_7[k]<15 && rand_y+ lenght_7[k]<15){

                    for(j=0;j<lenght_7[k];j++){
                        if(map[rand_y+j][rand_x-j]!='.'){                       // controls if the places for word is not used 
                            bad=1;
                            break;
                        }
                    }
                    if(bad==0){
                        for(j=0;j<lenght_7[k];j++){
                            map[rand_y+j][rand_x-j]=word7[k][j];

                            if(j==lenght_7[k]-1){
                                word_begin[0][k]=rand_x-j;                      //keeping start points of words 
                                word_begin[1][k]=rand_y+j;          

                            }
                        }
                    }
                }
                else{
                    bad=1;
                }
            }while(bad==1);
            strrev(word7[k]);
        }


    }//end of placing words


    for(k=0;k<15;k++){
        for(j=0;j<15;j++){
            if (map[k][j]=='.'){

                map[k][j]= rand()%26+97;              // random filling the gaps
            }
        }
    }

    char answer[30];
    char exitq[30];
    int x,y,ans_word_index=-1,total_point=0,mistakes=0;
    int c;
    
do{
    printmap(map);

    for(i=0;i<7;i++){
        printf("\n%s-> x:%d y:%d",word7[i],word_begin[0][i],word_begin[1][i] );       //printing begining of words 
    }

    ans_word_index=-1;
    
    printf("\nEnter coordinates and word: ");
    if( 0==fgets(answer,28,stdin) ){
        printf("\nenter valid entry\n");
        while ( (c = getchar()) != '\n' && c != EOF) { }
        continue;
    }
    


    sscanf(answer,"%s ",exitq);


    if( 0==strcmp(exitq,":q") ){

        printf("\nexiting\n");
        exit(1);
    }

    sscanf(answer,"%d %d %s",&x,&y,exitq);

    strcpy(answer,exitq);
        
            for(k=0;k<7;k++){                                   //controls if entered word is in map
                if( 0==strcmp(answer,word7[k]) ){
                    ans_word_index=k;
                }
            }
            if(ans_word_index==-1){                             // if ans_word_index equals -1 word is not in the map                        
                mistakes++;
                printf("\nWord you enter is not in the map\n");
                printf("\nWrong choice! You have only %d lefts.\n\n",3-mistakes);
                continue;                                          
            }
        
            bad=0;

            if( x==word_begin[0][ans_word_index] && y==word_begin[1][ans_word_index] ){         //controling if input x and y are correct 

                if(1==direction_num[ans_word_index]){                       

                    for( j=1;j<lenght_7[ans_word_index];j++ ){
                        if( word7[ans_word_index][j] != map[y][x+j] ){                 //controlling if words matches 
                            bad=1;
                            break;
                        }
                    }
                    if(bad==0){                                                     //replacing founded word with "X"
                        for( j=0;j<lenght_7[ans_word_index];j++ ){                              
                            map[y][x+j]='X';
                        }
                    }
                }
                else if(2==direction_num[ans_word_index]){

                    for( j=1;j<lenght_7[ans_word_index];j++ ){
                        if( word7[ans_word_index][j] != map[y][x-j] ){                 //controlling if words matches 
                            bad=1;
                            break;
                        }
                    }
                    if(bad==0){                                                     //replacing founded word with "X"
                        for( j=0;j<lenght_7[ans_word_index];j++ ){                              
                            map[y][x-j]='X';
                        }
                    }
                }
                else if(3==direction_num[ans_word_index]){
                    
                    for( j=1;j<lenght_7[ans_word_index];j++ ){
                        if( word7[ans_word_index][j] != map[y+j][x] ){                //controlling if words matches 
                            bad=1;
                            break;
                        }
                    }
                    if(bad==0){                                                     //replacing founded word with "X"
                        for( j=0;j<lenght_7[ans_word_index];j++ ){                              
                            map[y+j][x]='X';
                        }
                    }
                }
                else if(4==direction_num[ans_word_index]){
                    
                    for( j=1;j<lenght_7[ans_word_index];j++ ){
                        if( word7[ans_word_index][j] != map[y-j][x] ){                //controlling if words matches 
                            bad=1;
                            break;
                        }
                    }
                    if(bad==0){                                                     //replacing founded word with "X"
                        for( j=0;j<lenght_7[ans_word_index];j++ ){                              
                            map[y-j][x]='X';
                        }
                    }
                }
                else if(5==direction_num[ans_word_index]){
                    
                    for( j=1;j<lenght_7[ans_word_index];j++ ){
                        if( word7[ans_word_index][j] != map[y+j][x+j] ){                //controlling if words matches 
                            bad=1;
                            break;
                        }
                    }
                    if(bad==0){                                                     //replacing founded word with "X"
                        for( j=0;j<lenght_7[ans_word_index];j++ ){                              
                            map[y+j][x+j]='X';
                        }
                    }
                }
                else if(6==direction_num[ans_word_index]){
                    
                    for( j=1;j<lenght_7[ans_word_index];j++ ){
                        if( word7[ans_word_index][j] != map[y-j][x-j] ){             //controlling if words matches            
                            bad=1;
                            break;
                        }
                    }
                    if(bad==0){                                                     //replacing founded word with "X"
                        for( j=0;j<lenght_7[ans_word_index];j++ ){                              
                            map[y-j][x-j]='X';
                        }
                    }
                }
                else if(7==direction_num[ans_word_index]){
                    
                    for( j=1;j<lenght_7[ans_word_index];j++ ){
                        if( word7[ans_word_index][j] != map[y+j][x-j] ){             //controlling if words matches                                    
                            bad=1;
                            
                            break;
                        }
                    }
                    if(bad==0){                                                     //replacing founded word with "X"
                        for( j=0;j<lenght_7[ans_word_index];j++ ){                              
                            map[y+j][x-j]='X';
                        }
                    }
                }
                else if(8==direction_num[ans_word_index]){
                    
                    for( j=1;j<lenght_7[ans_word_index];j++ ){
                        if( word7[ans_word_index][j] != map[y-j][x+j] ){               //controlling if words matches          
                            bad=1;
                            break;
                        }
                    }
                    if(bad==0){                                                     //replacing founded word with "X"
                        for( j=0;j<lenght_7[ans_word_index];j++ ){                              
                            map[y-j][x+j]='X';
                        }
                    }
                }
            }

            else{                            //unwanted case
                bad=1;                              
            }
            if(bad==1){                // wrong answer 
                mistakes++;
                printf("\nWrong choice! You have only %d lefts.\n",3-mistakes);
            }
            else{                       //correct answer 
                total_point += 2;
                printf("\nFounded! you got 2 points. Your total points : %d\n",total_point);
            }
    
}while( mistakes<3 && total_point<14 );         //end conditions



if(mistakes==3){                                            //losing condition
    printf("\nTotal point is %d\n",total_point);
    printf("\n\nGAME OVER\n");
    return 1;
}
else if(total_point==14){                                   //win condition
    printf("\nTotal point is %d\n",total_point);
    printf("\n\nYOU WON\n");
    return 0;
}



    return 0;
}



