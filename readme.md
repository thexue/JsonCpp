# 简易Cpp解析Json练手项目
[Json数据格式说明](http://json.org/json-en.html)
[Github完整源码](https://github.com/thexue/JsonCpp)
## 基础数据类型表示
### Task1：

![在这里插入图片描述](https://img-blog.csdnimg.cn/6dd2e2355f1c426ba36a258f9d7bfb82.png)
### 设计思路
通过枚举表示Json的数据type，根据type不同来使用构造函数，给m_value实际的值
```cpp
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
 private:
     union Value
     {
        bool m_bool;
        int m_int;
        double m_double;
        std::string *m_string;
        std::vector<Json> * m_vector;
        std::map<string,Json>* m_object;
    };
    Value m_value;
    Type m_type;
   
             
};
```
### Task2

实现逆向赋值
![在这里插入图片描述](https://img-blog.csdnimg.cn/2b00b46b039840a1b5d0d216e49664a9.png)
### 设计思路
重载一下基本类型运算符
```cpp
    operator bool();
    operator int ();
    operator double();
    operator string();
```
### Task3

实现数组相关API
![在这里插入图片描述](https://img-blog.csdnimg.cn/e37593b7431e4f56b66ebd40baae2a88.png)

```cpp
output：[true,123,1.23,"hello","Yes"]
```
### 设计思路
重载[]，str使用递归来将对象解析为字符串
```cpp
 Json &operator [](int index);
 void append(const Json &other);
 string str ()const;

```
### Task4
实现object相关API，并注意内存泄漏的问题

```cpp
   v_object["bool"]=true;
   v_object["int"]=123;
   v_object["double"]=1.23;
   v_object["str"]="hello word";
   std::cout<< v_object.str()<<endl;
```
### 设计思路
重载运算符
```cpp
    Json &operator [](const char *key);
    Json &operator [](const string & key);
    void copy(const Json & other);
    void clear();
```

### Task5 
实现如下常用接口

```cpp
    /*迭代器*/
    typedef std::vector<Json>::iterator iterator;
    iterator begin();
    iterator end();
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
    double sDouble()const;
    string asString()const;
   /*判定是否存在某索引*/
    bool has(int index);
    bool has(const string key);
    bool has(const char*key);
    /*删除某元素*/
    void remove(int index);
    void remove(const string key);
    void remove(const char*key);
    
```
### Task6
1:完成基本数据类型的解析：NULL，int，double,string
2:完成符合类型解析：array，object

```cpp
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
```
