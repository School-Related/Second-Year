class One
{
    int a, b;
    void getValue(int p, int q)
    {
        a = p;
        b = q;
    }
    void display()
    {
        System.out.println("A = " + a);
        System.out.println("B = " + b);
    }
}


class Two extends One {
    int c, d;
    void getValue(int p, int q)
    {
        c = p;
        d = q;
    }
    void display()
    {
        System.out.println("C = " + c);
        System.out.println("D = " + d);
    }
}

class Main
{
    public static void main(String args[])
    {
        One obj = new One();
        obj.getValue(10, 20);
        obj.display();

        Two obj2 = new Two();
        obj2.getValue(10, 20);
        obj2.display();    }
}