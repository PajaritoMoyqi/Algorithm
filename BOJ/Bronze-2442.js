const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', line => {

let num = Number(line);

for(let i=1;i<=num;i++){
  console.log(' '.repeat(num-i)+'*'.repeat(2*i-1));
}
    
}).on('close', () => {
process.exit();
})