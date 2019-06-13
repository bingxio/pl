
import json

a = input('please input your name: ')
b = input('please input your pass: ')

if len(a) == 0 or len(b) == 0:
    print('illegal parameters.'), exit(64)

data = {
    'code': 200,
    'message': 'OK',
    'data': {
        'username': a,
        'password': b
    }
}

print(json.dumps(data, indent=4))
