#include<stdio.h>
#include"utils.h"


int main (){


int f_i=0,x,y,z,temp,n=0,ndiv;				

	printf("Enter the first integer: ");
	scanf("%d",&x);				
	printf("\n");
	printf("Enter the second integer: ");
	scanf("%d",&y);
	printf("\n");
	
	printf("Enter the divisor: ");
	scanf("%d",&z);
	printf("\n");
	
	(f_i)= find_divisible (x, y, z);			//returns first divisible integer or error code
	
	if ( (f_i) != -1 ){					//controls for if there are any divisible f_i
		printf("Enter the number how many next:");
		scanf("%d",&n);
		printf("\n");
		
		ndiv= find_nth_divisible(n, f_i,  z);		//finds n. divisible 
		
		
		
		
		if ( (ndiv>y)||(ndiv==y) ){				// controls  for n. divisible  boundaries
	
			printf("Not possible to find %d. divisible between %d and %d divided by %d\n\n",n+1,x,y,z);
	      
		}
	
		else  {				
			printf("The %d. integer between %d and %d divided by %d is %d\n\n",n+1,x,y,z,ndiv);
	
		}  		
	
	}//part1 end
	
	
	
	
	
	
	
	int validity,password;
	float cash_amount;
        char identity_number [50];
        
        identity_number [9]='u';			//control mechanism for 11 digit
        
        
        
  	printf("\nEnter the identity number: ");
	scanf("%s",identity_number);
	printf("\n");
	
	

	validity=validate_identity_number(identity_number);		//validation code transferred to validity	
	
	printf("Enter password : ");
	scanf("%d",&password);
	printf("\n"); 
	
	int temp_password=password;
	
	for(int j=0;j<5;j++){			//for 4 digit password control
		
		
		temp_password=temp_password/10;
		
		if((j==3)&&(temp_password==0) ){
			break;
		}
		
		
		if(  ((j!=3)&&(temp_password==0))  ||  (j==4) ) {
			printf("Password must be 4 digit\n");
			validity=0;	
			break;	
		}
		
		
	}
	
	
	
	if(validity== 0){
        	printf("Invalid identity number or password\n");
        	return 0;
	}	

	
	
	
	create_customer(identity_number,password);
	
	if ( check_login(identity_number,password) && (validity==1) ) {		
		printf("\nLogin succcesful\n")	;
	}
	
	else{ 
		printf("\nLogin unsucccesful\n");
			validity=0;
	}
	
	if(validity==1){
	
		printf("Enter cash amount: ");
		scanf("%f",&cash_amount);
	
		withdrawable_amount(cash_amount);
	}

  return 0;
	
}	//end of main



















