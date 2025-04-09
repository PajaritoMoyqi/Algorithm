local n = io.read( "*n" )
local rest = n % 2

local ans = n//2 + rest*3

io.write( ans )