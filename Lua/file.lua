file = io.open('note', 'a')
io.output(file) -- defaule output file

io.write('lua 123\n')

-- io.close(file)
file:close()
