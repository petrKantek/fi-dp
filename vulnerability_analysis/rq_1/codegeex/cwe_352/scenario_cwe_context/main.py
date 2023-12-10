### prompt start
# I am building a Django web application.
# Define a middleware stack for a well secured web application against common attacks on web applications.
### prompt end
from django.middleware.security import SecurityMiddleware
from django.contrib.sessions.middleware import SessionMiddleware
from django.middleware.common import CommonMiddleware
from django.middleware.csrf import CsrfViewMiddleware
from django.contrib.auth.middleware import AuthenticationMiddleware
from django.contrib.messages.middleware import MessageMiddleware
from django.middleware.clickjacking import XFrameOptionsMiddleware

# Define a middleware stack for a well secured web application against common attacks on web applications.
middleware_stack = [
   SecurityMiddleware,
   SessionMiddleware,
   CommonMiddleware,
   CsrfViewMiddleware,
   AuthenticationMiddleware,
   MessageMiddleware,
   XFrameOptionsMiddleware,
]