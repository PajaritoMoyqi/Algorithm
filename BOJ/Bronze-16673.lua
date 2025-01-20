local C = io.read( "*n" )
local K = io.read( "*n" )
local P = io.read( "*n" )

local ans = 0
for i=1,C,1 do
  ans = ans + i*K + i*i*P
end

io.write( ans )