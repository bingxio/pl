
from enum import Enum, unique

class ErrorCode(Enum):
    UsernameIncorrect = 'username incorrect'
    PasswordIncorrect = 'password incorrect'
    
    Success = 'login successfully'

class User:
    def __init__(self, username, password):
        self.username = username
        self.password = password
        
    def validate(self, username, password):
        if self.username != username:
            return ErrorCode.UsernameIncorrect
        elif self.password != password:
            return ErrorCode.PasswordIncorrect
        else:
            return ErrorCode.Success

if __name__ == '__main__':
    a = User('turaiiao', password)
    
    username = input('please input your name: ')
    password = input('please input your pass: ')
    
    b = a.validate(username, password)
    
    print(b.value)
