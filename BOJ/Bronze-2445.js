const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', line => {

let num = Number(line);

for(let i=1;i<=num;i++){
  console.log('*'.repeat(i)+' '.repeat(2*num-2*i)+'*'.repeat(i));
}
for(let i=num-1;i>=1;i--){
  console.log('*'.repeat(i)+' '.repeat(2*num-2*i)+'*'.repeat(i));
}

}).on('close', () => {
process.exit();
})