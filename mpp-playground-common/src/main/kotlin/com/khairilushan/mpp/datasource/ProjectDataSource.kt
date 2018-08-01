package com.khairilushan.mpp.datasource

import com.khairilushan.mpp.datasource.network.NetworkService
import com.khairilushan.mpp.datasource.network.entity.SearchProjectsEntity
import com.khairilushan.mpp.interactor.Failure
import com.khairilushan.mpp.interactor.Result
import com.khairilushan.mpp.interactor.Success
import com.khairilushan.mpp.model.Project
import com.khairilushan.mpp.repository.ProjectRepository

interface ProjectDataSource : ProjectRepository {
  class Network(private val service: NetworkService) : ProjectDataSource {
    override fun searchProject(keyword: String, completion: (Result<List<Project>>) -> Unit) {
      val params = mapOf("q" to keyword)
      service.requestJson(params) { entity: SearchProjectsEntity?, error: Throwable? ->
        if (entity != null && error == null) {
          completion(Success(entity.items.map { it.mapToProject() }))
        } else if (error != null) {
          completion(Failure(error.hashCode(), error.message.orEmpty()))
        }
      }
    }
  }
}
