# -*- coding : utf-8 -*-
# @Time      : 2022-01-04 21:05
# @Author    : Zong
# @File      : main.py
# @Software  : PyCharm
# @Function  : 
# @ChangeLog :

from ctypes import *

# g++ -fPIC -shared AutoLib.cpp -o AutoLib.so

test = cdll.LoadLibrary(r".\Library_client\AutoLib.so")
test.main()
