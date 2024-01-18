class IntObj
{
    int value;
    IntObj(int value)
    {
        this.value = value;
    }
}
class PointerButNotReally
{
    void mul(IntObj a)
    {
        a.value=a.value*2;
    }
    public static void main(String[] args)
    {
        IntObj a=new IntObj(5);
        System.out.println(a.value);
        PointerButNotReally t=new PointerButNotReally();
        t.mul(a);
        System.out.println(a.value);
    }
}