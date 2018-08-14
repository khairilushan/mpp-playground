package com.khairilushan.mpp.viewmodel

import kotlinx.coroutines.experimental.Job

interface ViewModel {
    interface Inputs {
        fun onViewDestroyed()
        fun onViewCreated()
    }
}

abstract class BaseViewModel : ViewModel.Inputs {

    internal val job = Job()

    override fun onViewDestroyed() {
        job.cancel()
    }
}
