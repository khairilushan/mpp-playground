package com.khairilushan.mpp.datasource.network.entity

import com.khairilushan.mpp.model.Project
import kotlinx.serialization.json.JsonObject

internal data class ProjectEntity private constructor(
    var fullName: String? = null,
    var owner: Owner? = null,
    var desc: String? = null,
    var htmlUrl: String? = null
) : Entity {

    data class Owner private constructor(
        var login: String? = null,
        var avatarUrl: String? = null
    ) : Entity {
        companion object {
            fun create(jsonObject: JsonObject) = Owner().also {
                it.parse(jsonObject)
            }
        }

        override fun parse(jsonObject: JsonObject) {
            login = jsonObject.getPrimitive("login").contentOrNull.orEmpty()
            avatarUrl = jsonObject.getPrimitive("avatar_url")
                .contentOrNull.orEmpty()
        }
    }

    companion object {
        fun create(jsonObject: JsonObject) = ProjectEntity().also {
            it.parse(jsonObject)
        }
    }

    override fun parse(jsonObject: JsonObject) {
        fullName = jsonObject.getPrimitive("full_name").contentOrNull.orEmpty()
        desc = jsonObject.getPrimitive("description").contentOrNull.orEmpty()
        htmlUrl = jsonObject.getPrimitive("html_url").contentOrNull.orEmpty()
        val ownerObject = jsonObject.getObject("owner")
        owner = Owner.create(ownerObject)
    }

    fun mapToProject() = Project(
        fullName.orEmpty(),
        desc.orEmpty(),
        owner?.login.orEmpty(),
        owner?.avatarUrl.orEmpty(),
        htmlUrl.orEmpty()
    )
}
