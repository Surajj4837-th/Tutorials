namespace ObjectMethods
{
    internal class Program
    {
        static void Main(string[] args)
        {
            STUDENT stu1 = new STUDENT("A", "Business", 2.8);
            STUDENT stu2 = new STUDENT("B", "Business", 3.6);

            Console.WriteLine(stu1.HasHonours());
            Console.WriteLine(stu2.HasHonours());
        }
    }
}
