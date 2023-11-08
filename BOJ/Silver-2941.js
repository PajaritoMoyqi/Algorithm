const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});


rl.on('line', line => {
const regex = /c\=|dz\=|s\=|z\=|lj|nj|d\-|c\-/g
const res = line.replace(regex, 'Y');

console.log(res.length);
}).on('close', () => {
  process.exit();
})    