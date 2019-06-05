package com.example.applicaton.model.impl

import com.example.applicaton.model.IDownloadModel
import com.example.applicaton.presenter.IDownloadPresenter

class DownloadModelImpl (private val iDownloadPresenter: IDownloadPresenter) : IDownloadModel {

    override fun download(url: String) {
        iDownloadPresenter.downloadSuccess("OK")
    }
}
