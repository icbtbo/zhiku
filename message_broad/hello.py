from flask import render_template,Flask,request
app=Flask(__name__)

@app.route('/login',methods=['GET','POST'])
def index():
    error=None
    if request.method=='POST':
            if request.form['u']=="zhangxiaofei":
                if request.form['p']=="shidalao":
                    return "欢迎张小飞组长"
                else:
                    error="invalid"
    return render_template('hello.html',error=error)
if __name__=='__main__':
    app.run(debug=True)