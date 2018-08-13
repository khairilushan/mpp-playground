package com.khairilushan.mpp.datasource.network

import com.khairilushan.mpp.utils.ApplicationDispatcher
import io.ktor.client.HttpClient
import io.ktor.client.request.request
import io.ktor.http.HttpMethod
import io.ktor.http.URLProtocol
import kotlinx.coroutines.experimental.launch

abstract class NetworkService<T> {

    internal open val baseUrl = "api.github.com"

    internal open val requestBody: Any? = null

    internal open val headers: Map<String, List<String>> = mapOf()

    internal abstract val path: String

    internal abstract fun parse(json: String): T

    internal open val httpMethod = HttpMethod.Get

    private val client: HttpClient by lazy { HttpClient() }

    internal fun requestJson(params: Map<String, String>, completion: (T) -> Unit) {
        launch(ApplicationDispatcher) {
            val response: String = client.request {
                method = httpMethod
                requestBody?.let { body = it }
                url.apply {
                    protocol = URLProtocol.HTTPS
                    port = 443
                    host = baseUrl
                    val query = params.map { "${it.key}=${it.value}" }.joinToString("&")
                    encodedPath = "$path?$query"
                }
            }
            completion(parse(response))
        }
    }

}
