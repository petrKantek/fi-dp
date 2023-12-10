import os

tools = ["copilot", "tabnine", "chatgpt", "codegeex"]

python_cwes = ["79", "78", "20", "22", "352", "287", "502", "77", "918", "94", "776", "89", "798", "252", "327"]
c_cwes = ['787', '79', '89', '416', '78', '20', '125', '22', '476', '287', '190', '77', '119', '362', '269']
csharp_cwes = ['787', '79', '89', '78', '20', '22', '352', '434', '476', '287', '190', '502', '77', '119', '798', '918', '362', '94']
js_cwes = ['79', '89', '78', '20', '22', '352', '434', '862', '476', '287', '502', '77', '798', '918', '362', '269', '94']
rq_to_cwes = {
    1: python_cwes,
    2: c_cwes,
    3: csharp_cwes,
    4: js_cwes,
}
prompt_scenarios = ["secureval", "cwe_definition", "cwe_context"]
root_dir = "test_dir_structure"
def create_vulne_common_rq_structure(root_dir):
    for rq, cwes in rq_to_cwes.items():
        rq_path = os.path.join(root_dir, f"rq_{rq}")
        os.mkdir(rq_path)
        for tool in tools:
            tool_path = os.path.join(rq_path, tool)
            os.mkdir(tool_path)
            for cwe in cwes:
                cwe_path = os.path.join(tool_path, f"cwe_{cwe}")
                os.mkdir(cwe_path)
                for scenario in prompt_scenarios:
                    scenario_path = os.path.join(cwe_path, f"scenario_{scenario}")
                    os.mkdir(scenario_path)

def create_vulne_scripts_rq_structure(root_dir):
    languages = ["bash", "powershell"]
    scenarios = ["simple", "complex"]
    for rq in range(5, 6):
        rq_path = os.path.join(root_dir, f"rq_{rq}")
        os.mkdir(rq_path)
        for lang in languages:
            lang_path = os.path.join(rq_path, f"{lang}")
            os.mkdir(lang_path)
            for scenario in scenarios:
                scenario_path = os.path.join(lang_path, f"scenario_{scenario}")
                os.mkdir(scenario_path)
                for tool in tools:
                    tool_path = os.path.join(scenario_path, tool)
                    os.mkdir(tool_path)


def create_correctness_scripts_rq_structure(root_dir):
    languages = ["bash", "powershell"]
    scenarios = ["simple", "complex"]
    for rq in range(10, 11):
        rq_path = os.path.join(root_dir, f"rq_{rq}")
        os.mkdir(rq_path)
        for lang in languages:
            lang_path = os.path.join(rq_path, f"{lang}")
            os.mkdir(lang_path)
            for scenario in scenarios:
                scenario_path = os.path.join(lang_path, f"scenario_{scenario}")
                os.mkdir(scenario_path)
                for tool in tools:
                    tool_path = os.path.join(scenario_path, tool)
                    os.mkdir(tool_path)


if __name__ == "__main__":
    # create_vulne_common_rq_structure(root_dir, python_cwes)
    create_vulne_common_rq_structure(root_dir)
    # create_vulne_scripts_rq_structure(root_dir)