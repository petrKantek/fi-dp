import os

import pandas as pd


def count_files_in_directory(directory):
    file_count = len(os.listdir(directory))
    return file_count

def count_files_in_all_directories(root_directory):
    data = {'Directory': [], 'Files': []}

    for root, dirs, files in os.walk(root_directory, topdown=False):
        for dir_name in dirs:
            dir_path = os.path.join(root, dir_name)
            files_in_subdir = count_files_in_directory(dir_path)
            print(f"Directory: {dir_path}, Files: {files_in_subdir}")

            data['Directory'].append(dir_path)
            data['Files'].append(files_in_subdir)

    df = pd.DataFrame(data)
    return df

root_directory = 'vulnerability_analysis'

result_df = count_files_in_all_directories(root_directory)

print(result_df)

pivot_table = result_df.pivot_table(index='Directory', values='Files', aggfunc='sum')

print(pivot_table)