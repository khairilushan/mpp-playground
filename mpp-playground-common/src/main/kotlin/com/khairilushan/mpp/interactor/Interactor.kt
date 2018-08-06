package com.khairilushan.mpp.interactor

import kotlinx.coroutines.experimental.Deferred
import kotlinx.coroutines.experimental.Job
import kotlinx.coroutines.experimental.launch
import kotlinx.coroutines.experimental.withContext
import kotlin.coroutines.experimental.CoroutineContext

@Suppress("unused")
sealed class Result<out T : Any> {
    data class Success<T : Any>(val result: T) : Result<T>()
    data class Failure(val errorCode: Int, val message: String) : Result<Nothing>()
}

interface RequestParams {
    fun build(): Map<String, String>
}

abstract class Interactor<P : RequestParams, R: Any>(
    private val executionContext: CoroutineContext,
    private val postExecutionContext: CoroutineContext
) {

    private val job = Job()

    abstract fun build(params: P? = null): Deferred<R>

    fun execute(params: P? = null, completion: (Result<R>) -> Unit) {
        launch(executionContext + job) {
            try {
                val result = build(params).await()
                withContext(postExecutionContext) { completion(Result.Success(result)) }
            } catch (error: Throwable) {
                withContext(postExecutionContext) {
                    completion(Result.Failure(error.hashCode(), error.message.orEmpty()))
                }
            }
        }
    }
}
