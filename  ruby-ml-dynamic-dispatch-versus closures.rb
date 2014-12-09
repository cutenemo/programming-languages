# Dan Grossman - UW - Coursera
# Dynamic Dispatch Versus Closures

# in ML
fun even x = if x=0 then true else odd (x-1)
and odd x = if x=0 then false else even (x-1)
  
fun even x = (x mod 2) = 0

# the "even" definition is the one used in the odd function definition
# since closures use lexical scope, so "odd" can't benefit from the new definition

# in OOP, ruby for example
class A
  def even x
     if x==0 then true else odd(x-1) end
  end

def odd x
     if x==0 then false else even(x-1) end
end end

class B < A
  def even x # changes B’s odd too!
x % 2 == 0 end
end

# here can we benefit from the new "even" definiton since "even" is overriden in class B
# so odd will the new faster "even" method