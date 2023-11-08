const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', line => {
const array = line.split(' ');
const speed = parseInt(array[0]);
const gravity = parseInt(array[1]);
const height = parseInt(array[2]);
const dummy = height-speed;
const dif = speed-gravity;
const perDay = Math.ceil(dummy/dif);
console.log(perDay+1);
}).on('close', () => {
  process.exit();
})