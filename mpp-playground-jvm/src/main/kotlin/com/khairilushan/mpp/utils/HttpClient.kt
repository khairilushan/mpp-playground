package com.khairilushan.mpp.utils

import io.ktor.common.client.HttpClient
import io.ktor.common.client.http.HttpMethod
import io.ktor.common.client.http.URLProtocol
import io.ktor.common.client.request
import kotlinx.coroutines.experimental.launch

actual fun request(
    httpMethod: String,
    requestHeaders: Map<String, List<String>>,
    baseUrl: String,
    path: String,
    params: Map<String, String>,
    completion: (String) -> Unit
) {
    launch {
        val response = HttpClient().request {
            method = HttpMethod(httpMethod)
            headers = requestHeaders.toMutableMap()
            url.apply {
                protocol = URLProtocol.HTTPS
                port = 443
                host = baseUrl
                val query = params.map { "${it.key}=${it.value}" }.joinToString("&")
                encodedPath = "$path?$query"
            }
        }
        completion(response.body)
    }
}
