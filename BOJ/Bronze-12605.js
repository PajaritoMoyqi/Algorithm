const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});
const array = [];
rl.on('line', line => {
array.push(line);
}).on('close', () => {

const num = Number(array[0]);

for(let i=1;i<=num;i++){
  let arr = array[i].split(' ');
  arr.reverse();
  console.log(`Case #${i}: ${arr.join(' ')}`);
}
    
  process.exit();
})