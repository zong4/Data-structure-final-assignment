# -*- coding : utf-8 -*-
# @Time      : 2022-01-08 10:53
# @Author    : Zong
# @File      : class_again.py
# @Software  : PyCharm
# @Function  : 尝试调用C++类
# @ChangeLog :

from ctypes import cdll

# g++ -fPIC -shared Test/class_again.cpp -o class_again.so

test = cdll.LoadLibrary(r"D:\Code\C++\Data-structure-final-assignment\Cpp\Test\class_again.so")

test.inse()

# print(a)
