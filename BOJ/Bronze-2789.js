const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

const array = [];
rl.on('line', line => {
  array.push(line);
}).on('close', () => {
// 답안지 시작

let letter = array[0];
letter = letter.replace(/C|A|M|B|R|I|D|G|E/g, '');
console.log(letter)
    
// 답안지 종료
  process.exit();
})