local pokemon_n, problem_n = io.read( "*n", "*n" )

local t = {}
local idx = 1
for i in string.gmatch( io.read( "*a" ), "%S+" ) do
  if idx <= pokemon_n then
    t[tostring(idx)] = i
    t[i] = idx
    idx = idx + 1
  else 
    io.write( t[i], "\n" )
  end
end