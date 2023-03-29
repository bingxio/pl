let dot = () => {
  let colors = ['red', 'orange', 'pink', 'grey', 'blue', 'purple']
  let stars = 300

  for (let i = 0; i < stars; i++) {
    let size = Math.random() * 4
    let color = colors[parseInt(Math.random() * 6)]
    $('#box').prepend(
      '<span style=" width: ' +
        size +
        'px; height: ' +
        size +
        'px; top: ' +
        Math.random() * 100 +
        '%; left: ' +
        Math.random() * 100 +
        '%; background: ' +
        color +
        '; box-shadow: 0 0 ' +
        Math.random() * 10 +
        'px' +
        color +
        ';"></span>',
    )
  }

  setTimeout(function () {
    $('#box span').each(function () {
      $(this)
        .css('top', Math.random() * 100 + '%')
        .css('left', Math.random() * 100 + '%')
    })
  }, 1)

  setInterval(function () {
    $('#box span').each(function () {
      $(this)
        .css('top', Math.random() * 100 + '%')
        .css('left', Math.random() * 100 + '%')
    })
  }, 100000)
}

setTimeout(() => dot(), 26000)
