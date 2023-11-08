const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

const array = [];
rl.on('line', line => {  
  array.push(line);
}).on('close', () => {
for(let i=0;i<array.length;i++){
  console.log(array[i]);
}
  process.exit();
})