import concurrent.futures
import itertools
import os
import subprocess

from tqdm import tqdm


def create_python():
    root_dir = "vulnerability_analysis"
    rqs = range(1, 2)
    tools = ["tabnine"]#["copilot", "tabnine", "chatgpt", "codegeex"]
    cwes = ["79", "78", "20", "22", "352", "287", "502", "77", "918", "94", "776", "89", "798", "252", "327"]
    prompt_scenarios = ["secureval", "cwe_definition", "cwe_context"]
    programs = itertools.product(rqs, tools, cwes, prompt_scenarios)
    for rq, tool, cwe, scenario in tqdm(list(programs)):
        # call codeql command in python subprocess
        dir_path = os.path.join(root_dir, f"rq_{rq}", tool, f"cwe_{cwe}", f"scenario_{scenario}")
        db_path = os.path.join(dir_path, "codeql_database")
        cmd = rf"C:\Users\pkantek\Downloads\codeql\codeql database create {db_path} --language=python --source-root=./{dir_path} --overwrite"
        try:
            _ = subprocess.run(cmd, shell=True, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        except subprocess.CalledProcessError as e:
            print("Error executing command:", e)
            print("Command output (stderr):", e.stderr)

# create_python()
def run_shell_command(command):
    try:
        result = subprocess.run(command, shell=True, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        return command, result.stdout, result.stderr
    except subprocess.CalledProcessError as e:
        return command, None, e.stderr

def run_parallel_commands(commands, max_workers):
    with concurrent.futures.ThreadPoolExecutor(max_workers=max_workers) as executor:
        futures = {executor.submit(run_shell_command, command): command for command in commands}
        for future in concurrent.futures.as_completed(futures):
            command = futures[future]
            try:
                result = future.result()
                # print(f"Command: {command}\nOutput:\n{result[1]}\nError:\n{result[2]}\n{'='*30}")
            except Exception as e:
                print(f"Command: {command}\nError: {e}\n{'='*30}")

def create_c():
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
        cmd = f"/home/pkantek/codeql/codeql database create {db_path} --language=cpp --source-root=./{dir_path} --command='make clean all' --overwrite"
        try:
            _ = subprocess.run(cmd, shell=True, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        except subprocess.CalledProcessError as e:
            print("Error executing command:", e)
            print("Command output (stderr):", e.stderr)
        # commands_to_run.append(cmd)


    # run_parallel_commands(commands_to_run, max_workers=4)

def create_js():
    root_dir = "vulnerability_analysis"
    rqs = range(4, 5)
    tools = ["copilot", "tabnine", "codegeex"] # "chatgpt"
    cwes = ['79', '89', '78', '20', '22', '352', '434', '862', '476', '287', '502', '77', '798', '918', '362', '269', '94']

    prompt_scenarios = ["secureval", "cwe_definition", "cwe_context"]
    programs = itertools.product(rqs, tools, cwes, prompt_scenarios)
    for rq, tool, cwe, scenario in tqdm(list(programs)):
        # call codeql command in python subprocess
        dir_path = os.path.join(root_dir, f"rq_{rq}", tool, f"cwe_{cwe}", f"scenario_{scenario}")
        db_path = os.path.join(dir_path, "codeql_database")
        # print("dir_path: ", dir_path)
        # print("db_path: ", db_path)
        cmd = rf"C:\Users\pkantek\Downloads\codeql\codeql database create {db_path} --language=javascript --source-root=./{dir_path} --overwrite"
        try:
            result = subprocess.run(cmd, shell=True, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
            # print(f"dir_path: {dir_path}, Command output:", result.stdout)
        except subprocess.CalledProcessError as e:
            print("Error executing command:", e)
            print("Command output (stderr):", e.stderr)
create_js()
    # print(commands_to_run)

def create_csharp():
    root_dir = "vulnerability_analysis"
    rqs = range(3, 4)
    tools = ["chatgpt"]#["copilot", "tabnine", "chatgpt", "codegeex"]
    cwes = ['787', '79', '89', '78', '20', '22', '352', '434', '476', '287', '190', '502', '77', '119', '798', '918', '362', '94']

    prompt_scenarios = ["secureval", "cwe_definition", "cwe_context"]
    programs = itertools.product(rqs, tools, cwes, prompt_scenarios)
    for rq, tool, cwe, scenario in tqdm(list(programs)):
        dir_path = os.path.join(root_dir, f"rq_{rq}", tool, f"cwe_{cwe}", f"scenario_{scenario}")
        db_path = os.path.join(dir_path, "codeql_database")
        pre_cmd_win_ps = f"Remove-Item -Path {db_path} -Recurse -ErrorAction SilentlyContinue";
        pre_cmd_win_cmd = f"if exist {db_path} rmdir /s /q {db_path}";
        pre_cmd_li = f"rm -rf {db_path}";
        cmd = f'({pre_cmd_win_cmd}) && (codeql database create {db_path} --language=csharp --source-root=./{dir_path} --command="dotnet build /t:rebuild" --overwrite)'
        try:
            _ = subprocess.run(cmd, shell=True, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        except subprocess.CalledProcessError as e:
            print("Error executing command:", e)
            print("Command output (stderr):", e.stderr)
