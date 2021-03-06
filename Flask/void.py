# -*- coding : utf-8 -*-
# @Time      : 2022-01-05 0:06
# @Author    : Zong
# @File      : void.py
# @Software  : PyCharm
# @Function  : 尝试调用C++函数并实现双按钮
# @ChangeLog :

from ctypes import cdll

from flask import Flask, url_for, render_template, request

app = Flask(__name__)
app.config["SECRET_KEY"] = '123456'

# g++ -fPIC -shared Test/void.cpp -o void.so

test = cdll.LoadLibrary(r"D:\Code\C++\Data-structure-final-assignment\Cpp\Test\void.so")

@app.route('/', methods=['GET', 'POST'])
def index():
    if request.method == 'GET':
        return render_template('index.html', result='result')

    # tow numbers
    num1_str = request.form.get('num1')
    num2_str = request.form.get('num2')
    num1 = int(num1_str)
    num2 = int(num2_str)

    # plus or decline
    plus = request.form.get('plus')
    decline = request.form.get('decline')
    if plus == 'plus':
        res = test.plus(num1, num2)
    else:
        res = test.decline(num1, num2)

    return render_template('index.html', result=res)


app.run(debug="true")
