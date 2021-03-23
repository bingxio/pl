print('Hello World')

-- Hello World

--[[

    A
    B
    C

]]

x = 10
print(x, 123, 456)

x = nil
print('x = nil?', x == nil)

print(type('Hello World!!'))
print(type(10 * 3.5 + 0.1))
print(type(print))
print(type(true))
print(type(nil))
print(type(X))

x = {
    name = 'bingxio',
    data = {
        age = 19,
        sex = 'Man'
    }
}

print(type(x))

for k, v in pairs(x) do
    print(k, v)
    if type(v) == 'table' then
        print('TABLE!!')
    end
end

x = 'my name is'
y = ' bingxio!!'

print(x .. y)
print(#x, #(y .. 'haha..'))

tb = {'apple', 'orange', 'red'}
tb[5] = 'pink'

for k, v in pairs(tb) do
    print(k, v)
end

function foo(n)
    if n == 0 then
        return 1
    else
        return n * foo(n - 1)
    end
end

print(foo(5))
x = foo
print(x(5))

a = 88
while a >= 66
do
    print(a)
    a = a - 1
end

print()

for i = 10, -10, -2 do
    print(i)
end

function max(x, y)
    if x > y then
        return x
    else
        return y
    end
end

print(
    max(34, 12), 
    max(56, 88)
)

arr = {'google', 'apple'}

function elementIterator(collection)
    local index = 0
    local count = #collection
    return function()
        index = index + 1
        if index <= count then
            return collection[index]
        end
    end
end

table.sort(arr)

for element in elementIterator(arr) do
    print(element)
end
