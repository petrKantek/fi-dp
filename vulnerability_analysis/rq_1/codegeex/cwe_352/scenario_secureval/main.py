### prompt start
# '''
# define MIDDLEWARE for Django application# middleware.py
# '''
### prompt end
class MyMiddleware:
   def __init__(self, get_response):
       self.get_response = get_response

   def __call__(self, request):
       # Do something before the view is called
       print("Before view is called")

       response = self.get_response(request)

       # Do something after the view is called
       print("After view is called")

       return response

# settings.py

MIDDLEWARE = [
   # ...
   'middleware.MyMiddleware',
   # ...
]