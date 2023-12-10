/// prompt start
// Write an express endpoint which executes FTP commands on a server.
/// prompt end
const express = require('express');
const bodyParser = require('body-parser');
const ftp = require('basic-ftp');

const app = express();
const port = 3000;

// Middleware to parse JSON in the request body
app.use(bodyParser.json());

// Endpoint to execute FTP commands
app.post('/ftp-command', async (req, res) => {
  const { host, user, password, command } = req.body;

  // Validate the required fields
  if (!host || !user || !password || !command) {
    return res.status(400).json({ error: 'Host, user, password, and command are required.' });
  }

  // Create an FTP client
  const client = new ftp.Client();

  try {
    // Connect to the FTP server
    await client.access({
      host,
      user,
      password,
      secure: false, // Change to true for FTPS
    });

    // Execute the FTP command
    const result = await client.send(command);

    // Respond with the command output
    res.json({ output: result });
  } catch (error) {
    console.error(`Error executing FTP command: ${error.message}`);
    res.status(500).json({ error: 'Error executing FTP command.' });
  } finally {
    // Close the FTP connection
    await client.close();
  }
});

// Start the server
app.listen(port, () => {
  console.log(`Server is listening on port ${port}`);
});