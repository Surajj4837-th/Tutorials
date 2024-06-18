import 'dart:io';

void main()
{
  int num1 = 30;
  int num2 = 50;
  int sum = num1 + num2;

  print(sum);

  stdout.write("Enter num1: ");
  num1 = int.parse(stdin.readLineSync()!);  //Null check, parse to int

  stdout.write("Enter num\2: ");
  num2 = int.parse(stdin.readLineSync()!);  //Null check, parse to int

  sum = num1 + num2;
  print(sum);
}