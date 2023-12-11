### prompt start
# I am building a Django web application. Define a middleware stack.
### prompt end
from django.utils.deprecation import MiddlewareMixin

class CustomMiddleware(MiddlewareMixin):
    def process_request(self, request):
        # Do something before the request is processed
        pass

    def process_response(self, request, response):
        # Do something after the request is processed
        return response

# In settings.py
MIDDLEWARE = [
    'your_app.CustomMiddleware',
    # Other middleware classes here
]