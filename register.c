#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void reg();

int main(){

	printf("\n\n\n\t*********************************************************** \n");
    printf("\t*                                                         * \n");
    printf("\t*        Welcome - Train Ticket Reservation System        * \n");
    printf("\t*                                                         * \n");
    printf("\t*********************************************************** \n\n\n");

    printf("\t**   Menu   ** \n\n");
    printf("\t [1] - Login \n");
    printf("\t [2] - Register \n\n");
    
	int navi;
	printf("\tPress the number for option : ");
	scanf("%d",&navi);
	fgetc(stdin);
	
	if(navi==2){
		reg();
	}
	else
		printf("\tError - Wrong Number\n");

return 0;
}

void reg(){

FILE *fp;
char name[100],password[10],email[50];
int i,tLetter,nameLength,fLetter;
char ch;

fp=fopen("Data.txt","a");

	printf("\n\t\t\t---------------------------------\n");
	printf("\t\t\t|\tUser Registration\t|\n");
	printf("\t\t\t---------------------------------\n\n");

	if(fp==NULL){
		printf("Can't connect to DataBase\n");
		exit(1);
	}

	do{
		tLetter=0;
		fLetter=0;

		printf("\t-----Enter your Name-------------------------------------------------------\n");
		printf("\tINSTRUCTIONS:- Name should be contain only Letters, Sapces, and Fullstops\n\n\t");
		fgets(name,100,stdin);

		nameLength=strlen(name)-1;

		for(i=0;i< nameLength ;i++)
		{
			ch=name[i];
			if( (ch>='a' && ch<='z')||(ch>='A' && ch<='Z')||(ch==' ')||(ch=='.') ){
				tLetter+=1;
			}
			else{
				fLetter+=1;
			}
		}

		if(nameLength==tLetter){
			fprintf(fp,"%s",name);//name printed into file

		}
		else{
			printf("\t\t!!!Your name contains invalid characters!!!\n");
			printf("\t\t\t\tTRY-AGAIN\n\n");
		}

	}while(nameLength!=tLetter);

//Enter password
int passwordLength,special,numbers;
char confPassword[10];
int valiPass;//,invaliPass;

	do{
		tLetter=0;
		fLetter=0;
		special=0;
		numbers=0;

		printf("\n\t-----Enter your password---------------------------------------------------\n");
		printf("\tINSTRUCTIONS:-Accecept only 8 characters with at least one of these ");
		printf("%c %c %c %c %c\n\n\t",'@','#','$','%','*');
		scanf("%s",password);

		passwordLength=strlen(password);

		for(i=0;i< passwordLength ;i++)
		{
			ch=password[i];

			if( (ch>='a' && ch<='z')||(ch>='A' && ch<='Z') ){
				tLetter+=1;
				//printf("%d th character -%c is passed\n",i+1,ch);
			}
			else if( (ch>='0' && ch<='9') ){
				numbers+=1;
				//printf("%d th character -%c is passed\n",i+1,ch);
			}
			else if( (ch=='@') || (ch=='#') || (ch=='$') || (ch=='%') || (ch=='*') ) {
				special+=1;
				//printf("%d th character -%c is passed\n",i+1,ch);
			}
			else{
				fLetter+=1;
				//printf("%d th character -%c is failed\n",i+1,ch);
			}
		}
		/*if(fLetter>0){
			printf("\n***Your password hsould contain at least one special characters***\n\n");
		}*/

		if( ( (tLetter+special+numbers)==8 ) && (special>0) ){

//re-enter password
			printf("\n\t-----Confirm Password:---------------------------------------------\n\n\t");
			do{

				valiPass=1;
				

				scanf("%s",confPassword);
				fgetc(stdin);

				/*
					invaliPass=0;
				for(i=0;i<strlen(password);i++){
					if(password[i]==confPassword[i]){
						//printf("%c==%c\n",password[i],confPassword[i]);
						valiPass+=1;
					}
					else{
						invaliPass+=1;
						//printf("%c!=%c\n",password[i],confPassword[i]);
					}
				}*/
				valiPass=strcmp(password,confPassword);

				/*if(valiPass==strlen(password)){
					printf("\n\t\t\t***Password confirmed***\n");
				}*/
				if(valiPass==0){
					printf("\n\t\t\t***Password confirmed***\n");
				}
				
				else{
					printf("\n\t\t\t!!!Password not similer to previous one!!!\n");
					printf("\t\t\t\tTRY-AGAIN\n\n\t");
				}

			}while( !(valiPass==0) );

			fprintf(fp,"%s\n",password);//password written to the file
			
		}
		else{
			printf("\t\t!!!Your password is not acceptable!!!\n");
			printf("\t\t\t\tTRY-AGAIN\n\n");
		}

	}while( !( ((tLetter+special+numbers)==8) && (special>0) ) );

// Enter email
int emailLength,compL;//pulstop
int existEmail;

	do{
		tLetter=0;
		compL=0;
		//pulstop=0;
		fLetter=0;

		printf("\n\t-----Enter your E-mail---------------------------------------------------\n");
		printf("\tINSTRUCTIONS:-E-mail should be contain Letters,%c , and Pulstops\n\n\t",'@');
		
		fgets(email,50,stdin);

		emailLength=strlen(email)-1;
		
		for(i=0;i< emailLength ;i++)
		{
			ch=email[i];
			if( (ch>='a' && ch<='z')||(ch>='A' && ch<='Z')||(ch>='0' && ch<='9') ){
				tLetter+=1;
				
			}
			else if( (ch=='@' || ch=='.') ){
				compL+=1;
				
			}
			
			else{
				fLetter+=1;
				
			}
		}
		
		//checking email exist or not
			char name[100],password[10],Emails[50],newline; // contains read data from file
			
			FILE *erfp;
			erfp=fopen("Data.txt","r");
			
			do{
				existEmail=1;
				
				fgets(name,100,erfp);
				fgets(password,10,erfp);//fscanf(erfp,"%s",password);
				fgets(Emails,50,erfp);//fscanf(erfp,"%s",Emails);
				newline=fgetc(erfp);//newline=fgetc(erfp);
								
				existEmail=strcmp(email,Emails);//compair user entered email with file contain emails
				
				if(existEmail==0){					
					break;
					printf("Email is Used before\n");
				}
				
			}while( !feof(erfp) );
			
			fclose(erfp);
		//
		
		if( (emailLength==(tLetter+compL)) && (compL>=2) && (existEmail!=0) ){ //(pulstop==1) && 
			fprintf(fp,"%s",email);
			printf("\n\t***Your registration has been successfully completed***\n\n");
		}
		else if(existEmail==0){
			printf("\n\t!!!ERROR - Anyone has registered under this e-mail!!!\n\t\t\tUse another email address\n\n");
		}
		else{
			printf("\n\t!!!Your e-mail contains invalid characters or not contain compulsory characters!!!\n");
			printf("\t\t\t\tTRY-AGAIN\n\n");
		}

	}while( !((emailLength==(tLetter+compL)) && (compL>=2) && (existEmail!=0)) );// (pulstop==1) &&
//


fputc('\n',fp);
fclose(fp);


}
