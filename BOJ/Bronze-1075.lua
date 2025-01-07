local n = io.read( "*n" )
local f = io.read( "*n" )

local rest = n % 100
local new = n - rest
local start = n - rest

while( new - n < 100 )
do
  if ( new % f == 0 ) then
    break
  end
  new = new + 1
end

local ans = new - start

if ( ans < 10 ) then
  io.write( '0' )
  io.write( ans )
else
  io.write( ans )
end