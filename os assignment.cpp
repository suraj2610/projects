//Header files required for the program
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<ctype.h>
#include<sys/types.h>
//main function (start of the execution of the program
int main()
{
	char s[100];
	int i,n;
	printf("Enter the size of the string to be entered(less than 100):");
	scanf("%d",&n);//size of the required string
	printf("Enter the String :");
	for(i=0;i<n;i++)
	{
	scanf("%c",&s[i]);//input of the string character by character
	}
	int f[2];	
	write(f[1],s,n);//Code responsible for writing 
	printf("Writing Pid :%d ",getpid());//fetching the Pid
	printf("\nString written to the pipe:%s\n",s);	
	for(i=0;i<n;i++)//for loop that converts the case in the code
	{
		if(islower(s[i]))
		   s[i]=toupper(s[i]);
		else
		   s[i]=tolower(s[i]);
    }
	close(f[0]);
	read(f[0],s,n);//Code responsible for reading
	printf("\nReading Pid :%d ",getpid());//Fetching the Pid for the read code
	printf("\nString read from the file:%s\n",s);//displaying the string 
}