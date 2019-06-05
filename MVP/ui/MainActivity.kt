package com.example.applicaton.ui

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle

import com.example.applicaton.R
import com.example.applicaton.presenter.impl.DownloadPresenterImpl
import com.example.applicaton.view.IDownloadView

class MainActivity : AppCompatActivity(), IDownloadView {

    private val downloadPresenterImpl = DownloadPresenterImpl(this)

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        downloadPresenterImpl.download("https://www.baidu.com/")
    }

    override fun showProgressBar(show: Boolean) {

    }

    override fun showProcessProgressBar(progress: Int) {

    }

    override fun setView(result: String) {

    }

    override fun showFailedToast() {

    }
}
