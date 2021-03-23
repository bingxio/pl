print('Hello World!!')

x = 30
y = 23

local z, p = 12, 'OK!!'

tb = {name = 'bingxio', data = {age = 19, sex = 'Man'}}
print(tb.name, tb.data.age, tb.data.sex)

Account = {balance = 0}

function Account.withdraw(v)
    Account.balance = Account.balance - v
end

Account.withdraw(89.24)
print(Account.balance)

Rectangle = {area = 0, length = 0, breadth = 0}

function Rectangle:new(o, length, breadth)
    o = o or {}
    setmetatable(o, self)
    self.__index = self
    self.length = length or 0
    self.breadth = breadth or 0
    self.area = length * breadth
    return o
end

function Rectangle:printArea()
    print('-> ', self.area)
end

r = Rectangle:new(nil, 10, 20)
print(r.length, r.breadth)

r:printArea()
