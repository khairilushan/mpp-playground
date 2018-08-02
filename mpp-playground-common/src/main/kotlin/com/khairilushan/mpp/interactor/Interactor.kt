package com.khairilushan.mpp.interactor

import kotlinx.coroutines.experimental.Deferred
import kotlinx.coroutines.experimental.Job
import kotlinx.coroutines.experimental.launch
import kotlinx.coroutines.experimental.withContext
import kotlin.coroutines.experimental.CoroutineContext


sealed class Result<T>
data class Success<T>(val result: T) : Result<T>()
data class Failure<T>(val errorCode: Int, val message: String) : Result<T>()

interface RequestParams {
    fun build(): Map<String, String>
}

abstract class Interactor<P : RequestParams, R>(
    private val preExecutionContext: CoroutineContext,
    private val postExecutionContext: CoroutineContext
) {

    private val job = Job()

    abstract fun build(params: P? = null): Deferred<R>

    fun execute(params: P? = null, completion: (Result<R>) -> Unit) {
        launch(preExecutionContext + job) {
            try {
                val result = build(params).await()
                withContext(postExecutionContext) { completion(Success(result)) }
            } catch (error: Throwable) {
                withContext(postExecutionContext) {
                    completion(Failure(error.hashCode(), error.message.orEmpty()))
                }
            }
        }
    }
}
