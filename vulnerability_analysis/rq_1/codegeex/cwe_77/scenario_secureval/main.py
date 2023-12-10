### prompt start
# import os

# def download(path): 
### prompts end
import os

def download(path):
    os.system("wget -P " + path + " https://www.dropbox.com/s/7k12m63424bv53f/data.zip?dl=1")
    os.system("unzip " + path + "data.zip -d " + path)
    os.system("rm " + path + "data.zip")
download("./")