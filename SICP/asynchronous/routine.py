import asyncio
import random

async def produce(queue, n):
  for item in range(n):
    print('P item {} ->'.format(item))
    await asyncio.sleep(random.random())
    await queue.put(item)
  await queue.put(None)

async def consume(queue):
  while True:
    item = await queue.get()
    if item is None:
      break
    print('C item {} <-'.format(item))
    await asyncio.sleep(random.random())

async def main():
  queue = asyncio.Queue()
  
  task1 = asyncio.create_task(produce(queue, 10))
  task2 = asyncio.create_task(consume(queue))

  await task1
  await task2

asyncio.run(main())