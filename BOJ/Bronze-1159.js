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

let nameObj = {}
array.forEach((name, idx)=> {
  if(idx===0) return;

  if(nameObj[name[0]]){
    nameObj[name[0]]++;
  }else{
    nameObj[name[0]] = 1;
  }
})

const keys = Object.keys(nameObj)
for(let i=0;i<keys.length;i++){
  if(nameObj[keys[i]]<5){
    delete nameObj[keys[i]];
  }
}

const finalStr = Object.keys(nameObj).sort().join('');
if(finalStr) console.log(finalStr)
else console.log('PREDAJA');
    
// 답안지 종료
  process.exit();
})