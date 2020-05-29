
/**
 * digit_sum_challange
 */
public class digit_sum_challange {

    public static void main(String[] args) 
    {
        System.out.println("\n Enter the number 125 is " + sumdigi(125));
            
    }

    public static int sumdigi(int number)
    {
        if (number>=10)
        {
            int sum=0,n;
            n = number;
            while(n!=0)
            {
                sum=sum+(n%10);
                n=n/10;
            }    
            return sum;
        }
        else
        {
            return -1;
        }
    }
}