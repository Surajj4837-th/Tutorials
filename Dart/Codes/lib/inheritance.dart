class A
{
  A()
  {
    print("Constructor of A.");
  }
  a(){
    print("A is called.");
  }
}

class B extends A   //inheritance declaration
{
  B()
  {
    print("Constructor of B.");
  }
  b(){
    print("B is called.");
  }
}

class C extends B   //inheritance declaration
{
  C()
  {
    print("Constructor of C.");
  }
  c(){
    print("C is called.");
  }
}

void main()
{
C obj_c = C();

obj_c.a();
obj_c.b();
obj_c.c();

}