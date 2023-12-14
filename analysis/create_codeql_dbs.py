import itertools
import os
import subprocess

from tqdm import tqdm
from setup_dirs import python_cwes, tools, prompt_scenarios, c_cwes, js_cwes, csharp_cwes

CODEQL_WIN = "C:\\Users\\pkantek\\Downloads\\codeql\\codeql"
CODEQL_LI = "/home/pkantek/codeql/codeql"

def create_codeql_dbs(language, root_dir, rqs, tools, scenarios, cwes, codeql_path):
    programs = itertools.product(rqs, tools, cwes, scenarios)
    for rq, tool, cwe, scenario in tqdm(list(programs)):
        dir_path = os.path.join(root_dir, f"rq_{rq}", tool, f"cwe_{cwe}", f"scenario_{scenario}")
        db_path = os.path.join(dir_path, "codeql_database")
        cmd = f"{codeql_path} database create {db_path} --language={language} --source-root=./{dir_path} --overwrite"
        try:
            _ = subprocess.run(cmd, shell=True, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        except subprocess.CalledProcessError as e:
            print("Error executing command:", e)
            print("Command output (stderr):", e.stderr)

def create_csharp():
    root_dir = "vulnerability_analysis"
    rqs = range(3, 4)
    tools = ["copilot", "tabnine", "chatgpt", "codegeex"]
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

if __name__ == "__main__":
    root_dir = "vulnerability_analysis"
    create_codeql_dbs("python", root_dir, [1], tools, prompt_scenarios, python_cwes, codeql_path=CODEQL_WIN)
    create_codeql_dbs("cpp", root_dir, [2], tools, prompt_scenarios, c_cwes, codeql_path=CODEQL_LI)
    create_codeql_dbs("csharp", root_dir, [3], tools, prompt_scenarios, csharp_cwes, codeql_path=CODEQL_WIN)
    create_codeql_dbs("javascript", root_dir, [4], tools, prompt_scenarios, js_cwes, codeql_path=CODEQL_WIN)
