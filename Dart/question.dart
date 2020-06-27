showItemClickDialog(MerchantEntity entity) {
    List<Widget> itemWidgets = [];

    List<Color> titleColors = [];

    Function callState;

    for (int i = 0; i < entity.item.length; i++) {
      titleColors.add(Colors.black);
    }

    for (int i = 0; i < entity.item.length; i++) {
      itemWidgets.add(Padding(
        padding: EdgeInsets.only(top: 10),
        child: Row(
          mainAxisAlignment: MainAxisAlignment.spaceBetween,
          children: <Widget>[
            Row(
              crossAxisAlignment: CrossAxisAlignment.center,
              children: <Widget>[
                Text('0', style: TextStyle(fontSize: ScreenUtil().setSp(20))),
                Padding(padding: EdgeInsets.only(left: 10)),
                Text(entity.item[i].title,
                    style: TextStyle(
                        fontSize: ScreenUtil().setSp(23),
                        color: titleColors[i]))
              ],
            ),
            Row(children: <Widget>[
              InkWell(
                  onTap: () {
                    callState(() {
                      titleColors[i] = Colors.blue;
                    });
                  },
                  child: Icon(Icons.add, size: 12, color: Colors.grey)),
              Padding(padding: EdgeInsets.only(left: 10)),
              InkWell(
                  onTap: () {},
                  child: Icon(Icons.remove, size: 12, color: Colors.grey))
            ])
          ],
        ),
      ));
    }

    itemWidgets.add(
      Container(
        height: 50,
        child: Material(
          shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(8)),
          color: Colors.white,
          child: InkWell(
            onTap: () {},
            child: Row(
              mainAxisAlignment: MainAxisAlignment.spaceBetween,
              children: <Widget>[
                Container(
                    margin: EdgeInsets.all(15),
                    child: RichText(
                      text: TextSpan(
                          text: '¥ ',
                          style: TextStyle(
                              color: Colors.red,
                              fontSize: ScreenUtil().setSp(30),
                              fontWeight: FontWeight.bold),
                          children: [
                            TextSpan(
                                text: 34.23.toStringAsFixed(1),
                                style: TextStyle(
                                    color: Colors.red,
                                    fontSize: ScreenUtil().setSp(35),
                                    fontWeight: FontWeight.bold))
                          ]),
                    )),
                Container(
                  margin: EdgeInsets.all(12),
                  child: FlatButton(
                      child: Text('完成',
                          style: TextStyle(
                              color: Colors.white,
                              fontSize: ScreenUtil().setSp(28))),
                      onPressed: () {},
                      shape: RoundedRectangleBorder(
                          borderRadius: BorderRadius.circular(3)),
                      color: Colors.red),
                )
              ],
            ),
          ),
        ),
      ),
    );

    showDialog(
        context: context,
        builder: (_) {
          return StatefulBuilder(builder: (ctx, state) {
            callState = state;

            return AlertDialog(
              shape: RoundedRectangleBorder(
                  borderRadius: BorderRadius.circular(8)),
              contentPadding: EdgeInsets.all(8),
              content: SingleChildScrollView(
                  child: Column(
                      mainAxisAlignment: MainAxisAlignment.spaceBetween,
                      children: itemWidgets)),
            );
          });
        });
  }
