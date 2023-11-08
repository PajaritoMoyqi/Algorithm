const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

const array = [];
rl.on('line', line => {
  array.push(line);
}).on('close', () => {
const num = parseInt(array[0]);
array.shift();
const arr2 = [];
for(let i=0;i<num;i++){
  if(parseInt(array[i])===0){
    arr2.pop()
  }else{
    arr2.push(array[i]);
  }
}
let sum = 0;
arr2.map(v => sum+=parseInt(v));
console.log(sum);
  process.exit();
})