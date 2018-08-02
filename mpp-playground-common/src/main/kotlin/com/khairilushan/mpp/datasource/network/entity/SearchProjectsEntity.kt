package com.khairilushan.mpp.datasource.network.entity

import kotlinx.serialization.SerialName
import kotlinx.serialization.Serializable

@Serializable
data class SearchProjectsEntity(
    val items: List<ProjectEntity>,
    @SerialName("total_count") val total: Int,
    @SerialName("incomplete_results") val incompleteResults: Boolean
)
