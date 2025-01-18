local k = io.read( "*n" )

for i = 1,100,1 
do 
  if ( 1 + i + i*i == k ) then
    io.write( i )
    break
  end
end