local X, L, R = io.read( "*n", "*n", "*n" )

if X <= L then
  io.write( L )
elseif R <= X then
  io.write( R )
else
  io.write( X )
end