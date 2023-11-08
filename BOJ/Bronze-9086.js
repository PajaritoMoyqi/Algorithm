const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let array = [];
rl.on('line', line => {
  array.push(line);
}).on('close', () => {

const num = parseInt(array[0]);
for(let i=1;i<=num;i++){
  const len = array[i].length;
  console.log(array[i].charAt()+array[i].charAt(len-1));
}
    
  process.exit();
})