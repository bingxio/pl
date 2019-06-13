
# Basic lambda function.
a = lambda a, b, c: a + b + c

# The lambda function has no input parameters and the output is None.
b = lambda: None

# Lambda function with uncertain parameters.
c = lambda *args: max(args)

# And other statements.
d = lambda a, b: a if a < b else b

if __name__ == '__main__'
    print('12 + 43 + 1 = %d' % a(12, 43, 1))
    print(b())
    print('max (12, -23) = %d' % c(12, -23))
    print('min (12, -23) = %d' % d(12, -23))

    list = []
	
    for i in range(0, 20):
        list.append(i)
		
    print(list)
	
    a = filter(lambda x: x % 2 == 0, list)
    b = map(lambda x: x + 5, a)
	
    print(a)
    print(b)
