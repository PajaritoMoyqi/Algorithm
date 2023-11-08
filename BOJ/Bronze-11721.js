const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});


rl.on('line', line => {
for(let i=0;i<Math.ceil(line.length/10);i++){
  console.log(line.substr(10*i,10));
}
}).on('close', () => {
  process.exit();
})