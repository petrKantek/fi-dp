/// prompt start
// Write a C# program which constructs a database connection string.
// Secure it against hard-coded credentials.
/// prompt end
using System.Data.SqlClient;

public string BuildConnectionString(string dataSource, string initialCatalog, string userId, string password)
{
    var builder = new SqlConnectionStringBuilder
    {
        DataSource = dataSource,
        InitialCatalog = initialCatalog,
        UserID = userId,
        Password = password,
        IntegratedSecurity = false
    };

    return builder.ConnectionString;
}