local n = io.read( "*n" )

local ans = n // 5
ans = ans + n // 25
ans = ans + n // 125
io.write( ans )