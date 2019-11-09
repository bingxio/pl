let login = async (username, password) => {
  return username != '' && password != ''
}

let test = async () => {
  await login('turaiiao', '12345678').then((data) => {
    if (data) {
      console.log('Login successfully !')
    }
  })
}

test(); 
