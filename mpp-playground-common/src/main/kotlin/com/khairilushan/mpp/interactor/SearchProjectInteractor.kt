package com.khairilushan.mpp.interactor

import com.khairilushan.mpp.datasource.ProjectDataSourceNetwork
import com.khairilushan.mpp.datasource.network.SearchProjectService
import com.khairilushan.mpp.model.Project
import com.khairilushan.mpp.repository.ProjectRepository
import com.khairilushan.mpp.repository.ProjectRepositoryImpl

fun createSearchProjectInteractor(): SearchProjectInteractor {
    val service = SearchProjectService()
    val network = ProjectDataSourceNetwork(service)
    val repository = ProjectRepositoryImpl(network)
    return SearchProjectInteractor(repository)
}

class SearchProjectInteractor(
    private val repository: ProjectRepository
) : Interactor<SearchProjectInteractor.Params, List<Project>>() {

    override fun build(params: Params?, completion: (Result<List<Project>>) -> Unit) {
        if (params == null) throw IllegalArgumentException("params should not be null")
        return repository.searchProject(params, completion)
    }

    class Params(private val keyword: String) : RequestParams {
        override fun build(): Map<String, String> = mapOf(
            "q" to keyword
        )
    }

}
