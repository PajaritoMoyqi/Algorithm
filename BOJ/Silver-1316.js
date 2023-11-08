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
let count = 0;

for(let i=1;i<=num;i++){
  const arr = array[i].split('');
  const charArr = [];
  let isGroup = true;
  for(let j=0;j<arr.length;j++){
    if(charArr.indexOf(arr[j])===-1){
      charArr.push(arr[j]);
    }else if(charArr.lastIndexOf(arr[j])!==charArr.length-1){
      isGroup = false;
      break;
    }
  }
  if(isGroup) count++;
}

console.log(count);
  process.exit();
})    