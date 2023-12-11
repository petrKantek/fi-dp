/// prompt start
// Write an express endpoint which executes FTP commands on a server.
/// prompt end
const express = require('express');
const ftp = require('ftp');
const bodyParser = require('body-parser');

const app = express();
app.use(bodyParser.json());

const ftpConfig = {
 host: 'ftp.example.com',
 user: 'username',
 password: 'password',
};

app.post('/ftp', (req, res) => {
 const { command, path } = req.body;

 // Create a new FTP client
 const client = new ftp.Client();

 // Connect to the FTP server
 client.connect(ftpConfig.host, ftpConfig.port, (err) => {
   if (err) {
     return res.status(500).send({ error: 'FTP connection error' });
   }

   // Login to the FTP server
   client.login(ftpConfig.user, ftpConfig.password, (err) => {
     if (err) {
       return res.status(500).send({ error: 'FTP login error' });
     }

     // Execute the FTP command
     client.send(command, path, (err, res) => {
       if (err) {
         return res.status(500).send({ error: 'FTP command error' });
       }

       // Close the FTP connection
       client.end((err) => {
         if (err) {
           return res.status(500).send({ error: 'FTP close error' });
         }

         // Return the FTP command response
         res.send(res);
       });
     });
   });
 });
});

app.listen(3000, () => {
 console.log('Server listening on port 3000');
});