import time

def consumer():
    r = ''
    while True:
        n = yield r
        if not n:
            return
        print("[CONSUMER] Consuming %s..." % n)
        time.sleep(1)
        r = "200 OK"

def produce(c):
    c.__next__()
    n = 0
    while n < 5:
        n = n + 1
        print("[PRODUCER] Producing %s..." % n)
        r = c.send(n)
        print("[PRODUCER] Comsumer return: %s" % r)
    c.close()
    
c = consumer()
produce(c)
