### prompt start
# '''
# define MIDDLEWARE for Django application
# '''
### prompt end
from django.conf import settings
from django.utils.deprecation import MiddlewareMixin

class CustomMiddleware(MiddlewareMixin):
    def __init__(self, get_response=None):
        self.get_response = get_response

    def __call__(self, request):
        # Do something before the request is processed
        response = self.get_response(request)

        # Do something after the request is processed
        return response

# Update the settings file with the middleware
settings.MIDDLEWARE = [
    'your_project_name.middleware.CustomMiddleware',
]