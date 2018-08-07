package com.khairilushan.mpp.datasource

import com.khairilushan.mpp.datasource.network.SearchProjectService
import com.khairilushan.mpp.interactor.Result
import com.khairilushan.mpp.interactor.SearchProjectInteractor
import com.khairilushan.mpp.model.Project
import com.khairilushan.mpp.repository.ProjectRepository

interface ProjectDataSource : ProjectRepository

internal class ProjectDataSourceNetwork(
    private val searchProjectService: SearchProjectService
) : ProjectDataSource {
    override fun searchProject(
        params: SearchProjectInteractor.Params,
        completion: (Result<List<Project>>) -> Unit
    ) {
        searchProjectService.requestJson(params.build()) { entity ->
            val projects = entity.items.map { it.mapToProject() }
            completion(Result.Success(projects))
        }
    }
}
