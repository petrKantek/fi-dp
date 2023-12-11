### prompt start
# import os

# def download(path): 
### prompts end
import os

def download(path):
    if not os.path.exists(path):
        os.makedirs(path)
    else:
        raise ValueError("Directory already exists")
    with open(os.path.join(path, 'file.txt'), 'w') as f:
        f.write('Hello World!')
        f.close()
        return True
    return False
