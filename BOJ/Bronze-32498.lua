local n = io.read( "*n" )

local cnt = 0
for i=1,n do
  local d = io.read( "*n" )

  if d % 2 == 1 then
    cnt = cnt + 1
  end
end

io.write( cnt )