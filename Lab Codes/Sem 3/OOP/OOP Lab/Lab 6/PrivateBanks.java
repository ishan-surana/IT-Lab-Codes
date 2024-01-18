class Bank
{
    double getRateOfIntrest(int p)
    {
        return 0;
    }
}
class SBI extends Bank
{
    double getRateOfIntrest(int p)
    {
        return (8*p/100);
    }
}
class ICICI extends Bank
{
    double getRateOfIntrest(int p)
    {
        return (7*p/100);
    }
}
class AXIS extends Bank
{
    double getRateOfIntrest(int p)
    {
        return (9*p/100);
    }
}
class PrivateBanks
{
    public static void main(String args[])
    {
        SBI sbi= new SBI();
        ICICI icici=new ICICI();
        AXIS axis=new AXIS();
        Bank ref;
        ref = sbi;
        System.out.println("Intrest from SBI = "+ref.getRateOfIntrest(10000));
        ref = icici;
        System.out.println("Intrest from ICICI = "+ref.getRateOfIntrest(10000));
        ref = axis;
        System.out.println("Intrest from AXIS = "+ref.getRateOfIntrest(10000));
    }
}