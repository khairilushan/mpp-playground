package com.khairilushan.mpp.datasource.network

import io.ktor.common.client.HttpClient
import io.ktor.common.client.HttpResponse
import io.ktor.common.client.http.HttpMethod
import io.ktor.common.client.http.URLProtocol
import io.ktor.common.client.request
import kotlinx.coroutines.experimental.Deferred
import kotlinx.coroutines.experimental.async
import kotlinx.serialization.json.JSON

abstract class NetworkService {

    open val protocol = URLProtocol.HTTPS

    open val port = 443

    open val baseUrl = "api.github.com"

    open val httpMethod = HttpMethod.Get

    open val requestBody: String? = null

    open val headers: Map<String, List<String>> = mapOf()

    abstract val path: String

    val client: HttpClient by lazy { HttpClient() }

    inline fun <reified ResultType : Any> requestJson(
        params: Map<String, String>
    ): Deferred<ResultType> = async {
        val response = request(params).await()
        JSON.nonstrict.parse<ResultType>(response.body)
    }

    fun request(
        params: Map<String, String>
    ): Deferred<HttpResponse> = async {
        client.request {
            method = httpMethod
            body = requestBody
            headers = this@NetworkService.headers.toMutableMap()
            url.apply {
                protocol = this@NetworkService.protocol
                port = this@NetworkService.port
                host = baseUrl
                val query = params.map { "${it.key}=${it.value}" }.joinToString("&")
                encodedPath = "$path?$query"
            }
        }
    }

}
