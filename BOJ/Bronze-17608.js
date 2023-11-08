const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

const array = [];
rl.on('line', line => {
  array.push(line);
}).on('close', () => {
const num = Number(array.shift());
const height = Number(array[num-1]);

let h = height;
let count = 1;
for(let i=num-1;i>=0;i--){
  if(Number(array[i])>h){
    h = array[i];
    count++;
  }
}

console.log(count);
  process.exit();
})