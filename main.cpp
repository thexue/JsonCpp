#include<iostream>
#include"json.h"
#include<fstream>
#include<sstream>
using namespace std;
using namespace Xzs::json;
int main()
{
  
  string str="null";
  Json v;
  v.parse(str);
  cout<<v.str()<<endl;
  str="true";
  v.parse(str);
  cout<<v.str()<<endl;
  str="false";
  v.parse(str);
  cout<<v.str()<<endl;
  str="123";
   v.parse(str);
  cout<<v.str()<<endl;
  str="1.23";
   v.parse(str);
  cout<<v.str()<<endl;
  str="-1.23";
   v.parse(str);
  cout<<v.str()<<endl;
  str="\"hello\"";
    v.parse(str);
  cout<<v.str()<<endl;
  str="[1,2]";
    v.parse(str);
  cout<<v.str()<<endl;
  str="[1,  2,3  ,\"true\",true,    false,1.23,-100,-0]";
    v.parse(str);
  cout<<v.str()<<endl;
  // str="{\"name\":Alic,\"age\":18}";
   str="{\"a\": 1,\"b\":\"2\"}";
    v.parse(str);
   cout<<v.str()<<endl;
   str="{\"name\":\"Alice\",\"age\": 18}";
    v.parse(str);
  cout<<v.str()<<endl;
  ifstream fin("./Data.json");
  stringstream ss;
   ss<<fin.rdbuf();
    v.parse(ss.str());
  cout<<v.str()<<endl;
  std::cout<<v["meta"]["name"].str()<<endl;
  
}