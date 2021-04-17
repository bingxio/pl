import time
import asyncio

async def exec() -> int:
  time.sleep(3)
  print("DONE.")
  return 1
  
async def main():
  print("START!!")
  print("END %d" % await exec())

asyncio.run(main())