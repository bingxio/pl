const {app, BrowserWindow} = require('electron')
const ipc = require('electron').ipcMain

let win

ipc.on('add', () => {
  console.log('button clicked !')
})

function createWindow() {
  win = new BrowserWindow({
    width: 800,
    height: 600,
    webPreferences: {
      nodeIntegration: true
    },
    frame: false
  })
  
  win.loadFile('index.html')
}

app.on('ready', createWindow)
