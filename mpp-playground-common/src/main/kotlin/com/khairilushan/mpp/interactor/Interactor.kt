package com.khairilushan.mpp.interactor


sealed class Result<T>
data class Success<T>(val result: T) : Result<T>()
data class Failure<T>(val errorCode: Int, val message: String) : Result<T>()

abstract class Interactor<Params, R> {

  abstract fun build(params: Params? = null, completion: (Result<R>) -> Unit)

  fun execute(params: Params? = null, completion: (Result<R>) -> Unit) {
    build(params) {
      completion(it)
    }
  }
}
