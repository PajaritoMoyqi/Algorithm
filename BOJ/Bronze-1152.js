const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString();

const array = input.trim().split(' ');

if(array[0]==''){
  console.log(0);
}else{
  console.log(input.trim().split(' ').length);
}