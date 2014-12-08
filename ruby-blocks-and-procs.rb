# Dan Grossman - UW - Coursera

# Blocks (second class expressions)
# - are not quite closures because they are not objects and can't be passed as regular arguments to a method
# - can be passed to other methods as anonymous functions 
# - can take 0 or more arguments
# - use lexical scope
# - It is also placed after any other “regular” arguments
# - can only be "yield", can't be stored, returned ... etc
# - The method body calls the block using the yield keyword
# - A method can use the block_given? primitive to see if the caller provided a block

# Example a block with no arguments
3.times { puts "hi" }

# Example of a block that takes an argument
sum = 0
[4,6,8].each do |x|
  sum += x
  puts sum 
end


# Proc Class (first class expressions)
# - The class Proc has instances that are closures
# - There is a function in the Object class called "lambda" that takes a block and returns a Proc!
# Example
a = [3, 5, 7, 9]
c = a.map { |x| {|y| x >= y} } # doesn't work with bocks
c = a.map { |x| (lambda {|y| x >= y}) } # works
# => [#<Proc:0x007fb263092c58@(irb):7 (lambda)>, #<Proc:0x007fb263092b90@(irb):7 (lambda)>,
#<Proc:0x007fb263092aa0@(irb):7 (lambda)>, #<Proc:0x007fb263092a50@(irb):7 (lambda)>]
#irb(main):011:0> c[1].call 4
#=> true
#irb(main):012:0> c[1].call 9
#=> false