
class Solution
{
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
     public static void reverse(char [] str1,int lo,int hi){
        while(lo<hi){
            char temp =str1[lo];
            str1[lo]=str1[hi];
            str1[hi]=temp;
            lo++;hi--;
        }
    }
        
    public static boolean isRotated(String str1, String str2)
    {
        // Your code here
        
        //convert the string to array
        char[] ch = str1.toCharArray();
        reverse(ch,0,1);
        reverse(ch,2,str2.length()-1);
        reverse(ch,0,str2.length()-1);
        //convert the array to string
        String str = String.valueOf(ch);
        if(str.equals(str2)==true){return true;}
        else{
            char[] ch1 = str1.toCharArray();
            reverse(ch1,str2.length()-2,str2.length()-1);
            reverse(ch1,0,str2.length()-3);
            reverse(ch1,0,str2.length()-1);
            String stxr = String.valueOf(ch1);
            if(stxr.equals(str2)==true){return true;}
        }
        return false;
    }
    
}