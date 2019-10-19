import asyncio

async def generator():
  await asyncio.sleep(1000)
  # Return a value.
  yield 50
