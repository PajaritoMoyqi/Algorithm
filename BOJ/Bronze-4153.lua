while true
do
  local a = io.read( "*n" )
  local b = io.read( "*n" )
  local c = io.read( "*n" )
  if ( a == 0 and b == 0 and c == 0 ) then
    break
  end

  local a2 = a*a
  local b2 = b*b
  local c2 = c*c

  if ( a2 + b2 == c2 or a2 + c2 == b2 or c2 + b2 == a2 ) then
    io.write( "right\n" )
  else
    io.write( "wrong\n" )
  end
end