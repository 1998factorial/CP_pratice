import asyncio
import aiohttp
import time
import urllib.request
import ssl
from concurrent.futures import ThreadPoolExecutor

ssl._create_default_https_context = ssl._create_unverified_context

sites = [
    'https://www.yahoo.com',
    'https://www.google.com',
    'https://www.python.org',
    'https://www.apple.com',
    'https://www.kernel.org',
]

executor = ThreadPoolExecutor(max_workers=10)

def get_site_size(url):
    t = time.time()
    with urllib.request.urlopen(url) as u:
        page = u.read()
        return t,url,len(page)

async def solve(loop):
    tasks = []
    for url in sites:
        tasks.append(loop.run_in_executor(executor,get_site_size,url))
    for r in await asyncio.gather(*tasks):
        print(r)

loop = asyncio.get_event_loop()
loop.run_until_complete(solve(loop))


