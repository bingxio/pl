if __name__ == '__main__':
  print('The `yield` keyword for python language...')

  def generate ():
    for i in range(10):
      yield i * 4

  for i in generate():
    print('value = %d' % i)

  a = generate()

  while True:
    try:
      print(next(a))
    except StopIteration:
      print('Will break...')
      break
