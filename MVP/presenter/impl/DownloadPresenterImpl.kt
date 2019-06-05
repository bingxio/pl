package com.example.applicaton.presenter.impl

import com.example.applicaton.model.impl.DownloadModelImpl
import com.example.applicaton.presenter.IDownloadPresenter
import com.example.applicaton.view.IDownloadView

class DownloadPresenterImpl (private val iDownloadView: IDownloadView) : IDownloadPresenter {

    private val downloadModelImpl = DownloadModelImpl(this)

    override fun download(url: String) {
        iDownloadView.showProgressBar(true)

        downloadModelImpl.download(url)
    }

    override fun downloadSuccess(result: String) {
        iDownloadView.showProgressBar(false)
        iDownloadView.setView(result)
    }

    override fun downloadProgress(progress: Int) {
        iDownloadView.showProcessProgressBar(progress)
    }

    override fun downloadFailed() {
        iDownloadView.showProgressBar(false)
        iDownloadView.showFailedToast()
    }
}