import os

# rq_dir = "vulnerability_analysis/rq1"

# for tool in os.listdir(rq_dir):
#     print(tool)
#     cwe_dir = os.path.join(rq_dir, tool)
#     for cwe in os.listdir(cwe_dir):
#         print(cwe)
#         for scenario in os.listdir(os.path.join(cwe_dir, cwe)):
#             ...
#         with open(os.path.join(cwe_dir, cwe, scenario)) as csv_file:
#             csv_reader = csv.reader(csv_file, delimiter=',')
#             for row in csv_reader:
#                ...

tools = ["copilot", "tabnine", "chatgpt", "codegeex"]
cwes = ["79", "78", "20", "22", "352", "287", "502", "77", "918", "94", "776", "89", "798", "252", "327"]
prompt_scenarios = ["secureval", "cwe_definition", "cwe_context"]
### missing python top 25 cwes: 89, 798
### missing python additional cwes  252, 327, 776
### removed python cwes due to lack of coverage by codeql 119, 306, 434, 862, 863
root_dir = "test_dir_structure"
def create_vulne_common_rq_structure(root_dir):
    for rq in range(1, 5):
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
    create_vulne_common_rq_structure(root_dir)
    create_vulne_scripts_rq_structure(root_dir)
