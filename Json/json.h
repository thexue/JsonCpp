#pragma once
#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;
namespace Xzs{

namespace json
{
         
 class Json
 {
 public :
    enum Type
    {
      json_null=0,
      json_bool,
      json_int,
      json_double,
      json_string,
      json_array,
      json_object
    };
    Json();
    Json(bool value);
    Json(int value);
    Json(double value);
    Json(const char * value);
    Json(string value);
    Json(Type type);
    Json(const Json &other);
    operator bool();
    operator int ();
    operator double();
    operator string();
    Json &operator [](int index);
    Json &operator [](const char *key);
    Json &operator [](const string & key);
    void operator =(const Json &other);
    void append(const Json &other);
    string str ()const;
    void copy(const Json & other);
    void clear();

    bool operator ==(const Json &other);
    bool operator !=(const Json &other);
    /*迭代器*/
    typedef std::vector<Json>::iterator Iterator;
    Iterator begin()const
    {

        if(m_type!=json_array)
        {throw new logic_error("iterator error");}
        if(m_type==json_array)
        {
            return (m_value.m_array)->begin();
        }
    }
    Iterator end()const 
    {
         if(m_type!=json_array)
        {throw new logic_error("iterator error");}
        if(m_type==json_array)
        {
            return (m_value.m_array)->end();
        }
    }
    /*是否为某类型*/
    bool isNull() const ;
    bool isBoll()const;
    bool isInt()const ;
    bool isDouble()const;
    bool isString()const;
    bool isArray()const;
    bool isObject()const;
   /*返回具体的值*/
    bool asBool()const;
    int asInt()const;
    double asDouble()const;
    string asString()const;
   /*判定是否存在某索引*/
    bool has(int index);
    bool has(const string key);
    bool has(const char*key);
    /*删除某元素*/
    void remove(int index);
    void remove(const string key);
    void remove(const char*key);
    void parse(const string & str);
   
  union Value
     {
        bool m_bool;
        int m_int;
        double m_double;
        std::string *m_string;
        std::vector<Json> * m_array;
        std::map<string,Json>* m_object;
    };
    Value m_value;
    Type m_type;
   

 private:
   
             
};
}
}