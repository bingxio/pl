--comment
print('hello' .. " lua!!")
print('3' + 3)

local tb = {'apple', 'pear', 'orange'}
print(tb)
print(#tb) -- length

tb['key'] = 'bingxio'
tb[20] = 34

print(#tb, tb[20], tb['pp'])

for k, v in pairs(tb) do
  print(k, v)
end

function fib(n)
  if n < 2 then
    return n
  else
    return fib(n - 1) + fib(n - 2)
  end
end

print(fib, fib(20) == 6765) -- true

function anyfn(fn)
  fn(2, 3)
end
anyfn(function(a, b)
  print(a, b, a * b)
end)

local x = 1
::lable:: print(x, 'goto lable')

x = x + 1
if x < 3 then
  goto lable
end

::foo:: do
  print('call')
end

--goto foo --deadloop

for i = 1, 3 do
  print('i = ', i)
end

local hgluc = 'the hgluc programming language'

print(
  string.upper(hgluc), 
  string.len(hgluc), 
  string.reverse(hgluc)
)

print('from module:')

local m = require('mod')
print(m.const)
m.fn()

--[[
  coroutine 协程
  与线程类似，拥有独立堆栈、变量、指令
  与其它协程共享数据
特殊的线程，可以暂停和恢复执行，从而允许非抢占式的多任务处理。
--]]

function foo()
  print('程序 foo 开始执行')

  local value = coroutine.yield('暂停 foo 执行')

  print('恢复 foo 执行，传入值为：' .. value)
  print('结束 foo 执行')
end

-- 创建协程
local co = coroutine.create(foo)

-- 启动协程
local status, result = coroutine.resume(co)
print(result) -- 输出：暂停 foo 执行

-- 恢复执行，并传入值
status, result = coroutine.resume(co, 32)
print(result) -- 输出：恢复 foo 执行，传入值为：32

co = coroutine.create(function(i)
  print(i)
end)

-- 启动，并传入参数 1
coroutine.resume(co, 1)
print(coroutine.status(co)) -- dead 已经执行完毕

-- 创建协程包装器，转换为一个可直接调用的函数
co = coroutine.wrap(function(i)
  print(i)
end)

co(1)
print('------')

co = coroutine.create(function()
  for i = 1, 10 do
    print(i)
    if i == 3 then
      print(coroutine.status(co))
      print(coroutine.running())
    end
    coroutine.yield()
  end
end)

coroutine.resume(co) -- 1
coroutine.resume(co) -- 2
coroutine.resume(co) -- 3

print(coroutine.status(co)) -- suspended 暂停执行
print(coroutine.running())

print('------')

function foo(x)
  print(x)
  return coroutine.yield(2 * x)
end

co = coroutine.create(function(a, b)
  print(a, b)
  local r = foo(a + 1)

  print(r)
  local r, s = coroutine.yield(a + b, a - b)

  print(r, s)
  return b
end)

print(coroutine.resume(co, 1, 10))
print(coroutine.resume(co, 'r'))
print(coroutine.resume(co, 'x', 'y'))
print(coroutine.resume(co, 'x', 'y'))
