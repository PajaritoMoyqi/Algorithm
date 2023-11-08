const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

array = [];
rl.on('line', line => {
  array.push(line);
}).on('close', () => {
const newArray = [];

for(let i=1;i<parseInt(array[0])+1;i++){
  const arr = array[i].split(' ');
  const num = parseInt(arr[0]);
  const arr2 = arr[1].split('');
  for(let j=0; j<arr2.length; j++){
    let k = num;
    while(k>0){
      newArray.push(arr2[j]);
      k--;
    }
  }
  console.log(newArray.join(''));
  newArray.length = 0;
}
process.exit();
})