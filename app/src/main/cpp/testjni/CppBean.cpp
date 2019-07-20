//
// Created by binbin on 2018/4/2.
//
#include "cppbean.h"

CppBean::CppBean() {
}

CppBean::~CppBean() {
}

int CppBean::getcpp_int() const {
    return cpp_int;
}

void CppBean::setcpp_int(int jb_int) {
    cpp_int = jb_int;
}

Bool CppBean::getcpp_Bool() const {
    return cpp_boolean;
}

void CppBean::setcpp_Bool(Bool jb_boolean) {
    cpp_boolean = jb_boolean;
}

Byte CppBean::getcpp_byte() const {
    return cpp_byte;
}

void CppBean::setcpp_byte(Byte jb_byte) {
    cpp_byte = jb_byte;
}

short CppBean::getcpp_short() const {
    return cpp_short;
}

void CppBean::setcpp_short(short jb_short) {
    cpp_short = jb_short;
}

long CppBean::getcpp_long() const {
    return cpp_long;
}

void CppBean::setcpp_long(long jb_long) {
    cpp_long = jb_long;
}

float CppBean::getcpp_float() const {
    return cpp_float;
}

void CppBean::setcpp_float(float jb_float) {
    cpp_float = jb_float;
}

double CppBean::getcpp_double() const {
    return cpp_double;
}

void CppBean::setcpp_double(double jb_double) {
    cpp_double = jb_double;
}

string CppBean::getcpp_str() const {
    return cpp_str;
}

void CppBean::setcpp_str(char *str) {
    cpp_str.assign(str);
}

int *CppBean::getcpp_intArr() {
    return cpp_intArr;
}

void CppBean::setcpp_intArr(int *intArr, int length) {
    memcpy(cpp_intArr, intArr, length * 4);
}
