local pokemon_n, problem_n = io.read( "*n", "*n", "*l" )
local t = {}

for i=1,pokemon_n do
  local pokemon = io.read( "*l" )
  t[tostring(i)] = pokemon
  t[pokemon] = i
end

for _=1,problem_n do
  local p = io.read( "*l" )
  io.write( t[p], "\n" )
end