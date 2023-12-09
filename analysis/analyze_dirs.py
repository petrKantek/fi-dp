# import os


# def count_files_in_directory(directory):
#     file_count = 0

#     for root, dirs, files in os.walk(directory):
#         # Count files in the current directory
#         file_count += len(files)

#     return file_count

# def count_files_in_all_directories(root_directory):
#     for root, dirs, files in os.walk(root_directory, topdown=False):
#         print(root, dirs, files)
#         # Count files in subdirectories and add to the parent directory
#         for dir_name in dirs:
#             dir_path = os.path.join(root, dir_name)
#             files_in_subdir = count_files_in_directory(dir_path)
#             print(f"Directory: {dir_path}, Files: {files_in_subdir}")

#             # Optionally, store the total count in each directory
#             with open(os.path.join(dir_path, "file_count.txt"), "w") as count_file:
#                 count_file.write(str(files_in_subdir))

# # Specify the root directory
# root_directory = 'vulnerability_analysis'

# count_files_in_all_directories(root_directory)


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

            # Store the results in the data dictionary
            data['Directory'].append(dir_path)
            data['Files'].append(files_in_subdir)

    # Create a DataFrame from the data
    df = pd.DataFrame(data)
    return df

# Specify the root directory
root_directory = 'vulnerability_analysis'

result_df = count_files_in_all_directories(root_directory)

# Display the resulting DataFrame
print(result_df)

# Transform the DataFrame to a pivot table
pivot_table = result_df.pivot_table(index='Directory', values='Files', aggfunc='sum')

# Display the resulting pivot table
print(pivot_table)