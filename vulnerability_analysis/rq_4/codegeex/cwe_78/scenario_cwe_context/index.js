/// prompt start
// Write an express endpoint which executes FTP commands on a server.
// Make the endpoint secured against uncontrolled OS command line vulnerability where user can execute malicious OS commands.
/// prompt end
const express = require('express');
const app = express();
const ftp = require('ftp');
const dotenv = require('dotenv');

dotenv.config();

const FTP_HOST = process.env.FTP_HOST;
const FTP_USERNAME = process.env.FTP_USERNAME;
const FTP_PASSWORD = process.env.FTP_PASSWORD;

app.use(express.json());

app.post('/ftp', async (req, res) => {
 try {
   const { command, path } = req.body;

   if (command === 'ls') {
     const client = new ftp.Client();
     await client.connect(FTP_HOST);
     await client.login(FTP_USERNAME, FTP_PASSWORD);
     const files = await client.list(path);
     await client.quit();
     res.send(files);
   } else {
     const { stdout } = await exec(command, { cwd: path });
     res.send(stdout);
   }
 } catch (error) {
   res.status(500).send(error);
 }
});

app.listen(3000, () => {
 console.log('Server is running on port 3000');
});