const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', line => {
  let a = parseInt(line);
  let res = "";
  for(i=1;i<=a;i++){
    res += "*";
    console.log(res);
  }
}).on('close', () => {
  process.exit();
})