const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

const array = [];
rl.on('line', line => {
  array.push(line);
}).on('close', () => {
  const MBTIArr = [
  ["E", "I"],
  ["S", "N"],
  ["T", "F"],
  ["J", "P"]
]

const reverseMBTI = (mbti) => {
  let arr = mbti.split('')
  let resultArr = [];
  arr.forEach((personality, index) => {
    const idx = MBTIArr[index].indexOf(personality)
    MBTIArr[index].splice(idx, 1)
  })
  console.log(MBTIArr[0]+MBTIArr[1]+MBTIArr[2]+MBTIArr[3])
}

  reverseMBTI(array[0])

  process.exit();
})