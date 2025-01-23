local n = io.read( "*n" )

local rest = n % 7
if ( rest == 2 ) then
  io.write( 1 )
else
  io.write( 0 )
end