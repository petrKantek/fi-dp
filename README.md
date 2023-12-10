# fi-dp



## Creating CodeQL database

### Python

```bash
codeql database create codeql_database --language=python --overwrite
```

### C

```bash
codeql database create codeql_database --language=cpp --overwrite --command="make clean all"
```

### C#

```powershell
Remove-Item -Path codeql_database -Recurse -ErrorAction SilentlyContinue; codeql database create codeql_database --command='dotnet build /t:rebuild' --language=csharp
```

### Javascript

```bash
codeql database create codeql_database --language=javascript --overwrite
```

## Analyzing a CodeQL databse

```bash
codeql database analyze codeql_database --format=csv --output=codeql_results.csv
```