# -*- coding:utf-8 -*-
import pymysql
from flask import render_template,Flask,request,session,redirect,url_for,abort,flash


app=Flask(__name__)
app.secret_key = "123456"
conn = pymysql.connect(host='127.0.0.1', port=3306, user='root', passwd='sjchlh',db='test', charset='utf8')
conn1 = pymysql.connect(host='127.0.0.1', port=3306, user='root', passwd='sjchlh',db='users', charset='utf8')

         

@app.route('/add',methods=['POST'])
def add_entry():
    cur = conn.cursor()
    if not session.get('logged_in'):
        abort(401)
    if len(request.form['text'])>50 and len(request.form['text'])<500:
        sql_insert = "insert into entries1 (name,text) values ('%s', '%s')" % (request.form['name'], request.form['text'])
        cur.execute(sql_insert)
        conn.commit()
        flash('New entry was successfully posted')
    else:
        flash('Your text must be limited 50 to 500 words')
    return redirect(url_for('show_entries'))


#输出函数
@app.route('/')
def show_entries():
    cur = conn.cursor()
    sql = "select name,text from entries1 order by id desc limit 10"
    cur.execute(sql)
    entries = [dict(name=row[0], text=row[1]) for row in cur.fetchall()]
    cur.close()
    return render_template('show_entries.html',entries=entries)

#注册函数
@app.route('/register',methods=['GET','POST'])
def Register():
    if request.method == 'POST':
        cur = conn1.cursor()
        sql = "insert into user1(username,password) values ('%s','%s')" % (request.form['usname'],request.form['pswd'])
        cur.execute(sql)
        conn1.commit()
        flash("new user has been successfully registered!")
        cur.close()
        return  redirect(url_for('index'))
    return render_template('register.html')


#登录函数
@app.route('/login',methods=['GET','POST'])
def index():
    error=None
    cur = conn1.cursor()
    if request.method=='POST':
        sql = "select username,password from user1 where username='%s'" % (request.form['u'],)
        cur.execute(sql)
        temp = cur.fetchone()
        if temp:
            if request.form['u']!=temp[0]:
                error = 'name error'
            elif request.form['p']!=temp[1]:
                error = 'password error'
            else:
                session['logged_in']= True
                flash('log in')
                return redirect(url_for('show_entries'))
    cur.close()
    return render_template('hello.html',error=error)
if __name__=='__main__':
    app.run(debug=True)
