package com.khairilushan.mpp.datasource.network

import io.ktor.common.client.HttpClient
import io.ktor.common.client.http.HttpMethod
import io.ktor.common.client.http.URLProtocol
import io.ktor.common.client.promise
import io.ktor.common.client.request
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
    params: Map<String, String>,
    crossinline completion: (ResultType?, Throwable?) -> Unit
  ) {
    request(params) { result: String?, error: Throwable? ->
      if (result != null && error == null) {
        completion(JSON.nonstrict.parse(result), null)
      } else if (error != null) {
        completion(null, error)
      }
    }
  }

  inline fun request(
    params: Map<String, String>,
    crossinline completion: (String?, Throwable?) -> Unit
  ) {
    promise {
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
    }.then {
      completion(it.body, null)
    }.catch {
      completion(null, it)
    }
  }

}
