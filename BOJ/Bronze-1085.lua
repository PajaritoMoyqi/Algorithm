local dx1 = io.read( "*n" )
local dy1 = io.read( "*n" )
local mx = io.read( "*n" )
local my = io.read( "*n" )

local dx2 = mx - dx1
local dy2 = my - dy1

local min
if dx1 > dy1 then
  min = dy1
else
  min = dx1
end

if min > dx2 then
  min = dx2
end

if min > dy2 then
  min = dy2
end

io.write( min )