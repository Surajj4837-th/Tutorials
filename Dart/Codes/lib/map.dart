void main ()
{
  Map<String, String> mapData = {
    "Name":"Suraj",
    "Surname":"Jadhav"
  };

  print(mapData);

  Map<String, dynamic> mapData2 = {   //dynamic keyword used to store different kinds of values
    "Name":"Suraj", 
    "Surname": "Jadhav",
    "rollNo": 1,
    "Marks": 95.6
  };

  //insert new pair
  mapData2["Game"] = "Football";

  print(mapData2);

  //print keys
  print(mapData2.keys);
  
  //print keys
  print(mapData2.values);

}