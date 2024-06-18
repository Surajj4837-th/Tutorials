void main()
{
  List<int> listNum = [1,2,3,4,5];

  listNum.add(6);
  print(listNum);

  listNum.remove(2);
  print(listNum);

  listNum.removeAt(0);
  print(listNum);

  print(listNum.contains(10));
  print(listNum.length);

  print(listNum.reversed);

  listNum.insert(0, 10);
  print(listNum);

  listNum.insertAll(5, [7,8,9]);
  print(listNum);

}
