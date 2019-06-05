package com.example.applicaton.view

interface IDownloadView {

    fun showProgressBar(show: Boolean)

    fun showProcessProgressBar(progress: Int)

    fun setView(result: String)

    fun showFailedToast()
}