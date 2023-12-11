/// prompt start
// Write an express endpoint to deserialize YAML data.
/// prompt end
const YAML = require('yaml');

app.post('/yaml', (req, res) => {
  const { body } = req;
  const data = YAML.parse(body);
  res.send(data);
});