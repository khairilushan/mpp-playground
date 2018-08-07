package com.khairilushan.mpp.repository

import com.khairilushan.mpp.datasource.ProjectDataSource
import com.khairilushan.mpp.interactor.Result
import com.khairilushan.mpp.interactor.SearchProjectInteractor
import com.khairilushan.mpp.model.Project
import kotlinx.coroutines.experimental.Deferred

interface ProjectRepository {
    fun searchProject(
        params: SearchProjectInteractor.Params,
        completion: (Result<List<Project>>) -> Unit
    )
}

class ProjectRepositoryImpl(
    private val network: ProjectDataSource
) : ProjectRepository {
    override fun searchProject(
        params: SearchProjectInteractor.Params,
        completion: (Result<List<Project>>) -> Unit
    ) {
        network.searchProject(params, completion)
    }
}
