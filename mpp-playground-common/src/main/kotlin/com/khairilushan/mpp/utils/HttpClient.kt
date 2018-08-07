package com.khairilushan.mpp.utils

expect fun request(
    httpMethod: String,
    requestHeaders: Map<String, List<String>>,
    baseUrl: String,
    path: String,
    params: Map<String, String>,
    completion: (String) -> Unit
)
