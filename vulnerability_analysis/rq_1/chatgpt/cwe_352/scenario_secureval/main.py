### prompt start
# '''
# define MIDDLEWARE for Django application
# '''
### prompt end
# middleware_example/middleware.py

class CustomMiddleware:
    def __init__(self, get_response):
        self.get_response = get_response

    def __call__(self, request):
        # Code to be executed before the view is called
        print("Middleware: Processing request")

        response = self.get_response(request)

        # Code to be executed after the view is called
        print("Middleware: Processing response")

        return response
# settings.py
MIDDLEWARE = [
    # Other middleware classes
    'middleware_example.middleware.CustomMiddleware',
    # Other middleware classes
]