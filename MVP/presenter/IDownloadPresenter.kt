package com.example.applicaton.presenter

interface IDownloadPresenter {

    fun download(url: String)

    fun downloadSuccess(result: String)

    fun downloadProgress(progress: Int)

    fun downloadFailed()
}