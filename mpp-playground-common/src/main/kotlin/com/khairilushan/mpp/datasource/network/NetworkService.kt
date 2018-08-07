package com.khairilushan.mpp.datasource.network

import com.khairilushan.mpp.utils.request
import io.ktor.common.client.HttpClient
import io.ktor.common.client.http.HttpMethod
import io.ktor.common.client.http.URLProtocol

abstract class NetworkService<T> {

    open val protocol = URLProtocol.HTTPS

    open val port = 443

    open val baseUrl = "api.github.com"

    open val httpMethod = HttpMethod.Get

    open val requestBody: String? = null

    open val headers: Map<String, List<String>> = mapOf()

    abstract val path: String

    abstract fun parse(json: String): T

    val client: HttpClient by lazy { HttpClient() }

    internal fun requestJson(params: Map<String, String>, completion: (T) -> Unit) {
        request(
            httpMethod = httpMethod.value,
            requestHeaders = headers,
            baseUrl = baseUrl,
            path = path,
            params = params,
            completion = {
                completion(parse(it))
            })
    }

}
