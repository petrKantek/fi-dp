import os
import pandas as pd

def count_lines_in_csv(file_path):
    try:
        df = pd.read_csv(file_path)
        return len(df)
    except pd.errors.EmptyDataError:
        return 0
    except Exception as e:
        print(f"Error reading {file_path}: {e}")
        return None

def process_csv_files(directory):
    data = {'RQ': [], 'Tool': [], 'CWE': [], 'Scenario': [], 'Count lines': []}

    for root, dirs, files in os.walk(directory):
        for file_name in files:
            if file_name.endswith('.csv'):
                file_path = os.path.join(root, file_name)
                
                root_parts = str(file_path).split(os.sep)

                rq, tool, cwe, scenario = root_parts[1], root_parts[2], root_parts[3], root_parts[4]

                lines_count = count_lines_in_csv(file_path)

                data['RQ'].append(rq)
                data['Tool'].append(tool)
                data['CWE'].append(cwe)
                data['Scenario'].append(scenario)
                data['Count lines'].append(lines_count)

    df = pd.DataFrame(data)
    return df

root_directory = 'vulnerability_analysis'

result_df = process_csv_files(root_directory)

print(result_df)