const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', line => {
  let a = line;
  console.log(a.charCodeAt());
}).on('close', () => {
  process.exit();
})