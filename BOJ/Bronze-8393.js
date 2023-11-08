const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().split(' ');
var a = parseInt(input[0]);

let total=0;
for(let i=1;i<=a;i++){
  total += i;
}
console.log(total);