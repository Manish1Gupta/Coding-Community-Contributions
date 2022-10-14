In Java, string is basically an object that represents sequence of char values. An array of characters works same as Java string. For example:
char[] ch={'j','a','v','a','t','p','o','i','n','t'};  
String s=new String(ch);  
What is String in Java?
Generally, String is a sequence of characters. But in Java, string is an object that represents a sequence of characters. The java.lang.String class is used to create a string object.

How to create a string object?
There are two ways to create String object:

By string literal
By new keyword
1) String Literal
Java String literal is created by using double quotes. For Example:

String s="welcome";  
Java String Example
StringExample.java

public class StringExample{    
public static void main(String args[]){    
String s1="java";//creating string by Java string literal    
char ch[]={'s','t','r','i','n','g','s'};    
String s2=new String(ch);//converting char array to string    
String s3=new String("example");//creating Java string by new keyword    
System.out.println(s1);    
System.out.println(s2);    
System.out.println(s3);    
}}   
