local max = 12
local T = {}
local Ans = {}

-- 3 hanoi answer table
for i=1,max,1 do
  T[i] = 1
  local a = i
  while ( a > 0 ) do
    T[i] = T[i] * 2
    a = a - 1
  end

  T[i] = T[i] - 1
end

for i=1,max,1 do
  if ( i == 1 ) then
    Ans[i] = T[i]
    print( Ans[i] )
    goto continue
  end

  local min = 1000000000
  for j=1,i,1 do
    local candidate
    if ( i == j ) then
      candidate = T[j]
    else
      candidate = T[j] + 2*Ans[i-j]
    end

    if ( min > candidate ) then
      min = candidate
    end
  end
  Ans[i] = min
  print( Ans[i] )

  ::continue::
end