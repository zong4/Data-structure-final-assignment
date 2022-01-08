# -*- coding : utf-8 -*-
# @Time      : 2022-01-04 22:56
# @Author    : Zong
# @File      : class.py
# @Software  : PyCharm
# @Function  : 尝试调用C++类
# @ChangeLog :

from ctypes import cdll

# g++ -fPIC -shared Test/class.cpp -o class.so

test = cdll.LoadLibrary(r"D:\Code\C++\Data-structure-final-assignment\Cpp\Test\class.so")

a = test.inse()
print(a)
