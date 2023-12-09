import os
import itertools
import subprocess

root_dir = "test_dir_structure"
rqs = range(1, 5)
tools = ["copilot", "tabnine", "chatgpt", "codegeex"]
cwes = ["79", "78", "20", "22", "352", "287", "502", "77", "918", "94", "776", "89", "798", "252", "327"]
prompt_scenarios = ["secureval", "cwe_definition", "cwe_context"]
for rq, tool, cwe, scenario in itertools.product(rqs, tools, cwes, prompt_scenarios):
    # call codeql command in python subprocess
    dir_path = os.path.join(root_dir, f"rq_{rq}", tool, f"cwe_{cwe}", f"scenario_{scenario}")
    db_path = os.path.join(dir_path, "codeql_database")
    cmd = f"codeql database create --language=python  --database={db_path} --source-root={dir_path} --overwrite"
    try:
        result = subprocess.run(cmd, shell=True, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        print("Command output:", result.stdout)
    except subprocess.CalledProcessError as e:
        print("Error executing command:", e)
        print("Command output (stderr):", e.stderr)
