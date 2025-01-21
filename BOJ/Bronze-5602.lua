local student_n = io.read( "*n" )
local candidate_n = io.read( "*n" )

-- initialization of table
T = {}
for i=1,candidate_n,1 do
  table.insert( T, { idx = i, value = 0 } )
end

for i=1,student_n,1 do
  for j=1,candidate_n,1 do
    local vote = io.read( "*n" )
    if ( vote == 1 ) then
      T[j].value = T[j].value + 1
    end
  end
end

table.sort( T, function( a, b )
  return
    a.value > b.value or
    (a.value == b.value and a.idx < b.idx)
end )

for i,v in ipairs( T ) do
  io.write( T[i].idx, " " )
end