namespace Inheritance
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Chef chef = new Chef();

            chef.MakeChicken();

            ItalianChef IC = new ItalianChef();

            IC.MakeChicken();       // Call inherited method.
            IC.MakePasta();

            //chef.MakePasta();     //Error

            //Override methods
            chef.MakeSpecialDish();
            IC.MakeSpecialDish();

        }
    }
}
/*
 * 1. virtual and override keywords used to override an inherited function.
 */