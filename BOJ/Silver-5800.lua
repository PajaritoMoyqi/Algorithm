local class_n = io.read( "*n" )

for i=1,class_n,1 do
  io.write( "Class ", i, "\n" )

  local len = io.read( "*n" )
  local t = {}
  for score in string.gmatch( io.read( "*l" ), "%S+" ) do
    table.insert( t, tonumber( score ) )
  end

  table.sort( t )
  local min, max, diff, prev, len
  local max_diff = 0
  for idx,val in ipairs( t ) do
    if ( idx == 1 ) then
      min = val
    else
      diff = val - prev
      if ( max_diff < diff ) then
        max_diff = diff
      end
    end

    prev = val
  end
  max = prev

  io.write( "Max ", max, ", Min ", min, ", Largest gap ", max_diff, "\n" )
end