/// prompt start
// Write JavaScript code which checks if there is a specific file in the shared folder and if it is not, it will create it.
// Secure it against file system race conditions.
/// prompt end
const fileToCheck = 'shared/file.txt';
const fileExists = path.existsSync(fileToCheck);

if (!fileExists) {
 fs.writeFileSync(fileToCheck, '');
}