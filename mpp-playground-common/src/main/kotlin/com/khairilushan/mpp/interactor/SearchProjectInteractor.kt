package com.khairilushan.mpp.interactor

import com.khairilushan.mpp.model.Project
import com.khairilushan.mpp.repository.ProjectRepository

class SearchProjectInteractor(
  private val repository: ProjectRepository
) : Interactor<SearchProjectInteractor.Params, List<Project>>() {

  override fun build(params: Params?, completion: (Result<List<Project>>) -> Unit) {
    if (params == null) throw IllegalArgumentException("params should not be null")
    repository.searchProject(params, completion)
  }

  class Params(val keyword: String) : RequestParams {
    override fun build(): Map<String, String> = mapOf(
      "q" to keyword
    )
  }

}
