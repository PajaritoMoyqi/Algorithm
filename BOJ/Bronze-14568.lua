local total = io.read( "*n" )

if ( total < 6 ) then
  io.write( 0 )
  return
end

local m = 2
local cnt = 0
while ( m < total ) do
  local left = total - m
  if ( left < 4 ) then
    break
  end

  if ( left % 2 == 1 ) then
    cnt = cnt + (left-3)/2
  else
    cnt = cnt + (left-2)/2
  end

  m = m + 2
end

io.write( cnt )