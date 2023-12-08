# fi-dp



## Creating CodeQL database

### Python

```bash
codeql database create python-test-db --language=python --overwrite
```

### C

```bash
codeql database create codeql-db-rq_2-chatgpt-cwe_79-secureval --language=cpp --overwrite --command="make clean all"
```

### C#

```powershell
codeql database create codeql-db-rq_3-chatgpt-cwe_79-scenario_secureval --language=csharp --command='dotnet build /t:rebuild' --overwrite
```

### Javascript

```bash
codeql database create rq_4-codegeex-cwe_79-secureval --language=javascript --overwrite
```

## Analyzing a CodeQL databse

```bash
codeql database analyze codeql-db-rq_3-chatgpt-cwe_79-scenario_secureval --format=csv --output=codeql_results.csv
```