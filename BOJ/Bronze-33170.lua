local A, B, C = io.read( "*n", "*n", "*n" )
local ans = A+B+C

if ans <= 21 then
  io.write( 1 )
else
  io.write( 0 )
end