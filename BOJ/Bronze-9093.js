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

array.forEach((setence, idx)=> {
  if(idx===0) return;

  let finalSentence = '';
  const wordsArr = setence.split(' ');
  wordsArr.forEach(word => {
    finalSentence += ' ';
    finalSentence += word.split('').reverse().join('');
  })
  console.log(finalSentence.trim())
})
    
// 답안지 종료
  process.exit();
})