local a, b = io.read( "*n", "*n" )

local sum = a + b
local sub = a - b

local min, max
if ( sum > sub ) then
  min = sub
  max = sum
else
  min = sum
  max = sub
end

io.write( max, "\n", min )