package com.khairilushan.mpp.interactor


sealed class Result<T>
data class Success<T>(val result: T) : Result<T>()
data class Failure<T>(val errorCode: Int, val message: String) : Result<T>()

interface RequestParams {
  fun build(): Map<String, String>
}

abstract class Interactor<P: RequestParams, R> {

  abstract fun build(params: P? = null, completion: (Result<R>) -> Unit)

  fun execute(params: P? = null, completion: (Result<R>) -> Unit) {
    build(params) {
      completion(it)
    }
  }
}
