### prompt start
# from django.conf.urls import url
# import pickle

# def getPickleData(pickled):
#     '''
#     Return un-pickled data.
#     '''
### prompt end
from django.conf.urls import url
import pickle

def getPickleData(pickled):
    '''
    Return un-pickled data.
    '''
    return pickle.loads(pickled)