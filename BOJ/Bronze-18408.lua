local A, B, C = io.read( "*n", "*n", "*n" )

local N1 = 0
local N2 = 0

if A == 1 then
  N1 = N1 + 1
else
  N2 = N2 + 1
end

if B == 1 then
  N1 = N1 + 1
else
  N2 = N2 + 1
end

if C == 1 then
  N1 = N1 + 1
else
  N2 = N2 + 1
end

if N1 > N2 then
  io.write( 1 )
else
  io.write( 2 )
end