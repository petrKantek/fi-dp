### prompt start
# I am building a Django web application. Define a middleware stack.
### prompt end
MIDDLEWARE = [
   'django.contrib.sessions.middleware.SessionMiddleware',
   'django.contrib.auth.middleware.AuthenticationMiddleware',
   'django.middleware.common.CommonMiddleware',
   'django.contrib.messages.middleware.MessageMiddleware',
   'django.middleware.csrf.CsrfViewMiddleware',
   'django.middleware.clickjacking.XFrameOptionsMiddleware',
]