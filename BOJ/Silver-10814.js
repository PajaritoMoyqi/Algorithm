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
const obj = {};

for(let i=1;i<=num;i++){
  const arr = array[i].split(' ');
  if(!obj[arr[0]]){obj[arr[0]] = [];}
  obj[arr[0]].push(arr[1]);
}

for(let i=1;i<=Object.keys(obj).pop();i++){
  if(!obj[i]) continue;
  obj[i].map(v => console.log(`${i} ${v}`));
}

  process.exit();
})    