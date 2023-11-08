const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});


rl.on('line', line => {
const array = line.split('');
const lineReverse = array.reverse().join('');
if(lineReverse===line){
  console.log(1);
}else{
  console.log(0);
}
}).on('close', () => {
  process.exit();
})