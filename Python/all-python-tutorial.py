# Hello ! This is python tutorial.
# The python language is built in c language and it is use bytecode to interpreter.
# The python has more than 20 years old that new version is 3.7.4 stable.
# This tutorial explain python basic syntax and some details.

# The function must be define before use.
def func():
  print('function was called !!')

# Has parameter and return value for function.
# We can specify return type use `->` operator at Python 3.x
def add(x, y) -> int:
  if x <= 0 or y <= 0:
    return -1
  return x + y

# The second parameter have default value that we can also specify it at call.
def show(name, age=17):
  print('name = %s age = %d' % (name, age))

# This function first parameter is a array type,
# We append a char of `sep` in list iterator.
def concat(*args, sep='/') -> str:
  return sep.join(args)

# Define a class data.
class User:
  # First class constructor initializtion.
  def __init__(self, name, age, sex):
    self.name = name
    self.age = age
    self.sex = sex
  # The method of parent class.
  def hello(self) -> bool:
    return self.age > 10

if __name__ == "__main__":
  # If current module is `__main__` and start at there.
  # It's so easy to define a variable
  a = 23
  # The string literal can use single quotation mark anywhere.
  # Also you can use double quotation mark but i like single mode.
  b = 'Hello Python !!'
  # We can use backslash to string escaping.
  c = 'doesn\'t'
  # Output expression to screen and default have a line feed.
  print(a, b, c)
  # If I don't need line feed that I can add `end=` parameter to `print` function.
  print(a, b, c, end='')
  print('\t Now in the previous line !!')
  # Some times I want output a path and it have escaping char,
  # We can add `r` char before the quote.
  path = r'C:\\Users\\Turaiiao\\Desktop'
  print(path)
  # Output many lines.
  print('''
    Hello, My name is turaiiao, i am from china. \n
    I like programming language it is beautiful !!
  ''')
  # It is interesting to output three hello.
  print(3 * 'hello ' + 'python')
  # And slice can used by string.
  print(b[0:5])
  # The cursor index can used by string.
  print(b[0])
  # Array.
  list = [1, 2, 3, 4, 5, 6]
  # Output start and end of list item.
  print(list[0], list[-1])
  # Append a list.
  list += [7, 8, 9]
  # And use native function.
  list.append(10)
  chars = ['a', 'b', 'c', 'd', 'e']
  # We can nesting two lists.
  nest = [list, chars]
  print(nest)
  # Loops.
  # Can define two variable just one line.
  a1, b1 = 1, 1
  # This can output fibonacci numbers less than 20.
  while a1 < 20:
    print(a1)
    # This is two variable change value.
    a1, b1 = b1, a1 + b1
  # And list iterator.
  for i in list:
    # Output even numbers of list item.
    if i % 2 == 0:
      print(i, end=' ')
  # The native function `range` it is very easy to use.
  # It has three parameter.
  # First is start and second it stop number size.
  # Third is skip number size.
  for i in range(0, 50, 2):
    # Output between 0 and 50 it is even number.
    print(i, end=' ')
  a = 12
  b = 13
  # The flow control syntax.
  if a > b:
    print('a greater than b.')
  elif a < b:
    print('a less than b.')
  else:
    print('i dont known.')
  # The dead loop.
  while True:
    if a < 0:
      # Use `break` keyword to exit.
      break
    a -= 1
    # This line just explain use `continue` keyword.
    continue
  print('a = %d' % a)
  if 1 + 1 == 2:
    # We can use `pass` keyword to do nothing.
    pass
  # Call defined function.
  func()
  # Return two numbers sum.
  print('23 + 55 = %d' % add(23, 55))
  print('23 + -5 = %d' % add(23, -5))
  # Call function without some parameters.
  show('turaiiao')
  # apple/orange/banana
  print(concat('apple', 'orange', 'banana'))
  # apple.orange.banana
  print(concat('apple', 'orange', 'banana', sep='.'))
  # Define a map.
  a =[(1, 'a'), (2, 'b'), (3, 'c')]
  # We can use list type as map type.
  print(a[1][0], a[1][1])
  # The lambda expression for python language.
  a = lambda a, b, c: a + b + c
  b = lambda *args: max(args)
  c = lambda a, b: a if a < b else b
  print(a(3, 4, 5))
  print(b(23, 22, 12, 55))
  print(c(34, 11))
  # Define a class data.
  a = User('turaiiao', 17, 'male')
  if a.age > 10:
    print(a.name, a.sex)
