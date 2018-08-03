package com.khairilushan.mpp.datasource.network.entity

import kotlinx.serialization.json.JsonObject

interface Entity {
    fun parse(jsonObject: JsonObject)
}
