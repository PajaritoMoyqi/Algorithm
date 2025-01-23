local _ = io.read( "*n" )
local str = io.read( "*a" )
str = string.gsub(str, "%s+", "")

t = { ['a'] = true, ['e'] = true, ['i'] = true, ['o'] = true, ['u'] = true }

local cnt = 0
for c in str:gmatch"." do
  if ( t[c] ~= nil ) then
    cnt = cnt + 1
  end
end

io.write( cnt )