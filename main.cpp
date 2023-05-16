#include<iostream>
#include"json.h"
using namespace std;
using namespace Xzs::json;
int main()
{
   Json v_null;
   Json v_int = 1;
   Json v_bool =true;
   Json v_double = 1.23;
   Json v_string ="hello world";
   Json v_array= new vector<Json>();
   Json v_object = new map<string,Json>; 

   Json v_other_int= v_int;
   Json v_other_bool= v_bool;
   Json v_other_double = v_double;
   Json v_other_string = v_string;
   Json v_other_array=v_array;
   Json v_other_object =v_object;

   bool b= v_bool;
   int i=v_int;
   double f=v_double;
   const string &s=v_string;
   
   v_array[0]=true;
   v_array[1]=123;
   v_array[2]=1.23;
  // v_array[3]="hello";
   v_array.append(1);
   std::cout<<v_array.str()<<endl;
   cout<<v_array.has(0)<<endl;
   cout<<v_array.has(10)<<endl;
 //  cout<<(v_array.m_value.m_array)->size()<<endl;
   v_array.remove(0);
  // cout<<(v_array.m_value.m_array)->size()<<endl;
   cout<<v_array.str()<<endl;
   v_object["bool"]=true;
   v_object["int"]=123;
   v_object["double"]=1.23;
   v_object["str"]="hello word";
  std::cout<< v_object.str()<<endl;
  
}