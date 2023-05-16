#pragma once
#include"json.h"
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
    m_value.m_vector=new vector<Json>();
    break;
    case json_object:
    m_value.m_object=new std::map<string,Json>;
    break;
    case json_string:
    m_value.m_string=new string();
    default:
    break;
   }
}
Json::Json(const Json &other)
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
        m_value.m_vector=other.m_value.m_vector;
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