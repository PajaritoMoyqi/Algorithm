d = io.read( "*n" )
res = d % 3
if res == 1 then
  io.write( "U" )
elseif res == 2 then
  io.write( "O" )
else
  io.write( "S" )
end