
#include"json.h"
#include<sstream>
#include"parser.h"
using namespace Xzs::json;
Json::Json(): m_type(json_null)
{

}
Json::Json(bool value):m_type(json_bool)
{
   m_value.m_bool=value;
}
Json:: Json(int value):m_type(json_int)
 {
  m_value.m_int=value;
}
Json::Json(double value):m_type(json_double)
{
   m_value.m_double=value;
}
Json::Json(const char * value):m_type(json_string)
{
  m_value.m_string=new string(value);
}
Json::Json(string value):m_type(json_string)
{
   m_value.m_string=new string(value);
}
Json::Json(Type type):m_type(type)
{
   switch(m_type)
   {
    case json_null:
    break;
    case json_int:
    m_value.m_int=0;
    break;
    case json_bool:
    m_value.m_bool=false;
    break;
    case json_double:
    m_value.m_double=0.0;
    break;
    case json_array:
    m_value.m_array=new vector<Json>();
    break;
    case json_object:
    m_value.m_object=new std::map<string,Json>;
    break;
    case json_string:
    m_value.m_string=new string();

    break;
   }
}
Json::Json(const Json &other)
{ 
   copy(other);
}
Json::operator bool()
{
   if(m_type!=json_bool)
   {
    throw new logic_error("type error,not bool value");
   }
   return m_value.m_bool;
}
Json::operator int ()
{
    if(m_type!=json_int)
   {
    throw new logic_error("type error,not int value");
   }
   return m_value.m_int;
}
Json:: operator double()
{
    if(m_type!=json_double)
   {
    throw new logic_error("type error,not double value");
   }
    return m_value.m_double;
}
Json::operator string()
{
    if(m_type!=json_string)
   {
    throw new logic_error("type error,not string value");
   }
    return *(m_value.m_string);
}
Json &Json::operator [](int index)
{
   if(m_type!=json_array)
  {
        m_type=json_array;
        m_value.m_array=new vector<Json>;
  }
  if(index<0)
  {
       throw new logic_error("array[] index <0");
  }
  int size=((m_value.m_array)->size());
  if(index>=size)
  {
    for(int i=size;i<=index;i++)
    {
      (m_value.m_array)->push_back(Json());
    }
  }
  return (m_value.m_array)->at(index);
}
void Json:: append(const Json &other)
{  
  if(m_type!=json_array)
  { 
    clear();
    m_type=json_array;
    m_value.m_array=new vector<Json>;
  }
  (m_value.m_array)->push_back(other);
}
string Json::str() const
{
     stringstream ss;
     switch(m_type)
   {
    case json_null:
    ss<<"null";
    break;
    case json_int:
    ss<<m_value.m_int;
    break;
    case json_bool:
      if(m_value.m_bool)
      {
        ss<<"true";
      }
      else 
      {
        ss<<"false";
      }
    break;
    case json_double:
         ss<<m_value.m_double;
        break;
   case json_array:
      {
          ss<<'[';
          for(auto it =((m_value.m_array))->begin();it!=(m_value.m_array)->end();it++)
          { 
            if(it!=(m_value.m_array)->begin())
            {
                ss<<",";
            }
            ss<<it->str();
          }
          ss<<']';
      }
        break;
    case json_object:
       {
         ss<<'{';
         for(auto it=(m_value.m_object)->begin();it!=(m_value.m_object)->end();it++)
         {
             if(it!=(m_value.m_object)->begin())
            {
                ss<<",";
            }
            ss<<'\"'<<it->first<<'\"'<<':'<<it->second.str();
         }
          ss<<'}';
       }
        break;
     case json_string:
     ss<<"\""<<*(m_value.m_string)<<"\"";
     break;
   }
   return ss.str();

}
 Json & Json::operator [](const char *key)
 {
     string name(key);
     return (*(this))[name];
 }
Json & Json::operator [](const string & key)
{  
    if(m_type!=json_object)
    {
        clear();
        m_type =json_object;
        m_value.m_object=new std::map<string,Json>;
    }
  return (*(m_value.m_object))[key];
}
void Json:: copy(const Json &other)
{
    m_type=other.m_type;
 switch(m_type)
   {
    case json_null:
    break;
    case json_int:
    m_value.m_int=other.m_value.m_int;
    break;
    case json_bool:
       m_value.m_bool=other.m_value.m_bool;
    break;
    case json_double:
        m_value.m_double=other.m_value.m_double;
        break;
        case json_array:
        m_value.m_array=other.m_value.m_array;
        break;
    case json_object:
        m_value.m_object=other.m_value.m_object;
        break;
    case json_string:
        m_value.m_string=other.m_value.m_string;
        default:
         break;
   }
}
void Json:: operator =(const Json &other)
{   
    clear();
    copy(other);
}
void Json:: clear()
{
    switch(m_type)
   {
    case json_null:
    break;
    case json_int:
    m_value.m_int=0;
    break;
    case json_bool:
       m_value.m_bool=false;
    break;
    case json_double:
        m_value.m_double=0.0;
        break;
        case json_array:
        for(auto it=(m_value.m_array)->begin();it!=(m_value.m_array)->end();it++)
        {
          it->clear();
        }
        delete m_value.m_array;
        break;
    case json_object:
    for(auto it=(m_value.m_object)->begin();it!=(m_value.m_object)->end();it++)
        {
          (it->second).clear();
        }
        delete m_value.m_object;
        break;
    case json_string:
       delete m_value.m_string;
         break;
   }
   m_type=json_null;
}
    /*是否为某类型*/
    bool Json::isNull() const 
    {
        return m_type==json_null;
    }
    bool Json::isBoll()const
    {
       return m_type==json_bool;
    }
    bool Json::isInt()const
    {
        return m_type==json_int;
    }
    bool Json::isDouble()const
    {
       return m_type==json_double;
    }
    bool Json::isString()const
    {
       return m_type==json_string;
    }
    bool Json::isArray()const
    {
       return m_type==json_array;
    }
    bool Json ::isObject()const
    {
      return m_type==json_object;
    }
   /*返回具体的值*/
    bool Json:: asBool()const
    {
        if(m_type!=json_bool)
        {
            throw logic_error("type error");
        }
        return m_value.m_bool;
    }
    int Json ::asInt()const
    {
       if(m_type!=json_int)
        {
            throw logic_error("type error");
        }
        return m_value.m_int;
    }
    double Json:: asDouble()const
    {
          if(m_type!=json_double)
        {
            throw logic_error("type error");
        }
        return m_value.m_double;
    }
    string Json:: asString()const
    {
       if(m_type!=json_string)
        {
            throw logic_error("type error");
        }
        return*( m_value.m_string);
    }
   /*判定是否存在某索引*/
    bool Json::has(int index)
    {     
        if(m_type!=json_array)
        {
            throw logic_error("type error");
        }
         int size=(m_value.m_array)->size();
         if(index<0||index>=size)return false;
         else return true;

    }
    bool Json ::has(const string key)
    {   
          if(m_type!=json_object)
        {
            throw logic_error("type error");
        }
        return (m_value.m_object)->find(key)==(m_value.m_object)->end();
    }
    bool Json:: has(const char*key)
    {
       return has(string(key));
    }
    /*删除某元素*/
    void Json::remove(int index)
    {
         if(!has(index))
         {
            throw logic_error("index not exit");
         }
         (m_value.m_array)->at(index).clear();
         (m_value.m_array)->erase((m_value.m_array)->begin()+index);
    }
    void Json::remove(const string key)
    {
        if(!has(key))
        {
             throw logic_error("key not exit");
        }
        auto it=(m_value.m_object)->find(key);
        if(it==(m_value.m_object)->end())
        {
            return ;
        }
        (*(m_value.m_object))[key].clear();
        (m_value.m_object)->erase(key);

    }
    void Json ::remove(const char*key)
    {
           remove(string(key));
    }
     bool Json:: operator ==(const Json &other)
     {
         if(m_type!=other.m_type)return false;
         switch (m_type)
         {
            case json_null:
            return true;
            case json_bool:
            return m_value.m_bool==other.m_value.m_bool;
            case json_int:
            return m_value.m_int==other.m_value.m_int;
            case json_double :
            return m_value.m_double==other.m_value.m_double;
            case json_string:
            return *(m_value.m_string)==*(other.m_value.m_string);
            case json_array:
            return m_value.m_array==other.m_value.m_array;
            case json_object:
            return m_value.m_object==other.m_value.m_object;
         }
         return false;
     }
    bool Json:: operator !=(const Json &other)
    {
          return !(*this==other);
    }
 void Json::parse(const string & str)
 {
   Parser p;
   p.load(str);
   *this=p.parse();
 }