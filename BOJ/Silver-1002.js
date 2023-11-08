const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const num = parseInt(input[0]);
for(let i=1; i<num+1; i++){
  const x1 = input[i].split(' ').map(number => parseInt(number))[0];
  const y1 = input[i].split(' ').map(number => parseInt(number))[1];
  const r1 = input[i].split(' ').map(number => parseInt(number))[2];
  const x2 = input[i].split(' ').map(number => parseInt(number))[3];
  const y2 = input[i].split(' ').map(number => parseInt(number))[4];
  const r2 = input[i].split(' ').map(number => parseInt(number))[5];
  
  if(x1==x2 && y1==y2){
    if(r1==r2){
      console.log(-1);
    }else{
      console.log(0);
    }
  }else{
    if(Math.sqrt(Math.pow(x1-x2, 2)+Math.pow(y1-y2, 2)) < Math.abs(r1+r2)){
      if(Math.sqrt(Math.pow(x1-x2, 2)+Math.pow(y1-y2, 2)) < Math.abs(r1-r2)){
        console.log(0);
      }else if(Math.sqrt(Math.pow(x1-x2, 2)+Math.pow(y1-y2, 2)) == Math.abs(r1-r2)){
        console.log(1);
      }else if(Math.sqrt(Math.pow(x1-x2, 2)+Math.pow(y1-y2, 2)) > Math.abs(r1-r2)){
        console.log(2);
      }
    }else if(Math.sqrt(Math.pow(x1-x2, 2)+Math.pow(y1-y2, 2)) == Math.abs(r1+r2)){
      console.log(1);
    }else if(Math.sqrt(Math.pow(x1-x2, 2)+Math.pow(y1-y2, 2)) > Math.abs(r1+r2)){
      console.log(0);
    }
  }
}