#include<stdio.h>  
int main()    
{    
int num,rem,sum=0,temp;    
printf("Enter a number:");    
scanf("%d",&num);    
temp=num;    
while(num>0)    
{    
rem=num%10;    
sum=(sum*10)+rem;    
num/=10;    
}    
if(temp==sum)    
printf("A Palindrome");    
else    
printf("Not a Palindrome");   
return 0;  
}   
