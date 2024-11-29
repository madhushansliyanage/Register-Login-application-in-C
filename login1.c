#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char userId[50];

int main(){

FILE *rfp;

char name[100],password[10],email[50],newline;
char userEmail[50],userPassword[10];
int Vemail,Vpass;
int errLog;

do{
	rfp=fopen("Data.txt","r");
	
	if(rfp==NULL){
		printf("ERROR connecting database\n");
		exit(1);
	}

	printf("\n---------------------------------User-LogIn------------------------------\n\n");

	errLog=0;
	printf("Enter your email: ");
	scanf(" %s",userEmail);

	printf("\nEnter your password: ");
	scanf(" %s",userPassword);

	/*printf("Read username from user: %s ",userEmail);
	printf("Read userpassword from user: %s ",userPassword);*/

	do{
		fgets(name,100,rfp);
		fscanf(rfp,"%s",password);
		fscanf(rfp,"%s",email);
		newline=fgetc(rfp);
		newline=fgetc(rfp);

		/*printf("\n\n\nRead name from file: %s ",name);
		printf("Read Email from file: %s ",email);
		printf("REad password from file: %s ",password);
		printf("Read newline from file: %c ",newline);*/

		Vemail=strcmp(userEmail,email);
		Vpass=strcmp(userPassword,password);

		if((Vemail==0) && (Vpass==0)){
			/*printf("\nyou were get correct email and password from file \n");*/
			break;
		}


	}while( !feof(rfp) );

	if( (Vemail==0) && (Vpass==0) )
	{	printf("\n\nYou have successfully logged In\n");
		printf("\nHi ,%s\n\n",name);
	}
	else{
		printf("\n\nYour Email or Password is Incorrect\n");
		errLog+=1;
	}

	fclose(rfp);

}while(errLog==1);

	int i;
	for(i=0;i<strlen(email); i++ ){

		if( email[i]== '@'){
			break;
		}
		else{
			userId[i]=email[i];
		}
	}
	strcat(userId,".txt");

	//printf("User Id data : %s\n",userId);

return 0;
}
