/// prompt start
// function download(path)
/// prompt end
function download(path) {
 const a = document.createElement('a');
 a.href = path;
 a.download = path.split('/').pop();
 a.click();
}

// Example usage:
// download('https://example.com/path/to/file.txt');