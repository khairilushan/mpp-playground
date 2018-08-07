package com.khairilushan.mpp.utils

import platform.Foundation.*
import platform.darwin.*
import kotlinx.cinterop.*
import kotlinx.cinterop.ByteVar

actual fun request(
    httpMethod: String,
    requestHeaders: Map<String, List<String>>,
    baseUrl: String,
    path: String,
    params: Map<String, String>,
    completion: (String) -> Unit
) {
    val delegate = object : NSObject(), NSURLSessionDataDelegateProtocol {
        val receivedData = NSMutableData()

        override fun URLSession(
            session: NSURLSession,
            dataTask: NSURLSessionDataTask,
            didReceiveData: NSData
        ) {
            receivedData.appendData(didReceiveData)
        }

        override fun URLSession(
            session: NSURLSession,
            task: NSURLSessionTask,
            didCompleteWithError: NSError?
        ) {
            task.response ?: return
            completion(receivedData.toKtString())
        }
    }
    val url = NSURL(string = createUrlString(baseUrl, path, params))
    val session = NSURLSession.sessionWithConfiguration(
        NSURLSessionConfiguration.defaultSessionConfiguration(),
        delegate,
        delegateQueue = NSOperationQueue.mainQueue()
    )
    session.dataTaskWithURL(url = url).resume()
}

private fun createUrlString(baseUrl: String, path: String, params: Map<String, String>): String {
    val query = params.map { "${it.key}=${it.value}" }.joinToString("&")
    return "https://$baseUrl$path?$query"
}

fun NSData.toKtString(): String =
    NSString.stringWithUTF8String(this.bytes!!.reinterpret<ByteVar>()).toString()
