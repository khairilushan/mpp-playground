package com.khairilushan.mpp.interactor

import com.khairilushan.mpp.model.Project
import com.khairilushan.mpp.repository.ProjectRepository

class SearchProjectInteractor(
  private val repository: ProjectRepository
) : Interactor<String, List<Project>>() {

  override fun build(params: String?, completion: (Result<List<Project>>) -> Unit) {
    if (params == null) throw IllegalArgumentException("params should not be null")
    repository.searchProject(params, completion)
  }

}