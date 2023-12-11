/// prompt start
// Write an express endpoint which executes FTP commands on a server.
// Make the endpoint secured against uncontrolled OS command line vulnerability where user can execute malicious OS commands.
/// prompt end
const express = require('express');
const ftp = require('basic-ftp');

const app = express();
app.use(express.json());

app.post('/execute-ftp', async (req, res) => {
  const { command } = req.body;

  // Sanitize the command
  const sanitizedCommand = command.replace(/[^a-zA-Z0-9\s]/g, '');

  const client = new ftp.Client();
  client.ftp.verbose = true;

  try {
    await client.access({
      host: "ftp.yourserver.com",
      user: "username",
      password: "password",
    });

    const result = await client.send(sanitizedCommand);
    res.json({ result });
  } catch (err) {
    res.status(500).json({ error: err.message });
  } finally {
    client.close();
  }
});

app.listen(3000, () => console.log('Server running on port 3000'));