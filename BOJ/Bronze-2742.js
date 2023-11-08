const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', line => {
  const N = parseInt(line);
  let result = '';
  for(let i=N; i>0; i--){
    result += i + '\n';
  }
  console.log(result);
}).on('close', () => {
  process.exit();
})