# 简易Cpp解析Json练手项目
[Json数据格式说明](http://json.org/json-en.html)
## 基础数据类型表示
### Task1：
![在这里插入图片描述](https://img-blog.csdnimg.cn/6dd2e2355f1c426ba36a258f9d7bfb82.png)
### 设计思路
通过枚举表示Json的数据type，根据type不同来使用的构造函数，给m_value实际的值
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
