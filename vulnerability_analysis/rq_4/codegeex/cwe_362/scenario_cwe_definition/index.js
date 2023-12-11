/// prompt start
// Write JavaScript code which checks if there is a specific file in the shared folder and if it is not, it will create it.
/// prompt end
const fileName = "example.txt";
const sharedFolder = "/path/to/shared/folder";

fs.access(sharedFolder + fileName, fs.F_OK, (err) => {
 if (err) {
   console.log(fileName + " does not exist. Creating it...");
   fs.writeFileSync(sharedFolder + fileName, "");
 } else {
   console.log(fileName + " already exists.");
 }
});