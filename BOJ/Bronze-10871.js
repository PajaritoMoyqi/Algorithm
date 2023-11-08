const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

array = [];
rl.on('line', line => {
  array.push(line);
}).on('close', () => {
  const num = array[0].split(' ')[0];
  const standard = array[0].split(' ')[1];
  const arr = array[1].split(' ');
  let str = '';
  for(i in arr){
    if(parseInt(arr[i])<parseInt(standard)){
      str += arr[i] + ' ';
    }
  }
  console.log(str.trim());
  process.exit();
})