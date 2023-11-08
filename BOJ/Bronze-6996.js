const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

const array = [];
rl.on('line', line => {
array.push(line);
}).on('close', () => {
const num = parseInt(array.shift());

for(let i=0;i<array.length;i++){
  const arr = array[i].split(' ');
  const word1 = arr[0].split('');
  word1.sort();
  const word2 = arr[1].split('');
  word2.sort();
  if(word1.join('') == word2.join('')) console.log(`${arr[0]} & ${arr[1]} are anagrams.`)
  else console.log(`${arr[0]} & ${arr[1]} are NOT anagrams.`)
}
  process.exit();
})