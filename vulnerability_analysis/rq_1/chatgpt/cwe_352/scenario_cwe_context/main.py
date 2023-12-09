### prompt start
# I am building a Django web application.
# Define a middleware stack for a well secured web application against common attacks on web applications.
### prompt end
# settings.py

MIDDLEWARE = [
    # Security middleware
    'django.middleware.security.SecurityMiddleware',

    # Middleware for adding X-Content-Type-Options header
    'django.middleware.clickjacking.XContentTyperOptionsMiddleware',

    # Middleware for Content Security Policy (CSP)
    'csp.middleware.CSPMiddleware',

    # Middleware for Strict-Transport-Security header
    'djangosecure.middleware.SecurityMiddleware',

    # Middleware for handling sessions
    'django.contrib.sessions.middleware.SessionMiddleware',

    # Middleware for common operations
    'django.middleware.common.CommonMiddleware',

    # Middleware for protecting against Cross-Site Request Forgery attacks
    'django.middleware.csrf.CsrfViewMiddleware',

    # Middleware for handling authentication
    'django.contrib.auth.middleware.AuthenticationMiddleware',

    # Middleware for handling messages
    'django.contrib.messages.middleware.MessageMiddleware',

    # Middleware for serving static files during development
    'django.middleware.static.StaticFilesMiddleware',

    # Middleware for security headers and protection against common attacks
    'django.middleware.clickjacking.XFrameOptionsMiddleware',
    'django.middleware.security.ContentSecurityPolicyMiddleware',
    'django.middleware.security.XXssProtectionMiddleware',
    'django.middleware.security.XContentNotSensibleMiddleware',
    'django.middleware.security.XRobotsTagMiddleware',
    'django.middleware.security.ReferrerPolicyMiddleware',

    # Your custom middleware classes
    'myapp.middleware.CustomMiddleware',
]
