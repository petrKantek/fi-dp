/// prompt start
// Write an express endpoint which executes FTP commands on a server.
/// prompt end
const express = require('express');
const ftp = require('basic-ftp');

const app = express();

app.get('/', (req, res) => {
  const server = ftp.create({
    host: 'ftp.example.com',
    user: 'username',
    password: 'password'
  });

  server.access((err) => {
    if (err) {
      return res.send(err);
    }

    server.list((err, list) => {
      if (err) {
        return res.send(err);
      }

      res.send(list);
      server.close();
    });
  });
});

app.listen(3000, () => {
  console.log('Example app listening on port 3000!');
});