package com.khairilushan.mpp.datasource.network.entity

import kotlinx.serialization.json.JsonObject

data class SearchProjectsEntity private constructor(
    var items: List<ProjectEntity> = listOf(),
    var total: Int? = null,
    var incompleteResults: Boolean? = null
) : Entity {
    companion object {
        fun create(jsonObject: JsonObject) = SearchProjectsEntity().also {
            it.parse(jsonObject)
        }
    }

    override fun parse(jsonObject: JsonObject) {
        total = jsonObject.getPrimitive("total_count").intOrNull
        incompleteResults = jsonObject.getPrimitive("incomplete_results").booleanOrNull
        items = jsonObject.getArray("items").content
            .map { it as JsonObject }
            .map { ProjectEntity.create(it) }
    }
}
