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

array.forEach((item, idx) => {
  if(idx === 0) return;

  const given = item.split(' ');
  const num1 = Number(given[0])
  const num2 = Number(given[1])

  switch(num1%10){
    case 0:
      console.log(10);
      break;
    case 1:
      console.log(1);
      break;
    case 2:
      if(num2%4===1) console.log(2)
      else if(num2%4===2) console.log(4)
      else if(num2%4===3) console.log(8)
      else if(num2%4===0) console.log(6)
      break;
    case 3:
      if(num2%4===1) console.log(3)
      else if(num2%4===2) console.log(9)
      else if(num2%4===3) console.log(7)
      else if(num2%4===0) console.log(1)
      break;
    case 4:
      if(num2%2===1) console.log(4)
      else if(num2%2===0) console.log(6)
      break;
    case 5:
      console.log(5);
      break;
    case 6:
      console.log(6);
      break;
    case 7:
      if(num2%4===1) console.log(7)
      else if(num2%4===2) console.log(9)
      else if(num2%4===3) console.log(3)
      else if(num2%4===0) console.log(1)
      break;
    case 8:
      if(num2%4===1) console.log(8)
      else if(num2%4===2) console.log(4)
      else if(num2%4===3) console.log(2)
      else if(num2%4===0) console.log(6)
      break;
    case 9:
      if(num2%2===1) console.log(9)
      if(num2%2===0) console.log(1)
  }
})
    
// 답안지 종료
  process.exit();
})