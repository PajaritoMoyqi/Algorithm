var fs = require('fs');
var array = fs.readFileSync('/dev/stdin').toString().trim().split('\n').map(str => Number(str));
array.shift();
array.sort(function(a,b){return a-b});
console.log(array.join("\n"));