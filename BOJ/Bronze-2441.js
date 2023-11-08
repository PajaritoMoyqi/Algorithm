const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});


rl.on('line', line => {

let num = Number(line);

for(let i=1;i<=num;i++){
  console.log(' '.repeat(i-1)+'*'.repeat(num+1-i));
}

}).on('close', () => {
process.exit();
})