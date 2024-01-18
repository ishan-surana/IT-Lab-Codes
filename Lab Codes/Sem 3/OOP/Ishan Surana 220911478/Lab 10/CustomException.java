class CustomException extends Exception
{
    public static void main(String[] args)
    {
        CustomException e=new CustomException();
        try
        {
            throw e;
        }
        catch(CustomException f)
        {
            System.out.println("Access Denied!");
        }
    }
}