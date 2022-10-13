/* java code to convert decimal numbers into hexa-decimal numbers */
import java.util.Scanner; 
class Dec2Hex
{
	public static void main(String[] args)
	{
		Scanner INP = new Scanner(System.in);		
		System.out.print("Enter decimal number : ");
		int dec = INP.nextInt();
		int temp = dec;
		
		int ascii = 0;
		int rem = 0;
		String hex = "";
		while(temp > 0)
		{
			rem = temp % 16;
			temp = temp / 16; 
			if(rem < 10)
			{
				ascii = (rem + 48);
				hex = (char)ascii + hex;
				continue;
			}
			ascii = (rem + 55);
			hex = (char)ascii + hex;	
		}

		System.out.println("The equivalent hexadecimal number is : " + hex);

		INP.close();
		return;
	}
}
