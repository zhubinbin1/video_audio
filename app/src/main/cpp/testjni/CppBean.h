//
// Created by binbin on 2018/4/2.
//

#ifndef MYAPPLICATION_CPPBEAN_H
#define MYAPPLICATION_CPPBEAN_H
#include <string>

using namespace std;

#define MCppBean  (CppBean::GetInstance())

typedef signed char Bool;
#define MPTrue          1
#define MPFalse         0

typedef unsigned char Byte;

class CppBean {
public:
    int getcpp_int() const;

    void setcpp_int(int jb_int);

    Bool getcpp_Bool() const;

    void setcpp_Bool(Bool jb_boolean);

    Byte getcpp_byte() const;

    void setcpp_byte(Byte jb_byte);

    short getcpp_short() const;

    void setcpp_short(short jb_short);

    long getcpp_long() const;

    void setcpp_long(long jb_long);

    float getcpp_float() const;

    void setcpp_float(float jb_float);

    double getcpp_double() const;

    void setcpp_double(double jb_double);

    string getcpp_str() const;

    void setcpp_str(char *str);

    int *getcpp_intArr();

    void setcpp_intArr(int *intArr, int length);


public:
    static CppBean &GetInstance() {
        static CppBean instance;
        return instance;
    }

    virtual ~CppBean();

private:
    CppBean();

    CppBean(const CppBean &);

    CppBean &operator=(const CppBean &);

private:

    int cpp_int;
    Bool cpp_boolean;
    Byte cpp_byte;
    short cpp_short;
    long cpp_long;
    float cpp_float;
    double cpp_double;

    string cpp_str;
    int cpp_intArr[];

};


#endif //MYAPPLICATION_CPPBEAN_H
