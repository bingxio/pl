const {app, BrowserWindow, Notification} = require('electron')

let win

function createWindow() {
  win = new BrowserWindow({
    width: 800,
    height: 600,
    webPreferences: {
      nodeIntegration: true
    }
  })

  win.loadFile('index.html')

  let notification = new Notification('title', {
    body: 'content'
  })
  notification.onclick = () => {
    console.log('click')
  }
  notification.show()

  win.setProgressBar(0.3)
}

app.on('ready', createWindow)
