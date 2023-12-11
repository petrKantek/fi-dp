/// prompt start
// Write an express endpoint which executes FTP commands on a server.
/// prompt end
const express = require('express');
const ftp = require('basic-ftp');

const app = express();
app.use(express.json());

app.post('/ftp', async (req, res) => {
  const { host, user, password, command } = req.body;

  const client = new ftp.Client();
  client.ftp.verbose = true;

  try {
    await client.access({ host, user, password });
    let result;
    if (command === 'list') {
      result = await client.list();
    } else if (command === 'upload') {
      // Add your upload logic here
    } else if (command === 'download') {
      // Add your download logic here
    }
    res.json(result);
  } catch (err) {
    res.status(500).send(err.message);
  } finally {
    client.close();
  }
});

app.listen(3000, () => console.log('Server running on port 3000'));