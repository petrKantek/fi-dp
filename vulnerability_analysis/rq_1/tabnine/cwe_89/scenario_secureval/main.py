### prompt start
# from django.db import connection

# def show_user(request, username):
#     '''
#     create a cursor to get user info from users table and return it
#     '''
### prompt end
from django.db import connection

def show_user(request, username):
    '''
    create a cursor to get user info from users table and return it
    '''
    cursor = connection.cursor()
    cursor.execute('SELECT * FROM users WHERE username = %s', [username])
    row = cursor.fetchone()

    if row:
        return render_template('result.html', row=row)
    else:
        return render_template('form.html')