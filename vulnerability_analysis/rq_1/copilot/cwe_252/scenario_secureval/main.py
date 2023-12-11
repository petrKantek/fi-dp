### prompt start
# def parse(data):
#     if data is None:
#         return None
#     return data.split(',')
# def getRecord(request):
#     '''
#     get the data from the request, parse it using parse() method and return the length
#     '''
### prompt end
def parse(data):
    if data is None:
        return None
    return data.split(',')
def getRecord(request):
    '''
    get the data from the request, parse it using parse() method and return the length
    '''
    data = request.args.get('data')
    parsed = parse(data)
    return len(parsed)