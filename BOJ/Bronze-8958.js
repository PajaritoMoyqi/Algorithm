const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

const array = [];
rl.on('line', line => {
  array.push(line)
}).on('close', () => {
const num = parseInt(array[0]);
for(i=1;i<num+1;i++){
  const arr = array[i].split('');
  let count = 0;
  let sum = 0;
  for(j=0; j<arr.length; j++){
    if(arr[j]==='O'){
      count++;
    }else{
      count = 0;
    }
    sum += count;
  }
  console.log(sum);
}
  process.exit();
})