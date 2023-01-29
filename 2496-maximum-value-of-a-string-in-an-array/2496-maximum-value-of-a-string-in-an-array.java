class Solution 
{
    public int maximumValue(String[] strs) {
        int max=Integer.MIN_VALUE;
        for(String e:strs){
            try{
            int a=Integer.parseInt(e);
            if(a>max)max=a;
            
        } 
            catch (NumberFormatException exception) {
                if (e.length() > max)
                    max = e.length();
            }
        }

        return max;
    }
}
        
       