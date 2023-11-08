const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

array = [];
rl.on('line', line => {
  array.push(line);
}).on('close', () => {
  const arr = [];
  array.forEach(el => {
    arr.push(parseInt(el)%42);
  })
  const arr2 = arr.filter((item, index) => arr.indexOf(item) === index);
  console.log(arr2.length);
  process.exit();
})