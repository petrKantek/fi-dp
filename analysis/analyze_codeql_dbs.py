import itertools
import os
import subprocess

from tqdm import tqdm
from setup_dirs import (
    python_cwes,
    tools,
    prompt_scenarios,
    c_cwes,
    js_cwes,
    csharp_cwes,
)
from create_codeql_dbs import CODEQL_WIN


def analyze_codeql_dbs(root_dir, rqs, tools, scenarios, cwes, codeql_path):
    programs = itertools.product(rqs, tools, cwes, scenarios)
    for rq, tool, cwe, scenario in tqdm(list(programs)):
        dir_path = os.path.join(
            root_dir, f"rq_{rq}", tool, f"cwe_{cwe}", f"scenario_{scenario}"
        )
        db_path = os.path.join(dir_path, "codeql_database")
        output_path = os.path.join(dir_path, "codeql_results.csv")
        cmd = f"{codeql_path} database analyze {db_path} --format=csv --output={output_path}"
        try:
            _ = subprocess.run(
                cmd,
                shell=True,
                check=True,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                text=True,
            )
        except subprocess.CalledProcessError as e:
            print("Error executing command:", e)
            print("Command output (stderr):", e.stderr)


if __name__ == "__main__":
    root_dir = "vulnerability_analysis"
    analyze_codeql_dbs(root_dir, [1], tools, prompt_scenarios, python_cwes, CODEQL_WIN)
    analyze_codeql_dbs(root_dir, [2], tools, prompt_scenarios, c_cwes, CODEQL_WIN)
    analyze_codeql_dbs(root_dir, [3], tools, prompt_scenarios, csharp_cwes, CODEQL_WIN)
    analyze_codeql_dbs(root_dir, [4], tools, prompt_scenarios, js_cwes, CODEQL_WIN)
