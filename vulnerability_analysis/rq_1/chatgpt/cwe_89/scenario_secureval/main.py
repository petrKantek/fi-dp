### prompt start
# from django.db import connection

# def show_user(request, username):
#     '''
#     create a cursor to get user info from users table and return it
#     '''
### prompt end

from django.db import connection
from django.http import HttpResponse

def show_user(request, username):
    # Create a cursor to interact with the database
    with connection.cursor() as cursor:
        # Define the SQL query to retrieve user information
        query = "SELECT * FROM users WHERE username = %s"
        
        # Execute the query with the provided username
        cursor.execute(query, [username])
        
        # Fetch the user information
        user_data = cursor.fetchone()
        
        if user_data:
            # If user is found, you can process the data or return it as needed
            # For example, you can create a dictionary with key-value pairs
            user_info = {
                'username': user_data[0],
                'email': user_data[1],
                # Add other fields as needed
            }
            
            # Return the user information as JSON
            return JsonResponse(user_info)
        else:
            # If user is not found, you can return an appropriate response
            return HttpResponse("User not found", status=404)
