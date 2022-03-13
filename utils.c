#include <stdio.h>
#include "utils.h"


int find_divisible(int x, int y, int z){
		int temp=x+1;
		
		if ((x>y)||(z>y)) { 
			printf("There is not any integer between %d and %d can be divided by %d\n",x,y,z);	
			
			return -1 ; 
		}
		
		
		for (;temp<y;temp++){				//finds first divisible integer
		
			if (temp%z==0){
		
				printf("The first integer between %d and %d divided by %d is %d\n\n",x,y,z,temp);
				printf("\n");
			
				return temp;			
			}				
		}
		
		printf("There is not any integer between %d and %d can be divided by %d\n",x,y,z);
		return -1;
		
		
	 }//end of find_divisible
	 
	 
	 int find_nth_divisible(int n, int f_i, int z){
		int temp=0;
		
		temp= f_i + z*n;
	
		return temp;

	}//end of find_nth_divisible
	 
	 
	 
	 

int validate_identity_number(char identity_number[]){

        int temp0=0,temp1=0,temp2=0,i=0;
   

  	if(identity_number[0]=='0'){				//controls for first digit being zero 
              
          	return (0);
        }

 


       if(  (identity_number[9]==('u')) || (identity_number[11]!=('\0') )    ){        //controls for 11 digit
                                                   
       
       	return 0;
        }



      for(int i =0;i<11;i++){  
       
       
           	 if(i<10){
                	temp0=temp0+identity_number[i]-48;		//temp0 for sum of first 10 digits
           	 }

                if( (identity_number[i]>'9') ||  (identity_number[i]<'0')  ){        //controls for digit only
                       
                        return 0;
                }

               
                if(i==0||i==2||i==4||i==6||i==8){			//temp1 for sum of odd digits expect 11th digit
                        temp1=temp1+identity_number[i]-48;
                       
                }
                if(i==1||i==3||i==5||i==7){				//temp2 for sum of even digits
                        temp2=temp2+identity_number[i]-48;
                       
                }

                if( i==10 ) {						

                    	 int  d10=(temp1*7-temp2)%10;			//d10 for tenth digit
                      
                      
                

               	 if  (  (d10 == (identity_number[9]-48 ) )   &&   ((identity_number[10]-48) ==(temp0%10) )) { //validation 

                  	         	printf("\n");
                 	           	return 1;
               	 }


              	  	else {  
              		  		printf("\n");
              	               	return 0;
             	  	 }
       
       
              	  }
               
        }

   }//end of validate_identity_number





int create_customer(char identity_number [ ], int password){

	FILE* customer;

	if(customer=fopen("customeraccount.txt","w")){				//opening text file in write mode
		fprintf(customer,"%s,%d",identity_number,password);
		fclose(customer);						//closing 	
	}
	else {
		printf("file cant be opened");
	}

}//end of create_customer



int check_login(char identity_number [ ], int password){

	int flag=1;
	char identitylogin[15],data_identity[15],data_password[12],passwordlogin[12];  
	
	printf("Enter identity number:");
	scanf("%s",identitylogin);
	printf("Enter password:");
	scanf("%s",passwordlogin);
	
	if(  (identitylogin[11])!=('\0')   ){        //controls for 11 digit
                                                   
       	return 0;
        }
	
	FILE* customer;
	customer=fopen("customeraccount.txt","r");			//open text in read mode
	
	
	fscanf(customer,"%[^,],%s",data_identity,data_password);		//reads text 	
	fclose(customer);
	
	
	
	for(int i=0;i<11;i++){
	
		if(data_identity[i]==identitylogin[i]){}		//checks matching for id number
			
		
		else flag= -1;
	
	}
	for(int j=0;j<4;j++){
	
		if(  (data_password[j]==passwordlogin[j])&&(flag==1) ){}	//checks matching for id number and password
	
			
		else flag= -1;
					
	}
	
	if(flag==-1) {
	
		printf("Invalid identity number or password\n");
		return 0;
	}
	
	return 1;
}//end of check_login
   





int withdrawable_amount(float cash_amount){			//uses the least amount of paper
 								//I could only make cash-(cash%10) but I did not
 	int fifty,twenty,ten,result=0;
 	
	fifty=cash_amount/50.0;			
	cash_amount=cash_amount-(fifty*50);

	twenty=cash_amount/20.0;
	cash_amount=cash_amount-(twenty*20);
	
	ten=cash_amount/10.0;
	cash_amount=cash_amount-(ten*10);


    	result=(fifty*50+twenty*20+ten*10);

	printf("Withdrawable amount is: %d\n",result);
	
	
	 
	if(result>=0){					//controls  validity of input 
		return 1;
	}
	
	else{
		printf("invalid cash amount");
		return 0;
	}
}//end of withdrawable_amount


