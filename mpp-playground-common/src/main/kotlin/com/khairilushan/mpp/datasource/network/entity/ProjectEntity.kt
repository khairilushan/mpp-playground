package com.khairilushan.mpp.datasource.network.entity

import com.khairilushan.mpp.model.Project
import kotlinx.serialization.SerialName
import kotlinx.serialization.Serializable

@Serializable
data class ProjectEntity(
  @SerialName("full_name") val fullName: String,
  val owner: Owner,
  @SerialName("description") val desc: String?,
  @SerialName("html_url") val htmlUrl: String
) {
  @Serializable
  data class Owner(
    val login: String,
    @SerialName("avatar_url") val avatarUrl: String
  )

  fun mapToProject() = Project(fullName, desc.orEmpty(), owner.login, owner.avatarUrl, htmlUrl)
}
