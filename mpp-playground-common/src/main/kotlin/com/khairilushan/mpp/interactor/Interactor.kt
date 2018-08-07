package com.khairilushan.mpp.interactor

@Suppress("unused")
sealed class Result<out T : Any> {
    data class Success<T : Any>(val result: T) : Result<T>()
    data class Failure(val errorCode: Int, val message: String) : Result<Nothing>()
}

interface RequestParams {
    fun build(): Map<String, String>
}

abstract class Interactor<P : RequestParams, R : Any> {

    abstract fun build(params: P? = null, completion: (Result<R>) -> Unit)

    fun execute(params: P? = null, completion: (Result<R>) -> Unit) {
        build(params, completion)
    }
}
