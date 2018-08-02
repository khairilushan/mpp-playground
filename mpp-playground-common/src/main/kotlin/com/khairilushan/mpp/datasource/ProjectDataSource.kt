package com.khairilushan.mpp.datasource

import com.khairilushan.mpp.datasource.network.NetworkService
import com.khairilushan.mpp.datasource.network.entity.SearchProjectsEntity
import com.khairilushan.mpp.interactor.SearchProjectInteractor
import com.khairilushan.mpp.model.Project
import com.khairilushan.mpp.repository.ProjectRepository
import kotlinx.coroutines.experimental.Deferred
import kotlinx.coroutines.experimental.async

interface ProjectDataSource : ProjectRepository {
    class Network(private val service: NetworkService) : ProjectDataSource {
        override fun searchProject(
            params: SearchProjectInteractor.Params
        ): Deferred<List<Project>> = async {
            val entity = service.requestJson<SearchProjectsEntity>(params.build()).await()
            entity.items.map { it.mapToProject() }
        }
    }
}
