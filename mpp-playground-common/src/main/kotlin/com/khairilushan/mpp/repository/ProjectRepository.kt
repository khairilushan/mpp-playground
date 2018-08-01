package com.khairilushan.mpp.repository

import com.khairilushan.mpp.datasource.ProjectDataSource
import com.khairilushan.mpp.interactor.Result
import com.khairilushan.mpp.model.Project

interface ProjectRepository {
  fun searchProject(keyword: String, completion: (Result<List<Project>>) -> Unit)
}

class ProjectRepositoryImpl(
  private val network: ProjectDataSource
) : ProjectRepository {
  override fun searchProject(keyword: String, completion: (Result<List<Project>>) -> Unit) {
    network.searchProject(keyword, completion)
  }
}
