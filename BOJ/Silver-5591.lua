local n, len = io.read( "*n", "*n" )

-- prefix sum table
local t = {}
for i=1,n,1 do
  local v = io.read( "*n" )

  if ( i == 1 ) then
    t[i] = v
  else
    t[i] = v + t[i-1]
  end
end

-- init
local max_sum = 0
for i=len,n,1 do
  if ( i == len ) then
    max_sum = t[i]
  else
    local sum = t[i] - t[i-len]
    if ( max_sum < sum ) then
      max_sum = sum
    end
  end
end

io.write( max_sum )