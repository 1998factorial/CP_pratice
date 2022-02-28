import asyncio
import aiohttp
import time

sites = [
    'https://www.yahoo.com',
    'https://www.google.com',
    'https://www.python.org',
    'https://www.apple.com',
    'https://www.kernel.org',
]

loop = asyncio.get_event_loop()

async def site_size(url):
    t = time.time()
    async with aiohttp.ClientSession(connector=aiohttp.TCPConnector(ssl=False)) as session:
        async with session.get(url) as u:
            page = await u.text()
            return t , url , len(page)

async def solve():
    ret = await asyncio.gather(*[site_size(url) for url in sites])
    for r in ret:
        print(r)

asyncio.get_event_loop().run_until_complete(solve())


"""
we are using create_task() here, so we will send each task to the 
background and they will be processed paralelly
"""