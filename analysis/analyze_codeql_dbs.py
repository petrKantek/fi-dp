import itertools
import os
import subprocess

from tqdm import tqdm
from utils import run_parallel_commands


def python():
    root_dir = "vulnerability_analysis"
    rqs = range(1, 2)
    tools = ["chatgpt"]#["copilot", "tabnine", "chatgpt", "codegeex"]
    cwes = ["79", "78", "20", "22", "352", "287", "502", "77", "918", "94", "776", "89", "798", "252", "327"]
    prompt_scenarios = ["secureval", "cwe_definition", "cwe_context"]
    programs = itertools.product(rqs, tools, cwes, prompt_scenarios)
    for rq, tool, cwe, scenario in tqdm(list(programs)):
        # call codeql command in python subprocess
        dir_path = os.path.join(root_dir, f"rq_{rq}", tool, f"cwe_{cwe}", f"scenario_{scenario}")
        db_path = os.path.join(dir_path, "codeql_database")
        output_path = os.path.join(dir_path, "codeql_results.csv")
        # print("dir_path: ", dir_path)
        # print("db_path: ", db_path)
        cmd = f"/home/pkantek/codeql/codeql database analyze {db_path} --format=csv --output={output_path}"
        # print("CMD >>>> ", cmd)
        try:
            result = subprocess.run(cmd, shell=True, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
            # print(f"dir_path: {dir_path}, Command output:", result.stdout)
        except subprocess.CalledProcessError as e:
            print("Error executing command:", e)
            print("Command output (stderr):", e.stderr)

def c():
    root_dir = "vulnerability_analysis"
    rqs = range(2, 3)
    tools = ["chatgpt"]#["copilot", "tabnine", "chatgpt", "codegeex"]
    cwes = ['787', '79', '89', '416', '78', '20', '125', '22', '476', '287', '190', '77', '119', '362', '269']
    prompt_scenarios = ["secureval", "cwe_definition", "cwe_context"]
    programs = itertools.product(rqs, tools, cwes, prompt_scenarios)
    # commands_to_run = [] 
    for rq, tool, cwe, scenario in tqdm(list(programs)):
        dir_path = os.path.join(root_dir, f"rq_{rq}", tool, f"cwe_{cwe}", f"scenario_{scenario}")
        db_path = os.path.join(dir_path, "codeql_database")
        output_path = os.path.join(dir_path, "codeql_results.csv")
        cmd = f"/home/pkantek/codeql/codeql database analyze {db_path} --format=csv --output={output_path}"
        try:
            _ = subprocess.run(cmd, shell=True, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        except subprocess.CalledProcessError as e:
            print("Error executing command:", e)
            print("Command output (stderr):", e.stderr)
        # commands_to_run.append(cmd)
    # run_parallel_commands(commands_to_run, max_workers=4)

def js():
    root_dir = "vulnerability_analysis"
    rqs = range(4, 5)
    tools = ["chatgpt"]#["copilot", "tabnine", "chatgpt", "codegeex"]
    cwes = ['79', '89', '78', '20', '22', '352', '434', '862', '476', '287', '502', '77', '798', '918', '362', '269', '94']
    prompt_scenarios = ["secureval", "cwe_definition", "cwe_context"]
    programs = itertools.product(rqs, tools, cwes, prompt_scenarios)
    for rq, tool, cwe, scenario in tqdm(list(programs)):
        # call codeql command in python subprocess
        dir_path = os.path.join(root_dir, f"rq_{rq}", tool, f"cwe_{cwe}", f"scenario_{scenario}")
        db_path = os.path.join(dir_path, "codeql_database")
        output_path = os.path.join(dir_path, "codeql_results.csv")
        # print("dir_path: ", dir_path)
        # print("db_path: ", db_path)
        cmd = f"/home/pkantek/codeql/codeql database analyze {db_path} --format=csv --output={output_path}"
        try:
            result = subprocess.run(cmd, shell=True, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
            # print(f"dir_path: {dir_path}, Command output:", result.stdout)
        except subprocess.CalledProcessError as e:
            print("Error executing command:", e)
            print("Command output (stderr):", e.stderr)

# js()
# c()

def csharp():
    root_dir = "vulnerability_analysis"
    rqs = range(3, 4)
    tools = ["copilot"]#["copilot", "tabnine", "chatgpt", "codegeex"]
    cwes = ['787', '79', '89', '78', '20', '22', '352', '434', '476', '287', '190', '502', '77', '119', '798', '918', '362', '94']
    prompt_scenarios = ["secureval", "cwe_definition", "cwe_context"]
    programs = itertools.product(rqs, tools, cwes, prompt_scenarios)
    for rq, tool, cwe, scenario in tqdm(list(programs)):
        dir_path = os.path.join(root_dir, f"rq_{rq}", tool, f"cwe_{cwe}", f"scenario_{scenario}")
        db_path = os.path.join(dir_path, "codeql_database")
        output_path = os.path.join(dir_path, "codeql_results.csv")
        cmd = f"codeql database analyze {db_path} --format=csv --output={output_path}"
        try:
            _ = subprocess.run(cmd, shell=True, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        except subprocess.CalledProcessError as e:
            print("Error executing command:", e)
            print("Command output (stderr):", e.stderr)

csharp()
        # print("CMD >>>> ", cmd)
        # try:
        #     result = subprocess.run(cmd, shell=True, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        #     # print(f"dir_path: {dir_path}, Command output:", result.stdout)
        # except subprocess.CalledProcessError as e:
        #     print("Error executing command:", e)
        #     print("Command output (stderr):", e.stderr)
