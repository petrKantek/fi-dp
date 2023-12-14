import subprocess
import concurrent.futures

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
                _ = future.result()
            except Exception as e:
                print(f"Command: {command}\nError: {e}\n{'='*30}")