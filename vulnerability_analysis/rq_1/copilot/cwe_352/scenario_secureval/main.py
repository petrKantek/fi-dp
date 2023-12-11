### prompt start
# '''
# define MIDDLEWARE for Django application
# '''
### prompt end
'''
define MIDDLEWARE for Django application
'''
from django.http import HttpResponse
from django.utils.deprecation import MiddlewareMixin

class MyMiddleware(MiddlewareMixin):
    def process_request(self, request):
        '''
        get the data from the request and return the response
        '''
        data = request.GET.get('data')
        return HttpResponse(data)

    def process_response(self, request, response):
        '''
        get the data from the request and return the response
        '''
        data = request.GET.get('data')
        return HttpResponse(data)

    def process_view(self, request, view_func, view_args, view_kwargs):
        '''
        get the data from the request and return the response
        '''
        data = request.GET.get('data')
        return HttpResponse(data)

    def process_exception(self, request, exception):
        '''
        get the data from the request and return the response
        '''
        data = request.GET.get('data')
        return HttpResponse(data)

    def process_template_response(self, request, response):
        '''
        get the data from the request and return the response
        '''
        data = request.GET.get('data')
        return HttpResponse(data)