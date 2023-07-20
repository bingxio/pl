-- 生产者与消费者
local newproductor

function productor()
  local i = 0
  while true do
    i = i + 1
    send(i) -- 将物品发送给消费者
  end
end

function consumer()
  while true do
    local i = receive() -- 得到物品
    print(i)
  end
end

function receive()
  local status, value = coroutine.resume(newproductor)
  return value
end

function send(x)
  coroutine.yield(x) -- 发送的值，返回以后挂起该程序
end

-- 启动程序
newproductor = coroutine.create(productor)
consumer()

--[[

具有多个线程的程序可以同时运行几个线程，协程则需要彼此协作运行。
在任意时刻只有一个协程在运行，并且只有在明确挂起的时候才会被挂起。
协程类似于同步的多线程，在等待同一个线程锁的几个线程类似协程。

调度：线程由操作系统的调度器进行抢占式调度，协程由程序控制执行权的转移。
并发：线程是并发执行，多多线程可运行在多核心处理器上，
      或者通过时间片在单核心上切换执行，协程是协作式的，只有一个协程处于
      运行状态，其它协程必须等待当前协程放弃执行权。
内存：线程需要独立堆栈和上下文，协程具有相同堆栈和上下文
数据：线程共享内存空间，有安全和同步问题，协程通过参数传递、返回值
      数据隔离性较好。
--]]
