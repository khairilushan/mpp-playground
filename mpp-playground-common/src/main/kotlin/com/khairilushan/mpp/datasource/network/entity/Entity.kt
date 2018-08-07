package com.khairilushan.mpp.datasource.network.entity

import kotlinx.serialization.json.JsonObject

internal interface Entity {
    fun parse(jsonObject: JsonObject)
}
