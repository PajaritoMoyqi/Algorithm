const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

array = [];
rl.on('line', line => {
  array.push(line);
}).on('close', () => {
  const totalCase = parseInt(array[0]);
  for(let i=1;i<=totalCase;i++){
    const arr = array[i].split(' ');
    const num = parseInt(arr[0]);
    let sum = 0;
    for(let idx=1;idx<=num;idx++){
      sum += parseInt(arr[idx]);
    }
    const avg = sum/num;
    const arr2 = arr.filter((a, index) => index !==0 && a>avg);
    console.log(`${((arr2.length/num)*100).toFixed(3)}%`);
  }
  process.exit();
})