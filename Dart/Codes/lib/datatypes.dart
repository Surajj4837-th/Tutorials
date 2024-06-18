import 'dart:io';

void main()
{
  stdout.write("Enter num1: ");
  int num1 = int.parse(stdin.readLineSync()!); //Null check, parse to int

  stdout.write("Enter num2: ");
  int num2 = int.parse(stdin.readLineSync()!); //Null check, parse to int

  int sum = num1 + num2;
  print(sum);

  stdout.write("Enter your name: ");
  String name = stdin.readLineSync()!; //Null check, parse to int
  print(name);

  bool value = true;
  print(value);

  var name1 = "ram";
  print(name1);

}